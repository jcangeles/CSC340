#include <iostream>
#include <new>


#include "dynamicArray.h"
using namespace std;

int * array_constructor(int *  &intPtr, int &size) {
	try {
		if (size > 0) {
			array_destructor(intPtr);
			intPtr = new int[size];

			for (int i = 0; i < size; ++i) {
				intPtr[i] = i*i;
			}
		}
		else{
			intPtr = nullptr;
		}
	}
	catch (bad_alloc& ba) {
		cerr << "bad_alloc caught: " << ba.what() << '\n';
	}
	return intPtr;//placeholder
}
int * array_resize(int * &intPtr, int& currSize, int& newSize) {
	int* tmpPtr;
	if(currSize>0 && newSize>0){
		tmpPtr = new int[newSize];
		if (currSize < newSize) {
			for (int i = 0; i < currSize; ++i) {
				tmpPtr[i] = intPtr[i];
			}
			for (int i = currSize; i < newSize; ++i) {
				tmpPtr[i] = i*i;
			}
		}
		else if(currSize > newSize){
			for (int i = 0; i < newSize; ++i) {
				tmpPtr[i] = intPtr[i];
			}
		}
		else {
			tmpPtr = intPtr;
		}
	} else{
		return intPtr;
	}
	delete[] intPtr;
	intPtr = tmpPtr;

	return intPtr;
}
void array_destructor(int * &intPtr) {
	if (intPtr != nullptr) {
		delete[] intPtr;
		intPtr = nullptr;
	}
}
void array_set(int* &intPtr, int &size) {
	srand(time(0));
	for (int i = 0; i < size; ++i) {
		intPtr[i] = rand()%100000000;
	}
}
void mysort(int* &intPtr, int size, bool(*comp)(int&, int&)) {
	unsigned int i, j;
	int temp;
	for (i = 1; i < size; i++) {
		j = i;
		while (j > 0 && comp(intPtr[j],intPtr[j-1])) {
			temp = intPtr[j];
			intPtr[j] = intPtr[j - 1];
			intPtr[j - 1] = temp;
			j--;
		}
	}
}
bool my_less_equal(int& x, int & y) {
	return x <= y;
}//return true if x<=y, false otherwise.
bool my_greater_equal(int& x, int & y) {
	return x >= y;
}//return true if x>=y, false otherwise.
