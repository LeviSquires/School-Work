#include <iostream>
#include <sstream>
#include <string>
#include "date.h"

/*
bool operator>(const Date& d1, const Date& d2)
{
	if(d1.getYear() > d2.getYear())
	{
		return true;
	}
	if(d1.getYear() < d2.getYear())
	{
		return false;
	}
	if(d1.getMonth() > d2.getMonth())
	{
		return true;
	}
	if(d1.getMonth() < d2.getMonth())
	{
		return false;
	}
	if(d1.getDay() > d2.getDay())
	{
		return true;
	}
	return false;
}



bool operator==(const Date& d1, const Date& d2)
{
	if(d1.getYear() == d2.getYear() && 
	   d1.getMonth() == d2.getMonth() && 
	   d1.getDay() == d2.getDay())
	{
		return true;
	}
	return false;
}


bool operator>=(const Date& d1, const Date& d2)
{
	return (d1 == d2) || (d1 > d2);
}

bool operator!=(const Date& d1, const Date& d2)
{
	return !(d1 == d2);
}

*/

int askForInt(std::string question, int high, int low)
{
	int ret;
	do
	{
		std::cout << question;
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
