#pragma once

#include <stdio.h>
#include "MainWindow.h"

#include "User_Interface.h"

#include "Building.h"
#include "Home.h"
#include "Storage.h"
#include "Office.h"
#include "Garage.h"

User_Interface::User_Interface(HWND window)
{
	this->m_window = window;
	this->OK_button = new GuiControl("BUTTON", "������", this->m_window, (HMENU)101, 200, 530, 50, 20,
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);

	this->type_build_box = new GuiListBox(this->m_window, 200, 50, 200, 20);
	this->type_build_box->addstring("����� ������");
	this->type_build_box->addstring("����");
	this->type_build_box->addstring("�����");
	this->type_build_box->addstring("�����");


	this->num_floors_edit = new GuiEditNum(this->m_window, 200, 80, 100, 20);
	this->length_edit = new GuiEditNum(this->m_window, 200, 110, 100, 20);
	this->width_edit = new GuiEditNum(this->m_window, 200, 140, 100, 20);
	this->mat_fund_box = new GuiListBox(this->m_window, 200, 170, 280, 20);
	this->checkbox = new GuiCheckBox(this->m_window, 20, 200, 100, 20);
	this->checkbox->set_text("������");
	this->mat_wall_box = new GuiListBox(this->m_window, 200, 230, 280, 20);
	this->mat_roof_box = new GuiListBox(this->m_window, 200, 260, 280, 20);
	//this->mat_panel_box = new GuiListBox(this->m_window, 200, 290, 280, 20);

	this->status = INPUT_DATA;
	
	Parser materialParser(materials);
	materialParser.init();
	this->add_materials();
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
	//delete this->mat_panel_box;

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
	//this->mat_panel_box->show(cmdShow);
}

void User_Interface::enable_all(BOOL Enable)
{
	this->type_build_box->set_enable(Enable);
	this->num_floors_edit->set_enable(Enable);
	this->length_edit->set_enable(Enable);
	this->width_edit->set_enable(Enable);
	this->mat_fund_box->set_enable(Enable);
	this->checkbox->set_enable(Enable);
	this->mat_wall_box->set_enable(Enable);
	this->mat_roof_box->set_enable(Enable);
	//this->mat_panel_box->set_enable(Enable);
}

void User_Interface::textout(const TCHAR* string, int x, int y)
{
	int lenght = _tcslen(string);
	HDC hdc = GetDC(this->m_window);
	TextOut(hdc, x, y, string, lenght);
	ReleaseDC(this->m_window, hdc);
}

void User_Interface::line(int x1, int y1, int x2, int y2)
{
	HDC hdc = GetDC(this->m_window);
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	ReleaseDC(this->m_window, hdc);
}

void User_Interface::print_static_text()
{
	if (this->status == INPUT_DATA)
	{
		this->textout("HomeCalculator-������ ������������ �����", 20, 20);
		this->textout("��� ������", 20, 50);
		this->textout("����� ������", 20, 80);
		this->textout("����� ������", 20, 110);
		this->textout("������ ������", 20, 140);
		this->textout("�������� ����������", 20, 170);
		this->textout("�������� ����", 20, 230);
		this->textout("�������� �����", 20, 260);
		//this->textout("�������� ����������", 20, 290);
	}
}

void User_Interface::add_materials()
{
	this->mat_fund_box->add_group_materials(this->materials,1);
	//this->mat_panel_box->add_group_materials(this->materials,3);

	this->mat_roof_box->add_group_materials(this->materials, 3);
	this->mat_wall_box->add_group_materials(this->materials, 2);
}

void User_Interface::update_window()
{
	UpdateWindow(this->m_window);
}

void User_Interface::redraw_window()
{
	//RedrawWindow(this->m_window, NULL, NULL, RDW_VALIDATE);
	RECT rect;
	GetClientRect(this->m_window, &rect);
	InvalidateRect(this->m_window, &rect, true);
}

