#include <iostream>
#include <vector>
#include <algorithm>

#include "randgen.h"

int main()
{
	RandGen rg;
	std::vector<unsigned> numbers;
	for(unsigned i = 0; i < 100; ++i)
	{
		numbers.push_back(rg(100));
	}
	for(std::vector<unsigned>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << " ";
	}
	
	std::cout << "\n\nSorting the vector.\n";
	std::sort(numbers.begin(), numbers.end());
	for(std::vector<unsigned>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << " ";
	}
	
	std::cout << "\n\nShuffling the vector.\n";
	std::random_shuffle(numbers.begin(), numbers.end(), rg);// passing in rg allows the function to use our randgen.
	for(std::vector<unsigned>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << " ";
	}
	
	return 0;
}