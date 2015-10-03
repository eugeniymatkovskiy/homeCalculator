#pragma once
#include "HomeCalculator.h"
#include "Foundation.h"


class Building
{
	private:
		double length;						//длина (м)
		double width;						//ширина (м)
		int floorCount;						//к-во этажей
		

	protected:
		//Foundation* foundation;				//фундамент
		//Floor* floor;						//этаж(и)
		//Roof* roof;						//крыша

		//void calcFoundationMaterials();		//рассчитать материалы для фундамента
		//void calcFloorsMaterials();			//рассчитать материалы для этажа(ей)
		//void calcRoofMaterials();			//рассчитать материалы для криши

	public:
		Building();
		Building(double, double, int);
		Building(const Building&);
		void setLength(double);								//установить длину здания (м)
		void setWidth(double);								//установить ширину здания (м)
		void setfloorCount(int);							//установить к-во этажей (м)
		double getLength();									//получить длину здания (м)
		double getWidth();									//получить ширину здания (м)
		int getfloorCount();								//получить высоту здания (м)
		void createFoundation(int, bool);					//создать фундамент
		virtual void calculate() = 0;						//расчитать все материалы 
		virtual void addMaterials(vector<MATERIAL*>*) = 0;	//добавить материалы в список
		//virtual void createFloor();						//создать этаж
		//virtual void createRoof();						//создать крышу

		Foundation* foundation;				//фундамент
		virtual ~Building();
};


Building::Building()
{

}
Building::Building(double length, double width, int floorCount)
{
	this->setLength(length);
	this->setWidth(width);
	this->setfloorCount(floorCount);
}
Building::Building(const Building &obj)
{
	this->length = obj.length;
	this->width = obj.width;
	this->floorCount = obj.floorCount;
}
//создание фундамента
void Building::createFoundation(int material, bool basement)
{
	this->foundation = new Foundation(	this->getLength(), 
							   			this->getWidth(), 
										this->getfloorCount(), 
										material, 
										basement);
}
//установить длину здания (м)
void Building::setLength(double length)
{
	this->length = length;
}
//установить ширину здания (м)
void Building::setWidth(double width)
{
	this->width = width;
}
//установить высоту здания (м)
void Building::setfloorCount(int floorCount)
{
	this->floorCount = floorCount;
}
//получить длину здания (м)
double Building::getLength()
{
	return this->length;
}
//получить ширину здания (м)
double Building::getWidth()
{
	return this->width;
}
//установить к-во этажей
int Building::getfloorCount()
{
	return this->floorCount;
}
Building::~Building()
{
	delete this->foundation;
}

