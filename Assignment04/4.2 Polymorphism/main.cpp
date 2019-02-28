#include <iostream>

#include"TVChannel.h"
#include"NewsChannel.h"
#include"MusicChannel.h"

int main(int argc, char** argv)
{
	TVChannel *p;
	NewsChannel ob1;
	MusicChannel ob2;
	
	p=&ob1;
	p->DisplayName();
	
	p=&ob2;
	p->DisplayName();
	
	return 0;
}
