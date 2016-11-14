/* test.cpp
 * Dennis Bruce
 * CS 3358
 * Prog8
 */


#include "BST_3358.h"
#include "queue_3358.h"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {

   BST_3358<int> myBST;
   cout << endl;
   myBST.insertItem(42);
   myBST.insertItem(12);
   myBST.insertItem(8);
   myBST.insertItem(15);

   cout << endl << "I have " << myBST.countNodes() << " nodes" << endl << endl;
   cout << "In Order Traversal:" << endl;
   myBST.inOrderTraversal();

   cout << endl << "Pre Order Traversal:" << endl;
   myBST.preOrderTraversal();


   cout << endl << "Post Order Traversal:" << endl;
   myBST.postOrderTraversal();
   
   cout << endl << "Delete 12" << endl;
   myBST.deleteItem(12);

   cout << "Make empty " << endl;
   myBST.makeEmpty();
   
   if (myBST.isEmpty())
      cout <<"it's empty"<< endl;
   else
      cout << "oops" << endl;
   
    if(!myBST.breadthFirstSearch(25))
    cout << endl << "inserting a collection of 25 ints into BST: " << endl;
    for(int i = 1; i < 26; i++) {
        myBST.insertItem(i*((i%5)+1));
    }
    cout << endl;
    //TESTING THE SEARCH FUNCTION
    //should find 25
    if(myBST.breadthFirstSearch(25))
        cout << "FOUND 25" << endl;
    else
        cout << "DIDN'T FIND 25" << endl;
   
    //shouldn't find 125
    if(myBST.breadthFirstSearch(125))
        cout << "FOUND 125" << endl;
    else
        cout << "DIDN'T FIND 125" << endl;
   
    return EXIT_SUCCESS;
}

