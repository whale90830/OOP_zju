#ifndef DISCIPLINE_H
#define DISCIPLINE_H
#include<string>
using namespace std;

class Discipline
{
public:
	Discipline();
	Discipline(string name, int num_of_courses, int credit_hours);
	
	string getName();
	void setName(string name);
	int getNumOfCourses();
	void setNumOfCoures(int num_of_courses);
	int getCreditHours();
	void setCreditHours(int credit_hours);
	
	int DegreeRequirement();
	void Input();
	void Display();
private:
	string name;
	int num_of_courses;
	int credit_hours;
};

#endif
