#ifndef MSBYRESEARCH_H
#define MSBYRESEARCH_H

#include"MSStudent.h"

class MSByResearch: public MSStudent
{
public:
	MSByResearch();
	MSByResearch(string name, string address, int rollNo, string advisor, bool thesisStatus);
	
	void PrintInfo();
	
	bool getThesisStatus();
	void setThesisStatus(bool thesisStatus);
private:
	bool thesisStatus;
};

#endif
