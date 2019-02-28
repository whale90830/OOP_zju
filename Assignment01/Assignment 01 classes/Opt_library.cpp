#include"Opt_library.h"
#include<iostream>
using namespace std;

Opt_library::Opt_library(int id,int days,int issued,int returned)
{
	card_number = id;
	valid_days_left = days;
	books_issued = issued;
	books_returned = returned;
}

Opt_library::~Opt_library()
{
	cout << endl << "Destructing..." << endl;
}

int Opt_library::PreviousStatusOfTheCard()
{
	if(books_issued > books_returned)
	{
		cout << endl << "No further operations can be made. Some books are still not returned" << endl;
		cout << endl;
		return 1;
	}
	else if (books_issued == books_returned)
	{
		cout << endl;
		cout << "Card Number: " << card_number << endl;
		cout << "Valid days left: " << valid_days_left << endl;
		cout << "Books issued previously: " << books_issued << endl;
		cout << "Books returned previously: " << books_returned << endl;
		cout << endl << "        " << "The status has been cleared." << endl;
		cout << endl;
		return 0;
	}
}

int Opt_library::issue_books(int books)
{
	if(valid_days_left < 15)
	{
		cout << endl << "Books cannot be issued, there are not enough days left for the validity of card" << endl;
		cout << endl;
		return 0;
	}
	
	if(books > 2)
	{
		cout << endl << "        " << "More than 2 books can not be issued at a time" << endl;
		cout << endl;
		return 1;
	}
	
	if(books <=2 && valid_days_left >= 15)
	{
		Number_of_books = books;
		display();
		return 0;
	}
	
}

void Opt_library::display()
{
	cout << endl << Number_of_books << " book(s), issued to the " << card_number << endl;
}
