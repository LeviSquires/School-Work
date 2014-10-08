#include <iostream>
#include <iomanip>

#include "matrix.h"

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

int main()
{
	try
	{
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

		m.SwitchRows(m, 0, 2);

		cout << endl << m << endl;

		m.SetRowVector(m.AddVectors(m.GetRowVector(0), m.GetRowVector(1)), 1);

		cout << endl << m << endl;

		m.SetRowVector(m.MultiplyRows(m.GetRowVector(0), 3), 0);
		
		cout << endl << m << endl;

	}
	catch(std::exception& ex)
	{
		cerr << ex.what() << endl;
	}

	cin.get();
	return 0;
}

