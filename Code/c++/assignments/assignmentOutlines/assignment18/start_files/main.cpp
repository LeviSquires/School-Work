

#include <iostream>
#include "tree.h"
#include "randgen.h"


int main()
{
  
  Tree tree;
  RandGen rg;
  
  
  int i = 0;
  
  while(i < 10)
  {
    if(tree.Insert(rg(100) - 50))
    {
      ++i;
    }
  }
  
  tree.InOrder(std::cout);
  std::cout << std::endl;
  tree.PreOrder(std::cout);
  std::cout << std::endl;
  tree.PostOrder(std::cout);
  std::cout << std::endl;
  
  
  
  return 0;
}


