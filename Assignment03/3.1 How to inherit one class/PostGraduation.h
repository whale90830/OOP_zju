#ifndef POSTGRADUATION_H
#define POSTGRADUATION_H
#include"Discipline.h"

class PostGraduation: public Discipline
{
public:
	PostGraduation();
	PostGraduation(string name, int num_of_courses, int credit_hours, string thesis_project);
	
	string getThesisProject();
	void setThesisProject(string thesis_project);
	
	int DegreeRequirement();
	void Input();
	void Display();
private:
	string thesis_project;
	int thesis_project_credit;
};

#endif
