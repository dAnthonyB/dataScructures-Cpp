/* stats.h

Written by Roger Priebe and Dennis Bruce
CS 3358
Prog1

This class will provide some simple statistics functions.

//USE THIS FILE FOR DOCUMENTATION (INCLUDING PRE and POST CONDITIONS)

*/
#ifndef STATS_H
#define STATS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class Stats {
    
   static const int MAX_SIZE = 10000;
   private:     
      int numVars; //the number of variables in the list of data
      double vars[MAX_SIZE]; //list of data set at size 10000
      
   public:     
      Stats();
      
      void clearData() {
         numVars = 0;
      }
      
      
      //This function adds one variable to the array in the class.
      //The function returns false if the variable is not successfully added to the class.
      //pre: numVars < MAX_SIZE
      //post: numVars = numvars + 1 and var has been added to the class   
      bool addVar(double var);
      
      //This function loops through vars[] and prints the data
      //The function has no return type
      //pre: numVars > 0;
      //post: all variables are looped through and shown
      void showData();
      
      //This function loops through vars[] and adds the elements together and finds the average.
      //The function returns the average of the data set
      //pre:  numVars > 0;
      //post: all variables are looped through and added and the total is averaged
      double getAverage();
      
      //This function loops through vars[] and searches for the largest
      //The function returns the highest value in vars[]]
      //pre: numVars > 0;
      //post: all variables are looped through and highest has the greatest value of vars[]
      double findHighest();
      
      //This function loops through vars[] and searches for the lowest
      //The function returns the lowest value in vars[]]
      //pre: numVars > 0;
      //post: all variables are looped through and highest has the lowest value of vars[]
      double findLowest();
      
      //This function loops through vars[], subtracts the square of the difference of each element, adds it into StdDev 
      //The function returns the highest Standard Deviation of vars[]'s values.
      //pre: numVars > 0;
      //post: all variables are looped through with calculations successful and returns the standard deviation
      double calcStdDeviation();
      
      int getNumVars() {
         return numVars;
      }
      
      static int getMaxSize() {
         return MAX_SIZE;
      }
      
};

#endif