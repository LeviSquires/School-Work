#include <iostream>
#include <string>
#include "prototypes.h"
#include "templates.h"


int main()
{
	int x = 5;
	ShowBits(std::cout, x);
	std::cout << std::endl;
	int y = -5;
	ShowBits(std::cout, y);



	/*
	double inc = 13.43;
	double total = 134.3;
	double acc = 0;

	for (unsigned i = 0; i < 10; ++i)
	{
		acc += inc;
	}

	if(acc == total)
	{
		std::cout << "Arithmentic works!";
	}
	else
	{
		std::cout << "Something stinks!" << "this:" <<  std::endl;
		ShowBits(std::cout, acc);
		std::cout << "Should equal:" << std::endl;
		ShowBits(std::cout, total);

	}
	*/

	

	std::cin.get();
	return 0;
}


