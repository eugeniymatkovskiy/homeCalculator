#include "GuiControl.h"


GuiControl::GuiControl()
{
}

GuiControl::GuiControl(TCHAR* classname, TCHAR* title, HWND owner, 
							int x, int y, int width, int height,DWORD style)
{
	this->classname = classname;
	this->title = title;
	this->owner = owner;
	this->hwnd = CreateWindowEx(0,
		classname,
		title,
		style,
		x,
		y,
		width,
		height,
		owner,
		NULL,
		GetModuleHandle(NULL),
		NULL);
}


GuiControl::GuiControl(TCHAR* classname, TCHAR* title, HWND owner,HMENU id,
							int x, int y, int width, int height, DWORD style)
{
	this->classname = classname;
	this->title = title;
	this->owner = owner;
	this->id = id;
	this->hwnd = CreateWindowEx(0,
		classname,
		title,
		style,
		x,
		y,
		width,
		height,
		owner,
		id,
		GetModuleHandle(NULL),
		NULL);
}


GuiControl::~GuiControl()
{
	DestroyWindow(this->hwnd);
}

void GuiControl::show(int cmdShow)
{

	ShowWindow(this->hwnd, cmdShow);
}

TCHAR* GuiControl::get_classname()
{
	return this->classname;
}

TCHAR* GuiControl::get_title()
{
	return this->title;
}

HWND GuiControl::get_owner()
{
	return this->owner;
}

HWND GuiControl::get_hwnd()
{
	return this->hwnd;
}

HMENU GuiControl::get_id()
{
	return this->id;
}

void GuiControl::set_text(TCHAR* text)
{
	SendMessage(this->hwnd,
		WM_SETTEXT,
		NULL,
		(LPARAM)text);
}

TCHAR*  GuiControl::get_text()
{
	int length = SendMessage(hwnd, WM_GETTEXTLENGTH, 0, 0);
	if (length == -1)
		return "";
	TCHAR* buffer = new TCHAR[length + 1];
	SendMessage(hwnd, WM_GETTEXT, length + 1, (LPARAM)buffer);
	return buffer;
}

void GuiControl::set_enable(BOOL bEnable)
{
	EnableWindow(this->hwnd, bEnable);
}