#include <iostream>
#include "tree.h"
#include "randgen.h"


int main()
{
  RandGen rg;
  Tree<double> tree;
  for (unsigned i = 0; i < 10; ++i)
  {
	  tree.Insert(rg.getNormalized());
  }

  std::cout << "Pre Order:\n";
  tree.PreOrder(std::cout);
  std::cout << "\nPost Order:\n";
  tree.PostOrder(std::cout);
  std::cout << "\nIn Order:\n";
  tree.InOrder(std::cout);
  std::cout << std::endl;

  Tree<double> tree2(tree);
  std::cout << "Pre Order:\n";
  tree2.PreOrder(std::cout);
  std::cout << "\nPost Order:\n";
  tree2.PostOrder(std::cout);
  std::cout << "\nIn Order:\n";
  tree2.InOrder(std::cout);
  std::cout << std::endl;

  Tree<double> tree3;
  std::cout << "Pre Order:\n";
  tree3.PreOrder(std::cout);
  std::cout << "\nPost Order:\n";
  tree3.PostOrder(std::cout);
  std::cout << "\nIn Order:\n";
  tree3.InOrder(std::cout);
  std::cout << std::endl;

  tree3 = tree2;
  std::cout << "Pre Order:\n";
  tree3.PreOrder(std::cout);
  std::cout << "\nPost Order:\n";
  tree3.PostOrder(std::cout);
  std::cout << "\nIn Order:\n";
  tree3.InOrder(std::cout);
  std::cout << std::endl;

  std::cin.get();
  
  return 0;
}


