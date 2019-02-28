#ifndef TOTAL_H
#define TOTAL_H

#include<iostream>
#include<string>
#include"Marks.h"
using namespace std;

class Total
{
public:
	Total();		// no-arg constructor
	Total(string course);
	Total(const Total& sec_Total);		// Copy Constructors
	
	// Setters and Getters
	string getCourse() const;
	void setCourse(string course);
	
	template<typename T>
	void Total_marks(const Marks<T>& marks);
private:
	string course;	//for course title
};

Total::Total()	// no-arg constructor
{
}
Total::Total(string course)
{
	this->course = course;
}
Total::Total(const Total& sec_Total)	// Copy Constructors
{
	this->course = sec_Total.getCourse();
}

// Setters and Getters
string Total::getCourse() const
{
	return course;
}
void Total::setCourse(string course)
{
	this->course = course;
}

template<typename T>
void Total::Total_marks(const Marks<T>& marks)
{
	T result;
	result = marks.getMid() + marks.getFinal() + marks.getAssignments();
	cout << result;
}

#endif
