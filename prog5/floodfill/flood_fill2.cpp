/* flood_fill2.cpp
 * Dennis Bruce
 * CS 3358
 * Prog5
 * Input: txt picture, a row and colum number, and color
 * Output: Picture that has been floodFilled where asked
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
// Creates a picture from the input file with an "invisible" border of 1s 
//to help the function no go out of bounds
void makePic(int argc, char** argv);
//prints the picture without displaying the border of 1s
void printPic(int offset, int hideBorder);
//recursive floodFill function
void floodFill(int x, int y, char toChange);

const int MAX_SIZE = 80; 
char myPic[MAX_SIZE+2][MAX_SIZE+2];

int length;
int width;

int main(int argc, char** argv) {
    int row;
    int colum;
    char color;
    
    makePic(argc, argv);
    
    do{
        printPic(1,1);

        cout << "Enter a row ";
        cin >> row;
        cout << endl;
        cout << "Enter a colum ";
        cin >> colum;
        cout << endl;
        cout << "Enter a color ";
        cin >> color;
        cout << endl;

        floodFill(row+1, colum, color);
    }while(row != -1 && colum != -1);
    
    return EXIT_SUCCESS;
    
}
void makePic(int argc, char** argv) {
    
    ifstream inFile;
    inFile.open(argv[1]);
    
    int row = 1;
    int colum = 1;
    string tempStr;
    
    while ( !inFile.eof() && row < MAX_SIZE+1) {
        inFile >> tempStr;
        
        for(colum = 1; colum < tempStr.length()+1 && colum < MAX_SIZE; colum++) {
            myPic[row][colum] = tempStr[colum-1];
        }
        myPic[row][colum] = '1';
        
        row++;
    }
    length = tempStr.length();
    width = row - 1;
    for(int i = 0; i < length+2; i++) {
        myPic[0][i] = '1';
        myPic[i][0] = '1';
        myPic[width+1][i] = '1';
    }
}
void printPic(int offset, int hideBorder) {
    cout << endl;
    for(int i = hideBorder; i < width+offset; i++){
        for(int j = hideBorder; j < length+offset; j++) {
            cout << myPic[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void floodFill(int x, int y, char toChange) {
    char tempC;
    tempC = myPic[x][y];
    if (tempC != toChange){
        myPic[x][y] = toChange;

        if(tempC == myPic[x][y+1])
            floodFill(x,y+1 ,toChange);
        if(tempC == myPic[x][y-1])
            floodFill(x , y-1 ,toChange);

        if(tempC == myPic[x+1][y])
            floodFill(x+1 , y ,toChange);
        if(tempC == myPic[x+1][y+1])
            floodFill(x+1 , y+1 ,toChange);
        if(tempC == myPic[x+1][y-1])
            floodFill(x+1 , y-1 ,toChange);

        if(tempC == myPic[x-1][y])
            floodFill(x-1 ,y ,toChange);
        if(tempC == myPic[x-1][y+1])
            floodFill(x-1 ,y+1 ,toChange);
        if(tempC == myPic[x-1][y-1])
            floodFill(x-1 , y+1 ,toChange);
    }
    else
        cout << "It is already that color." << endl;
}
