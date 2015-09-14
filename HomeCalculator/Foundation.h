#pragma once
#include "stdafx.h"


class Foundation
{
	private:
		double length;				//����� (�)
		double width;				//������ (�)
		double height;				//������ (�)
		double thickness;			//������� (�)
		int floorCount;				//�-�� ������
		bool basement;				//������� �������
		int material;				//��������
		double area;				//������� (�2)
		double volume;				//����� (�3) 
		//���� ��������� �� ������
		double concreteWeight;		//��� (��)
		//���� ��������� �� �����
		double stoneWeight;			//��� (��)
		//���� ��������� �� ������
		BLOCK block;				//������ ��������� ������������� �����
		int blocksCount;			//�-�� ������ � ����������
	
	public:
		Foundation(double, double, int, int, bool);
		Foundation(const Foundation&);
		void setLength(double);			//���������� ����� ���������� (�)
		void setWidth(double);			//���������� ������ ���������� (�)
		void setHeight(double);			//���������� ������ ���������� (�)
		void setThickness(double);		//���������� ������� ���������� (�)
		void setFloorCount(int);		//���������� �-�� ������
		void setBasement();				//���������� ������� �������
		void resetBasement();			//���������� ���������� �������
		void setMaterial(int);			//���������� �������� ���������� (FoundMaterial)
		double getLength();				//�������� ����� ���������� (�)
		double getWidth();				//�������� ������ ���������� (�)
		double getHeight();				//�������� ������ ���������� (�)
		double getThickness();			//�������� ������� ���������� (�)
		int getFloorCount();			//�������� �-�� ������
		bool getBasement();				//�������� ������� �������
		int getMaterial();				//�������� �������� ���������� (FoundMaterial)
		double getArea();				//�������� ������� ���������� (�2)
		double getVolume();				//�������� ����� ���������� (�3)
		double getConcreteWeight();		//�������� ��� ������� � ���������� (��)
		double getStoneWeight();		//�������� ��� ����� � ���������� (��)
		BLOCK getSelectedBlock();		//�������� ��� ��������� �����
		int getBlocksCount();			//�������� �-�� ������ � ����������
		void selectBlockType();			//������� ���� ��� ����������
		void calcArea();				//���������� ������� ����������
		void calcVolume();				//���������� ����� ����������
		void calcConcreteWeight();		//���������� ��� ������ � ����������
		void calcStoneWeight();			//���������� ��� ����� � ����������
		void calcBlocksCount();			//���������� �-�� ������ ����������
		void calculate();				//���������� ��� �������������� ����������
		virtual ~Foundation();
};

Foundation::Foundation(double length,		//����� ����������
						double width,		//������ ����������
						int floorCount,		//�-�� ������ ��� �����������
						int material,		//�������� ����������
						bool basement)		//������� �������
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
	this->concreteWeight = obj.concreteWeight;
	this->stoneWeight = obj.stoneWeight;
	this->block = obj.block;
	this->blocksCount = obj.blocksCount;
}
//���������� ����� ���������� (�)
void Foundation::setLength(double length)
{
	this->length = length;
}
//���������� ������ ���������� (�)
void Foundation::setWidth(double width)
{
	this->width = width;
}
//���������� ������ ���������� (�)
void Foundation::setHeight(double height)
{
	this->height = height;
}
//���������� ������� ���������� (�)
void Foundation::setThickness(double thickness)
{
	this->thickness = thickness;
}
//���������� �-�� ������
void Foundation::setFloorCount(int floorCount)
{
	this->floorCount = floorCount;
}
//���������� ������� �������
void Foundation::setBasement()
{
	this->basement = true;
}
//���������� ���������� �������
void Foundation::resetBasement()
{
	this->basement = false;
}
//���������� �������� ���������� (FoundMaterial)
void Foundation::setMaterial(int material)
{
	this->material = material;
}
//�������� ����� ���������� (�)
double Foundation::getLength()
{
	return this->length;
}
//�������� ������ ���������� (�)
double Foundation::getWidth()
{
	return this->width;
}
//�������� ������ ���������� (�)
double Foundation::getHeight()
{
	return this->height;
}
//�������� ������� ���������� (�)
double Foundation::getThickness()
{
	return this->thickness;
}
//�������� �-�� ������
int Foundation::getFloorCount()
{
	return this->floorCount;
}
//�������� ������� �������
bool Foundation::getBasement()
{
	return this->basement;
}
//�������� �������� ���������� (FoundMaterial)
int Foundation::getMaterial()
{
	return this->material;
}
//�������� ������� ���������� (�2)
double Foundation::getArea()
{
	return this->area;
}
//�������� ����� ���������� (�3)
double Foundation::getVolume()
{
	return this->volume;
}
//�������� ��� ������� � ���������� (��)
double Foundation::getConcreteWeight()
{
	return this->concreteWeight;
}
//�������� ��� ����� � ���������� (��)
double Foundation::getStoneWeight()
{
	return this->stoneWeight;
}
//�������� ��� ��������� �����
BLOCK Foundation::getSelectedBlock()
{
	return this->block;
}
//�������� �-�� ������ � ����������
int Foundation::getBlocksCount()
{
	return this->blocksCount;
}
//������� ���� ��� ����������
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
//���������� ������� ����������
void Foundation::calcArea()
{
	double commonArea = this->length * this->width;
	double emptyArea =
		(this->length - this->thickness * 2) *
		(this->width - this->thickness * 2);
	this->area = commonArea - emptyArea;
}
//���������� ����� ����������
void Foundation::calcVolume()
{
	this->volume = this->area * this->height;
}
//���������� ��� ������� � ����������
void Foundation::calcConcreteWeight()
{
	double concreteVolume;

	switch (this->material)
	{
	case FOUND_CONCRETE:
		this->concreteWeight = this->volume * FOUND_CONCRETE_WEIGHT;
		break;
	case FOUND_BLOCK:
		concreteVolume = this->volume * FOUND_CONCRETE_IN_BLOCK;
		this->concreteWeight = concreteVolume * FOUND_CONCRETE_WEIGHT;
		break;
	case FOUND_STONE:
		concreteVolume = this->volume * FOUND_CONCRETE_IN_STONE;
		this->concreteWeight = concreteVolume * FOUND_CONCRETE_WEIGHT;
		break;
	default:
		this->concreteWeight = 0;
		break;
	}
}
//���������� ��� ����� � ����������
void Foundation::calcStoneWeight()
{
	if (this->material == FOUND_STONE)
	{
		double stoneVolume = this->volume * (1-FOUND_CONCRETE_IN_STONE);
		this->stoneWeight = stoneVolume * FOUND_STONE_WEIGHT;
	}
}

//���������� �-�� ������ ����������
void Foundation::calcBlocksCount()
{

}
//���������� ��� �������������� ����������
void Foundation::calculate()
{
	this->calcArea();
	this->calcVolume();

	if (this->material == FOUND_CONCRETE)
	{
		this->calcConcreteWeight();
	}
	if (this->material == FOUND_STONE)
	{
		this->calcStoneWeight();
		this->calcConcreteWeight();
	}
	if (this->material == FOUND_BLOCK)
	{
		this->selectBlockType();
		this->calcBlocksCount();
		this->calcConcreteWeight();
	}

}
Foundation::~Foundation()
{
}