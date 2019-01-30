#include "ListADT.h"
#include "VectorADT.h"


int main()
{
	ListADT testList1;
	testList1.push_back(1);
	testList1.push_back(2);
	testList1.push_back(3);
	testList1.push_front(0);
	testList1.length();


	ListADT testList2;
	testList2.push_back(0);
	testList2.push_back(1);
	testList2.push_back(2);
	testList2.push_front(3);

	VectorADT testVec1;
	testVec1.push_back(1.0);
	testVec1.push_back(2.0);
	testVec1.push_back(3.0);


	VectorADT testVec2;
	testVec2.push_back(1.0);
	testVec2.push_back(2.0);
	testVec2.push_back(3.0);
	testVec2.push_back(4.0);

	VectorADT add = testVec1 + testVec2;
	cout << add << endl;
	return 0;
}
