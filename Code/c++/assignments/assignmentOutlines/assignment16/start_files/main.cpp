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

		Matrix n;
		vec.clear();
		vec.push_back(5);
		vec.push_back(-1);
		vec.push_back(-0.5);
		n.AddRow(vec);

		vec.clear();
		vec.push_back(4);
		vec.push_back(3);
		vec.push_back(-2);
		n.AddRow(vec);

		cout << endl << n << endl; 

		Matrix s = m * n;

		cout << endl << "Product Matrix:\n" << s << endl; 



/*
		Matrix m(2, 3, 19.9);
		cout << m << endl; 
		m.AddRow();
		cout << endl << m << endl; 

		std::vector<double> vec;
		vec.push_back(-9.1);
		vec.push_back(87.554);
		vec.push_back(101.4);

		m.AddRow(vec);
		cout << endl << m << endl;

		m.AddColumn();
		cout << endl << m << endl;

		vec.clear();
		vec.push_back(-7.6);
		vec.push_back(39);
		vec.push_back(1.414768);
		vec.push_back(-1);
		m.AddColumn(vec);
		cout << endl << m << endl;


		m.RemoveRow(2);
		cout << endl << m << endl;

		m.RemoveColumn(1);
		cout << endl << m << endl;
*/

	}
	catch(std::exception& ex)
	{
		cerr << ex.what() << endl;
	}



	cin.get();
	return 0;
}

