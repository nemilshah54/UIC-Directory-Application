#pragma once

#include <iostream>
using namespace std;
#include <vector>
#include "Employee.h"
#include "Course.h"



class Teacher : public Employee
{
private:
	// Private data members will not allowed to be used anywhere other than class.
	vector < Course> coursesTaught;
	vector < Course> coursesTeaching;
public:
	 Teacher();   // Default.
	 Teacher(string fn, string ln, double salaryy);  	// With parameters. Fully qualified.
	 Teacher(const Teacher& other); // copy constructor..
//	 Teacher(Teacher&& other);       // move
	 void addCourse(Course course);  // Keep track of all the courses taken.
	 void endSemester();
	 double getBalance();
	 void displayCurrent();
	 void displayall();
	 void paySalary () override;  // Override function.
};
