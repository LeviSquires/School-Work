#include <iostream>
#include <vector>


#include "weapons.h"

using std::vector;
using std::cout;
using std::endl;

int main()
{
    M777_Howitzer* mh = new M777_Howitzer;
    AK47* ak = new AK47;
    Tazer* t = new Tazer;
    BFG9000* bfg = new BFG9000;
    BowieKnife* bk = new BowieKnife;
    PointyStick* ps = new PointyStick;
    ICBM* icbm = new ICBM;

    vector<Weapon*> arsenal;
        
    arsenal.push_back(mh);
    arsenal.push_back(ak);
    arsenal.push_back(t);
    arsenal.push_back(bfg);
    arsenal.push_back(bk);
    arsenal.push_back(ps);
    arsenal.push_back(icbm);
        
    for(vector<Weapon*>::iterator it = arsenal.begin(); it != arsenal.end(); ++it)
    {
        Weapon* p = *it;
        p -> fire();
        cout << endl;
    }
    
    return 0;
}
