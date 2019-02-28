#include"Purchased_item.h"
int Purchased_item::item_num = 0;

Purchased_item::Purchased_item()
{
	price = 0;
	quantity = 0;
	item_num = 0;
}

Purchased_item::Purchased_item(int p,int q)
{
	price = p;
	quantity = q;
	++item_num;
}

int Purchased_item::GetItemTotal()
{
	return price*quantity;
}


Bill::Bill()
{
	total_amount = 0;
}

void Bill::GetItems()
{
	while(Purchased_item::item_num<5)
	{
		int temp_price;
		int temp_quantity;
		cout<<"enter price and purcahased quantity of item "<<Purchased_item::item_num+1<<endl;
		cout<<"price: ";
		cin>>temp_price;
		cout<<"Quantity: ";
		cin>>temp_quantity;
		items[Purchased_item::item_num] = Purchased_item(temp_price,temp_quantity);
	}
}

void Bill::calculate_total()
{
	for(int i=0;i<5;++i)
	{
		total_amount += items[i].GetItemTotal();
	}
}

void Bill::show()
{
	cout<<"Total amount to be paid is "<<total_amount<<endl;
}
