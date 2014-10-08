#include <iostream>
#include <vector>


#include "weapons.h"

using std::vector;
using std::cout;
using std::endl;

int main()
{
    BFG9000 bfg;
    bfg.fire();
    cout <<endl;
    Tazer t;
    t.fire();
    
    return 0;
}
