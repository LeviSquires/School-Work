#ifndef ENEMY_H__//compiler guard, works with both widows and unix
#define ENEMY_H__

class Enemy
{
public :
	Enemy(int damage = 10);
	void Attack() const;
	
protected :
	int m_Damage;
};

#endif