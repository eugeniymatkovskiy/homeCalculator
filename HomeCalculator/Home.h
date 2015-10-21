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

	void calculate();							//расчитать все материалы 
	void addMaterials(	vector<MATERIAL*>*,
						vector<MATERIAL*>*);	//добавить материалы в список
};
//расчитать все материалы 
void Home::calculate()
{
	this->foundation->calculate();
	this->wall->calculate();
	this->roof->roofSize();
}
//добавить материалы в список
void Home::addMaterials(vector<MATERIAL*>* mtrl, vector<MATERIAL*>* calcMtrl)
{
	//добавить материалы фундамента в список
	this->foundation->addMaterials(mtrl, calcMtrl);

	//добавить материалы этажа в список
	this->wall->addMaterials(mtrl, calcMtrl);

	//добавить материалы крыши в список
	this->roof->addMaterials(mtrl, calcMtrl);
}
Home::~Home()
{

}

