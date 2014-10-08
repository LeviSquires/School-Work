// WinDemo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WinDemo.h"

#define MAX_LOADSTRING 100

#define PI 3.14159265359

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
double PlotFunction(double d);


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WINDEMO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDEMO));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDEMO));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WINDEMO);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
    static int width = 0;
    static int height = 0;

	switch (message)
	{
    	case WM_COMMAND:
	    	wmId    = LOWORD(wParam);
		    wmEvent = HIWORD(wParam);
		    // Parse the menu selections:
		    switch (wmId)
		    {
		    case IDM_ABOUT:
			    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			    break;
		    case IDM_EXIT:
			    DestroyWindow(hWnd);
			    break;
		    default:
			    return DefWindowProc(hWnd, message, wParam, lParam);
		    }
		    break;
        case WM_SIZE:
            width = LOWORD(lParam);
            height = HIWORD(lParam);
            break;
	    case WM_PAINT:
		    hdc = BeginPaint(hWnd, &ps);
            {
                if(height > 105 && width > 45)
                {
                    int midx = width / 2;
                    int midy = height / 2;
                    HPEN hPen = CreatePen(PS_SOLID, 4, COLORREF(RGB(255, 127, 0)));
                    HGDIOBJ hOldPen = SelectObject(hdc, hPen);

                    MoveToEx(hdc, 20, midy, NULL);
                    LineTo(hdc, width - 20, midy);

                    MoveToEx(hdc, midx, 50, NULL);
                    LineTo(hdc, midx, height - 50);

                    double pixels = width - 40;
                    double xsizeFactor = pixels / 2;
                    double ysizeFactor = -(midy - 50);
                    for(int pixelIndex = 0; pixelIndex <=  pixels; ++pixelIndex)
                    {
                        double domainValue = (pixelIndex - (midx - 20)) / xsizeFactor;
                        int xPos = 20 + pixelIndex;
                        double rangeValue = PlotFunction(domainValue * PI) * ysizeFactor;
                        int yPos = midy + static_cast<int>(rangeValue);
                        SetPixel(hdc, xPos, yPos, COLORREF(RGB(0, 0, 255)));
                    }

                    SelectObject(hdc, hOldPen);
                    DeleteObject(hPen);
                }
            }
		    EndPaint(hWnd, &ps);
		    break;
	    case WM_DESTROY:
		    PostQuitMessage(0);
		    break;
	    default:
		    return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

double PlotFunction(double d)
{
    return sin(d);
}
