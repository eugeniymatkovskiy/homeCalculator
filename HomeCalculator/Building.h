#pragma once
#include "HomeCalculator.h"
#include "Foundation.h"


class Building
{
	private:
		double length;						//����� (�)
		double width;						//������ (�)
		double height;						//������ (�)
		int floorCount;						//�-�� ������
		Foundation* foundation;				//���������
		//Floor* floor;						//����(�)
		//Roof* roof;						//�����

	protected:
		void calcFoundationMaterials();		//���������� ��������� ��� ����������
		void calcFloorsMaterials();			//���������� ��������� ��� �����(��)
		void calcRoofMaterials();			//���������� ��������� ��� �����

	public:
		Building(double, double, int);
		Building(const Building&);
		void setLength(double);						//���������� ����� ������ (�)
		void setWidth(double);						//���������� ������ ������ (�)
		void setHeight(double);						//���������� ������ ������ (�)
		double getLength();							//�������� ����� ������ (�)
		double getWidth();							//�������� ������ ������ (�)
		double getHeight();							//�������� ������ ������ (�)
		void createFoundation(int, bool);			//������� ���������
		//void createFloor();						//������� ����
		//void createRoof();						//������� �����
		~Building();
};
