#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

int main()
{
	int * pAPointer = NULL;//declares a pointer. Pointers assigned nothing or that point to an invalid location are called: Dangling Pointers.
	int * pScore = 0;//pointers assigned to zero point "nowhere".
	int score = 1000;
	
	pScore = &score;//& sign means get address of that variable.
	
	cout << "Assigning the address of pScore to score.\n";
	cout << "The address of score is: " << &score << endl;
	cout << "The value of pScore is: " << pScore << endl;
	cout << "The value of score is: " << score << endl;
	cout << "The value of score through pScore is: " <<*pScore << endl;
	cout << "The value of pAPointer is: " << pAPointer << endl;
	if(pAPointer != NULL)
	{
		cout << "The value that pAPointer points to is: " << *pAPointer << endl;
		*pAPointer = 300;
	}
	cout << "Adding 500 to score:\n";
	score += 500;
	cout << "The value of score is: " << score << endl;
	cout << "The value of *pScore is: " << *pScore << endl;
	
	cout <<"Adding 500 to what pScore points to:\n";
	*pScore += 500;
	cout << "The value of score is: " << score << endl;
	cout << "The value of *pScore is: " << *pScore << endl;
	
	cout << "The size of an int pointer is: " << sizeof(int*) << endl;
	cout << "The size of an int pointer pointer is: " << sizeof(int**) << endl;
	cout << "The size of a double pointer is: " << sizeof(double*) << endl;
	
	int newScore = 5000;
	cout << "Declaring a newScore variable...\n";
	pScore = &newScore;
	cout << "pScore is: " << pScore << endl;
	cout << "The value that pScore points to is: " << *pScore << endl;
	cout << "newScore is: " << newScore << endl;
	
	cout << "Declaring a string object called str and a pointer to it.\n";
	string str("score");
	string * pstr = &str;
	
	cout << "The value of str is: " << str << endl;
	cout << "The value of pstr is: " << pstr << endl;
	cout << "The value of what pstr points to(*pstr) is; " << *pstr << endl;
	
	cout << "The size of the string str is; " <<str.size() << endl;
	cout << "Accesing the string through the pointer : " << (*pstr).size() << endl;
	cout << "Doing the same thing using arrow notation: " << pstr -> size() << endl;
	
	return 0;
}