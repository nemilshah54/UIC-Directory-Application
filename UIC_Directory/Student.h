#pragma once

#include <iostream>
using namespace std;
#include <vector>
#include "Person.h"
#include "Course.h"


class Course;
class Person;

class Student : public Person
{
private:
	// Private data members will not allowed to be used anywhere other than class.
	vector<Course> allcourses;
	vector<Course> currentcourses;
public:

	Student();   //Default
	Student(string fn, string ln);   //Parametized
	Student(const Student& other);   // Copy
//	Student(Student&& other);   // move
	~Student();
	void addCourse(Course course);  // Keep track of all the courses taken.									
	void endSemester();
	void displayall();
	void displayCurrent();
	void payTuition( double priceperhour);
	double getBalance();

};
