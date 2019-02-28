#include"Total.h"

int main(int argc, char** argv) {
	Marks<int> marks1(20,35,10);
	Marks<float> marks2(20,36.5,10);
	
	Total total1("OOP");
	Total total2("DS");
	
	cout << "Total marks in " << total1.getCourse() << " are ";
	total1.Total_marks(marks1);
	cout << endl;
	cout << "Total marks in " << total2.getCourse() << " are ";
	total2.Total_marks(marks2);
	cout << endl;
	
	return 0;
}
