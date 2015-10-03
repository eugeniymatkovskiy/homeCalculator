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
	//довжина будинку
	double houseLength;
	//ширина будинку
	double houseWidth;
	//довжина криші
	double roofLength;
	//площа криші
	double squareRoof;
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
	int reftersAmount;
	int slateAmount;
	int tilingAmount;
	double reftersPrice;
	double slatePrice;
	double tilingPrice;
	double ruberoidPrice;
};

