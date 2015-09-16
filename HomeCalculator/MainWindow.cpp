#pragma once
#include <Windows.h>
#include <tchar.h>

#include "MainWindow.h"


MainWindow::MainWindow()
{
}


MainWindow::~MainWindow()
{
	DestroyWindow(this->hWnd);
}

MainWindow::MainWindow(HINSTANCE hInst,const TCHAR* title, int x, int y, int width, int height)
{
	wcex.cbSize = sizeof(WNDCLASSEX);
	
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc =MainWindow::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInst;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName =NULL;
	wcex.lpszClassName = "HomeCalculator";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&wcex);

	hWnd = CreateWindowEx(0,
		"HomeCalculator",
		title,
		WS_OVERLAPPEDWINDOW,
		x,
		y,
		width,
		height,
		NULL,
		NULL,
		hInst,
		NULL);

}

HWND MainWindow::get_hWnd()
{
	return this->hWnd;
}

HINSTANCE MainWindow::get_hinst()
{
	return this->hinst;
}



void MainWindow::loop(MSG messages)
{
	/* Run the message loop. It will run until GetMessage() returns 0 */
	while (GetMessage(&messages, NULL, 0, 0))
	{
		/* Translate virtual-key messages into character messages */
		TranslateMessage(&messages);
		/* Send message to WindowProcedure */
		DispatchMessage(&messages);
	}
}

void MainWindow::show(int cmdShow)
{
	ShowWindow(this->hWnd, cmdShow);
}

void MainWindow::textout(const TCHAR* string, int x, int y)
{
	 int lenght = _tcslen(string);
	 HDC hdc = GetDC(this->hWnd);
	 TextOut(hdc, x, y, string, lenght);
	 ReleaseDC(this->hWnd, hdc);
}