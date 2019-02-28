#include <iostream>
using namespace std;

class Purchased_item
{
private:
	int price;
	int quantity;
public:
	static int item_num;
	Purchased_item();
	Purchased_item(int p,int q);
	
	int GetItemTotal();
};

class Bill
{
private:
	int total_amount;
	Purchased_item items[5];
public:
	Bill();
	void GetItems();
	void calculate_total();
	void show();
};
