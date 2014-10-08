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

bool isEmpty(const std::vector<const std::string*>& in);
bool isFull(const std::vector<const std::string*>& in);
bool contains(const std::vector<const std::string*>& in, const std::string* pstr);

void display(const std::vector<const std::string*>& in);
void add(std::vector<const std::string*>& in, const std::string* pstr);
void remove(std::vector<const std::string*>& in, const std::string* pstr);


