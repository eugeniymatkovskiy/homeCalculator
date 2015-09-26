#pragma once
#include <windows.h>
#include <tchar.h>
#include "GuiControl.h"

using namespace std;

class GuiEditNum : public GuiControl
{
public:
	GuiEditNum();
	~GuiEditNum(){ DestroyWindow(this->hwnd); }
	GuiEditNum(HWND owner, int x, int y, int width, int height) :
		GuiControl("EDIT", "", owner, x, y, width, height, WS_BORDER | WS_CHILD | WS_VISIBLE | ES_CENTER | ES_NUMBER){}
	GuiEditNum(HWND owner, HMENU id, int x, int y, int width, int height) :
		GuiControl("EDIT", "", owner, id, x, y, width, height, WS_BORDER | WS_CHILD | WS_VISIBLE | ES_CENTER | ES_NUMBER){}
};