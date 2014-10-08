//prototypes.h


#include <sstream>
#include <string>
#include <iostream>
#include <vector>

class Board;

/*
askForInt() prompts the user using stdout for an integer value, with the 
question.  The function checks for valid input (stdin) and the range as 
described between high and low (inclusive).
It returns the value entered by the user. 
*/
int askForInt(const std::string& question, int high = INT_MAX, int low = INT_MIN);


std::pair<unsigned, unsigned> GetMove(const Board& b);

