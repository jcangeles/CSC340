#include "ListADT.h"

//destructor
ListADT::~ListADT()
{
	Node *toDelete = head;
	while (toDelete != nullptr) {
		head = toDelete->next;
		delete toDelete;
		toDelete = head;
	}
	size = 0;
}

//default constructor
ListADT::ListADT() :head(nullptr), size(0)
{

}

//copy constructor
ListADT::ListADT(const ListADT &clone) {
	head   = new Node(clone.head->value);
	size = clone.length();
	Node *oldCurr = clone.head->next;
	Node *newCurr = head;
	while (oldCurr != nullptr) {
		newCurr->next = new Node(oldCurr->value);
		oldCurr = oldCurr->next;
		newCurr = newCurr->next;
	}
}

//overloaded assignment operator
ListADT& ListADT::operator=(const ListADT &rhs) {
	//if list is populate it, DESTROY IT!!!
	if (head != nullptr) this->~ListADT();
	this->size = rhs.size;

	this->head = new Node(rhs.head->value);
	Node *itr = rhs.head->next;
	while (itr != nullptr) {
		this->push_back(itr->value);
		itr = itr->next;
	}

	return *this;
}



void ListADT::push_front(int newVal)
{
	Node *newNode = new Node(newVal);
	newNode->next = head;
	head = newNode;
	size += 1;
}

void ListADT::push_back(int newVal)
{
	Node* newNode = new Node(newVal);
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
	size++;
}

void ListADT::pop_front()
{
	if (head != nullptr) {
		Node *temp = head->next;
		delete head;
		head = temp;
		size -= 1;

	}
}


void ListADT::pop_back()
{
	if (head != nullptr) {
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
		}
		else {
			Node* curr = head->next;
			Node* prev = head;
			while (curr->next != nullptr) {
				prev = curr;
				curr = curr->next;
			}
			delete curr;
			prev->next = nullptr;
		}
		size -=1;
	}
}

int ListADT::operator[](int i)
{
	int cnt = 0;
	Node *curr = head;
	while ((cnt < i) && (cnt < size)) {
		curr = curr->next;
		cnt++;
	}
	return curr->value;

}

ostream& operator<< (ostream& outStr, ListADT& list)
{
	outStr << list[0];
	for (int i = 1; i < list.length(); i++) {
		outStr << ", " << list[i];
	}
	return outStr;
}

int ListADT::length() const {
	return size;
}
