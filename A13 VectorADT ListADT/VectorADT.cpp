#include "VectorADT.h"

VectorADT::~VectorADT()
{
	if (array != nullptr) {
		delete[] array;
		array = nullptr;
	}
}

VectorADT::VectorADT()
{
	size = 0;
	capacity = 10;
	try {
		array = new double[capacity];
	}
	catch (const bad_alloc& e) {
		cerr << "Bad memory allocation";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < capacity; i++) {
		array[i] = 0.0;
	}
}

VectorADT::VectorADT(int size, int capacity)
{
	this->size = size;
	this->capacity = capacity;
	try {
		array = new double[capacity];
	}
	catch (const bad_alloc& e) {
		cerr << "Bad memory allocation";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < this->size; i++) {
		array[i] = 0.0;
	}
}

VectorADT::VectorADT(const VectorADT & clone)
{
	this->size = clone.size;
	this->capacity = clone.capacity;
	try {
		array = new double[capacity];
	}
	catch (const bad_alloc& e) {
		cerr << "Bad memory allocation";
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < capacity; i++) {
		this->array[i] = clone.array[i];
	}
}

void VectorADT::push_back(double val)
{
	size++;
	if (size > capacity) this->resize(size);
	array[size - 1] = val;
}

void VectorADT::resize(int newSize)
{
	double *temp;

	if (newSize > capacity) capacity = newSize * 2;

	try {
		temp = new double[capacity];
	} catch (const bad_alloc& e) {
		cerr << "Bad memory allocation";
		//exit(EXIT_FAILURE);
	}

	if (newSize < size) {
		for (int i = 0; i < newSize; i++) {
			temp[i] = array[i];
		}
	} else {
		for (int i = 0; i < size; i++) {
			temp[i] = array[i];
		}
	}

	size = newSize;
	delete[] array;
	array = temp;

}

void VectorADT::pop_back()
{
	size -= 1;
	array[size] = 0.0;
}

double VectorADT::operator[](int i)
{
	return array[i];
}

VectorADT& VectorADT::operator+ (const VectorADT& rhs) const
{
	VectorADT newVec;
	for (int i = 0; i < rhs.size; i++) {
		double value = this->array[i] + rhs.array[i];
		newVec.push_back(value);
	}
	return newVec;
}

std::ostream & operator<<(std::ostream & outStr, VectorADT & vector)
{
	outStr << vector[0];
	for (int i = 1; i < vector.length(); i++) {
		outStr << ", " << vector[i];
	}
	return outStr;
}

int VectorADT::length() const
{
	return size;
}

int VectorADT::curr_capacity() const
{
	return capacity;
}




VectorADT& VectorADT::operator= (const VectorADT& rhs) {
	if (this == &rhs) return *this;

	size = rhs.size;
	capacity = rhs.capacity;

	if (this->array != nullptr) this->~VectorADT();

	try {
		array = new double[capacity];
	} catch (const bad_alloc& e) {
			cerr << "Bad memory allocation";
			exit(EXIT_FAILURE);
	}

	for (int i = 0; i < capacity; i++) {
		array[i] = rhs.array[i];
	}

	return *this;
}
