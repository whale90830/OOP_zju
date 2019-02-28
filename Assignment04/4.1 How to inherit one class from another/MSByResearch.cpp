#include"MSByResearch.h"
#include<iostream>

MSByResearch::MSByResearch()
{
}
MSByResearch::MSByResearch(string name, string address, int rollNo, string advisor, bool thesisStatus)
{
	setName(name);
	setAddress(address);
	setRollNo(rollNo);
	setAdvisor(advisor);
	this->thesisStatus = thesisStatus;
}

void MSByResearch::PrintInfo()
{
	cout << "***MSByCourse***" << endl;
	cout << "Name: " << getName() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "RollNo: " << getRollNo() << endl;
	cout << "Advisor: " << getAdvisor() << endl;
	cout << "ThesisStatus: " << thesisStatus << endl;
}

bool MSByResearch::getThesisStatus()
{
	return thesisStatus;
}
void MSByResearch::setThesisStatus(bool thesisStatus)
{
	this->thesisStatus = thesisStatus;
}
