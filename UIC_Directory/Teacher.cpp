
#include <iostream>
#include <vector>
#include "Course.h"
#include "Employee.h"
#include "Teacher.h"
#include <string>
using namespace std;

// Default
Teacher::Teacher()
{
	
}

// Parametized
Teacher::Teacher(string fn, string ln, double salaryy) : Employee(fn, ln, salaryy) 
{

}

// copy constructor: make a copy of "other" into this vector. Deep copy.
Teacher::Teacher(const Teacher & r) : Employee (r)
{
	//balance = 0.0;
	//count++;
	this->coursesTaught = r.coursesTaught;
	this->coursesTeaching = r.coursesTeaching;
}


void Teacher::addCourse(Course course)
{	
	coursesTeaching.push_back(course);
}

void Teacher::endSemester()
{
	// Transfer currently taught course to the history.
	coursesTaught.insert(coursesTaught.end(), coursesTeaching.begin(), coursesTeaching.end());
	coursesTeaching.clear();
}


void Teacher::paySalary()
{
	balance = balance + coursesTeaching.size() *salary;
}


double Teacher::getBalance()
{
	return balance;
}

void Teacher::displayall()
{
	int hours = 0;
	cout << "Courses are ";
	for (auto & iter : coursesTaught)
	{
		cout << iter.getCourseName() << " ";
		hours = hours + iter.getCreditHours();
	}
	cout << endl;
	cout << "Total credits hours for" << this->getFullName() << "in the UIC are " << hours << endl;
}

void Teacher::displayCurrent()
{
	int hours = 0;
	cout << "Courses are ";
	for (auto & iter : coursesTeaching )
	{
		cout << iter.getCourseName() << " ";
		hours = hours + iter.getCreditHours();

	}
	cout << endl;
	cout << "Total credits hours for" << this->getFullName() << "in this semester are " << hours << endl;
}














