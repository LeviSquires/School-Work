#include <iostream>
#include <string>

#include "critter.h"
#include "prototypes.h"

std::string MENU = "\nCritter Caretaker"
				   "\n-----------------"
				   "\n\n0 - Quit"
				   "\n1 - Listen to Critter"
				   "\n2 - Feed your Critter"
				   "\n3 - Play with your Critter"
				   "\n4 - Ask Critter to perform a trick"
				   "\nChoice:";

int main()
{
	Critter crit;
	
	unsigned choice;
	do
	{
		choice = askForInt(MENU, 4, 0);
		switch(choice)
		{
			case 0:
				std::cout << "Goodbye.\n";
				break;
			case 1:
				crit.talk();
				break;
			case 2:
				crit.eat();
				break;
			case 3:
				crit.play();
				break;
			case 4:
				crit.performTrick();
				break;
		}
	}while(choice != 0);
	
	
	
	return 0;
}