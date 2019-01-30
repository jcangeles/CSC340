#include "Person.h"
using namespace std;
//destructor
Person::~Person(){
	if(placesVisited != nullptr){
		delete[] placesVisited;
		placesVisited = nullptr;
	}
}

//default constructor
Person::Person(){
	SSN = 0;
	name = "na";
	personalEmail = "personal@";
	cntPlaces = 10;
	//try-catch to initialize array
	try{
		placesVisited = new string[cntPlaces];
	} catch (const bad_alloc& e){
		cerr << "Bad memory allocation";
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < cntPlaces; i++) {
		placesVisited[i] = "unknown";
	}
}

//assignment operator
Person& Person::operator=(const Person& rhs ){
	//check if this is already rhs
	if(this == &rhs) return *this;
	//check if placesVisited array is occupied, if so delete
	if(this->placesVisited != nullptr)	delete[] this->placesVisited;
	
	this->SSN 	= rhs.SSN;
	this->name 	= rhs.name;
	this->personalEmail = rhs.personalEmail;
	this->cntPlaces = rhs.cntPlaces;
	
	//try-catch to initialize array
	try{
		this->placesVisited = new string[this->cntPlaces];
	} catch (const bad_alloc& e){
		cerr << "Bad memory allocation";
		exit(EXIT_FAILURE);
	}
	
	//transfer over array elements to new array
	for (int i=0; i< this->cntPlaces; i++){
		this->placesVisited[i] = rhs.placesVisited[i];	
	}
	
	return *this;
}

//cloning thingy
Person::Person( const Person &clone ){
	this->SSN 	= clone.SSN;
	this->name 	= clone.name;
	this->personalEmail = clone.personalEmail;
	this->cntPlaces = clone.cntPlaces;	
	//copy/paste from default constructor with some minor changes
	try{
		placesVisited = new string[this->cntPlaces];
	} catch (const bad_alloc& e){
		cerr << "Bad memory allocation";
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < this->cntPlaces; i++) {
		placesVisited[i] = clone.placesVisited[i];
	}
}

//return the i-th place in the placesVisited array if i is valid; otherwise return "out-of-boundary".
string Person::getPlace(int i) const{
	return this->placesVisited[i];
}

//return personalEmail
string Person::getEmail() const{
	return personalEmail;
}

//new_email-->personalEmail
void Person::setEmail( string new_email){
	this->personalEmail = new_email;
}

//return "Person"
string Person::getTypeOfObj() const{
	return "Person";
}
