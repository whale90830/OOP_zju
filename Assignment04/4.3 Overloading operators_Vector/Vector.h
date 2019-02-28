#ifndef VECTOR_H
#define VECTOR_H
using namespace std;

class Vector
{
public:
	Vector();
	Vector(double x, double y, double z);
	
	double getXComponent() const;
	void setXComponent(double x);
	double getYComponent() const;
	void setYComponent(double y);
	double getZComponent() const;
	void setZComponent(double z);
	
	void display();
	
	Vector operator+(const Vector& secondVector) const;
	double operator*(const Vector& secondVector) const;
private:
	double XComponent;
	double YComponent;
	double ZComponent;
};

#endif
