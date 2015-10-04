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

	void calculate();						//расчитать все материалы 
	void addMaterials(vector<MATERIAL*>*);	//добавить материалы в список
};
//расчитать все материалы 
void Home::calculate()
{
	this->foundation->calculate();
}
//добавить материалы в список
void Home::addMaterials(vector<MATERIAL*>* materials)
{
	this->foundation->addMaterials(materials);
}
Home::~Home()
{

}

