//#pragma once//compiler guard works only with windows
#ifndef BOSS_H__
#define BOSS_H__

#include "Enemy.h"

class Boss : public Enemy
{
public:
	Boss(int damage = 30, int mult = 3);
	~Boss();
	void Attack() const;
	void SpecialAttack() const;
	
protected :
	int m_DamageMultiplier;
};

#endif