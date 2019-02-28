#ifndef GRADUATION_H
#define GRADUATION_H
#include"Discipline.h"

class Graduation: public Discipline
{
public:
	Graduation();
	Graduation(string name, int num_of_courses, int credit_hours);
	
	int getThesisCredit();
	
	int DegreeRequirement();
	void Input();
	void Display();
private:
	int thesis_credit = 4;
};

#endif
