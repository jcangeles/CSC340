//File: linkedList.h

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


 //Q1. Add a function prototype here that overloads the << operator for this List class.
 //This operator, when invoked, will print the data member of each node on the list in
 //the same order as they appear on the list. Make sure you pass a List object to this
 //function by reference.
friend ostream& operator<<(ostream& os,const List &list);

//Q2. Add the function prototype here that overloads the assignment operator (=).
ListADT& operator=(const ListADT &rhs);

//Q3. Add a read-only member function with the name isEmpty to verify whether a list
//is empty or not?
bool isEmpty() const;

//Q4. Add a read-only member function with the name getLength to return the total
//number of nodes on a List object.
int getLength() const;


   //insert a new node to the front of the list. The data member of this new node is newItem.

    void insert_front(const int newItem);

   //remove the last node from the List
   void remove_last();

}; // end List
