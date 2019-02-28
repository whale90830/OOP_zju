#include"Student.h"
#include"Employee.h"
#include <iostream>

int main(int argc, char** argv) {
	Student student;
	student.Input();
	student.showOutPut();
	
	Employee employee;
	employee.Input();
	employee.showOutPut();
	
	return 0;
}
