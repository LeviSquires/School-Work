INSTRUCTIONS FOR PLAYING	
	To start this game simply get to the directory the game file is stored in with the command prompt
	then use the nmake command to compile all files and run the newly created .exe file.

Pseudo Code
	Introduce the game and explain game rules then ask player for their first name. 
	Then have player enter a staring bet and proceed to the first dice roll.
	Have different outcomes depending on the roll of the dice.
		rolling a 7 or 11.	
			player wins.
		rolling 2, 3, 12.
			player loses.
		player rolls 4, 5, 6, 8, 9, 10.
			player rolls again until roll = first roll or roll = 7.
			
			
Bonus Pseudo Code
	Use initial game code.
	Remove betting and player name features.
	Add a constant to simulate x amount of games(total games).
		Use a for loop to implement all these games.
			GAMES_TOTAL = 10,000
			for(int games = 0; games <= GAMES_TOTAL; ++games)
			{
				all code for simulating game here.
				also include code to increment house and players wins by one 
				depending on outcome of each round.
			}
	After simulation of games is complete:
		display average player and average house wins.
			
			int averagePlayerWins = total player wins / GAMES_TOTAL.
				cout << averagePlayerWins
			
			int averageHouseWins = total house wins / GAMES_TOTAL.
				cout << averageHouseWins
		
		display average rolls per turn.
			int averageRolls = total rolls / total games.
				cout << averageRolls
				
				
I was able to accomplish everything including the bonus.

Your logic for rolling the dice is not correct.  It also shows in your bonus because 
your percentages are way off.

int die1 = rg(6) + 1;
int die2 = rg(6) + 1;
int total = die1 + die2;

I suspected something when you didn't show the roll for each individual die.

With bonus 90%






	
