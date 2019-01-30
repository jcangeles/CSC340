#include <iostream>
#include "Person.h"
#include "Employee.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Person p;
	Employee e;
	
	p.setEmail("test@gmail.com");
	cout << p.getTypeOfObj() << " test's email is '"<<p.getEmail() << endl;
	
	return 0;
}
