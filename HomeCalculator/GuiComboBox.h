#pragma once
#include <windows.h>
#include <tchar.h>
#include "GuiControl.h"

using namespace std;

class GuiComboBox : public GuiControl
{
public:
	GuiComboBox();
	~GuiComboBox(){ DestroyWindow(this->hwnd); }
	GuiComboBox(HWND owner, int x, int y, int width, int height) :
		GuiControl("COMBOBOX", "", owner, x, y, width, height, WS_BORDER | WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_HASSTRINGS ){}
	GuiComboBox(HWND owner, HMENU id, int x, int y, int width, int height) :
		GuiControl("COMBOBOX", "", owner, id, x, y, width, height, WS_BORDER | WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_HASSTRINGS){}
};