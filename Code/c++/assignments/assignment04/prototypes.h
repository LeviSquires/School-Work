//prototypes.h
//The prototypes for the functions used the factors program
//C++ Assignment 3


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

/*
isPrime is a predicate that will return true if the argument is a prime number 
and false if not.
*/
bool isPrime(unsigned value);

/*
factors will build and return a vector of unsigned integers that are the factors 
of the values passed to it.
*/
std::vector<unsigned> factors(unsigned value);



