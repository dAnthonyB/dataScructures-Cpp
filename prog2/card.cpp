/* card.cpp
 * Dennis Bruce
 * CS 3358
 * Prog2
 */
#include "card.h"

using namespace std;
    
Card::Card() {
    myRank = 1;
    mySuit = spades;
};          // default, ace of spades

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s; 
}

string Card::toString()              const {
    return rankString(getRank()) + suitString(mySuit);
}  // return string version e.g. Ac 4h Js
bool Card::sameSuitAs(const Card& c) const {
    if(mySuit == c.mySuit)
        return true;
    else
        return false;
}  // true if suit same as c
int  Card::getRank()                 const {
    return myRank;
}  // return rank, 1..13
string Card::suitString(Suit s)      const {
    switch(s) {
        case spades:
            return "s";
            break;
        case hearts:
            return "h";
            break;
        case diamonds:
            return "d";
            break;
        case clubs:
            return "c";
            break;
        default:
            return " *ERROR*";
    }
}  // return "s", "h",...
string Card::rankString(int r)       const {
    ostringstream oss; //used for suitNumber to string
    if(r == 1)
            return "A";
    if(r < 11) {
            oss << r;
            return oss.str();
    }
    else if(r == 11)
        return "J";
    else if(r == 12)
        return "Q";
    else if(r == 13)
        return "K";
    else
        return "ERROR";
}  // return "A", "2", ..."Q"

bool Card::operator == (const Card& rhs) const {
    if(myRank == rhs.myRank && mySuit == rhs.mySuit)
        return true;
    else
        return false;
}
bool Card::operator != (const Card& rhs) const {
    if(myRank == rhs.myRank && mySuit == rhs.mySuit)
        return false;
    else
        return true;
}

ostream& operator << (ostream& out, const string& s) {
    ofstream myFile ("output.txt");
    if (myFile.is_open()) {
        myFile << s;
        myFile.close();
        return out;
    }
    else out << "failed";
    
}

ostream& operator << (ostream& out, const Card& c) {
    ofstream myFile ("output.txt");
    if (myFile.is_open()) {
        myFile << c.toString();
        myFile.close();
        return out;
    }
    else out << "failed";
}