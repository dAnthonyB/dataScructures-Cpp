//File Name: plagiarismCatcher.cpp
//Programmer: Dennis Bruce and Gilbert Amador
//Course: CS3358 Section 251
//Program: Number 7
//Purpose: Compare documents with others to see if the are plagiarized.

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "list_3358.h"
#include "list_3358_DLL.h"


using namespace std;
using namespace cs3358_DLL;
using namespace cs3358_LL;

int hashFunction(List_3358_DLL <string> &s, const int &mod);
int getdir (string dir, vector<string> &files);

int main(int argc, char** argv) {
    const int HASH_TABLE_SIZE = 199999; //Prime size of hash table
    
    List_3358_LL <int> hashTable[HASH_TABLE_SIZE]; //list of files that have collided
    
    List_3358_DLL <string> wordChunk; //a linked list representing the argv[2] sized wordChunks
    ifstream inFile; //used to get files
    string fileChar; //represents the char drawn from the files
    char upperChar; //stores the uppercase version of the char
    int hashKey; //stores the hash key for current word chunk
    
    int numHashes=0; //keeps count of the number of hash keys generated
    int largest = 0; //keeps track of the largest hash key generated
    int smallest = -1; //keeps track of the smallest hash key generated
    
    string dir = argv[1]; //takes command line argument to find folder containing documents
    int chunkSize = 0; //keeps track of the current chunk of text
    
    //takes the command line argument to get amount of words per chunk of text to be tested.
    char* text = argv[2]; 
    int numWords = atoi(text);
    
    //takes the command line argument to get the amount of collisions required to print out pairs of documents
    text = argv[2]; 
    int maxCollisions = atoi(text); 
    
    ofstream outFile("outFile.txt");//prints pairs of documents to file > maxCollisions
    
    //sets up vector with filenames
    vector<string> files = vector<string>();
    getdir(dir,files);
    
    vector < vector <int> > collisions; //a vector of ints that stores the number of collisions for [file1][file2]
    collisions.resize( files.size() , vector<int>(files.size() , -1 ) ); //makes the vector files.size()Xfiles.size() initialized with -1's
    
    //Prints out number of files and the files
    cout << "Number of files: " << files.size() << endl << endl;
    for (int i = 0 ; i < files.size(); i++) {
       cout << i << ": " << files[i] << endl;
    }
   
    for (int i = 0; i < files.size(); i++) { //loops through all files i = file number
        //cout << i << endl; //print file number when it opens
        //outFile << i << ": " << files[i] << endl;
        string directory = dir + "/" + files[i];
        inFile.open(directory.c_str()); //opens up the ith file
        
        do { //Loops through ith file until it reach the end of the file
            string tempString = "";
            inFile >> fileChar;

            for(int j = 0; j < fileChar.size(); j++) { //put letters (excludes symbols) into a temp String to add to the queue.
               upperChar = toupper(fileChar[j]);
               if((int) upperChar >= 65 && (int)upperChar <= 90) //tests if char is a letter
               tempString += upperChar;
            }
            //inserts string into the front
            wordChunk.reset();
            wordChunk.insert(tempString);
            chunkSize++;

            if (chunkSize == numWords) { //if the queue has gotten argv[2] words it will do the hash function then it and remove the first word of the chunk
                
                hashKey = hashFunction(wordChunk, HASH_TABLE_SIZE); //stores the hash key for the current file
                
                if(hashKey >= 0){
                     hashTable[hashKey].insert(i);//inserts a linked list node into the spot that the key represents on the hashTable
                     numHashes++; //increments the numHashes counter
                }else
                    cout << "hash key is less than 0" << endl;
                
                //checks for smallest and largest hash key values
                if(smallest == -1)
                    smallest = hashKey;
                if(hashKey > largest)
                    largest = hashKey;
                if (hashKey < smallest)
                    smallest = hashKey;
                   
                
                //removes the end word
                wordChunk.goToEnd();
                wordChunk.remove();
                chunkSize--;
            }
           
        }while(!inFile.eof());

         //empties wordChunk and closes the current file and clears it
        chunkSize = 0;
        wordChunk.emptyList(); 
        inFile.close();
        inFile.clear();
    
    }
    
    cout << "filled hash table" << endl;
    
    using namespace cs3358_LL;//using singly linked list now
    bool fileInTable = false; //used to keep track of weather or not the file is in the ith slot of the hash table
    //checks for collisions
    for(int fileNum = 0; fileNum < files.size(); fileNum++){
        for(int i = 0; i < HASH_TABLE_SIZE; i++){
            fileInTable = false; //resets to false after each file
            hashTable[i].reset();//makes sure the cursor is on the head of the LL
            while(hashTable[i].cursor != NULL){ //loops through hashTable to check for collisions
                if(fileInTable){//sees if the file is already known to be in the hash table
                    if (fileNum < hashTable[i].getCurrent()){ //so it doesn't test for itself or larger ones don't test for smaller ones again
                        collisions[fileNum][hashTable[i].getCurrent()]++; //Increments the number of collisions at the [i][cursor] spot
                    }
                }
                else{
                    if(hashTable[i].getCurrent() == fileNum ){ //checks to see if the file we are checking is in the collision spot
                        fileInTable = true;
                        hashTable[i].reset();
                        collisions[fileNum][hashTable[i].getCurrent()]++; //increments the number of collisions to account for the advance ahead
                    }
                }
                hashTable[i].advance();//moves the cursor forward
            }
        }
    }
    cout << "finished checking collisions" << endl << "outputting pairs to outFile.txt" << endl;
    
    //prints out files that have more than argv[3] collisions
    for(int i = 0; i < files.size()-1; i++) {
        for(int j = i+1; j < files.size(); j++) { //i+1 so it won't print duplicates
            if(collisions[i][j] >= maxCollisions){ //tests to see if files i and j have more collisions than max
                outFile << collisions[i][j] << " collisions for files : " << files[i] << " and " << files[j] << endl;
            }
        }
    }
    cout << "smallest hash key: " <<smallest<<endl;
    cout << "largest hash key: " << largest << endl;
    cout << "number of hashes: " << numHashes << endl;
    cout << "EXIT SUCCESS" << endl;
    return EXIT_SUCCESS;
}

int getdir (string dir, vector<string> &files)
{
   DIR *dp;
   struct dirent *dirp;

   if((dp  = opendir(dir.c_str())) == NULL)
   {
      cout << "Error(" << errno << ") opening " << dir << endl;
      return errno;
   }

   int i = 0; //makes sure it reads only the file names

   while ((dirp = readdir(dp)) != NULL)
   {
      if(i>1)//makes sure it reads only the file names
      files.push_back(string(dirp->d_name));
      i++;//makes sure it reads only the file names
   }

   closedir(dp);

   return 0;
};

int hashFunction(List_3358_DLL <string> &wordChunk, const int &tableSize){
    int hashNum = 0;
    string tempS = wordChunk.toString();//turns the wordChunk into a string and stores it into tempS
    
    //hash function that uses the ascii values of the string and the length of 
    //the string to generate a hash key
    const int CHAR_OFFSET = 64; // makes it to where char value starts at 1 vs 65
    for(int i = 0; i < tempS.size(); i++) {
        hashNum += (int(tempS[i]) - CHAR_OFFSET)*(tempS.size())^i; 
    }
    return ((hashNum)%tableSize); //mods it by the size of the hashTable
}
