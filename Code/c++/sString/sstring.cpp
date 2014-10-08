#include <cstring>
#include <iostream>

#include "sstring.h"

StupidString::StupidString(const char* p)
{
	if(!p)
	{
		_pData = NULL;
		_capacity = 0;
		return;
	}
	//This is a new array
	_pData = new char[_capacity + 1];// plus 1 for zero at end of string
	_capacity = strlen(p);
	if(_capacity == 0)
	{
		_pData = NULL;
		return;
	}
	strcpy(_pData, p);
}

StupidString::StupidString(unsigned len, char ch) : _pData(new char[len + 1]),
													_capacity(len)
{
	for(unsigned i = 0; i < _capacity; ++i)
	{
		_pData[i] = ch;
	}
	_pData[_capacity] = '\0'; //This is the same as just zero
}

StupidString::~StupidString()
{
	delete [] _pData; //This is an array delete because new array was used.
	std::cout << "StupidString::~StupidString() is called." << std::endl;

}

StupidString::StupidString(const StupidString& str)
{
	if(str.isEmpty())
	{
		_pData = NULL;
		_capacity = 0;
		return;
	}
	_capacity = str._capacity;
	_pData = new char[_capacity + 1];
	strcpy(_pData, str._pData);
}

StupidString& StupidString::operator=(const StupidString& str)
{
	//There are 2 StupidString objects here one is the argument for the function and because this is a member function there is 
	//an implied function on which this function is being called.
	//"this" is a pointer to that object.
	
	//Check for self assignment
	if(this== &str)
	{
		return *this;
	}
	//if we get this far we know they are 2 different objects.
	
	_capacity = str._capacity;
	delete [] _pData;
	if(_capacity == 0)
	{
		_pData = NULL;
		return *this;
	}
	_pData = new char[_capacity + 1];
	strcpy(_pData, str._pData);
	return *this;
	
}