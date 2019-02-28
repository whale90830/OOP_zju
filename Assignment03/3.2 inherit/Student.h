#ifndef STUDENT_H
#define STUDENT_H
#include"Person.h"

class Student: public Person
{
public:
	Student();
	Student(string id, string name, int age, string address, string phone_no,
		string course_name, int room_no, double GPA);
	
	string getCourseName();
	void setCourseName(string course_name);
	int getRoomNo();
	void setRoomNo(int room_no);
	double getGPA();
	void setGPA(double GPA);
	
	void Input();
	void showOutPut();
private:
	string course_name;
	int room_no;
	double GPA;
};

#endif
