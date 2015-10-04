#pragma once
#include "stdafx.h"

#include <tchar.h>
#include <vector>
#include <string>

#include <Windows.h>

#include "MainWindow.h"
#include "GuiControl.h"
#include "OpenGLViewPort.h"
#include "GuiCheckBox.h"
#include "GuiEditNum.h"
#include "GuiComboBox.h"
#include "GuiListBox.h"
#include "HomeCalculator.h"
#include "Building.h"
#include "Home.h"
#include "Storage.h"
#include "Office.h"
#include "Garage.h"

using namespace std;

enum status { INPUT_DATA, OUTPUT_DATA };

class User_Interface
{
public:
	User_Interface(){}
	User_Interface(HWND window);
	~User_Interface();
	int status;
	void show(int cmdShow);
	void print_static_text();
	void run();
	void add_materials(vector<MATERIAL*>* materials);
protected:
	HWND m_window;
	GuiControl* OK_button;
	GuiListBox* type_build_box;
	GuiEditNum* num_floors_edit;
	GuiEditNum* length_edit;
	GuiEditNum* width_edit;
	GuiListBox* mat_fund_box;
	GuiCheckBox* checkbox;
	GuiListBox* mat_wall_box;
	GuiListBox* mat_roof_box;
	GuiListBox* mat_panel_box;
	void textout(const TCHAR* string, int x, int y);
	vector<MATERIAL*>* materials;

};