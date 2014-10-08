#include <iostream>
#include <vector>


#include "weapons.h"
#include "prototypes.h"

using std::vector;
using std::cout;
using std::endl;

Weapon* weaponsFactory(int type);

int main()
{

    vector<Weapon*> arsenal;
    
    int choice = 0;
    do
    {
        choice = askForInt("0 - Quit\n"
                           "1 - Fire Weapons\n"
                           "2 - Create New AK47\n"
                           "3 - Create new BFG9000\n"
                           "4 - Create new Bowie Knife\n"
                           "5 - Create new ICBM\n"
                           "6 - Create new M777 Howizter\n"
                           "7 - Create new Pointy Stick\n"
                           "8 - Create new Tazer: ", 8, 0);
        if(choice == 1)
        {
            for(vector<Weapon*>::iterator it = arsenal.begin(); it != arsenal.end(); ++it)
            {
                Weapon* p = *it;
                p -> fire();
                cout << endl;
            }

        }
        else
        {
            Weapon* p = weaponsFactory(choice);
            if(p)
            {
                arsenal.push_back(p);
            }
        }
    }while(choice != 0);


        

    for(vector<Weapon*>::iterator it = arsenal.begin(); it != arsenal.end(); ++it)
    {
        Weapon* p = *it;
        delete p;
        cout << endl;
    }

    
    return 0;
}


Weapon* weaponsFactory(int type)
{
    switch(type)
    {
        case 2:
            return new AK47;
        case 3:
            return new BFG9000;
        case 4:
            return new BowieKnife;
        case 5:
            return new ICBM;
        case 6:
            return new M777_Howitzer;
        case 7:
            return new PointyStick;
        case 8:
            return new Tazer;
        default:
            return 0;
    }

}

