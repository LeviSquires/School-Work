//functions.cpp



#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <regex>

#include "board.h"

int askForInt(const std::string& question, int high, int low)
{
	int ret;
	do
	{
		std::cout << question  << std::endl;
		std::string str;
		std::getline(std::cin, str);
		std::stringstream ss(str);
		ss >> ret;
		if((ss) && (ret >= low && ret <= high))
		{
			break;
		}
		else
		{
			std::cout << "Try Again." << std::endl;
			continue;
		}
		
	}while(true);
	return ret;
}


std::pair<unsigned, unsigned> GetMove(const Board& b)
{
	//Build a regular expression for a chess move.  Not fully PGN compliant:
	//<start square> <end square>
	//Each square is <letter><number>
	unsigned long long positions = b.GetAllPieces();
    std::string moveExpression("[a-h][1-8] [a-h][1-8]");
	std::regex r(moveExpression);
	unsigned start = 0;
	std::string get;
	bool startOK = false;
	do
	{
		//check to see if the input is in the proper format.
		std::cout << "Enter a move (<start square> <end square>): ";
		bool goodInput = false;
		do
		{
			std::getline(std::cin, get, '\n');
			if(std::regex_search(get, r) == false)
			{
				std::cout << "Didn't quite understand that.  Try again: ";
			}
			else
			{
				goodInput = true;
			}
		}while(goodInput == false);
		//Check to see if the first square actually has a piece on it.
		unsigned rank = (get[1] - '1') * 8;
		rank = 56 - rank;
		start = (get[0] - 'a') + rank;
		unsigned long long mask = 1ULL;
		mask <<= start;
		if(mask & positions)
		{
			startOK = true;
		}
		else
		{
			std::cout << "There  is no piece on " << get.substr(0, 2) << std::endl;
		}
	}while(startOK == false);
	//destination square.  NOT following the rules of chess.
	unsigned rank = (get[4] - '1') * 8;
	rank = 56 - rank;
	unsigned end = (get[3] - 'a') + rank;
	return std::make_pair(start, end);
}












