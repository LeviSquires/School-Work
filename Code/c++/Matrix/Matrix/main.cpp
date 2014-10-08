#include <iostream>
#include <iomanip>

#include "Matrix.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	try
	{
		/*
		double inc = 2.1234567;
		double total = 21.234567;
		double acc = 0;
		for (unsigned i = 0; i < 10; ++i)
		{
		acc += inc;
		}
		if (FuzzyEquals(acc, total) == true)
		{
		cout << "Math works!" << endl;
		}
		else
		{
		cout << "Math doesn't work!" << endl;
		}
		
		Matrix m(2, 6, 19.9);
		cout << m << endl;
		m.AddRow();
		cout << endl << m << endl;

		std::vector<double> vec;
		vec.push_back(-3.9);
		vec.push_back(25);
		vec.push_back(8);
		vec.push_back(-25);
		vec.push_back(100);
		vec.push_back(11.25);

		m.AddRow(vec);

		cout << endl << m << endl;

		m.RemoveColumn(2);

		cout << endl << m << endl;
		*/

		Matrix m;

		std::vector<double> vec;
		vec.push_back(4);
		vec.push_back(1);
		vec.push_back(9);
		m.AddColumn(vec);
		vec.clear();
		vec.push_back(5);
		vec.push_back(2);
		vec.push_back(-9);
		m.AddColumn(vec);
		cout << endl << m << endl;

		Matrix n;
		vec.clear();
		vec.push_back(5);
		vec.push_back(1);
		vec.push_back(-0.5);
		n.AddRow(vec);
		vec.clear();
		vec.push_back(4);
		vec.push_back(3);
		vec.push_back(-2);
		n.AddRow(vec);
		cout << endl << n << endl;

		Matrix s = m * n; 
		cout << endl << "Product Matrix.\n" << s << endl;

	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << endl;
	}

	cin.get();
	return 0;
	
}