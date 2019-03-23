#pragma once

#include <iostream>
using namespace std;
# include <vector>
#include "Student.h"

class Student;
class Person;

class Course
{
private:
	// Private data members will not allowed to be used anywhere other than class.
	string courseName;
	int creditHours;
	vector<Student> courseStudents;

public:

	void addStudent(Student s);
	Course();    	// Default.
	Course(string cn, int credit);   // With parameters. Fully qualified.
	Course(const Course& other);    	// copy constructor..
	//	Course(Course&& other);   	// move constructor..
	~Course();   // destructor:
	string getCourseName();
	int getCreditHours();
};
