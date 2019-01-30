#include <iostream>
#include <new>

using namespace std;

#ifndef VECTORADT_H
#define VECTORADT_H

class VectorADT {
private:
	double * array;
	int size;    //the number of doubles stored in array
	int capacity;  //the maximum number of doubles that can be stored in array

public:
	//Destructor
	~VectorADT();
	//Default Constructor
	VectorADT();
	//Constructor
	VectorADT(int size, int capacity);
	//Copy Constructor
	VectorADT(const VectorADT& clone);

	//MemberFunctions
	void push_back(double val);
	void resize(int newSize);
	void pop_back();

	double operator[](int i);
	VectorADT& operator+ (const VectorADT& rhs) const;
	friend std::ostream& operator<< (std::ostream& outStr, VectorADT& vector);

	int length() const;
	int curr_capacity() const;


	VectorADT& operator= (const VectorADT& rhs);
};

#endif // !VECTORADT_H
