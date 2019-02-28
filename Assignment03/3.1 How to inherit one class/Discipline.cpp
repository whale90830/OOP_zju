#include"Discipline.h"
#include<iostream>

Discipline::Discipline()
{
}
Discipline::Discipline(string name, int num_of_courses, int credit_hours)
{
	this->name = name;
	this->num_of_courses = num_of_courses;
	this->credit_hours = credit_hours;
}

string Discipline::getName()
{
	return name;
}
void Discipline::setName(string name)
{
	this->name = name;
}
int Discipline::getNumOfCourses()
{
	return num_of_courses;
}
void Discipline::setNumOfCoures(int num_of_courses)
{
	this->num_of_courses = num_of_courses;
}
int Discipline::getCreditHours()
{
	return credit_hours;
}
void Discipline::setCreditHours(int credit_hours)
{
	this->credit_hours = credit_hours;
}

int Discipline::DegreeRequirement()
{
	return num_of_courses * credit_hours;
}

void Discipline::Input()
{
	cout << "Enter Discipline's name: ";
	cin >> name;
	cout << "Enter number of courses: ";
	cin >> num_of_courses;
	cout << "Enter credit hours per course: ";
	cin >> credit_hours;
}

void Discipline::Display()
{
	cout << endl;
	cout << "Degree: " << name << endl;
	cout << "Number of required courses: " << num_of_courses << endl;
	cout << "Number of credit hours: " << credit_hours << endl;
}
