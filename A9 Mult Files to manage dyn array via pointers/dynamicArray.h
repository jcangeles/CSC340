#include <iostream>
#include <cstdlib>
#include <new>
#include <algorithm>
#include <vector>
#include <ctime>



#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


int * array_constructor(int *  &intPtr, int &size);
int * array_resize(int * &intPtr, int& currSize, int& newSize);
void array_destructor(int * &intPtr);
void array_set(int* &intPtr, int &size);
void mysort(int* &intPtr, int size, bool(*comp)(int&, int&));
//return true if x<=y, false otherwise.
bool my_less_equal(int& x, int & y);
//return true if x>=y, false otherwise.
bool my_greater_equal(int& x, int & y);


#endif // !dynamicArray.h
