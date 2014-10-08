#include <iostream>
#include "randgen.h"

int main()
{
	RandGen rg;
	int die = rg(6) + 1;
	std::cout <<"You rolled a " <<die << std::endl;
	return 0;
}