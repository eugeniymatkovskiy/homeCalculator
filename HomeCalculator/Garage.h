#pragma once
#include "HomeCalculator.h"
#include "Building.h"


class Garage :
	public Building
{
public:
	Garage() :Building() {}
	Garage(double w, double l, int f) :Building(w, l, f) {}
	Garage(const Garage& obj) :Building(obj) {}
	virtual ~Garage();

	void calculate();							//��������� ��� ��������� 
	void addMaterials(	vector<MATERIAL*>*,
						vector<MATERIAL*>*);	//�������� ��������� � ������
};
//��������� ��� ��������� 
void Garage::calculate()
{
	this->foundation->calculate();
	this->wall->calculate();
	this->roof->roofSize();
}
//�������� ��������� � ������
void Garage::addMaterials(vector<MATERIAL*>* mtrl, vector<MATERIAL*>* calcMtrl)
{
	
	//�������� ��������� ���������� � ������
	this->foundation->addMaterials(mtrl, calcMtrl);

	//�������� ��������� ����� � ������
	this->wall->addMaterials(mtrl, calcMtrl);

	//�������� ��������� ����� � ������
	this->roof->addMaterials(mtrl, calcMtrl);


}
Garage::~Garage()
{

}

