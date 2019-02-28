#include"DInteger.h"

DInteger::DInteger()	// no-arg constructor
{
}
DInteger::DInteger(int one,int two)
{
	this->one = one;
	this->two = two;
}
DInteger::DInteger(const DInteger& sec_DInteger)	// Copy Constructors
{
	this->one = sec_DInteger.getOne();
	this->two = sec_DInteger.getTwo();
}

// Setters and Getters
int DInteger::getOne() const
{
	return one;
}
void DInteger::setOne(int one)
{
	this->one = one;
}
int DInteger::getTwo() const
{
	return two;
}
void DInteger::setTwo(int two)
{
	this->two = two;
}

DInteger DInteger::add(const DInteger& sec_DInteger) const
{
	int one = this->one + sec_DInteger.getOne();
	int two = this->two + sec_DInteger.getTwo();
	return DInteger(one,two);
}
DInteger DInteger::subtract(const DInteger& sec_DInteger) const
{
	int one = this->one - sec_DInteger.getOne();
	int two = this->two - sec_DInteger.getTwo();
	return DInteger(one,two);
}
DInteger DInteger::multiply(const DInteger& sec_DInteger) const
{
	int one = this->one * sec_DInteger.getOne();
	int two = this->two * sec_DInteger.getTwo();
	return DInteger(one,two);
}
DInteger DInteger::divide(const DInteger& sec_DInteger) const
{
	int one = this->one / sec_DInteger.getOne();
	int two = this->two / sec_DInteger.getTwo();
	return DInteger(one,two);
}

// constructor for type conversion
DInteger::DInteger(int one)
{
	this->one = one;
	this->two = 1;
}

// augmented assignment operators
DInteger& DInteger::operator+=(const DInteger& sec_DInteger)
{
	*this = add(sec_DInteger);
	return *this;
}
DInteger& DInteger::operator-=(const DInteger& sec_DInteger)
{
	*this = subtract(sec_DInteger);
	return *this;
}

DInteger& DInteger::operator++()	// prefix ++ operator
{
	++one;++two;
	return *this;
}
DInteger DInteger::operator++(int dummy)	// postfix ++ operator
{
	DInteger temp(one, two);
	++one;++two;
	return temp;
}

// stream Insertion operator
ostream& operator<<(ostream& out, const DInteger& dInteger)
{
	out << dInteger.getOne() << "," << dInteger.getTwo();
	return out;
}
// stream Extraction operator
istream& operator>>(istream& in, DInteger& dInteger)
{
	cout << "Enter one: ";
	in >> dInteger.one;
	cout << "Enter two: ";
	in >> dInteger.two;
	return in;
}

// assignment operator
const DInteger& DInteger::operator=(const DInteger& sec_DInteger)
{
	this->one = sec_DInteger.getOne();
	this->two = sec_DInteger.getTwo();
	
	return *this;
}

// nonmember function operators for arithmetic operators
DInteger operator+(const DInteger& d1, const DInteger& d2)
{
	return d1.add(d2);
}
DInteger operator-(const DInteger& d1, const DInteger& d2)
{
	return d1.subtract(d2);
}
DInteger operator*(const DInteger& d1, const DInteger& d2)
{
	return d1.multiply(d2);
} 
DInteger operator/(const DInteger& d1, const DInteger& d2)
{
	return d1.divide(d2);
}
