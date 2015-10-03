#pragma once
#include "stdafx.h"

class Roof
{
public:
	Roof(double houseLength, double houseWidth, int roofType, double reftersPrice, double slatePrice, double tilingPrice, double ruberoidPrice);
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
	double squareRoof;//����� �����
	double frontonHeight;//������ ��������
	double reftersLength;// ������� �������
	double reftersWidth;// ������� �� ���������
	double slateWidth;// ������ ������
	double slateLength;// ������� ������
	double slateLayingOn;//������ ���������� ������
	double tilingWidth;//������ ��������������
	double tilingLength;//������� ��������������
	double tilingLayingOn;//������ ���������� ��������������
	int roofType;
	int reftersAmount;
	int slateAmount;
	int tilingAmount;
	double reftersPrice;
	double slatePrice;
	double tilingPrice;
	double ruberoidPrice;
};

