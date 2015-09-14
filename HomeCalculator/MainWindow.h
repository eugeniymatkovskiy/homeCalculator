#pragma once
#include <windows.h>
#include <tchar.h>

using namespace std;


class MainWindow
{
public:
	MainWindow();
	MainWindow(HINSTANCE hInst,const TCHAR* title, int x, int y, int width, int height);
	virtual ~MainWindow();
	HWND get_hWnd();
	void loop(MSG messages);
	void show(int cmdShow);
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
private:
	HWND hWnd;
	WNDCLASSEX wcex;

};

