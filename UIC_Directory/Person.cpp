
#include <iostream>
#include "Person.h"
#include <string>
using namespace std;



// Getter function
int Person::getUIN() { return uiN; }
double Person::getBalance() { return uiN; }
string Person::getFullName()
{
	string full_name;

	full_name = firstName + lastName;
	cout << "Full name is  " + full_name << endl;
	return full_name;
}

// Default
Person::Person()
{
	uiN = 0;
	balance = 0.0;
	firstName = "Elbert";
	lastName = "Einstein";
	count++;
}

// Paramtized.
Person::Person(string fn, string ln, int myUIN) : firstName(fn), lastName(ln), uiN(myUIN)
{
	balance = 0.0;
	count++;
}

// Paramtized.
Person::Person(std::string fn, std::string ln) : firstName(fn), lastName(ln)
{
	
	balance = 0.0;
	//cout << "Balance in parent stud " << balance << endl;
	count++;
}

// copy constructor: make a copy of "other" into this vector. Deep copy.
Person::Person(const Person & r)
{
	//count++;
	this->firstName = r.firstName;
	this->lastName = r.lastName;
	this->balance = r.balance;
}


// Move constructor.
/*Person::Person(Person&& other)
	: firstName(std::move(other.firstName)), lastName(std::move(other.lastName)),uiN(std::move(other.uiN))
{}   */


// Destructor....
Person:: ~Person()
{
	//cout << " enter destructor enter" << endl;
	count--;
}     

void Person::sayName() { cout << firstName << " " << lastName << endl; }
int Person::total_Population() { return  count; }
void Person::newClassName(string newName) { className = newName; }











