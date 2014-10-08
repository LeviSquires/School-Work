#include <iostream>

#include "Boss.h"



Boss::Boss(int damage, int mult) : Enemy(damage), m_DamageMultiplier(mult)
{
	
}


Boss::~Boss()
{
}

void Boss::Attack() const
{
	std::cout << "Boss attack inflicts " << m_Damage << " damage.";
}

void Boss::SpecialAttack() const
{
	std::cout << "Boss special attack inflicts " << (m_DamageMultiplier * m_Damage) << " damage.";
}



