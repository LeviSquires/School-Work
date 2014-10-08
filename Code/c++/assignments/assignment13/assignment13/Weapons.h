#pragma once
class Weapons
{
public:
	Weapons(int damage);
	~Weapons();
	void Attack() const;
	
protected :
	int m_Damage;
};

