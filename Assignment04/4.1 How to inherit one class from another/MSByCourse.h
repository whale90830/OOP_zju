#ifndef MSBYCOURSE_H
#define MSBYCOURSE_H

#include"MSStudent.h"

class MSByCourse: public MSStudent
{
public:
	MSByCourse();
	MSByCourse(string name, string address, int rollNo, string advisor);
	
	void PrintInfo();
};

#endif
