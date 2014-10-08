#include <iostream>

#include "Crossbow.h"


Crossbow::Crossbow(int damage) : Weapons(damage)
{
}

Crossbow::~Crossbow()
{
}

void Crossbow::Attack()
{
	if (isLoaded() == true)
	{
		std::cout << "Crossbow attack inflicts " << m_Damage << " damage.";
		isLoaded() = false;
	}
	else
	{
		std::cout << "Crossbow cannot be fired until it has been reloaded.";
		reload();
	}
}

bool Crossbow::isLoaded() const
{
	if(isLoaded() == true)
	{
		std::cout << "Crossbow is loaded and ready to fire.";
		return true;
	}
	std::cout << "Crossbow is unloaded and must be reloaded before firing again.";
	return false;
}

void Crossbow::reload()
{
	std::cout << "The crossbow has been reloaded.";
	isLoaded() = true;
}
