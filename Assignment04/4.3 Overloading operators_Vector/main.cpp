#include <iostream>
#include"Vector.h"

int main(int argc, char** argv) {
	double x,y,z;
	
	cout << "Enter the components for vector 1:" << endl;
	cout << "X component:	";
	cin >> x;
	cout << "Y component:	";
	cin >> y;
	cout << "Z component:	";
	cin >> z;
	Vector vector1(x,y,z);
	
	cout << "Enter the components for vector 2:" << endl;
	cout << "X component:	";
	cin >> x;
	cout << "Y component:	";
	cin >> y;
	cout << "Z component:	";
	cin >> z;
	Vector vector2(x,y,z);
	
	cout << endl << "The two vectors are:" << endl;
	vector1.display();
	vector2.display();

	Vector vector_sum;
	vector_sum = vector1 + vector2;
	cout << endl << "The addition of two vectors is:" << endl;
	vector_sum.display();
	
	double vector_dotproduct = vector1 * vector2;
	if(vector_dotproduct == 0)
	{
		cout << endl << "The two vectors are perpendicular to each other" << endl;
	}
	else
	{
		cout << endl << "The two vectors are not perpendicular to each other" << endl;
	}
	
	return 0;
}
