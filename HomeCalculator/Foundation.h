#pragma once
#include "stdafx.h"


class Foundation
{
	private:
		double length;			//длина (м)
		double width;			//ширина (м)
		double height;			//высота (м)
		double thickness;		//толщина (м)
		int floorCount;			//к-во этажей
		bool basement;			//наличие подвала
		int material;			//материал
		double area;			//площадь (м2)
		double volume;			//обьем (м3) 
		double weight;			//вес (кг)
		//если фундамент из блоков
		BLOCK block;			//данные выбраного фундаментного блока
		int blocksCount;		//к-во блоков в фундаменте
	
	public:
		Foundation(double, double, int, int, bool);
		Foundation(const Foundation&);
		void setLength(double);			//установить длину фундамента (м)
		void setWidth(double);			//установить ширину фундамента (м)
		void setHeight(double);			//установить высоту фундамента (м)
		void setThickness(double);		//установить толщину фундамента (м)
		void setFloorCount(int);		//установить к-во этажей
		void setBasement();				//установить наличие подвала
		void resetBasement();			//установить отсутствие подвала
		void setMaterial(int);			//установить материал фундамента (FoundMaterial)
		double getLength();				//получить длину фундамента (м)
		double getWidth();				//получить ширину фундамента (м)
		double getHeight();				//получить высоту фундамента (м)
		double getThickness();			//получить толщину фундамента (м)
		int getFloorCount();			//получить к-во этажей
		bool getBasement();				//получить наличие подвала
		int getMaterial();				//получить материал фундамента (FoundMaterial)
		double getArea();				//получить площадь фундамента (м2)
		double getVolume();				//получить обьем фундамента (м3)
		double getWeight();				//получить вес фундамента (кг)
		BLOCK getSelectedBlock();		//получить тип выбраного блока
		int getBlocksCount();			//получить к-во блоков в фундаменте
		void selectBlockType();			//выбрать блок для фундамента
		void calcArea();				//рассчитать площадь фундамента
		void calcVolume();				//рассчитать обьем фундамента
		void calcWeight();				//рассчитать вес фундамента
		void calcBlocksCount();			//рассчитать к-во блоков фундамента
		void calculate();				//рассчитать все характеристики фундамента
		virtual ~Foundation();
};

Foundation::Foundation(double length,		//длина фундамента
						double width,		//ширина фундамента
						int floorCount,		//к-во этажей над фундаментом
						int material,		//материал фундамента
						bool basement)		//наличие подвала
{

}
Foundation::Foundation(const Foundation& obj)
{
	this->length = obj.length;
	this->width = obj.width;
	this->height = obj.height;
	this->thickness = obj.thickness;
	this->floorCount = obj.floorCount;
	this->basement = obj.basement;
	this->material = obj.material;
	this->area = obj.area;
	this->volume = obj.volume;
	this->weight = obj.weight;
	this->block = obj.block;
	this->blocksCount = obj.blocksCount;
}
//установить длину фундамента (м)
void Foundation::setLength(double length)
{
	this->length = length;
}
//установить ширину фундамента (м)
void Foundation::setWidth(double width)
{
	this->width = width;
}
//установить высоту фундамента (м)
void Foundation::setHeight(double height)
{
	this->height = height;
}
//установить толщину фундамента (м)
void Foundation::setThickness(double thickness)
{
	this->thickness = thickness;
}
//установить к-во этажей
void Foundation::setFloorCount(int floorCount)
{
	this->floorCount = floorCount;
}
//установить наличие подвала
void Foundation::setBasement()
{
	this->basement = true;
}
//установить отсутствие подвала
void Foundation::resetBasement()
{
	this->basement = false;
}
//установить материал фундамента (FoundMaterial)
void Foundation::setMaterial(int material)
{
	this->material = material;
}
//получить длину фундамента (м)
double Foundation::getLength()
{
	return this->length;
}
//получить ширину фундамента (м)
double Foundation::getWidth()
{
	return this->width;
}
//получить высоту фундамента (м)
double Foundation::getHeight()
{
	return this->height;
}
//получить толщину фундамента (м)
double Foundation::getThickness()
{
	return this->thickness;
}
//получить к-во этажей
int Foundation::getFloorCount()
{
	return this->floorCount;
}
//получить наличие подвала
bool Foundation::getBasement()
{
	return this->basement;
}
//получить материал фундамента (FoundMaterial)
int Foundation::getMaterial()
{
	return this->material;
}
//получить площадь фундамента (м2)
double Foundation::getArea()
{
	return this->area;
}
//получить обьем фундамента (м3)
double Foundation::getVolume()
{
	return this->volume;
}
//получить вес фундамента (кг)
double Foundation::getWeight()
{
	return this->weight;
}
//получить тип выбраного блока
BLOCK Foundation::getSelectedBlock()
{
	return this->block;
}
//получить к-во блоков в фундаменте
int Foundation::getBlocksCount()
{
	return this->blocksCount;
}
//выбрать блок для фундамента
void Foundation::selectBlockType()
{
	if ((this->material == FOUND_BLOCK) 
		&& (this->thickness > 0)
		&& (this->thickness < (BLOCK_WIDTH_600 / 1000)))
	{
		block.length = BLOCK_LENGTH_890;
		block.height = BLOCK_HEIGTH_580;
		
		if (this->thickness <= (BLOCK_WIDTH_600 / 1000))
		{
			this->thickness = BLOCK_WIDTH_600 / 1000;
			block.width = BLOCK_WIDTH_600;
			block.type = BLOCK_FBS966;
		}
		if (this->thickness <= (BLOCK_WIDTH_500 / 1000))
		{
			this->thickness = BLOCK_WIDTH_500 / 1000;
			block.width = BLOCK_WIDTH_500;
			block.type = BLOCK_FBS956;
		}
		if (this->thickness <= (BLOCK_WIDTH_400 / 1000))
		{
			this->thickness = BLOCK_WIDTH_400 / 1000;
			block.width = BLOCK_WIDTH_400;
			block.type = BLOCK_FBS946;
		}
		if (this->thickness <= (BLOCK_WIDTH_300 / 1000))
		{
			this->thickness = BLOCK_WIDTH_300 / 1000;
			block.width = BLOCK_WIDTH_300;
			block.type = BLOCK_FBS936;
		}
	}
}
//рассчитать площадь фундамента
void Foundation::calcArea()
{
	double commonArea = this->length * this->width;
	double emptyArea =
		(this->length - this->thickness * 2) *
		(this->width - this->thickness * 2);
	this->area = commonArea - emptyArea;
}
//рассчитать обьем фундамента
void Foundation::calcVolume()
{
	this->volume = this->area * this->height;
}
//рассчитать вес фундамента
void Foundation::calcWeight()
{
	switch (this->material)
	{
		case FOUND_CONCRETE:
			this->weight = this->volume * FOUND_CONCRETE_WEIGHT;
			break;
		case FOUND_BLOCK:
			this->weight = this->volume * FOUND_BLOCK_WEIGHT;
			break;
		case FOUND_STONE:
			this->weight = this->volume * FOUND_STONE_WEIGHT;
			break;
		default:
			this->weight = 0;
			break;
	}
}
//рассчитать к-во блоков фундамента
void Foundation::calcBlocksCount()
{

}
//рассчитать все характеристики фундамента
void Foundation::calculate()
{
	this->calcArea();
	this->calcVolume();

	if (this->material == FOUND_BLOCK)
	{
		this->selectBlockType();
		this->calcBlocksCount();
	}

	this->calcWeight();
}
Foundation::~Foundation()
{
}