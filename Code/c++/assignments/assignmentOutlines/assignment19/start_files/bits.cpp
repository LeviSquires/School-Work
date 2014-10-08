
#include <iostream>
#include "prototypes.h"
#include "templates.h"

using std::cout;
using std::endl;


int main()
{
    cout << endl;
    int numb1 = askForInt("Enter a number to be added: ");
    cout << numb1 << "'s bit pattern is:" << endl;
    ShowBits(std::cout, numb1);

    int numb2 = askForInt("\nEnter another number to be added: ");
    cout << numb2 << "'s bit pattern is:" << endl;
    ShowBits(std::cout, numb2);

    int dx = 0; // represents the dx register -- where the answer goes

    //Implement the bit-wise adding here...


    cout << "\nThe result of addition is: " << dx << endl;
    cout << "Bit pattern is:" << endl;
    ShowBits(std::cout, dx);
    cout << endl;

	std::cin.get();
    return 0;

}



