#pragma once
#include <windows.h>
#include <tchar.h>

using namespace std;


class MainWindow
{
private:
	HINSTANCE hinst;
	HWND hwnd;
	WNDCLASSEX wcex;
	MainWindow();
	MainWindow(const TCHAR* title, int x, int y, int width, int height);
	
public:
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
	 static	LRESULT CALLBACK	WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (base_window)
		{
			base_window->textout("HomeCalculator-расчет строительной сметы", 20, 20);
			base_window->textout("Тип здания", 20, 50);
			base_window->textout("Число этажей", 20, 80);
			base_window->textout("Длина здания", 20, 110);
			base_window->textout("Ширина здания", 20, 140);
			base_window->textout("Материал фундамента", 20, 170);
			base_window->textout("Материал стен", 20, 230);
			base_window->textout("Материал крыши", 20, 260);
			base_window->textout("Материал перекрытий", 20, 290);
		}
		switch (message)                  /* handle the messages */
		{
		
		case WM_DESTROY:
			PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
			break;
		default:                      /* for messages that we don't deal with */
			return DefWindowProc(hwnd, message, wParam, lParam);
		}
		return 0;
	}


};

