#pragma once
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include "stdafx.h"

#include "MainWindow.h"

//#include "GuiControl.h"
//#include "OpenGLViewPort.h"
//#include "GuiCheckBox.h"
//#include "GuiEditNum.h"
//#include "GuiComboBox.h"
#include "User_Interface.h"

#include "Roof.h"
#include "HomeCalculator.h"


using namespace std;

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	MSG msg;

	MainWindow* main_window = MainWindow::get_main_window("HomeCalculator", 10, 10, 500, 600);
	main_window->show(nCmdShow);
	

	GetMessage(&msg, NULL, 0, 0);
	main_window->loop(msg);// предпоследн€€ строчка !!!



	
	delete main_window;

	return (int)msg.wParam;
}
