#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void func();
//char askYesNo(); //if both functions have the same name but have different ARG lists its called function overloading.
char askYesNo(string question = "Please enter \'y\' or \'n\': ");

int askNumber(int high, int low = 1);

int main()
{
	int number = askNumber(5);
	cout << "Thanks for entering: " << number << endl;
	
	/*
	int var = 5;
	cout << "In main(), the value of var is: " << var << endl;
	func();
	cout << "Back in main(), the value of var is: " << var << endl;
	
	{
		cout << "In main(), in the new scope, the value of var is: " << var << endl;
		int var = 10;
		cout << "In the new scope the value of var is: " << var << endl;
	}
	cout << "In main after the scope the value of var is: " << var << endl;
	



	char answer1 = askYesNo();
	cout << "Thanks for answering " << answer1 << endl;
	
	//argument to function: "Do you want to save the game?\'y\' or \'n\'"
	//char answer2 = askYesNo("Do you want to save the game?\'y\' or \'n\'");
	//cout << "Thanks for answering " << answer2 << endl;
*/
	return 0;
}

int askNumber(int high, int low)
{
	int num;
	do
	{
		cout << "Please enter a number (" << low << "-" << high << "):";
		cin >> num;
	}while(num > high || num < low);
	return num;
}

void func()
{
	int var = -5;
	cout << "In func() the value of var is: " << var << endl;
}


/*
char askYesNo()
{
	char response;
	do
	{
		cout << "please enter \'y\' or \'n\': ";
		cin >> response;
	}while(response != 'y' && response != 'n');
	return response;//required to return a char from this function
}
*/
char askYesNo(string question)//function parameter 
{
	char response; //this is a local variable
	do
	{
		cout << question;
		cin >> response;
		
	}while(response != 'y' && response != 'n');
	return response;
}