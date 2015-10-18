#pragma once

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
	this->OK_button = new GuiControl("BUTTON", "Расчет", this->m_window, (HMENU)101, 225, 430, 50, 20,
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);

	this->type_build_box = new GuiListBox(this->m_window, 9, 200, 50, 200, 20);
	this->type_build_box->addstring("Жилое здание");
	this->type_build_box->addstring("Офис");
	this->type_build_box->addstring("Склад");
	this->type_build_box->addstring("Гараж");


	this->num_floors_edit = new GuiEditNum(this->m_window, 6, 200, 80, 100, 20);
	this->length_edit = new GuiEditNum(this->m_window, 7, 200, 110, 100, 20);
	this->width_edit = new GuiEditNum(this->m_window, 8, 200, 140, 100, 20);
	this->mat_fund_box = new GuiListBox(this->m_window, 1, 200, 170, 200, 20);
	this->checkbox = new GuiCheckBox(this->m_window, 5, 20, 200, 100, 20);
	this->checkbox->set_text("Подвал");
	this->mat_wall_box = new GuiListBox(this->m_window, 2, 200, 230, 200, 20);
	this->mat_roof_box = new GuiListBox(this->m_window, 3, 200, 260, 200, 20);
	this->mat_panel_box = new GuiListBox(this->m_window, 4, 200, 290, 200, 20);

	this->status = INPUT_DATA;
	
	Parser materialParser(materials);
	materialParser.init();
	this->add_materials();

	calcMtrl = materials;
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
	int type_build = this->type_build_box->get_top_index();
	if (type_build != 2 || type_build != 3) {
		this->mat_roof_box->show(cmdShow);
	}
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
	this->textout("HomeCalculator-расчет строительной сметы", 20, 20);
	this->textout("Тип здания", 20, 50);
	this->textout("Число этажей", 20, 80);
	this->textout("Длина здания", 20, 110);
	this->textout("Ширина здания", 20, 140);
	this->textout("Материал фундамента", 20, 170);
	this->textout("Материал стен", 20, 230);
	this->textout("Материал крыши", 20, 260);
	this->textout("Материал перекрытий", 20, 290);
}

void User_Interface::add_materials()
{
	int fund = this->mat_fund_box->get_id2();
	int panel = this->mat_panel_box->get_id2();
	int roof = this->mat_roof_box->get_id2();
	int wall = this->mat_wall_box->get_id2();

	this->mat_fund_box->add_materials(materials, fund);
	this->mat_panel_box->add_materials(materials, panel);
	this->mat_roof_box->add_materials(materials, roof);
	this->mat_wall_box->add_materials(materials, wall);
}

void  User_Interface::run()
{
	/*int type_build = this->type_build_box->get_top_index();
	if (type_build != 2 || type_build != 3) {
		this->mat_roof_box->show(SW_HIDE);
	}*/
	

	if (this->status == OUTPUT_DATA)
	{

		this->OK_button->set_text("Расчет");
		this->OK_button->show(SW_SHOW);
		this->show(SW_SHOW);
		this->status = INPUT_DATA;

	}

		if (this->status == INPUT_DATA)
		{
			if (this->materials){
				int type_build = this->type_build_box->get_top_index();
				this->show(SW_SHOW);
				int num_floors = _ttoi(this->num_floors_edit->get_text());
				int length = _ttoi(this->length_edit->get_text());
				int width = _ttoi(this->width_edit->get_text());
				/*char* sel_fund = this->mat_fund_box->get_text();
				TCHAR* sel_fund2 = this->mat_fund_box->get_text();*/
				int selected_mat_fund = this->mat_fund_box->get_top_index();
				int id_mat_fund = this->materials->at(selected_mat_fund)->id;
				int selected_mat_wall = this->mat_wall_box->get_top_index();
				int id_mat_wall = this->materials->at(selected_mat_wall + 4)->id;
				int selected_mat_roof = this->mat_roof_box->get_top_index();
				int id_mat_roof = this->materials->at(selected_mat_roof + 8)->id;
				int selected_mat_panel = this->mat_panel_box->get_top_index();
				int id_mat_panel = this->materials->at(selected_mat_panel)->id;
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

					building->createFoundation(id_mat_fund, podval);
					building->createRoof(id_mat_roof, type_build);
					building->calculate();
					building->addMaterials(this->materials, this->calcMtrl);



					this->show(SW_HIDE);
					this->OK_button->set_text("Новый");
					this->OK_button->show(SW_SHOW);
					this->status = OUTPUT_DATA;
					this->textout("Материал", 10, 50);
					this->textout("Количество", 100, 50);
					this->textout("Цена", 200, 50);
					this->textout("Сумма", 300, 50);
					int X = 10, Y = 70;
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
								this->textout((TCHAR*)this->calcMtrl->at(i)->type.c_str(), 10, Y);


								buf = (char*)malloc(_CVTBUFSIZE);
								err = _fcvt_s(buf, _CVTBUFSIZE, this->calcMtrl->at(i)->count, 0, &decimal, &sign);
								this->textout((TCHAR*)buf, 100, Y);
								_itoa_s(this->calcMtrl->at(i)->price, buf, _CVTBUFSIZE, 10);
								this->textout((TCHAR*)buf, 200, Y);
								/*for (int j = 0; j < this->materials->size(); j++)
								{
									if (this->calcMtrl->at(i))
								}*/
								double summa = this->calcMtrl->at(i)->count * this->materials->at(i)->price;
								err = _fcvt_s(buf, _CVTBUFSIZE, summa, 0, &decimal, &sign);
								this->textout((TCHAR*)buf, 300, Y);
								itogo += summa;
								Y += 20;
							}
						}

						this->textout("Итого:", 250, Y);
						err = _fcvt_s(buf, _CVTBUFSIZE, itogo, 3, &decimal, &sign);
						this->textout((TCHAR*)buf, 300, Y);
					}
				}
			}
			else{
				this->textout("Нет данных о строительных материалах", 10, 320);
				this->status = OUTPUT_DATA;
			}
			
		}
	
	/*	int ID = MessageBox(
			this->m_window,
			"Продолжить работу программы?",
			"HomeCalculator",
			MB_YESNO
			);
		if (ID == IDNO){ this->status = EXIT; }*/
		
	
}

