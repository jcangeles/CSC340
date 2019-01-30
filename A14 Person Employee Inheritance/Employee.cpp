#include "Employee.h"

using namespace std;

//destructor
Employee::~Employee(){
	if(sal_change_rates != nullptr){
		delete[] sal_change_rates;
		sal_change_rates = nullptr;
	}
}

//constructor
//0.0->salary, 10->cnt_sal_changes, "work@"->work_email, sal_change_rates: 
//allocate memory to hold 10 doubles, each of which has an initial value of 0.0
Employee::Employee(){
	//constructor for upper class Person
	Person();
	salary = 0.0;
	cnt_sal_changes = 10;
	work_email = "work@";
	
	//try-catch to initialize array
	try{
		sal_change_rates = new double[cnt_sal_changes];
	} catch (const bad_alloc& e) {
		cerr << "Bad memory allocation";
		exit(EXIT_FAILURE);
	}
	
	//initialize values to 0.0
	for (int i = 0; i < cnt_sal_changes; i++) {
		sal_change_rates[i] = 0.0;
	}
}

//another clone thingy
Employee::Employee( const Employee& clone) : Person(clone){
	this->salary = clone.salary;
	this->cnt_sal_changes = clone.cnt_sal_changes;
	this->work_email = clone.work_email;
	
	try {
		sal_change_rates = new double[this->cnt_sal_changes];
	} catch (const bad_alloc& e) {
		cerr << "Bad memory allocation";
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < this->cnt_sal_changes; i++) {
		sal_change_rates[i] = clone.sal_change_rates[i];
	}
}

//assignment operator
Employee Employee::operator=(const Employee& rhs ){
	Person::operator=(rhs);

	if (this == &rhs) return *this;

	if (this->sal_change_rates != nullptr) {
		delete[] this->sal_change_rates;
		sal_change_rates = nullptr;
	}

	this->salary = rhs.salary;
	this->cnt_sal_changes = rhs.cnt_sal_changes;
	this->work_email = rhs.work_email;
	try {
		this->sal_change_rates = new double[this->cnt_sal_changes];
	} catch (const bad_alloc& e) {
		cerr << "Bad memory allocation";
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < this->cnt_sal_changes; i++) {
		this->sal_change_rates[i] = rhs.sal_change_rates[i];
	}

	return *this;
}

//return the i-th rate in the sal_change_rates array if i is valid; otherwise return -1.00
double Employee::getChangeRate( int i) const{
	return sal_change_rates[i];
}

//return work_email
string Employee::getEmail() const{
	return this->work_email;
}

//new_email-->work_email
void Employee::setEmail( string new_email){
	this->work_email = new_email;
}

//return "Employee"
string Employee::getTypeOfObj() const{
	return "Employee";
}



void mixedArray( Person** &arrayPersonEmp, int numPersons, int numEmployees){
	int arrSize = numPersons + numEmployees;
	try {
		arrayPersonEmp = new Person*[arrSize];
	} catch (const bad_alloc& e) {
		cerr << "Bad memory allocation";
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < numPersons; i++) {
		arrayPersonEmp[i] = new Person();
		arrayPersonEmp[i]->setEmail("personal@gmail.com");
	}

	for (int i = numPersons; i < arrSize; i++) {
		arrayPersonEmp[i] = new Employee();
		arrayPersonEmp[i]->setEmail("work@gmail.com");
	}
}

void deleteMixedArray(Person** &arrayPersonEmp, int size ){
	if (arrayPersonEmp != nullptr) {
		//first set every element to nullptr;
		for (int i = 0; i < size; i++) {
			delete arrayPersonEmp[i];
			arrayPersonEmp[i] = nullptr;
		}
		//delete array
		delete[] arrayPersonEmp;
		arrayPersonEmp = nullptr;
	}
}
