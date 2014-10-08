#include <iostream>
#include <exception>

using std::exception;
using std::cout;
using std::endl;    

#include <iostream>
#include <exception>

using std::exception;
using std::cout;
using std::endl;    

void init();
void checkConfiguration1();
void checkConfiguration2();
void checkConfiguration3();
void checkConfiguration4();
void checkConfiguration5();
void checkConfiguration6();

int main()
{
    try
    {
         init();
    }
    catch(exception& e)
    {
        cout << "Catching the exception in main()" << endl;
    }
    return 0;
} 

void init()
{
    checkConfiguration1();   
    //Other checks…
}

void checkConfiguration1()
{
    checkConfiguration2();
    //Other checks…
}
void checkConfiguration2()
{
    checkConfiguration3();
    //Other checks…
}

void checkConfiguration3()
{
    checkConfiguration4();
    //Other checks…
}

void checkConfiguration4()
{
    checkConfiguration5();
    //Other checks…
}

void checkConfiguration5()
{
    checkConfiguration6();
    //Other checks…
}

void checkConfiguration6()
{
    if(/*some configuration error*/true)
    {
        cout << "Throwing the exception in checkConfiguration6()" << endl; 
        throw exception();
    }
}

