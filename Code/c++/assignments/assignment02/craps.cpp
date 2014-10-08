#include <iostream>
#include <string>

#include "randgen.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string firstName;
	int bet;
	RandGen rg;
	int dice = (rg(6) + 1) + (rg(6) +1);
	int dice2 = (rg(6) + 1) + (rg(6) +1);
	
    
	cout << "Welcome to Craps!\n\n"
		 << "In craps the player rolls two dice if the first roll is a 7 or an 11 the player wins.\n"
		 << "However if the player rolls 2, 3 or 12 the player losses and the house collects the bet.\n"
		 << "If nones of those number are rolled the player continues to roll the dice until they get their original roll or a 7.\n"
		 << "If they roll their original number they win and if they roll a 7 the house collects their bet.\n"
		 << "Enjoy the game!\n"
		 << "Enter first name: ";
	cin >> firstName;
	cout << "Let's begin by entering a starting bet.\n";
	cout << "Enter starting bet: $";
	cin >> bet;
	cout << "All right let's roll the dice for the first time.\n";
	
	cout << "You first roll is a " << dice << endl;

	if(dice == 7 || dice == 11)
	{
		cout << "\nCongratulations you've won!\n";
		cout << "You won $" << bet * 2;
		return 0;
	}
	if(dice == 2 || dice == 3 || dice == 12)
	{
		cout << "\nSorry, but the house has won this round."
			 << "\nYou lost your bet of $" << bet;
	}
	else/*(dice == 4 || dice == 5 || dice == 6 || dice == 8 || dice == 9 || dice ==10)*/
	{
		do
		{
			dice2 = (rg(6) + 1) + (rg(6) +1);
			cout << "Your next roll is a " << dice2 << endl;
			
			if(dice2 == dice)
			{
				cout << "\nCongratulations you've won!\n"
				     << "You won $" << bet * 2;
				return 0;
			}
		}while(dice2 != 7);
		cout << "\nSorry, but the house has won this round."
		     << "\nYou lost your bet of $" << bet;
	}
	
	return 0;
};




