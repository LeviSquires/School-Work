// dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "dll.h"
#include "randgen.h"


// This is an example of an exported variable
DLL_API int ndll=0;

// This is an example of an exported function.
DLL_API unsigned int GetNextRandom(unsigned limit)
{
    RandGen rg;
	return rg(limit);
}

// This is the constructor of a class that has been exported.
// see dll.h for the class definition
Cdll::Cdll()
{
	return;
}
