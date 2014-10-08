//prototypes.h


#include <sstream>
#include <string>
#include <iostream>
#include <vector>

/*
askForInt() prompts the user using stdout for an integer value, with the 
question.  The function checks for valid input (stdin) and the range as 
described between high and low (inclusive).
It returns the value entered by the user. 
*/
int askForInt(const std::string& question, int high = INT_MAX, int low = INT_MIN);

void welcomePlayer();
std::string askText(const std::string& question);
void tellStory(const std::string& aName,
			   const std::string& aNoun,
			   int aNumber,
			   const std::string& aBodyPart,
			   const std::string& aVerb);
