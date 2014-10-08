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
public:
    void fire();
};

class AK47: public ProjectileWeapon
{
public:
    void fire();
};

class Tazer: public ChargeWeapon
{
public:
    void fire();
};

class BFG9000: public ChargeWeapon
{
public:
    void fire();
};

class BowieKnife: public StabbingWeapon
{
public:
    void fire();
};

class PointyStick: public StabbingWeapon
{
public:
    void fire();
};

class ICBM: public BallisticWeapon
{
public:
    void fire();
};

#endif
