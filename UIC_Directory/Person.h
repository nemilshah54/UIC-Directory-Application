#pragma once

#include <iostream>
using namespace std;

# include <vector>


class Student;
class Course;

class Person
{
private:
	// Private data members will not allowed to be used anywhere other than class.
	string firstName;
	string lastName;
	int uiN;

protected:
	double balance;

public:

	enum status { Freshman, Sophomore, Junior, Senior };


	static int count;    // must be static as it is class scoped variable. 
	static string className;   // class scoped variable.

	// Getter function
	int getUIN();
	double getBalance();
	string getFullName();

	// Default.
	Person();

	// With parameters. Fully qualified.
	Person(string fn, string ln, int myUIN);
	Person(string fn, string ln);

	// copy constructor..
	Person(const Person& other);

	// move constructor..
	//Person(Person&& other);   

	// destructor:
	 virtual~ Person();    

	static int total_Population();             // Class scoped function so it is static. Called with class.
	void sayName();                             // Called with instance object.    
	static void newClassName(string newName);     // Class scoped function so it is static. Called with class.
};
