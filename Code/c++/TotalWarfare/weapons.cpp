#include <iostream>
#include "weapons.h"

using std::cout;
using std::endl;

void Weapon::use()
{
	cout << "Weapon::use() called." << endl;
}

void ChargedWeapon::use()
{
	cout << "ChargedWeapon::use() called." << endl;
	recharge();
}
void ChargedWeapon::recharge()
{
	cout << "Recharging the weapon.\n";
}


void BFG9000::use()
{
	cout << "BFG9000::use() called." << endl;
	ChargedWeapon::use();
}

void Taser::use()
{
	cout << "Taser::use() called." << endl;
	ChargedWeapon::use();
}

void PointyStick::use()
{
	cout << "PointyStick::use() called." << endl;
}

void Knife::use()
{
	cout << "Knife::use() called." << endl;
}

void Katana::use()
{
	cout << "Katana::use() called." << endl;
}

void GatlingGun::use()
{
	cout << "GatlingGun::use() called." << endl;
}

void Magnum::use()
{
	cout << "Magnum::use() called." << endl;
}

void AK47::use()
{
	cout << "AK47::use() called." << endl;
}

void BowAndArrow::use()
{
	cout << "BowAndArrow::use() called." << endl;
}

void ICBM::use()
{
	cout << "ICBM::use() called." << endl;
}

void Grenade::use()
{
	cout << "Grenade::use() called." << endl;
}