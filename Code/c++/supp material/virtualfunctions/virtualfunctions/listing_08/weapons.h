#if !defined(WEAPONS_H__)
#define WEAPONS_H__

class Weapon
{
public:
    virtual void fire() = 0;
};

class ProjectileWeapon: public Weapon
{
public:
    virtual void fire();
};

class ChargeWeapon: public Weapon
{
public:
    virtual void fire();
};


class StabbingWeapon: public Weapon
{
public:
    virtual void fire();
};


class BallisticWeapon: public Weapon
{
public:
    virtual void fire();
};

class M777_Howitzer: public ProjectileWeapon
{
public:
    virtual void fire();
};

class AK47: public ProjectileWeapon
{
public:
    virtual void fire();
};

class Tazer: public ChargeWeapon
{
public:
    virtual void fire();
};

class BFG9000: public ChargeWeapon
{
public:
    virtual void fire();
};

class BowieKnife: public StabbingWeapon
{
public:
    virtual void fire();
};

class PointyStick: public StabbingWeapon
{
public:
    virtual void fire();
};

class ICBM: public BallisticWeapon
{
public:
    virtual void fire();
};

#endif
