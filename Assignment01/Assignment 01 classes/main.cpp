#include <iostream>
using namespace std;
#include"Opt_library.h"

int main(int argc, char** argv) {
	int id, days, issued, returned, books;
	
	cout << "Enter card number: ";
	cin >> id;
	
	cout << "Enter days left for the validation: ";
	cin >> days;
	
	cout << "Enter number of books issued previously: ";
	cin >> issued;
	while(issued < 0)
	{
		cout << endl << "Number of books issued can not be negative" << endl;
		cout << "Enter number of books issued previously: ";
		cin >> issued;
	}
	
	cout << "Enter number of books returned previously: ";
	cin >> returned;
	while(returned < 0)
	{
		cout << endl << "Number of books returned can not be negative" << endl;
		cout << "Enter number of books returned previously: ";
		cin >> returned;
	}
	
	while(issued < returned)
	{
		cout << endl << "Number of books returned can not be greater than number of books issued" << endl;
		cout << endl;
		cout << "Enter number of books issued previously: ";
		cin >> issued;
		cout << "Enter number of books returned previously: ";
		cin >> returned;
	}
	
	Opt_library op(id, days, issued, returned);
	int flag1 = op.PreviousStatusOfTheCard();
	if(flag1)
	{
		return 0;
	}
	
	cout << "Please enter the number of books to be issued: ";
	cin >> books;
	
	int flag2 = op.issue_books(books);
	while(flag2)
	{
		cout << "Please enter the number of books to be issued: ";
		cin >> books;
		flag2 = op.issue_books(books);
	}
	
	return 0;
}
