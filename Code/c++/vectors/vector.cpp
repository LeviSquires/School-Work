#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector <string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armour");
	inventory.push_back("shield");
	
	cout << "You have " << inventory.size() << " items in your inventory.\n";
	
	cout << "Your inventory includes:\n";
	//using iterators for loops.
	for(vector<string>::iterator it = inventory.begin(); it != inventory.end(); ++it)
	{
		cout << *it << endl; //dereferencing the iterator.
	}
	
	/*
	//using indexing for loops.
	for(unsigned i = 0; i < inventory.size(); ++i)
	{
		cout << inventory[i] << endl;
	}
	*/
	cout << "\nYou trade your sword for a battle axe.\n";
	inventory[0] = "battle axe";
	cout << "Your new inventory includes:\n";
	for(unsigned i = 0; i < inventory.size(); ++i)
	{
		cout << inventory[i] << endl;
	}
	
	//cout << "\nThe first item has " << inventory[0].size() << " letters in it.\n\n";
	//cout << "\nThe first item has " << (*inventory.begin()).size() << " letters in it.\n\n";
	cout << "\nThe first item has " << inventory.begin() -> size() << " letters in it.\n\n";
	
	cout << "Your shield is destroyed in a battle.\n";
	inventory.pop_back();
	cout << "Your new inventory includes:\n";
	for(unsigned i = 0; i < inventory.size(); ++i)
	{
		cout << inventory[i] << endl;
	}
	
	cout << "\nYou were robbed of all your belongings by a thief.\n";
	inventory.clear();
	if(inventory.empty())
	{
		cout << "\nYou have nothing left.\n";
	}
	else
	{
		cout << "You have at least one item left.\n";
	}
	
	return 0;
}
