#pragma once
#include <windows.h>
#include <tchar.h>
#include "GuiControl.h"

using namespace std;

class GuiCheckBox : public GuiControl
{
public:
	GuiCheckBox(){}
   ~GuiCheckBox(){	DestroyWindow(this->hwnd);	}
   GuiCheckBox(HWND owner, int x, int y, int width, int height) :
	   GuiControl("BUTTON", "", owner, x, y, width, height, WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX){}
   GuiCheckBox(HWND owner,HMENU id, int x, int y, int width, int height) :
	   GuiControl("BUTTON", "", owner,id, x, y, width, height, WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX){}

   bool isChecked(){
	   // Выясняем текущее состояние chechbox'а.
	   LRESULT res = SendMessage(this->hwnd, BM_GETCHECK, 0, 0);
	   // Если галочка стоит.
	   if (res == BST_CHECKED)
	   {
		   return true;
	   }
	   // Если галочка не стоит.
	   if (res == BST_UNCHECKED)
	   {
		   return false;
	   }
   }

   void setChecked(bool checked){

	   if (checked){ SendMessage(this->hwnd, BM_SETCHECK, BST_CHECKED, 0); }
	   else { SendMessage(this->hwnd, BM_SETCHECK, BST_UNCHECKED, 0); }
   }

};