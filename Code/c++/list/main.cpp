#include <iostream>

#include "list.h"

int main()
{
	List lst;
	
	lst.PushFront(5);
	lst.PushBack(-7);
	lst.PushBack(44);
	lst.PushFront(-9);
	
	std::cout << "List size is: " << lst.Size() << std::endl;
	lst.Display(std::cout);
	
	lst.Clear();
	std::cout << "\nList size is: " << lst.Size() << std::endl;
	lst.Display(std::cout);
	
	
   return 0;
}

