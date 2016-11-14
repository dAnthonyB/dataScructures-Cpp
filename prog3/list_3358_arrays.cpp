/* list_3358_arrays.cpp
 * Dennis Bruce
 * CS 3358
 * Prog3
 * Input:
 * Output:
 * Description:
 
class List_3358 
 {
   
   public:
      
      typedef int value_type;  //change here for different data type
      typedef int size_type;
      static const size_type MAX_ITEMS = 100; // a named constant specifying the maximum number of items in a list.
      static const size_type EOL = -1;
      static const size_type BOL = -1;
      
   */

#include "list_3358_arrays.h"
using namespace std;
using namespace cs3358;

      //Constructor/Destructor
      //Preconditions: None.
      //Postconditions: Creates an empty list capable of holding Item type data items. 
      //Current position is at BOL/EOL. 
      //The List has a capacity of at most MAX_ITEMS items.
      
List_3358::List_3358 ( ) {
    
        head = BOL;
        tail = EOL;
        currentSize = 0;
        cursor = 0;
    }
      
List_3358::List_3358 ( const List_3358 & src ) {
    //default constructor
    if(src.currentSize == 0) {
        head = BOL;
        tail = EOL;
        cursor = 0;
        currentSize = 0;
    }
    //copy constructor
    else {
        for (int i = 0; i < src.currentSize; i++) {
            
            values[i] = src.values[i];
            next[i] = src.next[i];
            previous[i] = src.previous[i];
        }
        head = src.head;
        cursor = src.cursor;
        tail = src.tail;
        currentSize = src.currentSize;
    }
}
      
List_3358::~List_3358 ( ) {

}

      //************************************
      //Mutator(s)
      
void List_3358::insert (const value_type & item) {

    if (!isFull())
    {
        values[currentSize] = item;
        next[currentSize] = EOL;
        previous[currentSize] = BOL;
        if(isEmpty()) {
            cout << "inserting at start of list: " << item << endl;
            head = currentSize;
            tail = currentSize;
            cursor = EOL;
        }
        else if (cursor == head) {
            cout << "inserting at head: " << item << endl;
            next[currentSize] = head;
            previous[head] = currentSize;
            head = currentSize;
        }
        else if (atEOL())
        {
            cout << "inserting at the EOL: " << item << endl;
           next[tail] = currentSize;
           previous[currentSize] = tail;
           tail = currentSize;
        }
        else
        {
            cout << "inserting in middle of list: " << item << endl;
            next[currentSize] = cursor;
            next[previous[cursor]] = currentSize;
            previous[currentSize] = previous[cursor];
            previous[cursor] = currentSize;
        }
        currentSize++;
    }

}
            
void List_3358::remove() {
    /*cursor's previouses' next needs to point to cursors next
     cursor's next's previous needs to point to cursor's previous
     cursor's next previous and values needs to equal currentSize's
     then cursor's previouses' next needs to point to cursors next
     cursor's next's previous needs to point to cursor's previous
     currentSize--*/
    if (!atEOL() && !isEmpty()) {
        int tempC = cursor;
        if (cursor == head) {
            cout << "removing head" << endl;
            head = next[head];
            cursor = head;
            previous[head] = BOL;
           
            if (head == EOL)
               tail = EOL;  //deleted only item in list
        }
        else if (cursor == tail) {
            cout << "removing tail" << endl;
            tail = previous[tail];
            next[tail] = EOL;
            cursor = EOL;
        }
        else {
            cout << "removing from middle of list" << endl;
            int temp = previous[cursor];
            previous[next[cursor]] = previous[cursor];
            next[previous[cursor]]= next[cursor];
            cursor = temp;
        }
        currentSize--;
        if(cursor != EOL) {
            next[tempC] = next[currentSize];
            previous[tempC] = previous[currentSize];
            values[tempC] = values[currentSize];
            previous[next[tempC]] = tempC;
            next[previous[tempC]] = tempC;
        }
    }
}

void List_3358::reset ( ) {

   cursor = head;
}

bool List_3358::advance ( ) {
    
    if (!atEOL() && !isEmpty()) {
        cursor = next[cursor];
        
    }
        

    return (!atEOL());
}

      //*******************
      // Accessor(s)
      

bool List_3358::isEmpty ( ) const {

    return (currentSize == 0);
}
   
bool List_3358::atEOL ( ) const {

    return (cursor == EOL);   
}
      
bool List_3358::isFull ( ) const {

   return (currentSize == MAX_ITEMS);
}

List_3358::value_type List_3358::getCurrent ( ) const {
    
    if(!atEOL())
        return values[cursor];         
}
/*private:
      
      value_type values[MAX_ITEMS];
      size_type next[MAX_ITEMS];
      size_type previous[MAX_ITEMS];
      
      size_type currentSize;
      size_type head;
      size_type tail;
      size_type cursor;*/

        /*
         * if (!atEOL() && !isEmpty())
    {
        for (int i = cursor; i < currentSize - 1; i++)
            values[i] = values[i+1];

        currentSize--;
   }
        }*/