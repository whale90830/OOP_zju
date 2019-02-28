#ifndef MSSTUDENT_H
#define MSSTUDENT_H

#include"Student.h"

class MSStudent: public Student
{
public:
	MSStudent();
	MSStudent(string name, string address, int rollNo, string advisor);
	
	void PrintInfo();
	
	string getAdvisor();
	void setAdvisor(string advisor);
private:
	string advisor;
};

#endif
