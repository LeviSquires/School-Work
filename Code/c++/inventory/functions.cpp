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

bool isEmpty(const std::vector<const std::string*>& in)
{
	for(unsigned i = 0; i < in.size(); ++i)
	{
		if(in[i] != NULL)
		{
			return false;
		}
	}
	return true;
}

bool isFull(const std::vector<const std::string*>& in)
{
	for(unsigned i = 0; i < in.size(); ++i)
	{
		if(in[i] == NULL)
		{
			return false;
		}
		
	}
	return true;
}

bool contains(const std::vector<const std::string*>& in, const std::string* pstr)
{
	for(unsigned i = 0; i < in.size(); ++i)
	{
		if(in[i] != NULL)
		{
			if(*pstr == *in[i])
			{
				return true;
			}
		}
	}
	return false;
}

void display(const std::vector<const std::string*>& in)
{
	for(unsigned i = 0; i < in.size(); ++i)
	{
		if(in[i] != NULL)
		{
			std::cout << *in[i] << std::endl;
		}
	}
}

void add(std::vector<const std::string*>& in, const std::string* pstr)
{
	if(isFull(in) == true)
	{
		std::cout << "Inventory is full!\n";
		return;
	}
	if(contains(in, pstr) == true)
	{
		std::cout << "You already have one of these!\n";
	}
	for(unsigned i = 0; i < in.size(); ++i)
	{
		if(in[i] == NULL)
		{
			in[i] = pstr;
			return;
		}
	}
}

void remove(std::vector<const std::string*>& in, const std::string* pstr)
{
	if(isEmpty(in) == true)
	{
		std::cout << "Nothing to remove!\n";
		return;
	}
	if(contains(in, pstr) == false)
	{
		std::cout << "You can't remove something you don't have!\n";
		return;
	}
	for(unsigned i = 0; i < in.size(); ++i)
	{
		if(in[i] != NULL)
		{
			if(*in[i] == *pstr)
			{
				in[i] = NULL;
				return;
			}
		}
	}
}











