Instructions for Starting Game
	Get to this file's directory in the command prompt and run the compile command then launch the .exe file.
	
Pseudo Code for Guess my Number:
Start off by greeting the player and introducing the game.

Assign some variables including: 
	int lowNumber = 1;
	int highNumber = 101;
	int totalTurns = 0;
	int guess = (lowNumber + highNumber) / 2;
	guess will be initially set to 50 so that will be the computer's first guess.

Output the computers guess and give the player 3 different responses.
	1 - Too Low
	2 - Too High
	3 - That's my Number
	
Write code that will allow the computer to accurately narrow the range of numbers every guess.
	
	do
	{
	
		if(player input == 1 - Too Low)
		{
			lowNumber = guess;
			guess = (lowNumber + highNumber) / 2;
			cout << guess;
			++totalTurns;
		}
		
		if(player input == 2 - Too High)
		{
			highNumber = guess;
			guess = (highNumber + lowNumber) / 2;
			cout << guess;
			++totalTurns;
		}
	}while(player input != 3 - That's Correct)
	cout << "It only took me " << totalTurns << " to guess your number << endl;
Put all this code into a do while loop so it runs until a correct guess is made.


Small point: You can choose 0 as your number.  You need to be able to limit that.
Question: so how do you know the human is cheating?

98%

	
	
	




