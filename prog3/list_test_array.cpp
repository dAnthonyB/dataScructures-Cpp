/* list_test.cpp
 * Dennis Bruce
 * CS 3358
 * Prog
 * Input:
 * Output:
 * Description:
 */
#include "list_3358_arrays.h"
//#include "list_3358_pointers.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace cs3358;//makes the first iteration of function use the array list
void printList(List_3358 list);


int main(int argc, char** argv) {
    
    
    List_3358 list1; //makes a list used for functions
   
    //inserts multiples of 5 into list
    for (int i = 1; i <= 10; i++) {
        list1.insert(i*5);
    }
 
    List_3358 list2(list1); //makes a copy of the original list
    
    //removes the head and items from the middle to test function.
    list1.reset(); 
    list1.remove(); //removes first element to test remove function
    list1.advance();
    list1.advance();
    list1.remove();//removes from middle of list
    
    
    //makes a list of two elements and removes the tail
    List_3358 list3;
    list3.insert(4);
    list3.insert(1);
    list3.reset();
    list3.advance();
    list3.remove();
    
    cout << "printing list1" << endl;
    printList(list1);
    cout << "printing list2" << endl;
    printList(list2);
    cout << "printing list3" << endl;
    printList(list3);
    
    return EXIT_SUCCESS;
}

void printList(List_3358 list) {
    if (!list.isEmpty()) {
        list.reset();

        while (!list.atEOL())
        {
           cout << list.getCurrent() << endl;
           list.advance();
        }
    }
}