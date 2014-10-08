// PacMan.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "PacMan.h"
#include "pm.h"

#define MAX_LOADSTRING 100

#define PI 3.14159265359

const UINT TIMER_ID = 1;

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
VOID CALLBACK TimerProc(HWND hwnd, UINT, UINT_PTR idEvent, DWORD);


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
	LoadString(hInstance, IDC_PACMAN, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PACMAN));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PACMAN));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_PACMAN);
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
      CW_USEDEFAULT, CW_USEDEFAULT, 1260, 1080, NULL, NULL, hInstance, NULL);

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

static HDC memoryHDC;
PacMan pm(300, 272);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
    static int width = 0;
    static int height = 0;

	static UINT timer = TIMER_ID;
	static HBITMAP hbm;


	switch (message)
	{
		case WM_CREATE:
			timer = SetTimer(hWnd, timer, 17,  TimerProc); 
			hdc = GetDC(hWnd);
			pm.Load(hdc);
			memoryHDC = CreateCompatibleDC(hdc);
			
			
			ReleaseDC(hWnd, hdc);
			break;
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
		case WM_KEYDOWN:
			switch(wParam)
			{
				case VK_LEFT:
					pm.SetVX(-5);
					break;
				case VK_RIGHT:
					pm.SetVX(5);
					break;
				case VK_DOWN:
					pm.SetVY(5);
					break;
				case VK_UP:
					pm.SetVY(-5);
					break;
			}

			break;
		case WM_KEYUP:
			switch(wParam)
			{
				case VK_LEFT:
				case VK_RIGHT:
					pm.SetVX(0);
					break;
				case VK_DOWN:
				case VK_UP:
					pm.SetVY(0);
					break;
			}

			break;
	    case WM_PAINT:

		    hdc = BeginPaint(hWnd, &ps);
			
            {
				SetGraphicsMode(hdc, GM_ADVANCED);
				SetMapMode(hdc, MM_ISOTROPIC);
				SetWindowExtEx(hdc, 630, 540, NULL);
				SetViewportExtEx(hdc, 1260, 1080, NULL); 
				BitBlt(hdc, 0, 0, 630, 540, memoryHDC, 0, 0, SRCCOPY);
            }
			
		    EndPaint(hWnd, &ps);
		    break;
	    case WM_DESTROY:
			DeleteDC(memoryHDC);
			DeleteObject(hbm);

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

VOID CALLBACK TimerProc(HWND hwnd, UINT, UINT_PTR idEvent, DWORD)
{
	static HBITMAP hbm;
	if(idEvent == TIMER_ID)
	{
//		InvalidateRect(hwnd, NULL, TRUE);



		HDC hdc = GetDC(hwnd);
		SetGraphicsMode(hdc, GM_ADVANCED);
		SetMapMode(hdc, MM_ISOTROPIC);
		SetWindowExtEx(hdc, 630, 540, NULL);
		SetViewportExtEx(hdc, 1260, 1080, NULL); 
		hbm = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BACKGROUND));
		SelectObject ( memoryHDC, hbm );
		pm.Update();
		pm.Draw(memoryHDC);

		BitBlt(hdc, 0, 0, 630, 540, memoryHDC, 0, 0, SRCCOPY);
		ReleaseDC(hwnd, hdc);
	}
}