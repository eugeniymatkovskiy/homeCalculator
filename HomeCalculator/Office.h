#pragma once
#include "HomeCalculator.h"
#include "Building.h"


class Office :
	public Building
{
public:
	Office() :Building() {}
	Office(double w, double l, int f) :Building(w, l, f) {}
	Office(const Office& obj) :Building(obj) {}
	virtual ~Office();

	void calculate();							//расчитать все материалы 
	void addMaterials(	vector<MATERIAL*>*,
						vector<MATERIAL*>*);	//добавить материалы в список
};
//расчитать все материалы 
void Office::calculate()
{
	this->foundation->calculate();
}
//добавить материалы в список
void Office::addMaterials(vector<MATERIAL*>* mtrl, vector<MATERIAL*>* calcMtrl)
{
	this->foundation->addMaterials(mtrl, calcMtrl);
}
Office::~Office()
{

}

