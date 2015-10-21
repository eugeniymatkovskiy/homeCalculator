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

	void calculate();							//расчитать все материалы 
	void addMaterials(	vector<MATERIAL*>*,
						vector<MATERIAL*>*);	//добавить материалы в список
};
//расчитать все материалы 
void Garage::calculate()
{
	this->foundation->calculate();
	this->wall->calculate();
	this->roof->roofSize();
}
//добавить материалы в список
void Garage::addMaterials(vector<MATERIAL*>* mtrl, vector<MATERIAL*>* calcMtrl)
{
	
	//добавить материалы фундамента в список
	this->foundation->addMaterials(mtrl, calcMtrl);

	//добавить материалы этажа в список
	this->wall->addMaterials(mtrl, calcMtrl);

	//добавить материалы крыши в список
	this->roof->addMaterials(mtrl, calcMtrl);


}
Garage::~Garage()
{

}

