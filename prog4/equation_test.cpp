//File Name: check.cpp
//Programmer: Gilbert Amador
//Course: CS3358 Section 251
//Program: Number 4
//Purpose: Check delimiters using stack

#include <iostream>
#include <fstream>
#include "stack_3358.h"

using namespace std;

int main(int argc, char * argv[]){

  char missingChar;
  ifstream inFile;
  inFile.open(argv[1]);
  
  Stack_3358<char> myStack;
  string tempStr;
   
   while (!inFile.eof()) {
   	myStack.makeEmpty();
        inFile >> tempStr;
            bool haveEquation = true;
	bool finishedEqu = true;
	 
	while(haveEquation == true && finishedEqu == true)
	{
            for(int i = 0; i < tempStr.length(); i++)
	    {
	    if(tempStr[i] == '(' || tempStr[i] == '[' || tempStr[i] == '<')
	       {
	         myStack.push(tempStr[i]);
	       }
	       else if(tempStr[i] == ')' || tempStr[i] == ']' || tempStr[i] == '>')
	       {
	       	 char popped;
	       	 popped = myStack.pop();
	       }
       }
	   
       if(myStack.isEmpty() == false)
       {
         haveEquation = false;
         char popped;
         popped = myStack.pop();
         
		 if(popped == '(')
		 {
	       missingChar = ')';
	     }
	     else if(popped == '[')
	     {
	       missingChar = ']';
	     }
	     else
	     {
	       missingChar = '>';
	     }
       }
       finishedEqu = false;
     }
	 
     if(haveEquation == false) {
	   cout << "you are missing a " << missingChar << endl;
	}
     else {
	cout << tempStr << "  ==  valid equation" << endl;
     }
	cout << endl;
   }
    return EXIT_SUCCESS;
}
