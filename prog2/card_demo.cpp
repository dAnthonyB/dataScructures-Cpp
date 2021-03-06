/* go_fish.cpp
 * Dennis Bruce
 * CS 3358
 * Prog1
 * Input: No human players and two computer players
 * Output: A game of go fish between two computer players
 * Description:
 * This is a small demonstration program showing how the bag class is used.
 */
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

Deck d;
vector <Player> playerList;
int numStartCards;
int turn;
bool showCompCards;
// PROTOTYPES for functions used by this demonstration program:


void checkOppMatch(Player &p1, Player &p2);
bool makeHumanPlayer(string choice);
bool makeCompList(int numComp);
void startGame(string choice, int numComp);
void bookMatchingCards(Player &p1);
void dealHands();
void showHands();
bool gameOver();

int main( ) {
    
    startGame("0", 2);
    do {
        showHands();
        checkOppMatch(playerList[0], playerList[1]);
        showHands();
        checkOppMatch(playerList[1], playerList[0]);
        
        /*
        if(turn == playerList.size() - 1)
            turn = 0;
        else 
            turn++;*/
    }while( !(gameOver()) );
    
    if(playerList[0].getBookSize() > playerList[1].getBookSize())
        cout << playerList[0].getName() << " wins with " << playerList[0].getBookSize() << " books.";
    else
        cout << playerList[1].getName() << " wins with " << playerList[1].getBookSize() << " books.";
    
    return EXIT_SUCCESS;  
}
void startGame(string choice, int numComp) {
    showCompCards = makeHumanPlayer(choice);
    makeCompList(numComp);
    if(playerList.size() == 2)
        numStartCards = 7;
    else
        numStartCards = 5;
    d.shuffle();
    dealHands();
}
bool makeHumanPlayer(string choice) {
    if(choice == "-1") {
        cout << "Do you want to play? (Y/y for yes, or any other string for no): " << endl;
        cin >> choice;
    }
    
    if(choice == "y" || choice == "Y") {
        Player player("Human");
        playerList.push_back(player);
        return true;
    }
    else
        return false;
    
}
bool makeCompList(int numComp){
    if(numComp == -1) {
        cout << "Enter the number of computer players: " << endl;
        cin >> numComp;
    }
        
    for(int i = 1; i <= numComp; i++) {
        ostringstream oss;
        oss << i;
        playerList.push_back("Comp" + oss.str());
    } 
    if (playerList.size() <= 1)
        return false;
    else
        return true;
}
void dealHands() {
    for (int player = 0; player < playerList.size(); player++) {
        //deals numStartCards cards to a player (7 if players < 2 else 5)
        for (int i = 0; i < numStartCards; i++) {
            playerList[player].addCard(d.dealCard());
            cout << "the deck." << endl;
        }
        bookMatchingCards(playerList[player]);
    }
}

void checkOppMatch(Player &p1, Player &p2){
    
    if(p1.getHandSize() > 0 && p2.getHandSize() > 0) {
        Card temp1 = p1.chooseCardFromHand();
        cout << p1.getName() << " asks " << p2.getName() << " if they have a " << temp1.rankString(temp1.getRank()) << endl;
        if(p2.rankInHand(temp1)) {
            Card temp2 = p2.removeCardFromHand(temp1);
            p1.addCard(temp2);
            cout << p2.getName() << "'s hand." << endl;
            bookMatchingCards(p1);
        }
        else {
            cout << p2.getName() + " says, \"Go fish.\"" << endl;
            if(d.size() > 0) {
                p1.addCard(d.dealCard());
                cout << "the deck." << endl;
                bookMatchingCards(p1);
            }
            else
                cout << "The deck is empty." << endl;
        }
    }
    else {
        if(d.size() > 0) {
            p1.addCard(d.dealCard());
            cout << "the deck." << endl;
            bookMatchingCards(p1);
        }
    }
}
void bookMatchingCards(Player &p) {
    Card temp1;
    Card temp2;
    while(p.checkHandForBook(temp1, temp2)) {
        p.bookCards(temp1, temp2);
    }
}

bool gameOver() {
    bool emptyHands;
    if(d.size() <= 0) {
        for(int i = 0; i < playerList.size(); i++) {
            if(playerList[i].getHandSize() == 0)
                emptyHands = true;
        }
        if(emptyHands)
            return true;
    }
    return false;
}
void showHands(){
    for(int i = 0; i < playerList.size(); i++) {
        bookMatchingCards(playerList[i]);
        cout << playerList[i].showHand();
    }
}