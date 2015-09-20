#pragma once
#include "HomeCalculator.h"
#include "Foundation.h"


class Building
{
	private:
		double length;						//длина (м)
		double width;						//ширина (м)
		double height;						//высота (м)
		int floorCount;						//к-во этажей
		Foundation* foundation;				//фундамент
		//Floor* floor;						//этаж(и)
		//Roof* roof;						//крыша

	protected:
		void calcFoundationMaterials();		//рассчитать материалы для фундамента
		void calcFloorsMaterials();			//рассчитать материалы для этажа(ей)
		void calcRoofMaterials();			//рассчитать материалы для криши

	public:
		Building(double, double, int);
		Building(const Building&);
		void setLength(double);						//установить длину здания (м)
		void setWidth(double);						//установить ширину здания (м)
		void setHeight(double);						//установить высоту здания (м)
		double getLength();							//получить длину здания (м)
		double getWidth();							//получить ширину здания (м)
		double getHeight();							//получить высоту здания (м)
		void createFoundation(int, bool);			//создать фундамент
		//void createFloor();						//создать этаж
		//void createRoof();						//создать крышу
		~Building();
};
