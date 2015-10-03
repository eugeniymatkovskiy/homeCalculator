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
	void getReftersAmount(); //стропіли
	void getSlateAmount(); //шифер
	void getTilingAmount(); //металочерепиця
	void getRuberoidAmount(); //рубероїд;
	

protected:
	ifstream Read;
	ofstream Write;
	
	double houseLength;//довжина будинку
	double houseWidth;//ширина будинку
	double roofLength;//довжина криші
	double squareRoof;//площа криші
	double frontonHeight;//висота фронтону
	double reftersLength;// довжина стропіли
	double reftersWidth;// відстань між стропілами
	double slateWidth;// ширина шифера
	double slateLength;// довжина шефера
	double slateLayingOn;//ширина накладання шифера
	double tilingWidth;//ширина металочерепиці
	double tilingLength;//довжина металочерепиці
	double tilingLayingOn;//ширина накладання металочерепиці
	int roofType;
	int reftersAmount;
	int slateAmount;
	int tilingAmount;
	double reftersPrice;
	double slatePrice;
	double tilingPrice;
	double ruberoidPrice;
};

