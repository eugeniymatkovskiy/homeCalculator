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
		vector<MATERIAL*> materials;		//������ ����������
		Foundation* foundation;				//���������
		//Floor* floor;						//����(�)
		//Roof* roof;						//�����

	protected:
		void calcFoundationMaterials();		//���������� ��������� ��� ����������
		void calcFloorsMaterials();			//���������� ��������� ��� �����(��)
		void calcRoofMaterials();			//���������� ��������� ��� �����

	public:
		void setLength(double);				//���������� ����� ������ (�)
		void setWidth(double);				//���������� ������ ������ (�)
		void setHeight(double);				//���������� ������ ������ (�)
		double getLength();					//�������� ����� ������ (�)
		double getWidth();					//�������� ������ ������ (�)
		double getHeight();					//�������� ������ ������ (�)
		vector<MATERIAL*> getMaterials();	//�������� ������ ���� ���������� 
};
