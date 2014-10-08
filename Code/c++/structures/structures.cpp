/*
Turing complete language:
	1. Sequence of execution
		Through order of statements
	2. Selection - execute code based on some condition. 
		Through if statements and switch constructs(and another method we will talk about).
	3. Iteration - execute code repeatedly until a certain condition is met.
		for loop, while loop and the do while loop.
*/
#include <iostream>
#include <string>

int main()
{
	/*std::string str = "42";
	int i = 42;
	//will not work, must compare same data types.
	if(str == i)
	{
	}
	*/
	
	std::cout <<"Difficulty Levels\n\n";
	std::cout <<"1-easy\n"
			  <<"2-normal\n" 
			  <<"3-hard\n";
	
	int choice;
	std::cin >> choice;
	
	switch(choice)
	{
		case 1:
			std::cout <<"You picked easy.\n";
			break;
		case 2:
			std::cout <<"You picked normal.\n";
			break;
		case 3:
			std::cout <<"You picked hard.\n";
			break;
		default:
			std::cout <<"Invalid choice.\n";
			break;
	}
	
	
	
/*	int score;
	std::cout <<"Enter your score:";
	std::cin >> score;
	
	if(score >= 1000)
	{
		std::cout <<"Impressive you scored perfect!\n";
	}
	else
	{
		if(score >= 500)
		{
			std::cout <<"You scored 500 or more.\n";
		}
		else
		{
			if(score >=250)
			{
				std::cout <<"You scored 250 or more.\n";
			}
			else
			{
				std::cout <<"You scored less than 250 loser.\n";
			}
		}
	}
	
	if(true)
	{
		std::cout <<"This will always be displayed";
	}
	if(false)
	{
		std::cout <<"This will never be displayed";
	}
	int score = 1000;
	if(score)// if score does not = 0
	{
		std::cout <<"At least you didn't score 0.\n";
	}
	if(score >= 250)
	{
		std::cout <<"You scored greater than 250.\n";
	}
	if(score >= 500)
	{
		std::cout <<"You scored greater than 500.\n";
	}
	if(score >=1000)
	{
		std::cout <<"Impressive you scored perfect!\n";
	}*/
	return 0;
}