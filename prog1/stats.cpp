
/* 
 * File:   stats.cpp
 * Author: Dennis Bruce
 * CS 3358
 * Prog1
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "stats.h"

using namespace std;

       Stats::Stats(){
       };
      bool Stats::addVar(double var) {
        if(numVars < MAX_SIZE) {
            if(vars[0] == 0)
                numVars = 0;
            vars[numVars] = var;
            numVars++;
            return true;
        }
        return false;
      }
      
      void Stats::showData() {
          for(int i = 0; i < numVars; i++)
              cout << vars[i] << endl;
      }
      
      double Stats::getAverage() {
          double average = 0;
          
          for(int i = 0; i < numVars; i++)
              average += vars[i];
          
          average = average/numVars;
          return average;
      }
      double Stats::findHighest() {
          double highest;
          
          for(int i=0; i < numVars; i++) {
              if(vars[i] > highest)
                  highest = vars[i];
          }
          
          return highest;
      }
      double Stats::findLowest() {
          double lowest;
          lowest = vars[0];
          for(int i=0; i < numVars; i++) {
              if(vars[i] < lowest)
                  lowest = vars[i];
          }
          
          return lowest;
      }
      double Stats::calcStdDeviation() {
          double stdDev = 0;
          double average;
          double temp;
          average = getAverage();
          
          for(int i=0; i < numVars; i++) {
              temp = average - vars[i];
              temp *= temp;
              stdDev += temp;
          }
          stdDev = sqrt(stdDev);
          return stdDev / numVars;
      }