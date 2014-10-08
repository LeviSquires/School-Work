#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int lowNumber = 0;
	int highNumber = 101;
	int totalTurns = 1;
	int guess = (lowNumber + highNumber) / 2;
	int playerInput;
	
	cout << "\t\tWelcome to Guess My Number\n\n"
		 << "Pick a number between 1 and 100.\n";
	
	cout << "Is your number " << guess << "?" << endl;


	do
	{
		
		cout << "\n1 - Too Low.\n"
		 << "2 - Too High.\n"
		 << "3 - That's my number.\n";
		cin >> playerInput;
		if(playerInput == 1)
		{
			lowNumber = guess;
			guess = (lowNumber + highNumber) / 2;
			cout << "Is your number " << guess << "?" << endl;
			++ totalTurns;
		}
		
		if(playerInput == 2)
		{
			highNumber = guess;
			guess = (highNumber + lowNumber) / 2;
			cout << "Is your number " << guess << "?" << endl;
			++totalTurns;
		}
	}while(playerInput != 3);
	
	cout << "I guessed your number in " << totalTurns << " turns." << endl;
			
	return 0;
}