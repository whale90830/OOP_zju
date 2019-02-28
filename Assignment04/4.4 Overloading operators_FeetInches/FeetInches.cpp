#include"FeetInches.h"
#include <iostream>

FeetInches::FeetInches()
{
}
FeetInches::FeetInches(int feet, int inches)
{
	this->feet = feet;
	this->inches = inches;
	
	this->convert();
}

void FeetInches::convert()
{
	if(inches > 12)
	{
		feet += inches / 12;
		inches = inches % 12;
	}
}

int FeetInches::getFeet() const
{
	return feet;
}
void FeetInches::setFeet(int feet)
{
	this->feet = feet;
}
int FeetInches::getInches() const
{
	return inches;
}
void FeetInches::setInches(int inches)
{
	this->inches = inches;
}

bool FeetInches::operator>=(const FeetInches& secondFeetInches) const
{
	if(this->feet > secondFeetInches.getFeet())
		return true;
	else if(this->feet == secondFeetInches.getFeet())
	{
		if(this->inches >= secondFeetInches.getInches())
			return true;
		else
			return false;
	}
	else
		return false;
}
bool FeetInches::operator!=(const FeetInches& secondFeetInches) const
{
	if(this->feet == secondFeetInches.getFeet() && this->inches == secondFeetInches.getInches())
		return false;
	else
		return true;
}
FeetInches FeetInches::operator+(const FeetInches& secondFeetInches) const
{
	int feet = this->feet + secondFeetInches.getFeet();
	int inches = this->inches + secondFeetInches.getInches();
	FeetInches sumFeetInches(feet,inches);
	sumFeetInches.convert();
	return sumFeetInches;
}
FeetInches FeetInches::operator*(const FeetInches& secondFeetInches) const
{
	int feet = this->feet * secondFeetInches.getFeet();
	int inches = this->inches * secondFeetInches.getInches();
	FeetInches timesFeetInches(feet,inches);
	timesFeetInches.convert();
	return timesFeetInches;
}
FeetInches FeetInches::operator/(const FeetInches& secondFeetInches) const
{
	int inches1 = this->feet * 12 + this->inches;
	int inches2 = secondFeetInches.getFeet() * 12 + secondFeetInches.getInches();
	FeetInches dividedFeetInches(0,inches1/inches2);
	dividedFeetInches.convert();
	return dividedFeetInches;
}

void FeetInches::display()
{
	cout << this->feet << " feet, ";
	cout << this->inches << " inches";
}
