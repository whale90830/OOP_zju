#ifndef CIRCLE_H
#define CIRCLE_H

#include<iostream>
using namespace std;

template<typename T>
class Circle
{
public:
	Circle();
	Circle(T radius);
	Circle(const Circle& sec_Circle);
	
	double Area();
	void input();
	void display();
	
	T getRadius() const;
	void setRadius(T radius);
private:
	T radius;
};

template<typename T>
Circle<T>::Circle()
{
}

template<typename T>
Circle<T>::Circle(T radius)
{
	this->radius = radius;
}

template<typename T>
Circle<T>::Circle(const Circle& sec_Circle)		// Copy Constructors
{
	this->radius = sec_Circle.getRadius();
}

template<typename T>
double Circle<T>::Area()
{
	double area;
	area =  (3.1415 * radius*radius);
	return area; 
}
template<typename T>
void Circle<T>::input()
{
	cout << "radius: ";
	cin >> this->radius;

	cout << "Radius of the Circle is: " << this->radius << endl; 
}
template<typename T>
void Circle<T>::display()
{
	cout << "Area of the Circle is: " << this->Area() << endl;
}

template<typename T>
T Circle<T>::getRadius() const
{
	return radius;
}
template<typename T>
void Circle<T>::setRadius(T radius)
{
	this->radius = radius;
}

#endif
