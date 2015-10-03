#pragma once
#include "stdafx.h"

class Roof
{
public:
	Roof();
	~Roof();

	void PifagorTheorem();
	void roofSize();
	void roofPrice();
	void getPrices();
	void getSizes();

protected:
	ifstream Read;
	ofstream Write;
	//������� �������
	double houseLength = 10.5;
	//������ �������
	double houseWidth = 12.5;
	//������� �����
	double roofLength;
	//������ ��������
	double frontonHeight;
	// ������� �������
	double reftersLength;
	// ������� �� ���������
	double reftersWidth;
	// ������ ������
	double slateWidth;
	// ������� ������
	double slateLength;
	//������ ���������� ������
	double slateLayingOn;
	//������ ��������������
	double tilingWidth;
	//������� ��������������
	double tilingLength;
	//������ ���������� ��������������
	double tilingLayingOn;
	int roofType;
	int reftersAmount = 0;
	int slateAmount = 0;
	int tilingAmount = 0;
	double reftersPrice;
	double slatePrice;
	double tilingPrice;
};