void  User_Interface::run()
{
	switch (this->status){

	case OUTPUT_DATA:
		{
			int max = this->calcMtrl->size();
			for (unsigned int i = 0; i < max; i++)
			{
				this->calcMtrl->pop_back();
			}
			this->redraw_window();
			this->type_build_box->set_top_index(0);
			this->num_floors_edit->set_text("");
			this->length_edit->set_text("");
			this->width_edit->set_text("");
			this->mat_fund_box->set_top_index(0);
			this->mat_wall_box->set_top_index(0);
			this->mat_roof_box->set_top_index(0);
			//this->mat_panel_box->set_top_index(0);

			this->enable_all(true);
			this->OK_button->set_text("������");

			this->OK_button->show(SW_SHOW);
			this->show(SW_SHOW);
			this->status = INPUT_DATA;
			break;
		}

		case INPUT_DATA:
		{
			if (!this->materials->empty()){
				int type_build = this->type_build_box->get_top_index();

				int num_floors = _ttoi(this->num_floors_edit->get_text());
				double length = _ttof(this->length_edit->get_text());
				double width = _ttof(this->width_edit->get_text());

				int mat_fund = this->mat_fund_box->get_id_top_material();
				
				int mat_wall = this->mat_wall_box->get_id_top_material();
				
				int mat_roof = this->mat_roof_box->get_id_top_material();
				
				//int mat_panel = this->mat_panel_box->get_id_top_material();

				bool podval = this->checkbox->isChecked();

				Building* building = nullptr;
				switch (type_build)
				{
				case 0:
					building = new Home((double)width, (double)length, num_floors);
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

					building->createFoundation(mat_fund, podval);
					building->createWall(type_build, mat_wall);
					building->createRoof(mat_roof, type_build);
					building->calculate();
					building->addMaterials(this->materials, this->calcMtrl);

					this->enable_all(false);
					this->OK_button->set_text("�����");
					this->OK_button->show(SW_SHOW);
					this->status = OUTPUT_DATA;

					int X = 10, Y = 320;
					this->textout("��������", 10, Y);
					this->textout("����������", 230, Y);
					this->textout("����/��", 330, Y);
					this->textout("����� ���", 400, Y);
					this->line(5,Y-5, 475, Y-5);
					this->line(5, Y + 20, 475, Y + 20);
					this->line(5, Y - 5, 5, Y + 20);
					this->line(225, Y - 5, 225, Y + 20);
					this->line(325, Y - 5, 325, Y + 20);
					this->line(395, Y - 5, 395, Y + 20);
					this->line(475, Y - 5, 475, Y + 20);
					Y += 25;
					double itogo = 0;
					char * buf = 0;
					int decimal;
					int sign;
					int err;
					if (!this->calcMtrl->empty()){
						for (unsigned int i = 0; i < this->calcMtrl->size(); i++)
						{
							if (this->calcMtrl->at(i)->count != 0)
							{
								char name[25];
								strncpy_s(name,25, this->calcMtrl->at(i)->type.c_str(), 24);
								this->textout((TCHAR*)name, 10, Y);


								buf = (char*)malloc(_CVTBUFSIZE);
								err = _fcvt_s(buf, _CVTBUFSIZE, this->calcMtrl->at(i)->count, 0, &decimal, &sign);
								this->textout((TCHAR*)buf, 230, Y);
								_itoa_s(this->calcMtrl->at(i)->price, buf, _CVTBUFSIZE, 10);
								this->textout((TCHAR*)buf, 330, Y);
								double summa = this->calcMtrl->at(i)->count * this->calcMtrl->at(i)->price;
								err = _fcvt_s(buf, _CVTBUFSIZE, summa, 0, &decimal, &sign);
								this->textout((TCHAR*)buf, 400, Y);
								itogo += summa;
								this->line(5, Y + 20, 475, Y + 20);
								this->line(5, Y - 5, 5, Y + 20);
								this->line(225, Y - 5, 225, Y + 20);
								this->line(325, Y - 5, 325, Y + 20);
								this->line(395, Y - 5, 395, Y + 20);
								this->line(475, Y - 5, 475, Y + 20);
								Y += 25;
							}
						}

						this->textout("�����:", 350, Y);
						err = _fcvt_s(buf, _CVTBUFSIZE, itogo, 0, &decimal, &sign);
						this->textout((TCHAR*)buf, 400, Y);
						this->line(345, Y + 20, 475, Y + 20);
						this->line(345, Y - 5, 345, Y + 20);
						this->line(395, Y - 5, 395, Y + 20);
						this->line(475, Y - 5, 475, Y + 20);
					}
				}
			}
			else{
				this->textout("��� ������ � ������������ ����������", 10, 320);
				this->status = OUTPUT_DATA;
			}
			break;
		}

		

	}
}

