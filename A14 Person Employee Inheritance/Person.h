#ifndef Person_h
#define Person_h

#include <iostream>
#include <string>
#include <new>
#include <cstddef>

using namespace std;

class Person{
public:
    //******************Note*********
    //This interface is by no means complete.  Please feel free to
    // add more functions if needed. The test cases however will only
    // test the following functions.

    virtual ~Person();
    Person(); //0->SSN, "na"->name, "personal@"->personalEmail, 10->cntPlaces, allocate space to placesVisited and initializes each place to "unknown"
    Person& operator=(const Person& rhs );
    //copy constructor
    Person( const Person &clone );

    string getPlace(int i) const; //return the i-th place in the placesVisited array if i is valid; otherwise return "out-of-boundary".

    virtual string getEmail() const; //return personalEmail
    virtual void setEmail( string new_email); //new_email-->personalEmail
    virtual string getTypeOfObj() const; //return "Person"


private:
    int SSN;
    string name;
    string personalEmail;

    string *placesVisited;
    int cntPlaces; //companion variable of the above pointer
};


#endif /* Person_h */
