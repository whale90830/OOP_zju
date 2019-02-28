#include"Employee.h"
#include<iostream>

Employee::Employee()
{
}
Employee::Employee(string id, string name, int age, string address, string phone_no,
	string department_name, double gross_salary, double tax_percentage)
{
	setId(id);
	setName(name);
	setAge(age);
	setAddress(address);
	setPhoneNo(phone_no);
	this->department_name = department_name;
	this->gross_salary = gross_salary;
	this->tax_percentage = tax_percentage*1.0 / 100;
	this->net_salary = gross_salary * (1 - tax_percentage);
}

string Employee::getDepartementName()
{
	return department_name;
}
void Employee::setDepartmentName(string department_name)
{
	this->department_name = department_name;
}
double Employee::getGrossSalary()
{
	return gross_salary;
}
void Employee::setGrossSalary(double gross_salary)
{
	this->gross_salary = gross_salary;
}
double Employee::getTaxPercentage()
{
	return tax_percentage * 100;
}
void Employee::setTaxPercentage(double tax_percentage)
{
	this->tax_percentage = tax_percentage*1.0 / 100;
}
double Employee::getNetSalary()
{
	return net_salary;
}
void Employee::setNetSalary()
{
	net_salary = gross_salary * (1 - tax_percentage);
}

void Employee::Input()
{
	string id, name; int age; string address, phone_no;
	double tax_percentage;
	
	cout << endl; 
	cout << "*-*-*-**-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << " Enter Employee's Information " << endl;
	cout << "*-*-*-**-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "Enter the Employee Id:                    ";
	cin >> id;
	setId(id);
	cout << "Enter the Name of the Person:             ";
	cin >> name;
	setName(name);
	cout << "Enter the Age of the Person:              ";
	cin >> age;
	setAge(age);
	cout << "Enter the Address of the Person:          ";
	cin >> address;
	setAddress(address);
	cout << "Enter the Phone No of the Person:         ";
	cin >> phone_no;
	setPhoneNo(phone_no);
	cout << "Enter the Department of the Person:       ";
	cin >> department_name;
	cout << "Enter the Gross Salary of the Person:     ";
	cin >> gross_salary;
	cout << "Enter the Tax Percentage of the Person:   ";
	cin >> tax_percentage;
	this->tax_percentage = tax_percentage*1.0 / 100;
	this->net_salary = this->gross_salary * (1 - this->tax_percentage);
	cout << endl;
}

void Employee::showOutPut()
{
	cout << endl;
	cout << "*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "  Employee's Data  " << endl;
	cout << "*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "Employee Id:               " << getId() << endl;
	cout << "Employee Name:             " << getName() << endl;
	cout << "Employee Age:              " << getAge() << endl;
	cout << "Employee Address:          " << getAddress() << endl;
	cout << "Employee Phone Number:     " << getPhoneNo() << endl;
	cout << "Employee Department:       " << department_name << endl;
	cout << "Employee's Gross Salary:   " << gross_salary << " with " << tax_percentage*100 << "% of Tax" << endl;
	cout << "Employee's Net Salary:     " << net_salary << endl;
	cout << endl;
}
