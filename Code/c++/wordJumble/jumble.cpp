#include <iostream>
#include <string>
#include "randgen.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

const string WORDS[] = 
{
	"wall",
	"glasses",
	"laboured",
	"jumble",
	"elephant",
	"persistent",
	"helicopter",
	"computer"
};

const unsigned int NUM_WORDS = sizeof(WORDS) / sizeof(WORDS[0]);

int main()
{
	RandGen rg;
	int choice = rg(NUM_WORDS);
	string secretWord = WORDS[choice];
	
	string jumbled = secretWord;
	
	for(unsigned i = 0; i < jumbled.size(); ++i)
	{
		unsigned otherSpace = rg(jumbled.size());
		//swap the letters
		char temp = jumbled[i];
		jumbled[i] = jumbled[otherSpace];
		jumbled[otherSpace] = temp;
	}
	
	cout << "\tWelcome to the Word Jumble!\n\n"
		 << "Unscramble the letters to make a word.\n"
		 << "Enter \'quit\' to quit the game.\n\n"
		 << "The jumble is: " << jumbled;
	
	string guess;
	do
	{
		cout << "\n\nYour Guess: ";
		cin >> guess;
		if((guess != secretWord) && (guess != "quit"))
		{
			cout << "Sorry, but that guess is  incorrect.";
		}
		
	}while((guess != secretWord) && (guess != "quit"));
	if(guess == secretWord)
	{
		cout << "That's it! You guessed correctly!";
	}
	cout << "\nThanks for playing.";
	
	return 0;
}