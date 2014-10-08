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

/*bool isPrime(unsigned value)
	{
		int& num = askForInt(); 
		for(int i = 2; i < num; ++i)
		{
			if(num % i == 0)
			{
				std::cout << num << " is not a prime number.\n" << std::endl;
				return false;
			}
			std::cout << num << " is a prime number.\n" << std::endl;
			return true;
		}
	}








/*std::vector<unsigned> factors(unsigned value)
{
	std::vector<unsigned> ret;
	return ret;
}
*/
