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
	//довжина будинку
	double houseLength = 10.5;
	//ширина будинку
	double houseWidth = 12.5;
	//довжина криші
	double roofLength;
	//висота фронтону
	double frontonHeight;
	// довжина стропіли
	double reftersLength;
	// відстань між стропілами
	double reftersWidth;
	// ширина шифера
	double slateWidth;
	// довжина шефера
	double slateLength;
	//ширина накладання шифера
	double slateLayingOn;
	//ширина металочерепиці
	double tilingWidth;
	//довжина металочерепиці
	double tilingLength;
	//ширина накладання металочерепиці
	double tilingLayingOn;
	int roofType;
	int reftersAmount = 0;
	int slateAmount = 0;
	int tilingAmount = 0;
	double reftersPrice;
	double slatePrice;
	double tilingPrice;
};

