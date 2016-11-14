/* player.cpp
 * Dennis Bruce
 * CS 3358
 * Prog2
 */
#include "player.h"
#include "deck.h"

using namespace std;

Player::Player(){
    myName = "FALSE";
};

void Player::addCard(Card c) {
    
    if( c.getRank() != -1) {
        cout << "Added card " << c.toString() << " to " << getName() << "'s hand from ";
        myHand.push_back(c);
    }
    else
        cout << "The deck is empty." << endl;
}  //adds a card to the hand

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
    cout << "Booking " << c1.toString() << " and " << c2.toString() << " for " << myName << " and they now have " << (getBookSize()) << " book(s)!" << endl;
  }

  //OPTIONAL
  // comment out if you decide to not use it
  //this function will check a players hand for a pair. 
  //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2) {
    for(int i = 0; i < (getHandSize() - 1); i++) {
        for(int j = i+1; j < getHandSize(); j++) {
            if(myHand[i].getRank() == myHand[j].getRank()) {
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
};
  
bool Player::rankInHand(Card c) const {
    for(int i = 0; i < getHandSize(); i++) {
        if(c.getRank() == myHand[i].getRank()) 
            return true;
    }
    return false;
}; 

  //uses some strategy to read a card from the player's
  //hand so they can say "Do you have a 4?" aka compare it to another card
Card Player::chooseCardFromHand() const {
    /*
    int num;
    if(getName() == "Human") {
        do {
            cout << "Please enter the number you wish to choose (-1 to exit) ";
            cin >> num;
            cout << num;
            for(int i = 0; i < getHandSize(); i++) {
                if(num == myHand[i].getRank())
                    return myHand[i];
            }
        cout << endl << "You don't have a " << num << " in your hand." << endl;
        }while(num != -1);
    }
    else */
        return myHand[(rand() % getHandSize())];
    
}; 

  //Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const {
    for(int i = 0; i < getHandSize(); i++) {
        if(myHand[i] == c){
            return true;
        }
    }
    return false;
}; 

  //Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c) {
    Card tempC;
    for(int i = 0; i < getHandSize(); i++) {
        if(myHand[i].getRank() == c.getRank()) {
            tempC = myHand[i];
            myHand.erase(myHand.begin()+i);
            return tempC;
        }
    }
}; 

string Player::showHand() const {
      string hand = myName;
      hand = hand + " has:";
      for(int i = 0; i < getHandSize(); i++) {
          hand = hand + " ";
          hand = hand + myHand[i].toString();
           
      }
      hand = hand + "\n";
      return hand;
}; 
string Player::showBooks() const {
      string books = "Books: ";
      for(int i = 0; i < myBook.size(); i++) { //use .size() instead of getBookSize()
          books = books + " ";
          books = books + myBook[i].toString();
      }
      return books;
}; 

int Player::getHandSize() const {
      return myHand.size();
}; 
int Player::getBookSize() const {
      const int SIZE_OF_A_BOOK = 2;
      return (myBook.size() / SIZE_OF_A_BOOK);
};