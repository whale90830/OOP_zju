#include"Gpa.h"

int main(int argc, char** argv) {
	Gpa<int> gpa1;
	gpa1.input();
	gpa1.cal_gpa();
	cout << endl;
	
	cout << endl;
	Gpa<char> gpa2;
	gpa2.input();
	gpa2.cal_gpa();
	return 0;
}
