#ifndef DINTEGER_H
#define DINTEGER_H
#include<iostream>
using namespace std;

class DInteger{
public:
	DInteger();		// no-arg constructor
	DInteger(int one,int two);
	DInteger(const DInteger& sec_DInteger);		// Copy Constructors
	
	// Setters and Getters
	int getOne() const;
	void setOne(int one);
	int getTwo() const;
	void setTwo(int two);
	
	DInteger add(const DInteger& sec_DInteger) const;
	DInteger subtract(const DInteger& sec_DInteger) const;
	DInteger multiply(const DInteger& sec_DInteger) const;
	DInteger divide(const DInteger& sec_DInteger) const;
	
	DInteger(int one);		// constructor for type conversion
	
	// augmented assignment operators
	DInteger& operator+=(const DInteger& sec_DInteger);
	DInteger& operator-=(const DInteger& sec_DInteger);
	
	DInteger& operator++();		// prefix ++ operator
	DInteger operator++(int dummy);		// postfix ++ operator
	
	friend ostream& operator<<(ostream& out, const DInteger& dInteger);	// stream Insertion operator
	friend istream& operator>>(istream& in, DInteger& dInteger);	// stream Extraction operator
	
	const DInteger& operator=(const DInteger& dInteger);	// assignment operator
private:
	int one;
	int two;
};

// Define nonmember function operators for arithmetic operators
DInteger operator+(const DInteger& d1, const DInteger& d2);
DInteger operator-(const DInteger& d1, const DInteger& d2);
DInteger operator*(const DInteger& d1, const DInteger& d2);
DInteger operator/(const DInteger& d1, const DInteger& d2);

#endif
