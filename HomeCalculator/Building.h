#pragma once
#include "HomeCalculator.h"
#include "Foundation.h"


class Building
{
	private:
		double length;						//����� (�)
		double width;						//������ (�)
		int floorCount;						//�-�� ������
		Foundation* foundation;				//���������
		//Floor* floor;						//����(�)
		//Roof* roof;						//�����

	protected:
		//void calcFoundationMaterials();		//���������� ��������� ��� ����������
		//void calcFloorsMaterials();			//���������� ��������� ��� �����(��)
		//void calcRoofMaterials();			//���������� ��������� ��� �����

	public:
		Building();
		Building(double, double, int);
		Building(const Building&);
		void setLength(double);						//���������� ����� ������ (�)
		void setWidth(double);						//���������� ������ ������ (�)
		void setfloorCount(int);					//���������� �-�� ������ (�)
		double getLength();							//�������� ����� ������ (�)
		double getWidth();							//�������� ������ ������ (�)
		int getfloorCount();						//�������� ������ ������ (�)
		void createFoundation(int, bool);			//������� ���������
		void calculate();							//��������� ��� ��������� 
		void addMaterials(vector<MATERIAL>&);		//�������� ��������� � ������
		//void createFloor();						//������� ����
		//void createRoof();						//������� �����
		~Building();
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

}
//�������� ����������
void Building::createFoundation(int material, bool basement)
{
	this->foundation = new Foundation(	this->getLength(), 
							   			this->getWidth(), 
										this->getfloorCount(), 
										material, 
										basement);
}
//��������� ��� ��������� 
void Building::calculate()
{
	this->foundation->calculate();
}
//�������� ��������� � ������
void Building::addMaterials(vector<MATERIAL>& materials)
{
	this->foundation->addMaterials(materials);
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
}

