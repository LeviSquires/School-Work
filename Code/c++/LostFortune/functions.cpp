//functions.cpp



#include <sstream>
#include <string>
#include <iostream>
#include <vector>

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












