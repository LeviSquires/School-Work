/*Lost Fortune - a text based RPG.*/

#include <iostream>
#include <string> //needed for C++ string objects.
#include "prototypes.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int GOLD_PIECES = 900;

int main()
{
	string leader;
	int adventurers = askForInt("Enter a positive number: ", 50, 2);
	int killed = askForInt("Enter a positive number less than the first: ", adventurers - 1, 0);
	
	cout << "\tWelcome to LostFortune\n\n" 
		 << "Please enter the following for a personalized adventure"
		 << "Enter your last name:";
	cin >> leader;
	cout << "Enter a positive number:";
	cin >> adventurers;
	cout << "Enter a positive number less than the first";
	cin >> killed;
	
	//calculate new values
	int survivors = adventurers - killed;
	int extraGoldPieces = GOLD_PIECES % survivors;
	
	cout << endl <<"The Brave " << leader
				 <<" led a group of " << adventurers
				 <<" adventurers on a quest.\n"
				 <<"They fought a band of ogres and lost "
				 << killed <<" ...only " << survivors
				 <<" survived,\n" <<"The party was about to give up "
				 << "when they stumbled upon a\nburied treasure of "
				 << GOLD_PIECES <<" gold pieces."
				 << " They split the loot and\n"
				 <<leader << " kept the extra " << extraGoldPieces
				 << " gold pieces to keep things fair.";
	
	return 0;
}
