#include <iostream>
#include <string>
#include<sstream>
using namespace std;

class Student
{
private:
    string* StudentName;
    string* FatherName;
    string* TelephoneNumber;
public:
    Student()
    {
        StudentName = NULL;
        FatherName = NULL;
        TelephoneNumber = NULL;
    }
    void Setter(string SN,string FN,string TN)
    {
        StudentName = new string(SN);
        FatherName = new string(FN);
        TelephoneNumber = new string(TN);
    }
    string* Getter()
    {
        string* result = new string[3];
        result[0] = *StudentName;
        result[1] = *FatherName;
        result[2] = *TelephoneNumber;
        return result;
    }
    ~Student(){
        delete StudentName;
        delete FatherName;
        delete TelephoneNumber;
    }
    void show(){
        cout<<"Student Name                          : "<<*StudentName<<endl;
        cout<<"Father's Name                          : "<<*FatherName<<endl;
        cout<<"Telephone Number                          : "<<*TelephoneNumber<<endl;
    }
};

class Teacher
{
private:
    string TeacherId;
    string* Name;
    string Subject;
public:
    Teacher(string TI,string N,string S){
        TeacherId = TI;
        Name = new string(N);
        Subject = S;
    }
    Teacher(){

    }
    ~Teacher(){
        delete Name;
    }
    string* Getter(){
        string result[2];
        result[1] = TeacherId;
        result[2] = *Name;
        result[3] = Subject;
        return result;
    }
    const Teacher& operator=(const Teacher& t1){
        TeacherId = t1.TeacherId+"x";
        Name = new string(*t1.Name);
        Subject = t1.Subject;
        return *this;
    }
    void show(){
        cout<<"Teacher Id \t\t\t: "<<TeacherId<<endl<<endl;
        cout<<"Teacher Name                 : "<<*Name<<endl<<endl;
        cout<<"Subject Name                 : "<<Subject<<endl<<endl;
    }
};

int main(){
    string SN,FN,TN;
    int num;
    int* cur = new int(0);
    cout<<"Enter the number of records you want to enter   :";
    cin>>num;
    getchar();
    Student s[num-1];
    while(*cur<num){
        cout << "Enter the Student Name                : ";
        getline(cin,SN);
        cout << "Enter the Father's Name               : ";
        getline(cin,FN);
        cout << "Enter the Telephone Number            : ";
        getline(cin,TN);
        cout << endl;
        s[*cur].Setter(SN,FN,TN);
        ++(*cur);
    }
    delete cur;

    for(int i=0;i<num;++i){
        string* result = s[i].Getter();
        cout<<"Student Name                 : "<<(result[0])<<endl<<endl;
        cout<<"Father's Name                : "<<(result[1])<<endl<<endl;
        cout<<"Telephone Number             : "<<(result[2])<<endl<<endl;
        delete[] result;
    }
    
    Teacher t1("12345","WangFei","Computer Science");
    Teacher t2;
    t2 = t1;
    t1.show();
    cout<<endl;
    t2.show();
    return 0;
}
