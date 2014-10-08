#if !defined(WEAPONS_H__)
#define WEAPONS_H__

class Weapon
{
public:
    virtual void fire() = 0;
    virtual ~Weapon();
};

class ProjectileWeapon: public Weapon
{
public:
    virtual void fire();
    virtual ~ProjectileWeapon();
};

class ChargeWeapon: public Weapon
{
public:
    virtual void fire();
    virtual ~ChargeWeapon();
};


class StabbingWeapon: public Weapon
{
public:
    virtual void fire();
    virtual ~StabbingWeapon();
};


class BallisticWeapon: public Weapon
{
public:
    virtual void fire();
    virtual ~BallisticWeapon();
};

class M777_Howitzer: public ProjectileWeapon
{
public:
    virtual void fire();
    virtual ~M777_Howitzer();
};

class AK47: public ProjectileWeapon
{
public:
    virtual void fire();
    virtual ~AK47();
};

class Tazer: public ChargeWeapon
{
public:
    virtual void fire();
    virtual ~Tazer();
};

class BFG9000: public ChargeWeapon
{
public:
    virtual void fire();
    virtual ~BFG9000();
};

class BowieKnife: public StabbingWeapon
{
public:
    virtual void fire();
    virtual ~BowieKnife();
};

class PointyStick: public StabbingWeapon
{
public:
    virtual void fire();
    virtual ~PointyStick();
};

class ICBM: public BallisticWeapon
{
public:
    virtual void fire();
    virtual ~ICBM();
};

#endif
