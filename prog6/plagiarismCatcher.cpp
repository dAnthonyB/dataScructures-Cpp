//File Name: plagiarismCatcher.cpp
//Programmer: Dennis Bruce and Gilbert Amador
//Course: CS3358 Section 251
//Program: Number 6
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
#include "List_3358.h"
#include "queue.h"

using namespace std;

int hashFunction(List_3358 <string> &s, const int &mod);
int getdir (string dir, vector<string> &files);

int main(int argc, char** argv)
{
    //int numWords = 6;
    const int HASH_TABLE_SIZE = 100003;
    List_3358 <int> hashTable[HASH_TABLE_SIZE]; //list of files that have collided
    List_3358 <string> wordChunk;
    ifstream inFile;
    string fileChar;
    char upperChar;
    
    int largest = 0;
    int smallest = -1;
    int wordCount = 0;
    //ofstream outFile("outFile.txt");

    string dir = "big_doc_set";
    //string dir = argv[1];

    //const char* text = argv[2];
    //int numWords = atoi(text);
    int numWords = 6;
    
    //sets up vector with filenames
    vector<string> files = vector<string>();
    getdir(dir,files);
    
    //Prints out number of files and the files
    cout << "Number of files: " << files.size() << endl << endl;
    for (int i = 0 ; i < files.size(); i++)
    {
       cout << i << ": " << files[i] << endl << endl;
    }
   
    for (int i = 0; i < files.size(); i++)
    { //loops through all files
        cout << i << endl;
        //outFile << i << ": " << files[i] << endl;
        string directory = dir + "/" + files[i];
        inFile.open(directory.c_str());

        do
        {
           string tempString = "";
           inFile >> fileChar;

           for(int j = 0; j < fileChar.size(); j++)
           { //put letters (excludes symbols) into a temp String to add to the queue.
              upperChar = toupper(fileChar[j]);
              if((int) upperChar >= 65 && (int)upperChar <= 90) //tests if char is a letter
              tempString += upperChar;
           }
           wordChunk.reset();
           wordChunk.insert(tempString);
           
           if (wordChunk.size() == numWords)
           { //if the queue has gotten 6 words it will print it and remove the first word of the chunk
                
              /*
               wordChunk.showList(outFile);
              outFile << endl;*/
                int key = hashFunction(wordChunk, HASH_TABLE_SIZE);
                
                /*if(key != 0)
                    hashTable[key].insert(i);*/
               
                wordChunk.goToEnd();
                wordChunk.remove();
           }
           
   }while(!inFile.eof());
   
   
    inFile.close();
    inFile.clear();
    }
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

int hashFunction(List_3358 <string> &wordChunk, const int &mod){
    int hashNum = 0;
    string tempS = wordChunk.toString();
    for(int i = 0; i < tempS.size(); i++) {
        hashNum += int(tempS[i])*(tempS.size());
    }
    return hashNum%mod;
}
