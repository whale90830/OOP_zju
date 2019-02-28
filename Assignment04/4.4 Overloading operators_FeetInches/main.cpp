#include"FeetInches.h"
#include <iostream>

int main(int argc, char** argv) {
	int feet,inches;
	
	cout << "Enter a length in feet and inches:" << endl;
	cout << "Feet:	";
	cin >> feet;
	cout << "Inches:	";
	cin >> inches;
	FeetInches feetinches1(feet,inches);
	
	cout << "Enter a length in feet and inches:" << endl;
	cout << "Feet:	";
	cin >> feet;
	cout << "Inches:	";
	cin >> inches;
	FeetInches feetinches2(feet,inches);
	
	cout << endl;
	FeetInches sumfeetinches = feetinches1 + feetinches2;
	feetinches1.display();
	cout << " sum ";
	feetinches2.display();
	cout << " is ";
	sumfeetinches.display();
	cout << endl;
	
	cout << endl;
	FeetInches timesfeetinches = feetinches1 * feetinches2;
	feetinches1.display();
	cout << " times ";
	feetinches2.display();
	cout << " is ";
	timesfeetinches.display();
	cout << endl;

	cout << endl;
	feetinches1.display();
	if(feetinches1 >= feetinches2)
		cout << " is greater than and equal to ";
	else
		cout << " is not greater than and equal to ";
	feetinches2.display();
	cout << endl;

	cout << endl;
	if(feetinches1 != feetinches2)
		cout << "Two are not equal";
	else
		cout << "Two are equal";
	cout << endl;

	cout << endl;
	FeetInches dividedfeetinches = feetinches1 / feetinches2;
	feetinches1.display();
	cout << " divided ";
	feetinches2.display();
	cout << " is ";
	dividedfeetinches.display();
	cout << endl;
	
	return 0;
}
