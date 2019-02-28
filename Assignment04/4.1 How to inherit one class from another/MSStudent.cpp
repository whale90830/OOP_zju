#include"MSStudent.h"
#include<iostream>

MSStudent::MSStudent()
{
}
MSStudent::MSStudent(string name, string address, int rollNo, string advisor)
{
	setName(name);
	setAddress(address);
	setRollNo(rollNo);
	this->advisor = advisor;
}

void MSStudent::PrintInfo()
{
	cout << "***MSStudent***" << endl;
	cout << "Name: " << getName() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "RollNo: " << getRollNo() << endl;
	cout << "Advisor: " << advisor << endl; 
}

string MSStudent::getAdvisor()
{
	return advisor;
}
void MSStudent::setAdvisor(string advisor)
{
	this->advisor = advisor;
}
