#include <iostream>

#include "Weapons.h"


Weapons::Weapons(int damage) : m_Damage(damage)
{
}

Weapons::~Weapons()
{
}

void Weapons::Attack() const
{
	std::cout << "Weapon attack inflicts " << m_Damage << " damage.";
}
