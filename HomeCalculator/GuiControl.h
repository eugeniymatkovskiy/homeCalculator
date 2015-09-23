#pragma once
#include <windows.h>
#include <tchar.h>

using namespace std;

class GuiControl
{
public:
	GuiControl();
	GuiControl(TCHAR* classname, TCHAR* title, HWND owner, int x, int y, int width, int height, DWORD style );
	GuiControl(TCHAR* classname, TCHAR* title, HWND owner,HMENU id, int x, int y, int width, int height, DWORD style);
	virtual ~GuiControl();
	void show(int cmdShow);
	void set_text(TCHAR* text);
	TCHAR* get_text();
	TCHAR* get_classname();
	TCHAR* get_title();
	HWND get_owner();
	HWND get_hwnd();
	HMENU get_id();
protected:
	HMENU id;
	TCHAR* classname;
	TCHAR* title;
	HWND owner;
	HWND hwnd;
};

