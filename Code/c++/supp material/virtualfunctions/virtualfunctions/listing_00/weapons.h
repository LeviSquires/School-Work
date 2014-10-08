#if !defined(WEAPONS_H__)
#define WEAPONS_H__


class Weapon
{
public:
    void fire();
};

class ProjectileWeapon: public Weapon
{
};

class ChargeWeapon: public Weapon
{
};


class StabbingWeapon: public Weapon
{
};


class BallisticWeapon: public Weapon
{
};

class M777_Howitzer: public ProjectileWeapon
{
};

class AK47: public ProjectileWeapon
{
};

class Tazer: public ChargeWeapon
{
};

class BFG9000: public ChargeWeapon
{
};

class BowieKnife: public StabbingWeapon
{
};

class PointyStick: public StabbingWeapon
{
};

class ICBM: public BallisticWeapon
{
};


#endif


