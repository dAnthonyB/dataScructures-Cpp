/* 
 * File:   climate.cpp
 * Author: Dennis Bruce
 * CS 3358
 * Prog1
 * Input: data.txt provided by professor
 * Output: a list of doubles from the source file outputted with their max,min,mean, and Standard Deviation.
 * Purpose: Driver program for stats class that will do desired output

 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "stats.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    string fileName; //used to collect the file name of the file.
    string str; //used as a temp variable for string data from the data file
    double var; //used as a temp variable for double data from the data file
    const string deciPoint = "."; //used to find decimals in the strings to make sure they are doubles.
    bool exitLoop; //a temporary bool to exit loop
    ifstream inFile;  //required for file access
    inFile.open(argv[1]);
    Stats s; //a stats object used for data set
    do {
        inFile >> str;
    }
    while (str != "MLO");
    
    //adds decimal values from the file using var into s.vars[] until s.addVar() returns false or inFile does
    do {
        inFile >> str;
        if(3 == str.find(deciPoint) && atof(str.c_str()) != 0) { //looks for a decimal in the 3rd spot
            var = atof(str.c_str());
            exitLoop = !(s.addVar(var));
        }
    }while(!inFile.eof() && !exitLoop);
    
    
     //This segment prints out all needed output.
     //pre: that it reached the end of the file or that we ran out of space in vars[]
     //post: exit
    cout << "Data: " << endl;
    s.showData();
    cout << "Highest: " << s.findHighest() << endl;
    cout << "Lowest: " << s.findLowest() << endl;
    cout << "Average: " << s.getAverage() <<endl;
    cout << "Standard Deviation: " << s.calcStdDeviation() << endl;
    
    
    return EXIT_SUCCESS;
}