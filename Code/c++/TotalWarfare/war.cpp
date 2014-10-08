#include <iostream>
#include <vector>

#include "weapons.h"

int main()
{
	std::vector<Weapon*> arsenal;	
	//arsenal.push_back(new Weapon);
	arsenal.push_back(new BFG9000);
	arsenal.push_back(new AK47);
	arsenal.push_back(new Grenade);
	arsenal.push_back(new Taser);
	arsenal.push_back(new PointyStick);
	arsenal.push_back(new Knife);
	arsenal.push_back(new Katana);
	arsenal.push_back(new GatlingGun);
	arsenal.push_back(new Magnum);
	arsenal.push_back(new BowAndArrow);
	arsenal.push_back(new ICBM);
	
	for(std::vector<Weapon*>::iterator it = arsenal.begin(); it != arsenal.end(); ++it)
	{
		(*it) -> use();
	}
	
	//Clearing 
	for(std::vector<Weapon*>::iterator it = arsenal.begin(); it != arsenal.end(); ++it)
	{
		delete *it;
	}

    return 0;
}
