#pragma once
#include "HomeCalculator.h"
#include "Building.h"


class Garage :
	public Building
{
public:
	Garage() :Building() {};
	Garage(double w, double l, int f) :Building(w, l, f) {};
	Garage(const Garage& obj) :Building(obj) {};
	~Garage();

	void calculate();						//��������� ��� ��������� 
	void addMaterials(vector<MATERIAL*>*);	//�������� ��������� � ������
};
//��������� ��� ��������� 
void Garage::calculate()
{
	this->foundation->calculate();
}
//�������� ��������� � ������
void Garage::addMaterials(vector<MATERIAL*>* materials)
{
	this->foundation->addMaterials(materials);
}
Garage::~Garage()
{

}

