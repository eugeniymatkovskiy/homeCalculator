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
	GuiListBox(HWND owner, int id2, int x, int y, int width, int height) :
		GuiControl("LISTBOX", "", owner, id2, x, y, width, height, WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL){}
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

	void add_materials(vector<MATERIAL*>* mat, int id)
	{
		TCHAR* txt;
		MATERIAL* noviy;
		for (unsigned int i = 0; i < mat->size(); i++)
		{
			noviy = mat->at(i);
			txt = (TCHAR*)noviy->type.c_str();
			int groupId = noviy->groupId;
			int matId = noviy->id;
			if (id == 1 && groupId == 1) {
				this->addstring(txt);
			}
			else if (id == 2 && groupId == 2) {
				this->addstring(txt);
			}
			else if (id == 3 && groupId == 3 && matId != 304 && matId != 303) {
				this->addstring(txt);
			}
		}
	}
};