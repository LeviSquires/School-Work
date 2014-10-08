#include <iostream>
#include <string>

#include "prototypes.h"

using namespace std;

int main()
{
	welcomePlayer();
	string name = askText("Enter a name: ");
	string noun = askText("Enter a noun: ");
	int number = askForInt("Enter a number; ", 1000, 1);
	string bodyPart = askText("Enter a body part: ");
	string verb = askText("Enter a verb: ");
	tellStory(name, noun, number, bodyPart, verb);
	return 0;
}

