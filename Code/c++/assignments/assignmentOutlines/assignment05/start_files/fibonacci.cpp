//Start file for c++ assignment 4

#include <iostream>

double fibonacci(unsigned term);

int main()
{
    std::cout << "Term\t\tValue\n"
              << "====\t\t=====\n";
    
    for(unsigned i = 0; i < 51; ++i)
    {
        std::cout << i << "\t\t" << std::fixed << fibonacci(i) << std::endl;
    }
              
    return 0;
}

/*
double fibonacci(unsigned term)
{
    if(term == 0 || term == 1)
    {
        return 1;
    }
    return fibonacci(term - 1) + fibonacci(term - 2);
}
*/

double fibonacci(unsigned term)

