#pragma once
#include "HomeCalculator.h"
#include "Building.h"


class Home :
	public Building
{
public:
	Home() :Building() {}
	Home(double w, double l, int f) :Building(w, l, f) {}
	Home(const Home& obj) :Building(obj) {}
	virtual ~Home();

	void calculate();						//��������� ��� ��������� 
	void addMaterials(vector<MATERIAL*>*);	//�������� ��������� � ������
};
//��������� ��� ��������� 
void Home::calculate()
{
	this->foundation->calculate();
}
//�������� ��������� � ������
void Home::addMaterials(vector<MATERIAL*>* materials)
{
	this->foundation->addMaterials(materials);
}
Home::~Home()
{

}

