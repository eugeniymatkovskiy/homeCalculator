#pragma once
#include <windows.h>
#include <tchar.h>
#include <vector>
#include <string>
#include "GuiControl.h"
#include "HomeCalculator.h"

using namespace std;

class GuiListBox : public GuiControl
{
public:
	GuiListBox();
	~GuiListBox(){ DestroyWindow(this->hwnd); }
	GuiListBox(HWND owner, int x, int y, int width, int height) :
		GuiControl("LISTBOX", "", owner, x, y, width, height, WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL){}
	GuiListBox(HWND owner, HMENU id, int x, int y, int width, int height) :
		GuiControl("LISTBOX", "", owner, id, x, y, width, height, WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL){}
	void addstring(TCHAR* text)
	{
		SendMessage(this->hwnd,
			LB_ADDSTRING,
			NULL,
			(LPARAM)text);
	}

	int get_selected_index()
	{
		return (int)SendMessage(this->hwnd, LB_GETCURSEL, 0, 0);
	}

	int get_top_index()
	{
		return (int)SendMessage(this->hwnd, LB_GETTOPINDEX, 0, 0);
	}

	void add_materials(vector<MATERIAL*>* mat)
	{
		TCHAR* txt;
		MATERIAL* noviy;
		for (unsigned int i = 0; i < mat->size(); i++)
		{
			noviy = mat->at(i);
			txt = (TCHAR*)noviy->type.c_str();
			this->addstring(txt);
		}
	}
};