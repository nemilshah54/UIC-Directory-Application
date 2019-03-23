
#include <iostream>
#include <algorithm>
#include <cstring>
#include "Person.h"
#include "Course.h"
#include "Student.h"
#include "Teacher.h"
#include "Employee.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

int Person::count;
string  Person::className;

void instructions()
{
	cout << "On -1, end the loop" << endl
		<< "On 0, Display this menu again." << endl
		<< "On 1, create a new student." << endl
		<< "On 2, create a new employee." << endl
		<< "On 3, create a new teacher." << endl
		<< "On 4, create a new course." << endl
		<< "On 5, enroll a student in a course." << endl
		<< "On 6, assign a teacher to a course." << endl
		<< "On 7, output the total number of people in the database, followed by their names, one per line, in alphabetical order by last name. " << endl
		<< "On 8, output the names of each of the courses, in alphabetical order." << endl
		<< "On 9, charge tuition for all students." << endl
		<< "On 10, pay salary to all employees." << endl
		<< "On 11, end the semester for all students and teachers." << endl
		<< "On 12, output the balance for a person." << endl << endl; cout << "On -1, end the loop" << endl;
}

int main()
{
	map < string, string> people;   // map contain. of person 
	map < string, Course>  courses;
	map < string, Student>  students;  //  map container for all students
	map < string, Teacher>  teachers;  //  map container for all teachers
	map < string, Employee> employees;  //  map container for all employees.

	// Initializing static scope variables.
	Person::count = 0;
	Person::className = "Person";

	cout << Person::total_Population() << endl;  // 1

	courses.emplace("CS 100", *new Course("CS 100", 1));  // 2
	courses.emplace("CS 474", *new Course("CS 474", 3));  // 3
	students.emplace( "Allison Doe",  *new Student("Allison", "Doe"));  // 4
	students.at("Allison Doe").addCourse( courses.at("CS 100"));  // 5
	people.emplace( "Doe" ,"Allison");   

	teachers.emplace("Jennifer Lawrence", *new Teacher("Jennifer", " Lawrence", 20000));  // 6
	people.emplace( "Lawrence", "Jennifer"); 
	teachers.at("Jennifer Lawrence").addCourse(courses.at("CS 474"));  // 7

	// Out total people.
	cout << Person::total_Population() << endl;  // 8

	for (auto &iter : students)  // 9
	{
		iter.second.payTuition(10000);
	}

	for (auto &iter : teachers)  // 10
	{
		iter.second.paySalary();
	}

	for (auto &iter : students)  // 11
	{
		iter.second.endSemester();
	}

	for (auto &iter : teachers)  // 11
	{
		iter.second.endSemester();
	}  

	// End Semeter-----------------------------------------------------------------------------------------------------

	// Begin a loop   
	int userInteraction = 0; int creditHours;	double salary = 0.0; int tuition = 0;
	string firstName; string lastName; string courseName;  string studentName; string teacherName;
	string fullName;

	while (userInteraction != -1)  // 12
	{

		cout << "What operation would like to perform (0 for help)?" << endl;
		cin >> userInteraction;

		if (userInteraction == -1)
			break;

		switch (userInteraction)
		{

		case 0:
		{
			instructions();
			break;
		}
		case 1:
		{
			
			cout << "What is student's first name?" << endl;
			cin >> firstName;
			cout << "What is student's last name?" << endl;
			cin >> lastName;

			fullName = firstName + " " + lastName;
			students.emplace( fullName, *new Student(firstName, lastName));
			people.emplace( lastName, firstName);
			break;
		}

		case 2:
		{
			cout << "What is employee's first name?" << endl;
			cin >> firstName;
			cout << "What is employee's last name?" << endl;
			cin >> lastName;
			cout << "What is employee's salary?" << endl;
			cin >> salary;

			fullName = firstName + " " + lastName;
			people.emplace(lastName, firstName);
			employees.emplace(fullName, *new Employee(firstName, lastName, salary));
			break;
		}
		case 3:
		{
			string firstNamee; string lastNamee;
			cout << "What is teacher's first name?" << endl;
			cin >> firstNamee;
			cout << "What is teacher's last name?" << endl;
			cin >> lastNamee;
			cout << "What is teacher's salary?" << endl;
			cin >> salary;

			fullName = firstNamee + " " + lastNamee;
			people.emplace(lastName, firstName);
			teachers.emplace(fullName, *new Teacher(firstNamee, lastNamee, salary));
			break;
		}


		case 4:
		{
			cout << "What is course's name?" << endl;
			cin.ignore();  	getline(cin, courseName);
			cout << "How many number of credit hours?" << endl;
			cin >> creditHours;

			courses.emplace(courseName, *new Course(courseName, creditHours));
			break;
		}
		case 5:
		{	
			cout << "Which student is enrolling in? " << endl;
			cin.ignore();    	getline(cin, studentName);
			cout << "What course are they enrolling in?" << endl;
			getline(cin, courseName);
			students.at(studentName).addCourse(courses.at(courseName));
			break;
		}
		case 6:
		{
			cout << "What is teacher's name?" << endl;
			cin.ignore();    	getline(cin, teacherName);
			cout << "What is the name of the course?" << endl;
			getline(cin, courseName);

			// Assign a course to the teacher.
			teachers.at(teacherName).addCourse(courses.at(courseName));
			break;

		}
		case 7:
		{
			cout << Person::total_Population() << endl;

			for (auto &x : people)
			{
				// Sorted.
				cout << x.second << " " << x.first << endl;
			}
			break;
		}
		case 8:
		{
			// Output all courses.
			for (auto &x : courses)
			{
				// Sorted.
				cout << x.second.getCourseName() << endl;
			}
			break;
		}
		case 9:
		{
			cout << "How much is tuition?" << endl;
			cin >> tuition;
			for (auto &x : students)
			{
				// Sorted.		
				x.second.payTuition(tuition);
			}
			break;
		}
		case 10:
		{
			// Pay salary to all employees.
			for (auto &x : teachers)
			{
				// Sorted.
				x.second.paySalary();
			}

			break;

		}
		case 11:
		{
			// End semester for all students and teachers.
			for (auto &x : students)
			{
				// Sorted.
				x.second.endSemester();
			}

			for (auto &x : teachers)
			{
				// Sorted.
				x.second.endSemester();
			}

			break;

		}
		case 12:
		{

			cout << "Whose balance would you like to check?" << endl;
			cin.ignore();    	getline(cin, studentName);

			for (auto &x : students)
			{
				if (x.first == studentName)
				{
					cout << students.at(studentName).getBalance() << endl;
					break;
				}
			}

			for (auto &x : teachers)
			{
				if (x.first == studentName)
				{
					cout <<  teachers.at(studentName).getBalance() << endl;
					break;
				}
			}
			break;
		}
		default:
		{
			cout << "Sorry the operation you entered is invalid" << endl;
		}
		}
	}
	cout << "Goodbye" << endl;	
//	system("pause");
	return 0;
}
