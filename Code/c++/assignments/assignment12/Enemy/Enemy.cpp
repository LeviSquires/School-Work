#include <iostream>

#include "Enemy.h"

using std::cout;
using std::endl;

Enemy::Enemy(int damage) : m_Damage(damage)
{
	
}

void Enemy::Attack() const
{
	cout << "Enemy attack inflicts " << m_Damage << " damage.";
}

