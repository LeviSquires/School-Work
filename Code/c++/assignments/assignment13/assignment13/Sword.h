#pragma once
#include "Weapons.h"
class Sword :
	public Weapons
{
public:
	Sword(int damage = 10);
	~Sword();
	void Attack() const;
};

