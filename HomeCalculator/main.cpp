#pragma once
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include "MainWindow.h"

using namespace std;

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	MSG msg;

	MainWindow* main_window = new MainWindow(hInstance,"HomeCalculator", 10, 10, 500, 500);
	main_window->show(nCmdShow);
	GetMessage(&msg, NULL, 0, 0);
	main_window->textout("HomeCalculator-������ ������������ �����", 20, 20);


	main_window->loop(msg);// ������������� ������� !!!
	return (int)msg.wParam;
}