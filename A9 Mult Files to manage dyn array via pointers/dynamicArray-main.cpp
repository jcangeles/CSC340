#include "dynamicArray.h"

using namespace std;

int main()
{
	int* testPtr = nullptr;
	int* test2Ptr = nullptr;
	int size = 17;
	int newSize = 0;

	array_constructor(testPtr, size);
	for (int i = 0; i < size; i++) {
		cout << "myArray["<<i <<"]="<< testPtr[i] << endl;
	}

	test2Ptr = array_resize(testPtr,size,newSize);
	for (int i = 0; i < newSize; i++) {
		cout << "myArray2["<<i <<"]="<< testPtr[i] << endl;
	}

	testPtr = array_resize(testPtr,size,newSize);
	for (int i = 0; i < newSize; i++) {
		cout << "myArray["<<i <<"]="<< testPtr[i] << endl;
	}

	return 0;
}
