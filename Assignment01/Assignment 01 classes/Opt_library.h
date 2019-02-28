class Opt_library
{
private:
	int card_number;
	int valid_days_left;
	int books_issued;
	int books_returned;
	int Number_of_books;
public:
	Opt_library(int,int,int,int); 
	~Opt_library();
	
	int getCardNumber(){return card_number;}
	int getValidDaysLeft(){return valid_days_left;}
	int getBooksIssued(){return books_issued;}
	int getBooksReturned(){return books_returned;}
	int getNumberOfBooks(){return Number_of_books;}
	void setCardNumber(int id){card_number = id;}
	void setValidDaysLeft(int days){valid_days_left = days;}
	void setBooksIssued(int issued){books_issued = issued;}
	void setBooksReturned(int returned){books_returned = returned;}
	void setNumberOfBooks(int books){Number_of_books = books;}
	
	int PreviousStatusOfTheCard();
	int issue_books(int);
	void display();
};
