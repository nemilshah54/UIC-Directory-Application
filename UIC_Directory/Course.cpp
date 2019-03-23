

#include <iostream>
# include <vector>
#include "Course.h"
#include "Student.h"

#include <string>
using namespace std;

// Default
Course::Course()
{
	courseName = "CS111";
	creditHours = 3;
}

// Paramtized.
Course::Course(string cn, int credit) : courseName(cn), creditHours(credit) {}

// copy constructor: make a copy of "other" into this vector. Deep copy.
Course::Course(const Course & r) { this->courseName = r.courseName;  this->creditHours = r.creditHours; }

// move constructor.
//Course::Course( Course && r) { this->courseName = r.courseName;  this->creditHours = r.creditHours; }

// Destructor....
 Course:: ~Course() {}

// Getter function
string Course::getCourseName() { return courseName; }
int Course::getCreditHours() { return 	creditHours; }

void Course::addStudent(Student s)
{
	courseStudents.push_back(s);
}




















