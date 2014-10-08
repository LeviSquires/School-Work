#include <iostream>
#include "weapons.h"

using std::cout;
using std::endl;


void Weapon::fire()
{
    cout << "Weapon::fire() executed."  << endl;    
}

Weapon::~Weapon()
{
    cout << "Weapon dtor executed."  << endl;    
}



void ChargeWeapon::fire()
{
    cout << "ChargeWeapon::fire() executed."  << endl;
    Weapon::fire();
}


ChargeWeapon::~ChargeWeapon()
{
    cout << "ChargeWeapon dtor executed."  << endl;    
}


void ProjectileWeapon::fire()
{
    cout << "ProjectileWeapon::fire() executed."  << endl;
    Weapon::fire();
}


ProjectileWeapon::~ProjectileWeapon()
{
    cout << "ProjectileWeapon dtor executed."  << endl;    
}


void StabbingWeapon::fire()
{
    cout << "StabbingWeapon::fire() executed."  << endl;
    Weapon::fire();
}


StabbingWeapon::~StabbingWeapon()
{
    cout << "StabbingWeapon dtor executed."  << endl;    
}


void BallisticWeapon::fire()
{
    cout << "BallisticWeapon::fire() executed."  << endl;
    Weapon::fire();
}


BallisticWeapon::~BallisticWeapon()
{
    cout << "BallisticWeapon dtor executed."  << endl;    
}

void M777_Howitzer::fire()
{
    cout << "M777_Howitzer::fire() executed."  << endl;
    ProjectileWeapon::fire();
}


M777_Howitzer::~M777_Howitzer()
{
    cout << "M777_Howitzer dtor executed."  << endl;    
}



void AK47::fire()
{
    cout << "AK47::fire() executed."  << endl;
    ProjectileWeapon::fire();
}


AK47::~AK47()
{
    cout << "BowieKnife dtor executed."  << endl;    
}


void Tazer::fire()
{
    cout << "Tazer::fire() executed."  << endl;
    //call to the base class implementation of fire()
    ChargeWeapon::fire();
    
}


Tazer::~Tazer()
{
    cout << "Tazer dtor executed."  << endl;    
}


void BFG9000::fire()
{
    cout << "BFG9000::fire() executed."  << endl;
    //call to the base class implementation of fire()
    ChargeWeapon::fire();
}


BFG9000::~BFG9000()
{
    cout << "BFG9000 dtor executed."  << endl;    
}


void BowieKnife::fire()
{
    cout << "BowieKnife::fire() executed."  << endl;
    StabbingWeapon::fire();
}

BowieKnife::~BowieKnife()
{
    cout << "BowieKnife dtor executed."  << endl;    
}


void PointyStick::fire()
{
    cout << "PointyStick::fire() executed."  << endl;
    StabbingWeapon::fire();
}

PointyStick::~PointyStick()
{
    cout << "PointyStick dtor executed."  << endl;    
}


void ICBM::fire()
{
    cout << "ICBM::fire() executed."  << endl;
    BallisticWeapon::fire();
}

ICBM::~ICBM()
{
    cout << "ICBM dtor executed."  << endl;    
}

