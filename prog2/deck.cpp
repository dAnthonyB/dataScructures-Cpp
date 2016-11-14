/* deck.cpp
 * Dennis Bruce
 * CS 3358
 * Prog2
 */
#include "deck.h"

using namespace std;

Deck::Deck() {
    
    myIndex = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            Card temp((j+1),(Card::Suit) (i));
            myCards[myIndex] = temp;
            myIndex++;
        }
    }
    myIndex = 0;
}           // pristine, sorted deck

void Deck::shuffle() {
    int randCard1;
    int randCard2;
    Card temp;
    
    for(int i = 0; i < 200; i++) {
        do {
            randCard1 = (rand() % 52);
            randCard2 = (rand() % 52);
        }while(randCard1 == randCard2);
        temp = myCards[randCard1];
        myCards[randCard1] = myCards[randCard2];
        myCards[randCard2] = temp;
    }
        
}   // shuffle the deck, all 52 cards present
Card Deck::dealCard() {
    if(size() > 0) {
        Card temp = myCards[myIndex];
        myIndex++;
        return temp;
    }
    else{
        Card empty(-1, (Card::Suit) 0);
        return empty;
    }
        
}   // get a card, after 52 are dealt, fail 

int  Deck::size() const {
    return 52 - myIndex;
} // # cards left in the deck