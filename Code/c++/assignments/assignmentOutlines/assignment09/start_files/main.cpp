#include <iostream>
#include <fstream>

#include "list.h"
#include "randgen.h"


int main()
{

	List lst;
	RandGen rg;
	
	for(unsigned i = 0; i < 10; ++i)
	{
		lst.PushBack(rg(100) - 50);
	}
	for(unsigned i = 0; i < 10; ++i)
	{
		lst.PushFront(rg(100) - 50);
	}

	
	{
	//Uncomment the next line to trigger a crash
//		List lst2 = lst;
	}
	
	{
	//Uncomment the next two lines to trigger a crash
		List lst2;
		lst2 = lst;
	}
	
	
    return 0;
}

