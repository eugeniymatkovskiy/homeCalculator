#pragma once

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
	double houseLength;
	//������ �������
	double houseWidth;
	//������� �����
	double roofLength;
	//����� �����
	double squareRoof;
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
	int reftersAmount;
	int slateAmount;
	int tilingAmount;
	double reftersPrice;
	double slatePrice;
	double tilingPrice;
	double ruberoidPrice;
};

