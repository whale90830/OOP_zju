#include <stdlib.h>
#include"DInteger.h"

int main(){
	DInteger a, b, sum, mul, div, sub; //DInteger is a class, it is not simple int
	
	cin>>a;
	cin>>b;
	
	sum = a + b;
	mul = a * b;
	div = a / b;
	sub = a - b;
    a += 10;
    a -= 10;
    a++;
	
	cout<<sum<<endl;
	cout<<mul<<endl;
	cout<<div<<endl;
	cout<<sub<<endl;
	
	cout<<endl;
	
	return 0;
}
