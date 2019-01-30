#ifndef ListADT_h
#define ListADT_h

#include <iostream>
#include <new>

using namespace std;

class ListADT {
private:
	class Node {
	public:
		Node() :value(0), next(nullptr) {};
		Node(int newVal) :value(newVal), next(nullptr) {};
		int value;
		Node *next;
	};
	Node  * head;
	int   size;
public:


	friend std::ostream& operator<< (std::ostream& outStr, ListADT& list);

	//CONSTRUCTORS
	~ListADT();	//destructor
	ListADT(); //nullptr->head, 0->size
	ListADT(const ListADT& clone);

	ListADT& operator=(const ListADT& rhs);

	//MEMBERFUNCTIONS
	void push_front(int newVal); //add newVal to the front of a list
	void push_back(int newVal);  //add newVal to the back of a list
	void pop_front();
	void pop_back();
	int operator[](int i);
	int length() const;

};
#endif /* ListADT_hpp */
