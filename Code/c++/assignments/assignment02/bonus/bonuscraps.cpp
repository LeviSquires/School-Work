#include <iostream>
#include <string>

#include "randgen.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	float GAMES_TOTAL = 100000;
	float gamesPlayed = 0;
	RandGen rg;
	int dice = (rg(6) + 1) + (rg(6) +1);
	int dice2 = (rg(6) + 1) + (rg(6) +1);
	float pWins = 0;
	float hWins = 0;
	int totalRolls = 0;
	
	for(gamesPlayed; gamesPlayed <= GAMES_TOTAL;)
	{
		dice = (rg(6) + 1) + (rg(6) +1);
		//cout << "You rolled a " << dice << endl;
		++totalRolls;

		if(dice == 7 || dice == 11)
		{
			++pWins;
			++gamesPlayed;
			continue;
			
		}
		if(dice == 2 || dice == 3 || dice == 12)
		{
			++hWins;
			++gamesPlayed;
			continue;
		}
		else
		{
			do
			{
				dice2 = (rg(6) + 1) + (rg(6) +1);
				//cout << "You rolled a " << dice2 << endl;
				++totalRolls;
				
				if(dice2 == dice)
				{
					++pWins;
					++gamesPlayed;
					continue;
					return 0;
				}
			}while(dice2 != 7);
			++hWins;
			++gamesPlayed;
			continue;
			
		}
		
	}
	
	
	float averagePlayerWins = pWins / GAMES_TOTAL * 100;
	float averageHouseWins = hWins / GAMES_TOTAL * 100;
	float averageRollsPerRound = totalRolls / GAMES_TOTAL;
		
	cout << "After playing " << GAMES_TOTAL << " rounds of craps the stats are as follow.\n";
	cout << "average player wins " << averagePlayerWins << "%" << endl;
	cout << "average house wins " << averageHouseWins << "%" << endl;
	cout << "average rolls per round " << averageRollsPerRound << endl;
	
	return 0;
}
