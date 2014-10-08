// dllmain.h : Declaration of module class.

class CCOMServerModule : public ATL::CAtlDllModuleT< CCOMServerModule >
{
public :
	DECLARE_LIBID(LIBID_COMServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_COMSERVER, "{C8AD0122-CE72-433B-B54C-5ABDA08184E4}")
};

extern class CCOMServerModule _AtlModule;
