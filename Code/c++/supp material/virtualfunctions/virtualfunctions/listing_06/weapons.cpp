#include <iostream>
#include "weapons.h"

using std::cout;
using std::endl;



void ChargeWeapon::fire()
{
    cout << "ChargeWeapon::fire() executed."  << endl;
    cout << "Starting to recharge...."  << endl;
    
}


void M777_Howitzer::fire()
{
    cout << "M777_Howitzer::fire() executed."  << endl;
}



void AK47::fire()
{
    cout << "AK47::fire() executed."  << endl;
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
}



void PointyStick::fire()
{
    cout << "PointyStick::fire() executed."  << endl;
}



void ICBM::fire()
{
    cout << "ICBM::fire() executed."  << endl;
}


