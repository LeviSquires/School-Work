#pragma once
#include "Weapons.h"
class Crossbow :
	public Weapons
{
public:
	Crossbow(int damage = 20);
	~Crossbow();
	void Attack();
	bool isLoaded() const;
	void reload();
};

