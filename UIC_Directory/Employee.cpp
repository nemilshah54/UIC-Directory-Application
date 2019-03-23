

#include <iostream>
#include <vector>
#include "Employee.h"
#include <string>
using namespace std;

// Default.
Employee::Employee()
{

}

 // Parmatezied.
Employee::Employee(string fn, string ln, double salaryy) : Person(fn, ln)
{
	salary = salaryy;
}

// copy constructor: make a copy of "other" into this vector. Deep copy.
Employee::Employee(const Employee & r) : Person ( r)
{
	//count++;
	this->salary = r.salary;
	//this->lastName = r.lastName;
}


void Employee::paySalary()
{
	balance = balance + salary;
}















