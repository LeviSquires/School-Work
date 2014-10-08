#include <iostream>
#include <string>

template <class T>
void swap(T& r1, T& r2)
{
	T temp = r1;
	r1 = r2;
	r2 = temp;
}

template <typename S>
S Accumulate(S* array, unsigned size)
{
	S ret = array[0];
	for(unsigned i = 1; i < size; ++i)
	{
		ret += array[i];
	}
	return ret;
}

int main()
{
	int x = 9;
	int y = -42;
	
	std::cout << "The value of x is: " << x << ". The value of y is: " << y << ".\n";
	
	swap(x, y);
	std::cout << "The value of x is: " << x << ". The value of y is: " << y << ".\n";
	
	std::string c = "Levi";
	std:: string d = "Squires";
	std::cout << "The value of c is: " << c << ". The value of d is: " << d << ".\n";
	
	swap(c, d);
	std::cout << "The value of c is: " << c << ". The value of d is: " << d << ".\n";

	double doubleArray[] = {2, -7.4, 8.6, 33.79, -101.4};
	
	std::cout << "Accumulated value is: " << Accumulate(doubleArray, 5) << std::endl;

	std::string text[] =
	{
		"First String ",
		"Second String ",
		"Third String"
	};
	std::cout << "Accumulated value is: " << Accumulate(text, 3) << std::endl;

	


	return 0;
}