#include"Student.h"
#include<iostream>

Student::Student()
{
}
Student::Student(string name, string address, int rollNo)
{
	this->name = name;
	this->address = address;
	this->rollNo = rollNo;
}

void Student::PrintInfo()
{
	cout << "***Student***" << endl;
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "RollNo: " << rollNo << endl;
}

string Student::getName()
{
	return name;
}
void Student::setName(string name)
{
	this->name = name;
}
string Student::getAddress()
{
	return address;
}
void Student::setAddress(string address)
{
	this->address = address;
}
int Student::getRollNo()
{
	return rollNo;
}
void Student::setRollNo(int rollNo)
{
	this->rollNo = rollNo;
}
