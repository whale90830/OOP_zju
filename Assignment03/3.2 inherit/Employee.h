#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include"Person.h"

class Employee: public Person
{
public:
	Employee();
	Employee(string id, string name, int age, string address, string phone_no,
		string department_name, double gross_salary, double tax_percentage);
	
	string getDepartementName();
	void setDepartmentName(string department_name);
	double getGrossSalary();
	void setGrossSalary(double gross_salary);
	double getTaxPercentage();
	void setTaxPercentage(double tax_percentage);
	double getNetSalary();
	void setNetSalary();
	
	void Input();
	void showOutPut();
private:
	string department_name;
	double gross_salary;
	double tax_percentage;
	double net_salary;
};

#endif
