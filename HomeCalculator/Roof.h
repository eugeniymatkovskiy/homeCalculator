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
	int getReftersAmount(); //строп≥ли
	int getSlateAmount(); //шифер
	int getTilingAmount(); //металочерепиц€
	int getRuberoidAmount(); //рубероњд;
	int getRoofType();
	void addMaterials(vector<MATERIAL*>*,
		vector<MATERIAL*>*);	//считать и добавить материалы в новый список
	

protected:
	ifstream Read;
	ofstream Write;
	
	double houseLength;//довжина будинку
	double houseWidth;//ширина будинку
	double roofLength;//довжина криш≥
	double frontonHeight;//висота фронтону
	double reftersLength;// довжина строп≥ли
	double reftersWidth;// ширина строп≥ли
	double reftersWidthBetween; //в≥дстань м≥ж строп≥лами 
	double slateWidth;// ширина шифера
	double slateLength;// довжина шефера
	double slateLayingOn;//ширина накладанн€ шифера
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

