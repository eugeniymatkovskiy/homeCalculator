#pragma once
#include "HomeCalculator.h"
#include "Foundation.h"
#include "Roof.h"
#include "Wall.h"


class Building
{
private:
	double length;						//����� (�)
	double width;						//������ (�)
	int floorCount;						//�-�� ������


protected:
	//Foundation* foundation;				//���������
	//Floor* floor;						//����(�)
	//Roof* roof;						//�����

	//void calcFoundationMaterials();		//���������� ��������� ��� ����������
	//void calcFloorsMaterials();			//���������� ��������� ��� �����(��)
	//void calcRoofMaterials();			//���������� ��������� ��� �����

public:
	Building();
	Building(double, double, int);
	Building(const Building&);
	void setLength(double);									//���������� ����� ������ (�)
	void setWidth(double);									//���������� ������ ������ (�)
	void setfloorCount(int);								//���������� �-�� ������ (�)
	double getLength();										//�������� ����� ������ (�)
	double getWidth();										//�������� ������ ������ (�)
	int getfloorCount();									//�������� ������ ������ (�)
	void createFoundation(int, bool);						//������� ���������
	void createWall(int, int);								//������� ����
	void createRoof(int, int);									//������� �����
	virtual void calculate() = 0;							//��������� ��� ��������� 
	virtual void addMaterials(	vector<MATERIAL*>*,
								vector<MATERIAL*>*) = 0;	//�������� ��������� � ������
	Foundation* foundation;									//���������
	Wall* wall;											//����
	Roof* roof;												//�����
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
//�������� ����������
void Building::createFoundation(int material, bool basement)
{
	this->foundation = new Foundation(this->getLength(),
		this->getWidth(),
		this->getfloorCount(),
		material,
		basement);
}
//�������� �����
void Building::createWall(int buildType, int material)
{
	this->wall = new Wall(this->getLength(),
		this->getWidth(),
		this->getfloorCount(),
		buildType,
		material);
}
//�������� �����
void Building::createRoof(int roofType, int buildType)
{
	this->roof = new Roof(this->getLength(),
		this->getWidth(),
		roofType,
		buildType);
}
//���������� ����� ������ (�)
void Building::setLength(double length)
{
	this->length = length;
}
//���������� ������ ������ (�)
void Building::setWidth(double width)
{
	this->width = width;
}
//���������� ������ ������ (�)
void Building::setfloorCount(int floorCount)
{
	this->floorCount = floorCount;
}
//�������� ����� ������ (�)
double Building::getLength()
{
	return this->length;
}
//�������� ������ ������ (�)
double Building::getWidth()
{
	return this->width;
}
//���������� �-�� ������
int Building::getfloorCount()
{
	return this->floorCount;
}
Building::~Building()
{
	delete this->foundation;
	delete this->wall;
	delete this->roof;
}

