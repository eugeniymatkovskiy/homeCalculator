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

	void calculate();						//расчитать все материалы 
	void addMaterials(vector<MATERIAL*>*);	//добавить материалы в список
};
//расчитать все материалы 
void Storage::calculate()
{
	this->foundation->calculate();
}
//добавить материалы в список
void Storage::addMaterials(vector<MATERIAL*>* materials)
{
	this->foundation->addMaterials(materials);
}
Storage::~Storage()
{

}

