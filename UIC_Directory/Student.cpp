
#include <iostream>
#include <vector>
#include "Course.h"
#include "Student.h"
#include <string>
using namespace std;


// Default
Student::Student()
{
	 allcourses.clear();
	 currentcourses.clear();
}

//Parametized.
Student::Student(string fn, string ln) : Person(fn, ln)
{
	//balance = 0.0;
	//cout << "Balance in child stud " << balance << endl;
}

// copy constructor: make a copy of "other" into this vector. Deep copy.
Student::Student(const Student & r): Person (r)
{ this->allcourses = r.allcourses;  this->currentcourses = r.currentcourses; }   


/* Move constructor.
Student::Student( Student&& r)
	: Person(r)
{
	this->allcourses = r.allcourses;  this->currentcourses = r.currentcourses;
}  */

// Destructor....
Student:: ~ Student()
{
	//cout << " enter destructor enter" << endl;
	// ~Person();
	 count--;
}     


void Student::payTuition(double priceperhour)
{
	
	int total_hours = 0;
	for (auto &x : currentcourses)
	{
		total_hours = total_hours + x.getCreditHours();
	}
	balance = balance - total_hours * priceperhour;
}

void Student::addCourse(Course c)
{
	currentcourses.push_back(c);
}

void Student::endSemester()
{
	allcourses.insert(allcourses.end(), currentcourses.begin(), currentcourses.end());
	currentcourses.clear();
}

void Student::displayall()
{
	int hours = 0;
	cout << "Courses are ";
	for (auto & iter : allcourses)
	{
		cout << iter.getCourseName() << " ";
		hours = hours + iter.getCreditHours();
	}
	cout << endl;

	cout << "Total credits hours for" << this->getFullName() << "in the UIC are " << hours << endl;
}

void Student::displayCurrent()
{
	int hours = 0;
	cout << "Courses are ";
	for (auto & iter : currentcourses)
	{
		cout << iter.getCourseName() << " ";
		hours = hours + iter.getCreditHours();
	
	}
	cout << endl;

	cout << "Total credits hours for" << this->getFullName() << "in this semester are " << hours << endl;
}

double Student::getBalance()
{
	return balance;
}















