//File: linkedList.cpp
//NOT FULL IMPLEMENTATION FILE, ONLY ANSWER TO QUESTIONS AS ASKED DURING EXAM

// Q1.  Implement  the default constructor using an initialization segment.  (2 points)
List::List() :head(nullptr)
{
  //i did not set a size(0) like, because there is no private variable size
}
// Q2.  Implement the IsEmpty( ) function you have declared earlier.   (2 points)
bool List::isEmpty() const
{
    return (head == nullptr);
}
// Q3.  Implement the getLength() function you have declared earlier.   (5 points)
int List::getLength() const
{
  int length = 0;
   Node *curr=head;
   while (curr != nullptr){
      length++;
       curr = curr->next;
   }
   return length;
}


// Q4.  Implement the void insert_front(int newItem); with exception handling.  (3 points)
void insert_front(int newItem){
  Node *newNode
  try{
     newNode = new Node(newItem);
  }	catch (bad_alloc& ba) {
		cerr << "bad_alloc caught: " << ba.what() << '\n';
  }
  newNode->next = head;
  head = newNode;
}





#include <iostream>

using namespace std;

class List{



private:
  class Node{ 
   public:
         int item;       // A data item on the list.        
         Node *next; // Pointer to the next node.
         Node():item(0),next(nullptr){ };
         Node(int  val):item(val),next(nullptr) { };
  }; // end Node

   Node *head;// Pointer to linked list of items.
public:
   List();                  // Default constructor:  nullptr-->head
   List(const List& aList);// Copy constructor
   ~List();                // Destructor.


 //Q1. Add a function prototype here that overloads the << operator for this List class. This operator, when invoked, will print the data member of each node on the list in the same order as they appear on the list. Make sure you pass a List object to this function by reference.

//Q2. Add the function prototype here that overloads the assignment operator (=).

//Q3. Add a read-only member function with the name isEmpty to verify whether a list is empty or not?

//Q4. Add a read-only member function with the name getLength to return the total number of nodes on a List object.

   //insert a new node to the front of the list. The data member of this new node is newItem.

    void insert_front(int newItem);

   //remove the last node from the List
   void remove_last();

}; // end List
