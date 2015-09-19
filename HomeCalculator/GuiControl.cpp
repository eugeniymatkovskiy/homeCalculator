#include "GuiControl.h"


GuiControl::GuiControl()
{
}

GuiControl::GuiControl(TCHAR* classname, TCHAR* title, HWND owner, int x, int y, int width, int height, 
	DWORD style)
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

GuiControl::~GuiControl()
{
	DestroyWindow(this->hwnd);
}

void GuiControl::show(int cmdShow)
{

	ShowWindow(this->hwnd, cmdShow);
}