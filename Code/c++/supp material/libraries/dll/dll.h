// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif


// This class is exported from the dll.dll
class DLL_API Cdll {
public:
	Cdll(void);
	// TODO: add your methods here.
};


extern DLL_API int ndll;

extern "C"
{
DLL_API unsigned int GetNextRandom(unsigned limit);
}