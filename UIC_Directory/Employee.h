#pragma once

#include <iostream>
using namespace std;
#include <vector>
#include "Person.h"
#include <string>

class Employee : public Person
{
protected:
	// Private data members will not allowed to be used anywhere other than class.
	double salary;

public:
	Employee();   // Default;
	Employee(const Employee& other); 	// copy constructor..
//	Employee( Employee&& other);       // move
	Employee(string fn, string ln, double salary);  	// Parametized construcotr.
	virtual void paySalary();  	// Virtual function.
};
