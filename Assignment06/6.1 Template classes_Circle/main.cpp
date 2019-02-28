#include"Circle.h"

int main(int argc, char** argv) {
	Circle<int> intCircle;
	cout << "Enter the radius of first Circle: " << endl;
	intCircle.input();
	intCircle.display();
	cout << endl;
	
	Circle<float> floatCircle;
	cout << "Enter the radius of second Circle: " << endl;
	floatCircle.input();
	floatCircle.display();
	cout << endl;
	
	Circle<double> doubleCircle;
	cout << "Enter the radius of third Circle: " << endl;
	doubleCircle.input();
	doubleCircle.display();
	cout << endl;
	
	return 0;
}
