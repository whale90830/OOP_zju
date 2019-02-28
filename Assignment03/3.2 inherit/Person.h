#ifndef PERSON_H
#define PERSON_H
#include<string>
using namespace std;

class Person
{
public:
	Person();
	Person(string id, string name, int age, string address, string phone_no);
	~Person();
	
	string getId();
	void setId(string id);
	string getName();
	void setName(string name);
	int getAge();
	void setAge(int age);
	string getAddress();
	void setAddress(string address);
	string getPhoneNo();
	void setPhoneNo(string phone_no);
	
	void Input();
	void showOutPut();
private:
	string id;
	string name;
	int age;
	string address;
	string phone_no;
};

#endif
