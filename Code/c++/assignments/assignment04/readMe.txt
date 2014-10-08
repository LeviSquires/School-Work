Instructions for running this program:
	Simply get to this file's directory then run the nmake command to compile all files. 
	Then run the .exe file to start the program.
	
Pseudo Code:
	Welcome player and introduce game.
	Using the askForInt function create a input text field that 
	prompts the user for a number to factor or lets them quit by pressing zero.
	
	Fill in the isPrime function we were given.
		bool isPrime(unsigned int number& = askForInt)//the number entered from the askForInt function
		{
			for(int i =2; i < number)
			{
				if(number % i == 0)
				{
					return false;
					++i;
				}
				return true;
			}
		}
	For factors 
	for(int i = 2; i < number)
	{
		if(isPrime = true && number % i == 0)
		{
			factor = number
		}
	}
		
		
I had trouble getting the factor function to work and wasn't able to get isPrime function to use the value from askForInt. 
This program uses a cin in command to get a number from a player and then tells them if its prime or not.
	