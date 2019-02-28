#ifndef GPA_H
#define GPA_H

#include<iostream>
using namespace std;

const int COURSENUMBER = 5;
const int CREDITHOUR = 3;

template<typename T>
class Gpa
{
public:
	Gpa();		// no-arg constructor
	Gpa(T* result);
	Gpa(const Gpa& sec_Gpa);	// Copy Constructors
	~Gpa();		// destructor
	
	// Setters and Getters
	T* getResult() const;
	void setResult(T* result);
	
	void input();
	void cal_gpa();
private:
	T* result;
};

template<typename T>
Gpa<T>::Gpa()		// no-arg constructor
{
	this->result = new T[COURSENUMBER];
	for(int i=0;i<COURSENUMBER;i++)
	{
		this->result[i] = 0;
	}
}
template<typename T>
Gpa<T>::Gpa(T* result)
{
	if(result==NULL)
	{
		this->result = new T[COURSENUMBER];
		for(int i=0;i<COURSENUMBER;i++)
		{
			this->result[i] = 0;
		}
	}
	else
	{
		this->result = new T[COURSENUMBER];
		for(int i=0;i<COURSENUMBER;i++)
		{
			this->result[i] = result[i];
		}
	}
}
template<typename T>
Gpa<T>::Gpa(const Gpa& sec_Gpa)		// Copy Constructors
{
	delete []result;
	this->result = new T[COURSENUMBER];
	for(int i=0;i<COURSENUMBER;i++)
	{
		this->result[i] = sec_Gpa.getResult()[i];
	}
}
template<typename T>
Gpa<T>::~Gpa()		// destructor
{
	delete []result;
} 

// Setters and Getters
template<typename T>
T* Gpa<T>::getResult() const
{
	return result;
}
template<typename T>
void Gpa<T>::setResult(T* result)
{
	delete []result;
	if(result==NULL)
	{
		this->result = new T[COURSENUMBER];
		for(int i=0;i<COURSENUMBER;i++)
		{
			result[i] = 0;
		}
	}
	else
	{
		this->result = new T[COURSENUMBER];
		for(int i=0;i<COURSENUMBER;i++)
		{
			this->result[i] = result[i];
		}
	}
}

template<typename T>
void Gpa<T>::input()
{
	delete []result;
	this->result = new T[COURSENUMBER];
	cout << "Enter student's marks in each course: " << endl;
	for(int i=0;i<COURSENUMBER;i++)
	{
		cin >> result[i];
	}
}
template<typename T>
void Gpa<T>::cal_gpa()
{
	int total_points = 0;
	int total_credits = COURSENUMBER * CREDITHOUR;
	for(int i=0;i<COURSENUMBER;i++)
	{
		if(result[i]=='A' || result[i]>=80)
		{
			total_points += 12;
		}
		else if(result[i]=='B' || result[i]>=70)
		{
			total_points += 9;
		}
		else if(result[i]=='C' || result[i]>=60)
		{
			total_points += 6;
		}
		else if(result[i]=='D' || result[i]>=50)
		{
			total_points += 3;
		}
		else if(result[i]=='F' || result[i]<=49)
		{
			total_points += 0;
		}
	}
	double GPA = total_points*1.0 / total_credits;
	cout << "The student's Gpa is " << GPA;
}

#endif
