#include <iostream>

#include "Weapons.h"
#include "Sword.h"
#include "Crossbow.h"

int main()
{
	Sword s;
	s.Attack();
	std::cout << std::endl;

	Crossbow c;
	c.Attack();
	std::cout << std::endl;
	
	std::cin.get();

	return 0;
}
