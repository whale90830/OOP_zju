#include"Person.h"
#include<iostream>

Person::Person()
{
}
Person::Person(string id, string name, int age, string address, string phone_no)
{
	this->id = id;
	this->name = name;
	this->age = age;
	this->address = address;
	this->phone_no = phone_no; 
}
Person::~Person()
{
}

string Person::getId()
{
	return id;
}
void Person::setId(string id)
{
	this->id = id;
}
string Person::getName()
{
	return name;
}
void Person::setName(string name)
{
	this->name = name;
}
int Person::getAge()
{
	return age;
}
void Person::setAge(int age)
{
	this->age = age;
}
string Person::getAddress()
{
	return address;
}
void Person::setAddress(string address)
{
	this->address = address;
}
string Person::getPhoneNo()
{
	return phone_no;
}
void Person::setPhoneNo(string phone_no)
{
	this->phone_no = phone_no; 
}

void Person::Input()
{
	cout << endl;
	cout << "*-*-*-**-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "  Enter Person's Information  " << endl;
	cout << "*-*-*-**-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "Enter the Roll No:                                   ";
	cin >> id;
	cout << "Enter the Name of the Person:                        ";
	cin >> name;
	cout << "Enter the Age of the Person:                         ";
	cin >> age;
	cout << "Enter the Address of the Person:                     ";
	cin >> address;
	cout << "Enter the Phone No of the Person:                    ";
	cin >> phone_no;
	cout << endl;
}
void Person::showOutPut()
{
	cout << endl;
	cout << "*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "   Person's Data   " << endl;
	cout << "*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "Person Id:             " << id << endl;
	cout << "Person Name:           " << name << endl;
	cout << "Person Age:            " << age << endl;
	cout << "Person Address:        " << address << endl;
	cout << "Person Phone Number:   " << phone_no << endl;
	cout << endl;
}
