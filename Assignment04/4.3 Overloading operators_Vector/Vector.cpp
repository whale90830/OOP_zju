#include"Vector.h"
#include <iostream>

Vector::Vector()
{
}
Vector::Vector(double x, double y, double z)
{
	this->XComponent = x;
	this->YComponent = y;
	this->ZComponent = z;
}

double Vector::getXComponent() const
{
	return XComponent;
}
void Vector::setXComponent(double x)
{
	this->XComponent = x;
}
double Vector::getYComponent() const
{
	return YComponent;
}
void Vector::setYComponent(double y)
{
	this->YComponent = y;
}
double Vector::getZComponent() const
{
	return ZComponent;
}
void Vector::setZComponent(double z)
{
	this->ZComponent = z;
}

void Vector::display()
{
	cout << this->XComponent << "i";
	if(this->YComponent >= 0)
	{
		cout << "+";
	}
	cout << this->YComponent << "j";
	if(this->ZComponent >= 0)
	{
		cout << "+";
	}
	cout << this->ZComponent << "k";
	cout << endl;
}

Vector Vector::operator+(const Vector& secondVector) const
{
	double x = this->XComponent + secondVector.getXComponent();
	double y = this->YComponent + secondVector.getYComponent();
	double z = this->ZComponent + secondVector.getZComponent();
	return Vector(x,y,z);
}
double Vector::operator*(const Vector& secondVector) const
{
	double r1 = this->XComponent * secondVector.getXComponent();
	double r2 = this->YComponent * secondVector.getYComponent();
	double r3 = this->ZComponent * secondVector.getZComponent();
	return r1 + r2 + r3;
}
