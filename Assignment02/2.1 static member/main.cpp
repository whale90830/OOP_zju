#include <iostream>
#include "stdlib.h"
#include"Purchased_item.h" 

int main(int argc, char** argv) {
	Bill bill;
	
	bill.GetItems();
	bill.calculate_total();
	bill.show();
	system("pause");
	return 0;
}
