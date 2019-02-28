#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;

class Student
{
public:
	Student();
	Student(string name, string address, int rollNo);
	
	virtual void PrintInfo();
	
	string getName();
	void setName(string name);
	string getAddress();
	void setAddress(string address);
	int getRollNo();
	void setRollNo(int rollNo);
private:
	string name;
	string address;
	int rollNo;
};

#endif
