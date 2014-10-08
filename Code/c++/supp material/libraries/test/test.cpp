// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <Objbase.h>
#include <Unknwn.h>
#include <iostream>
#include <strsafe.h>

#include "randgen.h"
#include "..\COMServer\COMServer_i.h"


void ShowErrorMessage(LPTSTR lpszFunction);


int main()
{

    //Testing the static library...
    RandGen rg;
    std::cout << "Using the static library: " << rg(100) << std::endl;


    //Testing the dynamic library
    HMODULE hm = LoadLibrary(L"randgen.dll");
    if(hm)
    {
        std::cout << "Module Loaded." << std::endl;
    }
    else
    {
        ShowErrorMessage(L"LoadLibrary");
        return 1;
    }

    void* p = 0;
    p = GetProcAddress(hm, "GetNextRandom");
    if(!p)
    {
        ShowErrorMessage(L"GetProcAddress");
        return 1;
    }
    //convert to a function pointer
    unsigned (*fp)(unsigned);
    fp = static_cast<unsigned (*)(unsigned)>(p);
    std::cout << "Using the dynamic library: " << fp(100) << std::endl;
    FreeLibrary(hm);


    
	//Testing the COM Component
    HRESULT hCOM = CoInitialize(NULL);
    if(hCOM != S_OK)
    {
        std::cerr << "CoInitialize failed with " << GetLastError() << std::endl;
        return 1;

    }
    std::cout << "COM Initialized." << std::endl;

    
    IRandObject* pRand = 0;


    hCOM = CoCreateInstance(__uuidof(RandObject), NULL, CLSCTX_INPROC_SERVER, __uuidof(IRandObject), reinterpret_cast<void**>(&pRand));
    if(hCOM != S_OK)
    {
        ShowErrorMessage(L"CoCreateInstance");

    }
    else
    {        
        long value;
		pRand -> get_GetANum(&value);
        std::cout << "Using the COM component: " << value << std::endl;
        pRand -> Release();
    }

	CoUninitialize();

    std::cin.get();
    
	return 0;
}


void ShowErrorMessage(LPTSTR lpszFunction) 
{ 
    // Retrieve the system error message for the last-error code

    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError(); 

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );

    // Display the error message and exit the process

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, 
        (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR)); 
    StringCchPrintf((LPTSTR)lpDisplayBuf, 
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"), 
        lpszFunction, dw, lpMsgBuf); 
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK); 

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
}

