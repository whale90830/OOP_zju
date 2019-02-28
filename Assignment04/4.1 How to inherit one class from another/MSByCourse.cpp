#include"MSByCourse.h"
#include<iostream>

MSByCourse::MSByCourse()
{
}
MSByCourse::MSByCourse(string name, string address, int rollNo, string advisor)
{
	setName(name);
	setAddress(address);
	setRollNo(rollNo);
	setAdvisor(advisor);
}

void MSByCourse::PrintInfo()
{
	cout << "***MSByCourse***" << endl;
	cout << "Name: " << getName() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "RollNo: " << getRollNo() << endl;
	cout << "Advisor: " << getAdvisor() << endl; 
}
