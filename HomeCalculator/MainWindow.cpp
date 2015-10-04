#pragma once
#include <Windows.h>
#include <tchar.h>

#include "MainWindow.h"

MainWindow* MainWindow::base_window = 0;

MainWindow::MainWindow()
{
}


MainWindow::~MainWindow()
{
	this->user_gui->~User_Interface();
	DestroyWindow(this->hwnd);
}

MainWindow::MainWindow(const TCHAR* title, int x, int y, int width, int height)
{
	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = MainWindow::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = GetModuleHandle(NULL);
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "HomeCalculator";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&wcex);

	this->hwnd = CreateWindowEx(0,
		"HomeCalculator",
		title,
		WS_OVERLAPPEDWINDOW,
		x,
		y,
		width,
		height,
		NULL,
		NULL,
		GetModuleHandle(NULL),
		NULL);
	this->hinst = GetModuleHandle(NULL);
	this->user_gui = new User_Interface(this->hwnd);

}

void  MainWindow::add_user_gui(User_Interface* user_gui)
{
	this->user_gui = user_gui;
}

HWND MainWindow::get_hwnd()
{
	return this->hwnd;
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
	ShowWindow(this->hwnd, cmdShow);
	this->user_gui->show(cmdShow);
}

void MainWindow::textout(const TCHAR* string, int x, int y)
{
	int lenght = _tcslen(string);
	HDC hdc = GetDC(this->hwnd);
	TextOut(hdc, x, y, string, lenght);
	ReleaseDC(this->hwnd, hdc);
}

