#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::fixed;

double factorial(unsigned level);
long double fibonacci(unsigned level);

int main()
{
	for(int i = 0; i < 51; ++i)
	{
		cout << "The fibonacci of " << i << " is " << fixed << fibonacci(i) << endl;
	}
	
	return 0;
}
//recursive function
long double fibonacci(unsigned level)
{
	//base case - a case where you do not recurse.
	if(level == 0|| level == 1)
	{
		return 1;
	}
	return fibonacci(level -1 ) + fibonacci(level -2);
}

double factorial(unsigned level)
{
	if(level == 0)
	{
		return -1;//error message
	}
	if(level == 1)
	{
		return 1.0;
	}
	
	return level * factorial(level - 1);// a function that calls itself with different arguments is called a recursive function.
}