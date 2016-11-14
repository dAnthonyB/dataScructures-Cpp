//File Name: list_3358.h
//Programmer: Dennis Bruce and Gilbert Amador
//Course: CS3358 Section 251
//Program: Number 7
//Purpose: Compare documents with others to see if the are plagiarized.

/*  list_3358.h
Spring 2008
Updated Fall 2009

a very simple cursor based List ADT

-It is homogenious -- the elements in the collection are all of the same type.
-It has a finite length (the number of elements).
-The elements are arranged sequentially:
o There is a first element and a last element
o Every element except the last has a unique successor
o Every element except the first has a unique predecessor
*/

#ifndef LIST_3358_H
#define LIST_3358_H

#include <cstdlib>  // Provides size_t

using namespace std;


namespace cs3358_LL
{
template<class ItemType>

class List_3358_LL
{

   public:


   //typedef int value_type;
   //typedef size_t size_type;


   //Constructor/Destructor
   //Preconditions: None.
   //Postconditions: Creates an empty list capable of holding Item type data items.
   //Current position is at BOL/EOL.
   //The List has a capacity of at most MAX_ITEMS items.

   List_3358_LL ( );

   //Preconditions: None
   //Postconditions: Creates a new List which is a deep copy of the passed src List.
   //Implement the copy constructor last, after the rest of the implementation has been debugged.

   List_3358_LL ( const List_3358_LL & src );

   //Preconditions: None.
   //Postconditions: Destroys the list, cleaning up all resources associated with the object.

   ~List_3358_LL ( );


   //************************************
   //Mutator(s)

   //Preconditions: List is not full (i.e. the number of items currently in the list is less than its capacity).
   //Postconditions: The item has been inserted by copying into the list.
   //Location of the insert occurs at the current position (the item previously at the current position
   // is moved to the next position in the list).
   //After an insert, the current position remains the same.
   //If the current position is at the end of the list, the current position will remain
   //at the end of the list after the insert.
   void insert ( const ItemType & item );


   //Preconditions: Current position is not EOL and list is not empty.
   //Postconditions: The item at the current position is removed from the list.
   //The current position becomes that of the item's successor,
   //or EOL if the removed item were the last in the list.

   void remove ( );


   //Preconditions: None.
   //Postconditions: Resets the current position to the beginning of the list BOL.
   //If the list is empty, then the position is set to EOL.

   void reset ( );

   void goToEnd ();

   //Preconditions: None.
   //Postconditions: Advances the current position to the next item in the list.
   //Advancing from EOL leaves the current position at EOL.
   //If the position following the advance is not EOL, the result of the function is TRUE,
   //and if the position following the advance is EOL, the result of the function is FALSE.

   bool advance ( );

   //*******************
   // Accessor(s)

   //Preconditions: None.
   //Postconditions: Return value is true if the list contains no items, and false otherwise.

   bool isEmpty ( ) const;

   //Preconditions: None.
   //Postconditions: Return value is true if the current position is logically at EOL,
   //and false otherwise.

   bool atEOL ( ) const;

   //Preconditions: None.
   //Postconditions: Return value is true if the list contains its capacity of items,
   //and false otherwise.

   bool isFull ( ) const;

   //Preconditions: Current position is not EOL or at BOL.
   //Postconditions: Return value is a copy of the item at the current position.
   //The list is unaffected.

   ItemType getCurrent ( ) const;
   string toString();
   void emptyList();
   
   
   public:
      struct Node {
      ItemType value;
      Node* next;
      };

      Node* head;
      Node* tail;
      Node* cursor;

};


   /*******************************
   / Function implementations
   ********************************/
   template<class ItemType>
   List_3358_LL<ItemType>::List_3358_LL()
   {
      head = NULL;
      tail = NULL;
      cursor = NULL;
   }

   template<class ItemType>
   List_3358_LL<ItemType>::List_3358_LL( const List_3358_LL & src )
   {
      Node *temp;

      head = NULL;
      tail = NULL;
      cursor = NULL;

	  if (src.head != NULL)
      {
         temp = src.head;
         insert(temp->value);
         advance();
         temp = temp->next;

         while(temp != NULL)
         {
            insert(temp->value);
            temp = temp->next;
            advance();
         }
      }

	  reset();

      while (getCurrent() != src.getCurrent() || atEOL())
         advance();
}

   template<class ItemType>
   List_3358_LL<ItemType>::~List_3358_LL()
   {
      if (!isEmpty())
      {
         cursor = head;
         while (!atEOL())
         {
         head = head->next;
         delete cursor;
         cursor = head;
         }
      }
   }

   template<class ItemType>
   void List_3358_LL<ItemType>::insert( const ItemType & item )
   {
      Node *newNode;
      newNode = new Node;
      newNode->value = item;

      if (isFull())
      {
      //do nothing, violates precondition
      }
      else if (isEmpty())
      {
         newNode->next = NULL;
         head = newNode;
         tail = newNode;
         cursor = newNode;
      }
	  // if the list is not empty and the cursor is at the end of the list
      else
      {
         newNode->next = NULL;
         tail->next = newNode;
         tail = newNode;
      }
   }

   template<class ItemType>
   void List_3358_LL<ItemType>::remove()
   {
      // at the beginning of the list and more than one item
      if (cursor == head && cursor != tail)
      {
         head = head->next;
         delete cursor;
         reset();
      }

	  // only one item in the list
      else if (cursor == tail && cursor == head)
      {
         head = NULL;
         tail = NULL;
         delete cursor;
         cursor = NULL;
      }

	  // at the last item in the list
      else if (cursor == tail && cursor != head)
      {
         tail->next = NULL;
         delete cursor;
         cursor = tail;
      }

	  // somewhere in the middle
      else
      {
         Node *temp;
         temp = cursor->next;
         delete cursor;
         cursor = temp;
      }
   }

   template<class ItemType>
   void List_3358_LL<ItemType>::reset()
   {
      cursor = head;
   }

   template<class ItemType>
   void List_3358_LL<ItemType>::goToEnd()
   {
       cursor = tail;
   }

   template<class ItemType>
   bool List_3358_LL<ItemType>::advance()
   {
      bool retVal = true; //assume it advances and not to EOL

      if (isEmpty() || atEOL())
         retVal = false;
      else
      {
         cursor = cursor->next;
         if (atEOL())
            retVal = true;
      }

      return retVal;
   }

   template<class ItemType>
   bool List_3358_LL<ItemType>::isEmpty() const
   {
      return (head == NULL && tail == NULL);
   }

   template<class ItemType>
   bool List_3358_LL<ItemType>::atEOL() const
   {
      return (cursor == NULL && tail != NULL);
   }

   template<class ItemType>
   bool List_3358_LL<ItemType>::isFull() const
   {
      try
      {
         Node *temp = new Node;
         delete temp;
         return false;
      }
      catch(std::bad_alloc)
	  {
         return true;
      }
   }

   template<class ItemType>
   ItemType List_3358_LL<ItemType>::getCurrent() const
   {
        return cursor->value;
   }
}
#endif
