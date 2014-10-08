#include <iostream>

#include "sstring.h"

int main()
{
	StupidString str("This is a stupid string.");
	std::cout << str.data() << std::endl;

	{
		StupidString str2(str);
		std::cout << str2.data() << std::endl;
	}
	{
		StupidString s;
		s = str;
		std::cout << s.data() << std::endl;
	}
	
	return 0;
}