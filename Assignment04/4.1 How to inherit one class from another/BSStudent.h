#ifndef BSSTUDENT_H
#define BSSTUDENT_H

#include"Student.h"

class BSStudent: public Student
{
public:
	BSStudent();
	BSStudent(string name, string address, int rollNo, int year);
	
	void PrintInfo();
	
	int getYear();
	void setYear(int year);
private:
	int year;
};

#endif
