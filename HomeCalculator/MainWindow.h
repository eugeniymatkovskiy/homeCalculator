#pragma once
#include <windows.h>
#include <tchar.h>

using namespace std;


class MainWindow
{
private:
	HINSTANCE hinst;
	HWND hWnd;
	WNDCLASSEX wcex;
public:
	MainWindow();
	MainWindow(HINSTANCE hInst,const TCHAR* title, int x, int y, int width, int height);
	virtual ~MainWindow();
	HWND get_hWnd();
	HINSTANCE get_hinst();
	void loop(MSG messages);
	void show(int cmdShow);
	void textout(const TCHAR* string, int x, int y);
	 static	LRESULT CALLBACK	WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)                  /* handle the messages */
		{
		
		case WM_DESTROY:
			PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
			break;
		default:                      /* for messages that we don't deal with */
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}


};

