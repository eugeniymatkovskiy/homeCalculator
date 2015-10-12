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

	void calculate();							//расчитать все материалы 
	void addMaterials(	vector<MATERIAL*>*,
						vector<MATERIAL*>*);	//добавить материалы в список
};
//расчитать все материалы 
void Storage::calculate()
{
	this->foundation->calculate();
	this->roof->roofSize();
}
//добавить материалы в список
void Storage::addMaterials(vector<MATERIAL*>* mtrl, vector<MATERIAL*>* calcMtrl)
{
	//добавить материалы фундамента в список
	this->foundation->addMaterials(mtrl, calcMtrl);

	//добавить материалы крыши в список
	this->roof->addMaterials(mtrl, calcMtrl);
}
Storage::~Storage()
{

}

