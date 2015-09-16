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
#include "GuiControl.h"

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
 	//**********TEST GUI ************************************************
	
	GuiControl* OK_button = new GuiControl("BUTTON", "������", main_window->get_hWnd(),225,430, 50, 20,
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
	OK_button->show(nCmdShow);
	GuiControl* Edit = new GuiControl("EDIT", "���� ������", main_window->get_hWnd(), 50, 50, 200, 20,
		WS_BORDER | WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL);
	
	Edit->show(nCmdShow);

	

	main_window->textout("HomeCalculator-������ ������������ �����", 20, 20);

	//************************TEST GUI ****************************************

	GetMessage(&msg, NULL, 0, 0);
	main_window->loop(msg);// ������������� ������� !!!
	return (int)msg.wParam;
}