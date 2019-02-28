#include"PostGraduation.h"
#include<iostream>

PostGraduation::PostGraduation()
{
}
PostGraduation::PostGraduation(string name, int num_of_courses, int credit_hours, string thesis_project)
{
	setName(name);
	setNumOfCoures(num_of_courses);
	setCreditHours(credit_hours);
	
	this->thesis_project = thesis_project;
	
	if(thesis_project == "Thesis")
		this->thesis_project_credit = 4;
	else if(thesis_project == "Project")
		this->thesis_project_credit = 6;
}

string PostGraduation::getThesisProject()
{
	return thesis_project;
}
void PostGraduation::setThesisProject(string thesis_project)
{
	this->thesis_project = thesis_project;
}

int PostGraduation::DegreeRequirement()
{
	return getNumOfCourses() * getCreditHours() + thesis_project_credit;
}

void PostGraduation::Input()
{
	string name;
	int num_of_courses;
	int credit_hours;
	char thesis_project;
	
	cout << "Enter Discipline's name: ";
	cin >> name;
	setName(name);
	
	cout << "Enter number of courses: ";
	cin >> num_of_courses;
	setNumOfCoures(num_of_courses);
	
	cout << "Enter credit hours per course: ";
	cin >> credit_hours;
	setCreditHours(credit_hours);
	
	cout << "Enter your choice for Thesis or Project;  T/t for thesis; P/p for project: ";
	cin >>  thesis_project;
	if(thesis_project == ('T' or 't'))
		this->thesis_project = "Thesis";
	else if(thesis_project == ('P' or 'p'))
		this->thesis_project = "Project";
	
	if(this->thesis_project == "Thesis")
		this->thesis_project_credit = 4;
	else if(this->thesis_project == "Project")
		this->thesis_project_credit = 6;
}

void PostGraduation::Display()
{
	cout << endl;
	cout << "Degree: " << getName() << endl;
	cout << "Number of required courses: " << getNumOfCourses() << endl;
	cout << "Number of credit hours: " << getCreditHours() << endl;
	
	if(thesis_project == "Thesis")
		cout << "Thesis credit: " << '4' << endl;
	else if(thesis_project == "Project")
		cout << "Project credit: " << '6' << endl;
	
	cout << "Total number of required credit hours for graduation degree: " << DegreeRequirement() << endl;
	cout << endl;
}
