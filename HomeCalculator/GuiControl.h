#pragma once
#include <windows.h>
#include <tchar.h>

using namespace std;

class GuiControl
{
public:
	GuiControl();
	GuiControl(TCHAR* classname, TCHAR* title, HWND owner, int x, int y, int width, int height, DWORD style );
	virtual ~GuiControl();
	void show(int cmdShow);
protected:
	TCHAR* classname;
	TCHAR* title;
	HWND owner;
	HWND hwnd;
};

