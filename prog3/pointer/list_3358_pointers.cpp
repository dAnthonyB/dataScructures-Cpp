/* list_3358_pointers.cpp
 * Dennis Bruce
 * CS 3358
 * Prog3
 * Input:
 * Output:
 * Description:
 */
#include "list_3358_pointers.h"
using namespace std;
using namespace cs3358_LL;

//Constructor/Destructor
//Preconditions: None.
//Postconditions: Creates an empty list capable of holding Item type data items. 
//Current position is at BOL/EOL. 
//The List has a capacity of at most MAX_ITEMS items.

List_3358::List_3358 ( ) {
    
    head = NULL;
    tail = NULL;
    cursor = NULL;
};

  //Preconditions: None
  //Postconditions: Creates a new List which is a deep copy of the passed src List. 
  //Implement the copy constructor last, after the rest of the implementation has been debugged.
      
List_3358::List_3358 ( const List_3358 & src ) {
    if (src.head == NULL)
    {
        head = NULL;
        tail = NULL;
        cursor = NULL;
     }
     else
     {
        Node *temp;
        Node *prev = NULL;

        for (Node *p = src.head; p != NULL; p=p->next)
        {
           temp = new Node;
           temp->value = p->value;
           temp->next = NULL;
           temp->previous = prev;
           
           if (prev == NULL)
              prev = temp;
           else
           {
              prev->next = temp;
              prev = temp;
           }

           if (p == src.head)
              head = temp;
           if (p == src.cursor)
              cursor = temp;
           if (p == src.tail)
              tail = temp;
        }
    }
}

//Preconditions: None.
//Postconditions: Destroys the list, cleaning up all resources associated with the object.

List_3358::~List_3358 ( ) {
    Node *p = head;

    while (head != NULL)
    {
       head = head->next;
       delete p;
       p = head;
    }
}


//************************************
//Mutator(s)

//Preconditions: List is not full (i.e. the number of items currently in the list is less than its capacity).
//Postconditions: The item has been inserted by copying into the list. 
//Location of the insert occurs at the current position (the item previously at the current position
// is moved to the next position in the list). 
//After an insert, the current position remains the same.
//If the current position is at the end of the list, the current position will remain 
//at the end of the list after the insert.

void List_3358::insert ( const value_type & item ) {
    
    if (!isFull()) {
        
        Node *temp = new Node;
        temp->value = item;
        temp->next = NULL;
        temp->previous = NULL;

        if (isEmpty())
        {
            cout << "inserting at start of list: " << item << endl;
             head = temp;
             tail = temp;
             cursor = NULL; //end of list
        }
        else if (cursor == head) { //inserting at head
            cout << "inserting at head: " << item << endl;
            temp->next = head;
            head->previous = temp;
            head = temp;
        }
        else if (atEOL())
        {
            cout << "inserting at the EOL: " << item << endl;
             tail->next = temp;
             temp->previous = tail;
             tail = temp;
        }
        
        else {
            cout << "inserting in middle of list: " << item << endl;
            temp->next = cursor;
            cursor->previous->next = temp;
            temp->previous = cursor->previous;
            cursor->previous = temp;
        }
    }
}


//Preconditions: Current position is not EOL and list is not empty.
//Postconditions: The item at the current position is removed from the list. 
//The current position becomes that of the item's successor, 
//or EOL if the removed item were the last in the list.  

void List_3358::remove ( ) {
    

    if (!atEOL() && !isEmpty()) {
        if (cursor == head) {
            cout << "removing head" << endl;
            head = head->next;
            delete cursor;
            cursor = head;
            head->previous = NULL;
           
            if (head == NULL)
               tail = NULL;  //deleted only item in list
        }
        else if (cursor == tail) {
            cout << "removing tail" << endl;
            tail = tail->previous;
            tail->next = NULL;
            delete cursor;
            cursor = NULL;
        }
        else {
            cout << "removing from middle of list" << endl;
            Node *temp = cursor->previous;
            cursor->next->previous = cursor->previous;
            cursor->previous->next = cursor->next;
            delete cursor;
            cursor = temp;
        }
    }
}


//Preconditions: None.
//Postconditions: Resets the current position to the beginning of the list BOL. 
//If the list is empty, then the position is set to EOL. 

void List_3358::reset ( ) {
    cursor = head;
}


//Preconditions: None.
//Postconditions: Advances the current position to the next item in the list. 
//Advancing from EOL leaves the current position at EOL. 
//If the position following the advance is not EOL, the result of the function is TRUE, 
//and if the position following the advance is EOL, the result of the function is FALSE. 

bool List_3358::advance ( ) {
    if (!atEOL() && !isEmpty())
        cursor = cursor->next;
    
    return  (!atEOL()); 
}



//*******************
// Accessor(s)

//Preconditions: None.
//Postconditions: Return value is true if the list contains no items, and false otherwise.

bool List_3358::isEmpty ( ) const {
    
    return (head == NULL);
    
}


//Preconditions: None.
//Postconditions: Return value is true if the current position is logically at EOL, 
//and false otherwise.

bool List_3358::atEOL ( ) const {
    
    return (cursor==NULL);
    
}


//Preconditions: None.
//Postconditions: Return value is true if the list contains its capacity of items, 
//and false otherwise.

bool List_3358::isFull ( ) const {
    
    return false;
    
}



//Preconditions: Current position is not EOL or at BOL.
//Postconditions: Return value is a copy of the item at the current position. 
//The list is unaffected. 

List_3358::value_type List_3358::getCurrent ( ) const {
    if (!atEOL())
        return cursor->value;
}