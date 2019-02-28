#ifndef FEETINCHES_H
#define FEETINCHES_H
using namespace std;

class FeetInches
{
public:
	FeetInches();
	FeetInches(int feet, int inches);
	
	int getFeet() const;
	void setFeet(int feet);
	int getInches() const;
	void setInches(int inches);
	
	bool operator>=(const FeetInches& secondFeetInches) const;
	bool operator!=(const FeetInches& secondFeetInches) const;
	FeetInches operator+(const FeetInches& secondFeetInches) const;
	FeetInches operator*(const FeetInches& secondFeetInches) const;
	FeetInches operator/(const FeetInches& secondFeetInches) const;
	
	void display();
private:
	int feet;
	int inches;
	
	void convert();
};

#endif
