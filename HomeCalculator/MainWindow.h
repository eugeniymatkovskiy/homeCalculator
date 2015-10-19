#pragma once
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include "iostream"
#include "string"
#include "math.h"
#include "fstream"
#include "User_Interface.h"

using namespace std;


class MainWindow
{
private:
	HINSTANCE hinst;
	HWND hwnd;
	WNDCLASSEX wcex;
	MainWindow();
	MainWindow(const TCHAR* title, int x, int y, int width, int height);
	User_Interface* user_gui;
public:
	void print_static_text();
	void add_user_gui(User_Interface* user_gui);
	static MainWindow* base_window;
	static MainWindow* get_main_window(const TCHAR* title, int x, int y, int width, int height)
	{
		if (!base_window)
		{
			base_window = new MainWindow(title, x, y, width, height);
		}
		return base_window;
	}
	virtual ~MainWindow();
	HWND get_hwnd();
	HINSTANCE get_hinst();
	void loop(MSG messages);
	void show(int cmdShow);
	void textout(const TCHAR* string, int x, int y);
	void update_window();
	void line(int x1, int y1, int x2, int y2);
	static	LRESULT CALLBACK	WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (base_window )
		{
			
			base_window->user_gui->print_static_text();
			
		}

		switch (message)                  /* handle the messages */
		{
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
			case 101: base_window->user_gui->run(); 
			default:                      /* for messages that we don't deal with */
				return DefWindowProc(hwnd, message, wParam, lParam);
			
			}
		case WM_CLOSE:
			base_window->user_gui->status = EXIT;
			PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
			break;
		case WM_QUIT:
			base_window->user_gui->status = EXIT;
			PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
			break;
		case WM_DESTROY:
			base_window->user_gui->status = EXIT;
			PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
			break;
		default:                      /* for messages that we don't deal with */
			return DefWindowProc(hwnd, message, wParam, lParam);
		}
		return 0;
	}


};

