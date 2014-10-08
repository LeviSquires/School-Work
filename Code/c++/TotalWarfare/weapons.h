#include <iostream>
class Weapon
{
public :
	//create a pure virtual function
	virtual void use() = 0;
	virtual ~Weapon()
	{
		std::cout << "~Weapon() has been called." << std::endl;	
	}
};
//c++ inheritance
class ChargedWeapon : public Weapon
{
public :
	virtual ~ChargedWeapon()
	{
		std::cout << "~ChargedWeapon() has been called." << std::endl;	
	}
	virtual void use();
private :
	virtual void recharge();
};

class MeleeWeapon : public Weapon
{
public :
	virtual ~MeleeWeapon()
	{
		std::cout << "~MeleeWeapon() has been called." << std::endl;	
	}
};

class ProjectileWeapon : public Weapon
{
public :
	virtual ~ProjectileWeapon()
	{
		std::cout << "~ProjectileWeapon() has been called." << std::endl;	
	}
};

class ExplosiveWeapon : public Weapon
{
public :
	virtual ~ExplosiveWeapon()
	{
		std::cout << "~ExplosiveWeapon() has been called." << std::endl;	
	}
};

class BallisticWeapon : public Weapon
{
public :
	virtual ~BallisticWeapon()
	{
		std::cout << "~BallisticWeapon() has been called." << std::endl;	
	}
};

class AK47 : public ProjectileWeapon
{
public :
	virtual void use();
	virtual ~AK47()
	{
		std::cout << "~AK47() has been called." << std::endl;	
	}

};

class BFG9000 : public ChargedWeapon
{
public :
	virtual void use();
	virtual ~BFG9000()
	{
		std::cout << "~BFG9000() has been called." << std::endl;	
	}
};

class Taser : public ChargedWeapon
{
public :
	virtual void use();
	virtual ~Taser()
	{
		std::cout << "~Taser() has been called." << std::endl;	
	}
};

class PointyWeapon : public MeleeWeapon
{
public :
	virtual ~PointyWeapon()
	{
		std::cout << "~PointyWeapon() has been called." << std::endl;	
	}
};

class SlashingWeapon : public MeleeWeapon
{
public :
	virtual ~SlashingWeapon()
	{
		std::cout << "~SlashingWeapon() has been called." << std::endl;	
	}
};

class PointyStick : public PointyWeapon
{
public :
	virtual void use();
	virtual ~PointyStick()
	{
		std::cout << "~PointyStick() has been called." << std::endl;	
	}
};

class Knife : public PointyWeapon
{
public :
	virtual void use();
	virtual ~Knife()
	{
		std::cout << "~Knife() has been called." << std::endl;	
	}
};

class Katana : public SlashingWeapon
{
public :
	virtual void use();
	virtual ~Katana()
	{
		std::cout << "~Katana() has been called." << std::endl;	
	}
};

class GatlingGun : public ProjectileWeapon
{
public :
	virtual void use();
	virtual ~GatlingGun()
	{
		std::cout << "~GatlingGun() has been called." << std::endl;	
	}
};

class Magnum : public ProjectileWeapon
{
public :
	virtual void use();
	virtual ~Magnum()
	{
		std::cout << "~Magnum() has been called." << std::endl;	
	}
};

class BowAndArrow : public ProjectileWeapon
{
public :
	virtual void use();
	virtual ~BowAndArrow()
	{
		std::cout << "~BowAndArrow() has been called." << std::endl;	
	}
};

class Grenade : public ExplosiveWeapon
{
public :
	virtual void use();
	virtual ~Grenade()
	{
		std::cout << "~Grenade() has been called." << std::endl;	
	}
};

class ICBM : public BallisticWeapon
{
public :
	virtual void use();
	virtual ~ICBM()
	{
		std::cout << "~ICBM() has been called." << std::endl;	
	}
};