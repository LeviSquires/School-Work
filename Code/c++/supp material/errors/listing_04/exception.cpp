#include <iostream>
#include <exception>

using std::exception;
using std::cout;
using std::endl;    

void functionThatCouldThrowAnException();

int main()
{
    try
    {
        functionThatCouldThrowAnException();
    }
    catch(std::exception& e)
    {
        cout << "Exception caught." << endl;
        //deal with the exception
    }
}

void functionThatCouldThrowAnException()
{
    if(/*some error condition*/ true)
    {
        cout << "Throwing an exception." << endl;
        throw exception();
    }
}
