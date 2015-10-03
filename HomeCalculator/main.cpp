#pragma once
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include "stdafx.h"
#include "MainWindow.h"
#include "GuiControl.h"
#include "OpenGLViewPort.h"
#include "GuiCheckBox.h"
#include "GuiEditNum.h"
#include "GuiComboBox.h"
#include "Roof.h"
#include "HomeCalculator.h"


using namespace std;

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	MSG msg;

	MainWindow* main_window = MainWindow::get_main_window("HomeCalculator", 10, 10, 500, 500);
	main_window->show(nCmdShow);
 	//**********TEST GUI ************************************************
	
	GuiControl* OK_button = new GuiControl("BUTTON", "Расчет", main_window->get_hwnd(),225,430, 50, 20,
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
	OK_button->show(nCmdShow);
	/*GuiControl* Edit = new GuiControl("EDIT", "Ввод данных", main_window->get_hWnd(), 50, 50, 200, 20,
		WS_BORDER | WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL);
	
	Edit->show(nCmdShow);*/

	GuiComboBox* type_build_box = new GuiComboBox(main_window->get_hwnd(), 200, 50, 100, 20);
	type_build_box->show(nCmdShow);

	GuiEditNum* num_floors_edit = new GuiEditNum(main_window->get_hwnd(), 200, 80, 100, 20);
	num_floors_edit->show(nCmdShow);

	GuiEditNum* length_edit = new GuiEditNum(main_window->get_hwnd(), 200, 110, 100, 20);
	length_edit->show(nCmdShow);

	GuiEditNum* width_edit = new GuiEditNum(main_window->get_hwnd(), 200, 140, 100, 20);
	width_edit->show(nCmdShow);

	GuiComboBox* mat_fund_box = new GuiComboBox(main_window->get_hwnd(), 200, 170, 100, 20);
	mat_fund_box->show(nCmdShow);
	
	GuiCheckBox* checkbox = new GuiCheckBox(main_window->get_hwnd(), 20, 200, 100, 20);
	checkbox->set_text("Подвал");
	checkbox->show(nCmdShow);

	GuiComboBox* mat_wall_box = new GuiComboBox(main_window->get_hwnd(), 200, 230, 100, 20);
	mat_wall_box->show(nCmdShow);

	GuiComboBox* mat_roof_box = new GuiComboBox(main_window->get_hwnd(), 200, 260, 100, 20);
	mat_roof_box->show(nCmdShow);

	GuiComboBox* mat_panel_box = new GuiComboBox(main_window->get_hwnd(), 200, 290, 100, 20);
	mat_panel_box->show(nCmdShow);

	main_window->textout("HomeCalculator-расчет строительной сметы", 20, 20);
	main_window->textout("Тип здания", 20, 50);
	main_window->textout("Число этажей", 20, 80);
	main_window->textout("Длина здания", 20, 110);
	main_window->textout("Ширина здания", 20, 140);
	main_window->textout("Материал фундамента", 20, 170);
	main_window->textout("Материал стен", 20, 230);
	main_window->textout("Материал крыши", 20, 260);
	main_window->textout("Материал перекрытий", 20, 290);

	//OpenGLViewPort* glPort = new OpenGLViewPort(main_window->get_hWnd(), 200, 10, 200, 200);

	//glPort->enableOpenGL();
	//glPort->testOpenGL();

	//glPort->show(nCmdShow);
	
	//************************TEST GUI ****************************************

	GetMessage(&msg, NULL, 0, 0);
	main_window->loop(msg);// предпоследняя строчка !!!



	delete type_build_box;
	delete num_floors_edit;
	delete length_edit;
	delete width_edit;
	delete mat_fund_box;
	delete checkbox;
	delete mat_wall_box;
	delete mat_roof_box;
	delete mat_panel_box;
	delete main_window;
	
	return (int)msg.wParam;
}