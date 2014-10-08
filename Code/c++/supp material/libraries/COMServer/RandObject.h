// RandObject.h : Declaration of the CRandObject

#pragma once
#include "resource.h"       // main symbols



#include "COMServer_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CRandObject

class ATL_NO_VTABLE CRandObject :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRandObject, &CLSID_RandObject>,
	public IDispatchImpl<IRandObject, &IID_IRandObject, &LIBID_COMServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CRandObject()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RANDOBJECT)


BEGIN_COM_MAP(CRandObject)
	COM_INTERFACE_ENTRY(IRandObject)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(get_GetANum)(long* pVal);
};

OBJECT_ENTRY_AUTO(__uuidof(RandObject), CRandObject)
