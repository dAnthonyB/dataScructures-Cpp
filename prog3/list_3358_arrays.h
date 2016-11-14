/* list_3358_arrays.h
 * Dennis Bruce
 * CS 3358
 * Prog3
 * Input:
 * Output:
 * Description: a very simple cursor based List ADT
  
  This implentation will use a simulated doubly-linked list that uses arrays.
  
  The constant EOL will be assinged the value -1 and signifies the end of the list
  and the beginning of the list.
  
  We will not use user-defined templates for this program.
  
    -It is homogenious -- the elements in the collection are all of the same type.
    -It has a finite length (the number of elements).
    -The elements are arranged sequentially:
          o There is a first element and a last element
          o Every element except the last has a unique successor
          o Every element except the first has a unique predecessor
*/

#ifndef LIST_3358_H
#define	LIST_3358_H
#include <iostream>             
#include <cstdlib>  // Provides size_t


using namespace std;


namespace cs3358 {
 class List_3358 
 {
   
   public:
      
      typedef int value_type;  //change here for different data type
      typedef int size_type;
      static const size_type MAX_ITEMS = 100; // a named constant specifying the maximum number of items in a list.
      static const size_type EOL = -1;
      static const size_type BOL = -1;
      
   
      //Constructor/Destructor
      //Preconditions: None.
      //Postconditions: Creates an empty list capable of holding Item type data items. 
      //Current position is at BOL/EOL. 
      //The List has a capacity of at most MAX_ITEMS items.
      
      List_3358 ( );

      //Preconditions: None
      //Postconditions: Creates a new List which is a deep copy of the passed src List. 
      //Implement the copy constructor last, after the rest of the implementation has been debugged.
      
      List_3358 ( const List_3358 & src );

      //Preconditions: None.
      //Postconditions: Destroys the list, cleaning up all resources associated with the object.
      
      ~List_3358 ( );

      
      //************************************
      //Mutator(s)
      
      //Preconditions: List is not full (i.e. the number of items currently in the list is less than its capacity).
      //Postconditions: The item has been inserted by copying into the list. 
      //Location of the insert occurs at the current position (the item previously at the current position
      // is moved to the next position in the list). 
      //After an insert, the current position remains the same.
      //If the current position is at the end of the list, the current position will remain 
      //at the end of the list after the insert.
      
      void insert ( const value_type & item );


      //Preconditions: Current position is not EOL and list is not empty.
      //Postconditions: The item at the current position is removed from the list. 
      //The current position becomes that of the item's successor, 
      //or EOL if the removed item were the last in the list.  
      
      void remove ( );


      //Preconditions: None.
      //Postconditions: Resets the current position to the beginning of the list BOL. 
      //If the list is empty, then the position is set to EOL. 
      
      void reset ( );


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
       
       value_type getCurrent ( ) const;
      
  
     
   private:
      
      value_type values[MAX_ITEMS];
      size_type next[MAX_ITEMS];
      size_type previous[MAX_ITEMS];
      
      size_type currentSize;
      size_type head;
      size_type tail;
      size_type cursor;
     
      
 };
}
#endif	/* LIST_3358_ARRAYS_H */

