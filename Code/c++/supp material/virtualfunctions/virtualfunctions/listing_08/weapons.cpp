#include <iostream>
#include "weapons.h"

using std::cout;
using std::endl;


void Weapon::fire()
{
    cout << "Weapon::fire() executed."  << endl;    
}


void ChargeWeapon::fire()
{
    cout << "ChargeWeapon::fire() executed."  << endl;
    Weapon::fire();
}

void ProjectileWeapon::fire()
{
    cout << "ProjectileWeapon::fire() executed."  << endl;
    Weapon::fire();
}

void StabbingWeapon::fire()
{
    cout << "StabbingWeapon::fire() executed."  << endl;
    Weapon::fire();
}

void BallisticWeapon::fire()
{
    cout << "BallisticWeapon::fire() executed."  << endl;
    Weapon::fire();
}


void M777_Howitzer::fire()
{
    cout << "M777_Howitzer::fire() executed."  << endl;
    ProjectileWeapon::fire();
}



void AK47::fire()
{
    cout << "AK47::fire() executed."  << endl;
    ProjectileWeapon::fire();
}



void Tazer::fire()
{
    cout << "Tazer::fire() executed."  << endl;
    //call to the base class implementation of fire()
    ChargeWeapon::fire();
    
}



void BFG9000::fire()
{
    cout << "BFG9000::fire() executed."  << endl;
    //call to the base class implementation of fire()
    ChargeWeapon::fire();
}



void BowieKnife::fire()
{
    cout << "BowieKnife::fire() executed."  << endl;
    StabbingWeapon::fire();
}



void PointyStick::fire()
{
    cout << "PointyStick::fire() executed."  << endl;
    StabbingWeapon::fire();
}



void ICBM::fire()
{
    cout << "ICBM::fire() executed."  << endl;
    BallisticWeapon::fire();
}


