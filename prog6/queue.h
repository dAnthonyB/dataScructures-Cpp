//File Name: queue.h
//Programmer: Dennis Bruce and Gilbert Amador
//Course: CS3358 Section 251
//Program: Number 6
//Purpose: Compare documents with others to see if the are plagiarized.

#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>  // Provides size_t
#include <vector>
#include <cassert>
#include "list_3358.h"

using namespace std;
using namespace cs3358_LL;

template<class ItemType>
class queue
{
   public:

   // typedef int value_type;
   //typedef int size_type;

   queue();

   //Copy constructor
   queue(const queue & src);

   /****************************
   makeEmpty

   Function: Removes all the items from the stack.
   Preconditions: Queue has been initialized
   Postconditions: All the items have been removed
   *****************************/
   void makeEmpty();
   int size();
   void showList(ofstream& outFile) const;
   /****************************
   isEmpty

   Function: Checks to see if there are any items on the stack.
   Preconditions: Queue has been initialized
   Postconditions: Returns true if there are no items on the stack, else false.
   *****************************/
   bool isEmpty() const;

   /****************************
   isFull

   Function: Determines if you have any more room to add items to the stack
   Preconditions: Queue has been initialized
   Postconditions: Returns true if there is no more room to add items, else false
   *****************************/
   bool isFull() const;

   /****************************
   * enqueue

   Function: Adds newItem to the top of the stack.
   Preconditions: Queue has been initialized and is not full.
   Postconditions: newItem is at the top of the stack.
   *****************************/
   void enqueue(const ItemType &);

   /****************************
   * dequeue

   Function: Removes topItem from stack and returns it.
   Preconditions: Queue has been initialized and is not empty.
   Postconditions: Top element has been removed from stack and item is a copy of the removed element.
   *****************************/
   ItemType dequeue();

   private:
      List_3358<ItemType> list;
      int sizeOfList;

};

/*******************************
/ Function implementations
********************************/

template<class ItemType>
queue<ItemType>::queue ()
{
   sizeOfList = 0;
}

//Copy constructor not needed
template<class ItemType>
queue<ItemType>::queue(const queue & src)
{

}

template<class ItemType>
void queue <ItemType>::makeEmpty()
{
   list.~List_3358();
}

template<class ItemType>
int queue<ItemType>::size ()
{
   return sizeOfList;
}

template<class ItemType>
bool queue <ItemType>::isEmpty() const
{
   return (list.isEmpty());
}

template<class ItemType>
bool queue <ItemType>::isFull() const
{
   return false;
}

template<class ItemType>
void queue <ItemType>::enqueue(const ItemType& newItem)
{
   assert(isFull() == false);
   list.goToEnd ();
   list.insert(newItem);
   sizeOfList++;
}

template<class ItemType>
ItemType queue <ItemType>::dequeue()
{
   assert(isEmpty() == false);
   list.reset ();
   ItemType temp;
   temp = list.getCurrent();

   list.remove();
   sizeOfList--;
   return temp;
}

template<class ItemType>
void queue <ItemType>::showList(ofstream& outFile) const
{
   list.showList(outFile);
}
#endif
