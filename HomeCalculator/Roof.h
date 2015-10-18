#pragma once
#include "stdafx.h"

class Roof
{
public:
	Roof(double houseLength, double houseWidth, int roofType, int typeBuild);
	~Roof();

	void PifagorTheorem();
	void roofSize();
	void roofPrice();
	int getReftersAmount(); //�������
	int getSlateAmount(); //�����
	int getTilingAmount(); //��������������
	int getRuberoidAmount(); //�������;
	int getRoofType();
	void addMaterials(vector<MATERIAL*>*,
		vector<MATERIAL*>*);	//������� � �������� ��������� � ����� ������
	

protected:
	ifstream Read;
	ofstream Write;
	
	double houseLength;//������� �������
	double houseWidth;//������ �������
	double roofLength;//������� �����
	double frontonHeight;//������ ��������
	double reftersLength;// ������� �������
	double reftersWidth;// ������ �������
	double reftersWidthBetween; //������� �� ��������� 
	double slateWidth;// ������ ������
	double slateLength;// ������� ������
	double slateLayingOn;//������ ���������� ������
	int roofType;
	int typeBuild;
	int reftersAmount;
	int slateAmount;
	int tilingAmount;
	int ruberoidAmount;


	/*double reftersPrice;
	double slatePrice;
	double tilingPrice;
	double ruberoidPrice;*/
};

