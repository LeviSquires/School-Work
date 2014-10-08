/*
Setup Game
	Pick a random number between 1 and 100.
while players_guess != randomNumber
begin	
	get a new guess from player
	if players_guess is < random number
	begin
		tell player guess is to low.
	end
	if players_guess is > random number
	begin
		tell player guess is too high
	end
	if players_guess == random number
	begin
		congratulate players and give game stats(guesses and tries left)
	end
	
*/

#include <iostream>
#include "randgen.h"

using std::endl;
using std::cout;
using std::cin;

int main()
{
	cout <<"\tWelcome to Guess my Number!\n\n"
		 <<"I have chosen a number between 1 and 100.\n";
	
	RandGen rg;
	int random = rg(100) + 1;
	int guess;
	int tries = 0;
	
	do
	{
		cout<<"What is my number?";
		cin >> guess;
		++tries;
		if(guess < random)
		{
			cout<<"Your guess is too low. Try again.\n";
		}
		if(guess > random)
		{
			cout <<"your guess is too high. Try again.\n";
		}
		if(guess == random)
		{
			cout<<"You got it in " <<tries <<" guesses.\n";
		}
	}while(random != guess);
	
	return 0;
}