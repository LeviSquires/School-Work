#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void Swap(int& val1, int& val2);
void Swap(int* p1, int* p2);
void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void display(const vector<string>& inventory);

//double& oops();

int main()
{
	int x = 7;
	int y = 9;
	
	cout << "x: " << x << ", y; " << y << endl;
	Swap(&x, &y);
	cout << "x: " << x << ", y; " << y << endl;
	/*
	vector<string> in;
	in.push_back("sword");
	in.push_back("armour");
	in.push_back("shield");
	
	display(in);
	

	*/
	
	/*
	int x = 7;
	int y = 9;
	
	//int& r = x;//This is a reference. A different name for the same chunk of memory. References need to be bound to variables or constants.
	const int& r2 = 7; //Cannot change value of r2 and you cannot bind a variable reference to a constant.
	cout << "x: " << x << ", y; " << y << endl;
	Swap(x, y);
	cout << "x: " << x << ", y; " << y << endl;
	*/
	return 0;
}




void display(const vector<string>& inventory)
{
	cout << "Your Items:\n";
	for(vector<string>::const_iterator it = inventory.begin(); it != inventory.end(); ++it)
	{
		cout << *it << endl;
	}
}


void Swap(int& val1, int& val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}