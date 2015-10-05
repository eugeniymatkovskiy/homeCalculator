#pragma once
#include <Windows.h>
#include <tchar.h>

#include "MainWindow.h"
#include "GuiControl.h"
#include "OpenGLViewPort.h"
#include "GuiCheckBox.h"
#include "GuiEditNum.h"
#include "GuiComboBox.h"
#include "GuiListBox.h"

#include "User_Interface.h"

#include "Building.h"
#include "Home.h"
#include "Storage.h"
#include "Office.h"
#include "Garage.h"

using namespace std;

User_Interface::User_Interface(HWND window)
{
	this->m_window = window;
	this->OK_button = new GuiControl("BUTTON", "������", this->m_window, (HMENU)101, 225, 430, 50, 20,
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);

	this->type_build_box = new GuiListBox(this->m_window, 200, 50, 200, 20);
	this->type_build_box->addstring("����� ������");
	this->type_build_box->addstring("����");
	this->type_build_box->addstring("�����");
	this->type_build_box->addstring("�����");


	this->num_floors_edit = new GuiEditNum(this->m_window, 200, 80, 100, 20);
	this->length_edit = new GuiEditNum(this->m_window, 200, 110, 100, 20);
	this->width_edit = new GuiEditNum(this->m_window, 200, 140, 100, 20);
	this->mat_fund_box = new GuiListBox(this->m_window, 200, 170, 200, 20);
	this->checkbox = new GuiCheckBox(this->m_window, 20, 200, 100, 20);
	this->checkbox->set_text("������");
	this->mat_wall_box = new GuiListBox(this->m_window, 200, 230, 200, 20);
	this->mat_roof_box = new GuiListBox(this->m_window, 200, 260, 200, 20);
	this->mat_panel_box = new GuiListBox(this->m_window, 200, 290, 200, 20);

	this->status = INPUT_DATA;


}

User_Interface::~User_Interface()
{
	delete this->type_build_box;
	delete this->num_floors_edit;
	delete this->length_edit;
	delete this->width_edit;
	delete this->mat_fund_box;
	delete this->checkbox;
	delete this->mat_wall_box;
	delete this->mat_roof_box;
	delete this->mat_panel_box;

}

void User_Interface::show(int cmdShow)
{
	this->OK_button->show(cmdShow);
	this->type_build_box->show(cmdShow);
	this->num_floors_edit->show(cmdShow);
	this->length_edit->show(cmdShow);
	this->width_edit->show(cmdShow);
	this->mat_fund_box->show(cmdShow);
	this->checkbox->show(cmdShow);
	this->mat_wall_box->show(cmdShow);
	this->mat_roof_box->show(cmdShow);
	this->mat_panel_box->show(cmdShow);
}

void User_Interface::textout(const TCHAR* string, int x, int y)
{
	int lenght = _tcslen(string);
	HDC hdc = GetDC(this->m_window);
	TextOut(hdc, x, y, string, lenght);
	ReleaseDC(this->m_window, hdc);
}

void User_Interface::print_static_text()
{
	this->textout("HomeCalculator-������ ������������ �����", 20, 20);
	this->textout("��� ������", 20, 50);
	this->textout("����� ������", 20, 80);
	this->textout("����� ������", 20, 110);
	this->textout("������ ������", 20, 140);
	this->textout("�������� ����������", 20, 170);
	this->textout("�������� ����", 20, 230);
	this->textout("�������� �����", 20, 260);
	this->textout("�������� ����������", 20, 290);
}

void User_Interface::add_materials(vector<MATERIAL*>* materials)
{
	this->materials = materials;
	this->mat_fund_box->add_materials(materials);
	this->mat_panel_box->add_materials(materials);
	this->mat_roof_box->add_materials(materials);
	this->mat_wall_box->add_materials(materials);
}

void  User_Interface::run()
{
	if (this->status == OUTPUT_DATA)
	{
		this->show(SW_HIDE);
		this->OK_button->set_text("������");
		this->OK_button->show(SW_SHOW);
		this->status = INPUT_DATA;
	}

	if (this->status == INPUT_DATA)
	{
		int type_build = this->type_build_box->get_selected_index();
		int num_floors = _ttoi(this->num_floors_edit->get_text());
		int length = _ttoi(this->length_edit->get_text());
		int width = _ttoi(this->width_edit->get_text());
		int mat_fund = this->mat_fund_box->get_selected_index();
		int mat_wall = this->mat_wall_box->get_selected_index();
		int mat_roof = this->mat_roof_box->get_selected_index();
		int mat_panel = this->mat_panel_box->get_selected_index();
		bool podval = this->checkbox->isChecked();
		Building* building=nullptr;
		switch (type_build)
		{
		case 0 :
			building = new Home((double)width,(double)length,num_floors);
			break;
		case 1:
			building = new Office((double)width, (double)length, num_floors);
			break;
		case 2:
			building = new Storage((double)width, (double)length, num_floors);
			break;
		case 3:
			building = new Garage((double)width, (double)length, num_floors);
			break;
		default:
			break;
		}

		if (building){
			building->addMaterials(this->materials);
			building->calculate();

		}

		this->show(SW_HIDE);
		this->OK_button->set_text("�����");
		this->OK_button->show(SW_SHOW);
		this->status = OUTPUT_DATA;
		this->textout("��������", 10, 10);
		this->textout("����������", 100, 10);
		this->textout("����", 200, 10);
		this->textout("�����",300, 10);
		int X = 10, Y = 20;
		double itogo = 0;
		char * buf = 0;
		int decimal;
		int sign;
		int err;
		for (unsigned int i = 0; i < this->materials->size(); i++)
		{
			if (this->materials->at(i)->count != 0)
			{
				this->textout((TCHAR*)this->materials->at(i)->type.c_str(), 10, Y);
				

				buf = (char*)malloc(_CVTBUFSIZE);
				err = _fcvt_s(buf, _CVTBUFSIZE, this->materials->at(i)->count,3, &decimal, &sign);
				this->textout((TCHAR*)buf, 100, Y);
				_itoa_s(this->materials->at(i)->price, buf, _CVTBUFSIZE, 10);
				this->textout((TCHAR*)buf, 200, Y);
				double summa = this->materials->at(i)->count * this->materials->at(i)->price;
				err = _fcvt_s(buf, _CVTBUFSIZE,summa, 3, &decimal, &sign);
				this->textout((TCHAR*)buf, 300, Y);
				itogo += summa;
				Y += 15;
			}
		}

		this->textout("�����:", 250, Y);
		err = _fcvt_s(buf, _CVTBUFSIZE, itogo, 3, &decimal, &sign);
		this->textout((TCHAR*)buf, 300, Y);
	}
	
}

