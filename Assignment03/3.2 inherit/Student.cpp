#include"Student.h"
#include<iostream> 

Student::Student()
{
}
Student::Student(string id, string name, int age, string address, string phone_no,
		string course_name, int room_no, double GPA)
{
	setId(id);
	setName(name);
	setAge(age);
	setAddress(address);
	setPhoneNo(phone_no);
	this->course_name = course_name;
	this->room_no = room_no;
	this->GPA = GPA;
}
	
string Student::getCourseName()
{
	return course_name;
}
void Student::setCourseName(string course_name)
{
	this->course_name = course_name;
}
int Student::getRoomNo()
{
	return room_no;
}
void Student::setRoomNo(int room_no)
{
	this->room_no = room_no;
}
double Student::getGPA()
{
	return GPA;
}
void Student::setGPA(double GPA)
{
	this->GPA = GPA;
}

void Student::Input()
{
	string id, name; int age; string address, phone_no;
	
	cout << endl; 
	cout << "*-*-*-**-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "  Enter Student's Information " << endl;
	cout << "*-*-*-**-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "Enter the Roll No:                                   ";
	cin >> id;
	setId(id);
	cout << "Enter the Name of the Person:                        ";
	cin >> name;
	setName(name);
	cout << "Enter the Age of the Person:                         ";
	cin >> age;
	setAge(age);
	cout << "Enter the Address of the Person:                     ";
	cin >> address;
	setAddress(address);
	cout << "Enter the Phone No of the Person:                    ";
	cin >> phone_no;
	setPhoneNo(phone_no);
	cout << "Enter the Course Discipline of the Person [CS/IT]:   ";
	cin >> course_name;
	cout << "Enter the Room No of the Person:                     ";
	cin >> room_no;
	cout << "Enter the GPA of the Person:                         ";
	cin >> GPA;
	cout << endl;
}
void Student::showOutPut()
{
	cout << endl;
	cout << "*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "   Student's Data  " << endl;
	cout << "*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "Student Id:                          " << getId() << endl;
	cout << "Student Name:                        " << getName() << endl;
	cout << "Student Age:                         " << getAge() << endl;
	cout << "Student Address:                     " << getAddress() << endl;
	cout << "Student Phone Number:                " << getPhoneNo() << endl;
	cout << "Student Course Discipline [CS/IT]:   " << course_name << endl;
	cout << "Student Room No:                     " << room_no << endl;
	cout << "Student GPA:                         " << GPA << endl;
	cout << endl;
}
