#include <iostream>

int main()
{
	int a = -27;
	int b = 50;
	int c = a % 12;
	int d = b % 12;
	
	int e = -50 / 12;
	
	
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cin.get();
	return 0;
}