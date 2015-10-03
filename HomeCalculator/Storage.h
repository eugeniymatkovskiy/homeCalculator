#pragma once
#include "HomeCalculator.h"
#include "Building.h"


class Storage :
	public Building
{
public:
	Storage() :Building() {};
	Storage(double w, double l, int f) :Building(w, l, f) {};
	Storage(const Storage& obj) :Building(obj) {};
	~Storage();

	void calculate();						//��������� ��� ��������� 
	void addMaterials(vector<MATERIAL*>*);	//�������� ��������� � ������
};
//��������� ��� ��������� 
void Storage::calculate()
{
	this->foundation->calculate();
}
//�������� ��������� � ������
void Storage::addMaterials(vector<MATERIAL*>* materials)
{
	this->foundation->addMaterials(materials);
}
Storage::~Storage()
{

}

