#include <iostream>

#include "Boss.h"
#include "Enemy.h"

int main()
{
	Enemy e;
	e.Attack();
	std::cout << std::endl;

	Boss b;
	b.Attack();
	std::cout << std::endl;

	b.SpecialAttack();
	std::cout << std::endl;
	
	std::cin.get();

	return 0;

}