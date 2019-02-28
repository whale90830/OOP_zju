#include"Graduation.h"
#include<iostream>

Graduation::Graduation()
{
}

Graduation::Graduation(string name, int num_of_courses, int credit_hours)
{
	setName(name);
	setNumOfCoures(num_of_courses);
	setCreditHours(credit_hours);
}

int getThesisCredit()
{
	return '4';
}

int Graduation::DegreeRequirement()
{
	return getNumOfCourses() * getCreditHours() + thesis_credit;
}

void Graduation::Input()
{
	string name;
	int num_of_courses;
	int credit_hours;
	
	cout << "Enter Discipline's name: ";
	cin >> name;
	setName(name);
	
	cout << "Enter number of courses: ";
	cin >> num_of_courses;
	setNumOfCoures(num_of_courses);
	
	cout << "Enter credit hours per course: ";
	cin >> credit_hours;
	setCreditHours(credit_hours);
}

void Graduation::Display()
{
	cout << endl;
	cout << "Degree: " << getName() << endl;
	cout << "Number of required courses: " << getNumOfCourses() << endl;
	cout << "Number of credit hours: " << getCreditHours() << endl;
	cout << "Thesis credit: " << '4' << endl;
	cout << "Total number of required credit hours for graduation degree: " << DegreeRequirement() << endl;
	cout << endl;
}
