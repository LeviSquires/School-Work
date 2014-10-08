#if !defined(WEAPONS_H__)
#define WEAPONS_H__

class Weapon
{
public:
    virtual void fire() = 0;
    ~Weapon();
};

class ProjectileWeapon: public Weapon
{
public:
    virtual void fire();
    ~ProjectileWeapon();
};

class ChargeWeapon: public Weapon
{
public:
    virtual void fire();
    ~ChargeWeapon();
};


class StabbingWeapon: public Weapon
{
public:
    virtual void fire();
    ~StabbingWeapon();
};


class BallisticWeapon: public Weapon
{
public:
    virtual void fire();
    ~BallisticWeapon();
};

class M777_Howitzer: public ProjectileWeapon
{
public:
    virtual void fire();
    ~M777_Howitzer();
};

class AK47: public ProjectileWeapon
{
public:
    virtual void fire();
    ~AK47();
};

class Tazer: public ChargeWeapon
{
public:
    virtual void fire();
    ~Tazer();
};

class BFG9000: public ChargeWeapon
{
public:
    virtual void fire();
    ~BFG9000();
};

class BowieKnife: public StabbingWeapon
{
public:
    virtual void fire();
    ~BowieKnife();
};

class PointyStick: public StabbingWeapon
{
public:
    virtual void fire();
    ~PointyStick();
};

class ICBM: public BallisticWeapon
{
public:
    virtual void fire();
    ~ICBM();
};

#endif
