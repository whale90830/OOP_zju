#include"BSStudent.h"
#include<iostream>

BSStudent::BSStudent()
{
}
BSStudent::BSStudent(string name, string address, int rollNo, int year)
{
	setName(name);
	setAddress(address);
	setRollNo(rollNo);
	this->year = year;
}

void BSStudent::PrintInfo()
{
	cout << "***BSStudent***" << endl;
	cout << "Name: " << getName() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "RollNo: " << getRollNo() << endl;
	cout << "Year: " << year << endl; 
}

int BSStudent::getYear()
{
	return year;
}
void BSStudent::setYear(int year)
{
	this->year = year;
}
