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

#include "Parser.h"


using namespace std;

enum status { INPUT_DATA, OUTPUT_DATA,EXIT };

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
	void add_materials();
	void enable_all(BOOL Enable);
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
protected:
	HWND m_window;
	void textout(const TCHAR* string, int x, int y);
	void line(int x1, int y1, int x2, int y2);
	void update_window();
	void redraw_window();
	vector<MATERIAL *> *materials = new vector<MATERIAL *>;
	vector<MATERIAL *> *calcMtrl = new vector<MATERIAL *>;

};