#pragma once
#include "stdafx.h"

class Roof
{
public:
	Roof(double houseLength, double houseWidth, int roofType);
	~Roof();

	void PifagorTheorem();
	void roofSize();
	void roofPrice();
	void getReftersAmount(); //�������
	void getSlateAmount(); //�����
	void getTilingAmount(); //��������������
	void getRuberoidAmount(); //�������;
	

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
	int reftersAmount;
	int slateAmount;
	int tilingAmount;
	int ruberoidAmount;


	/*double reftersPrice;
	double slatePrice;
	double tilingPrice;
	double ruberoidPrice;*/
};

