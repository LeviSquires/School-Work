/*
psuedo code
	create a group of words to use.
	pick one word at random from selection to be secret word.
display how many guesses left and what letters have been guessed.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

#include "randgen.h"

using namespace std;

const int MAX_WRONG = 8;

int main()
{
	vector<string> words;
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	words.push_back("TOMATO");
	words.push_back("LOCOMOTIVE");
	
	RandGen rg;
	random_shuffle(words.begin(), words.end(), rg);
	
	const string THE_WORD = words[0];
	
	int wrong = 0;
	
	string soFar(THE_WORD.size(), '-');
	string used;
	
	cout << "\n\t\tWelcome to Hangman! Good luck!\n\n";
	
	while((wrong < MAX_WRONG) && (soFar != THE_WORD)) 
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong)
			 << " incorrect guesses left.\n"
			 << "You have used the following letters: " << used
			 << "\nSo far the word is: " << soFar << endl;
		
		char guess;
		cout << "\n\nEnter your next guess: ";
		cin >> guess;
		guess = toupper(guess);
		while(used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed" << guess 
				 << " Guess again.";
			cin >> guess;
		}
		used += guess;
		
		if(THE_WORD.find(guess) != string::npos)
		{
			cout << "That's right, " << guess << " is in the word.\n";
			for(unsigned i = 0; i < THE_WORD.size(); ++i)
			{
				if(THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry " << guess << " is not part of the word.\n";
			wrong++;
		}
	}//end of game loop.
	
	if(wrong == MAX_WRONG)
	{
		cout << "\nYou have been hanged!";
	}
	else
	{
		cout << "\nYou guessed it congrats!";
	}
	cout << "\nThe word was " << THE_WORD << endl;
	
	return 0;
}