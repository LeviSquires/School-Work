// RandObject.cpp : Implementation of CRandObject

#include "stdafx.h"
#include "RandObject.h"
#include "randgen.h"

// CRandObject



STDMETHODIMP CRandObject::get_GetANum(long* pVal)
{
	// TODO: Add your implementation code here
	RandGen rg;
	*pVal = rg(100);
	return S_OK;
}
