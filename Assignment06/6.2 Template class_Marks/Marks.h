#ifndef MARKS_H
#define MARKS_H

template<typename T>
class Marks
{
public:
	Marks();	// no-arg constructor
	Marks(T mid, T final, T assignments);
	Marks(const Marks& sec_Marks);		// Copy Constructors
	
	// Setters and Getters
	T getMid() const;
	void setMid(T mid);
	T getFinal() const;
	void setFinal(T final);
	T getAssignments() const;
	void setAssignments(T assignments);
private:
	T mid;			//for mid-term exam marks	
	T final;		//for final-term exam marks		
	T assignments;	//for assignments marks	
};

template<typename T>
Marks<T>::Marks()	// no-arg constructor
{
}
template<typename T>
Marks<T>::Marks(T mid, T final, T assignments)
{
	this->mid = mid;
	this->final = final;
	this->assignments = assignments;
}
template<typename T>
Marks<T>::Marks(const Marks& sec_Marks)	// Copy Constructors
{
	this->mid = sec_Marks.getMid();
	this->final = sec_Marks.getFinal();
	this->assignments = sec_Marks.getAssignments();
}

// Setters and Getters
template<typename T>
T Marks<T>::getMid() const
{
	return mid;
}
template<typename T>
void Marks<T>::setMid(T mid)
{
	this->mid = mid;
}
template<typename T>
T Marks<T>::getFinal() const
{
	return final;
}
template<typename T>
void Marks<T>::setFinal(T final)
{
	this->final = final;
}
template<typename T>
T Marks<T>::getAssignments() const
{
	return assignments;
}
template<typename T>
void Marks<T>::setAssignments(T assignments)
{
	this->assignments = assignments;
}

#endif
