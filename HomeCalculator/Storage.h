#pragma once
#include "HomeCalculator.h"
#include "Building.h"


class Storage :
	public Building
{
public:
	Storage() :Building() {}
	Storage(double w, double l, int f) :Building(w, l, f) {}
	Storage(const Storage& obj) :Building(obj) {}
	virtual ~Storage();

	void calculate();							//��������� ��� ��������� 
	void addMaterials(	vector<MATERIAL*>*,
						vector<MATERIAL*>*);	//�������� ��������� � ������
};
//��������� ��� ��������� 
void Storage::calculate()
{
	this->foundation->calculate();
	this->roof->roofSize();
}
//�������� ��������� � ������
void Storage::addMaterials(vector<MATERIAL*>* mtrl, vector<MATERIAL*>* calcMtrl)
{
	//�������� ��������� ���������� � ������
	this->foundation->addMaterials(mtrl, calcMtrl);

	//�������� ��������� ����� � ������
	this->roof->addMaterials(mtrl, calcMtrl);
}
Storage::~Storage()
{

}

