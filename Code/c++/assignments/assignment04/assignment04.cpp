#include <iostream>
#include <vector>
#include "prototypes.h"
using namespace std;

int main()
{
	int number = 0;
	cout << "\t\tWelcome to the Factor Machine\n\n";
	
	cout << "Enter a number to factor: \n";
	
	cin >> number;
	
	for(int i = 2; i < number; ++i)
	{	
		{
			if(number % i == 0)
			{
				std::cout << number << " is not a prime number.\n" << std::endl;
				return false;
			}
			std::cout << number << " is a prime number.\n" << std::endl;
			return true;
		}
	}
	
	
	
	//askForInt("Enter a number to factor<0 to quit>.", 1000000, 0);
	
	//cout << isPrime << endl;
	
	//cout << "\n\nThanks for playing." << endl;
	
	return 0;
	
	
	
}





