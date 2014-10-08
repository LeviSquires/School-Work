#include <iostream>

#include "Sword.h"


Sword::Sword(int damage) : Weapons(damage)
{
}

Sword::~Sword()
{
}

void Sword::Attack() const
{
	std::cout << "Sword attack inflicts " << m_Damage << " damage.";
}
