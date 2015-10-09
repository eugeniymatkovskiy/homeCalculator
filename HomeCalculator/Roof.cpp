#include "Roof.h"

Roof::Roof(double houseLength, double houseWidth, int roofType) {
	this->houseLength = houseLength;
	this->houseWidth = houseWidth;
	this->roofType = roofType;
	this->frontonHeight = 4;//висота фронтону
	this->reftersLength = 4,5;// довжина стропіли
	this->reftersWidthBetween = 0.50; //відстань між стропілами
	this->reftersWidth = 0.50;// ширина стропіли
	this->slateWidth = 1.13;// ширина шифера
	this->slateLength = 1.75;// довжина шифера
	this->slateLayingOn = 0.20;//ширина накладання шифера

	//отримання цін на матеріали
	//this->reftersPrice = reftersPrice; //за метр квадратний стропіл
	//this->slatePrice = slatePrice;
	//this->tilingPrice = tilingPrice;
	//this->ruberoidPrice = ruberoidPrice;
}

Roof::~Roof() {
}

void Roof::PifagorTheorem() {
	this->roofLength = sqrt((this->houseWidth / 2) * (this->houseWidth / 2) + this->frontonHeight * this->frontonHeight); //довжина криші
}

void Roof::roofSize() {
	this->PifagorTheorem();// визначення довжини криші

	//визначення кількості стропіл з двох сторін будинку
	double reftersAmountHeight = ceil(this->roofLength / this->reftersLength); //кількість стропіл по висоті
	double reftersAmountInMeter = (ceil(this->houseLength / (this->reftersWidth + this->reftersWidthBetween) + 1) * reftersAmountHeight) * 2; //загальна кількість стропіл з двох сторін будинку
	this->reftersAmount = (this->reftersLength * this->reftersWidth * 0.50) * reftersAmountInMeter;

	cout << "Enter the type of root: 0 for slate, 1 for tiling" << endl;
	cin >> roofType;

	//визначення кількості шиферу
	if (this->roofType == 0) {
		double slateAmountHeight = 1; //кількість необхідного шиферу по висоті
		double tmp = this->slateLength - this->slateLayingOn;
		while (true) {
			if (this->slateLength >= this->roofLength) {
				break;
			}
			else {
				slateAmountHeight++;
				this->slateLength += tmp;
			}
		}
		this->slateAmount = (int)(ceil(this->houseLength / this->slateWidth) * slateAmountHeight) * 2; //загальна кількість шиферу = визначена кількість шиферу по довжині будинку помножена на кількість по висоті 
		cout << "General slate amount: " << this->slateAmount << endl;
		cout << "General refters amount: " << this->reftersAmount << endl;
	}
	//визначення кількості металочерепиці
	else if (this->roofType == 1) {
		double squareHomeRoof;
		squareHomeRoof = this->houseLength * this->roofLength * 2; //площа криші з обох боків
		this->tilingAmount = ceil(squareHomeRoof);
		//double tilingAmountHeight = 1; //кількість необхідної металочерепиці по висоті
		//double tmp = this->tilingLength - this->tilingLayingOn;
		//while (true) {
		//	if (this->tilingLength >= this->roofLength) {
		//		break;
		//	}
		//	else {
		//		tilingAmountHeight++;
		//		this->tilingLength += tmp;
		//	}
		//}
		//this->tilingAmount = (ceil(this->houseLength / this->tilingWidth) * tilingAmountHeight) * 2; //загальна кількість металочерепиці = визначена кількість металочерепиці по довжині будинку помножена на кількість по висоті 
		cout << "General tiling amount: " << this->tilingAmount << endl;
		cout << "General refters amount: " << this->reftersAmount << endl;
	}
	else if (this->roofType == 2) {
		double squareGarageRoof;
		squareGarageRoof = this->houseLength * this->houseWidth;
		this->tilingAmount = ceil(squareGarageRoof);
		cout << "General amount square meters of ruberoid: " << this->ruberoidAmount << endl;
	}	
}

//void Roof::roofPrice() {
//	this->roofSize();
//
//	double reftersCost, slateCost, tilingCost, ruberoidCost, generalRoofCost;
//	//вартість стропіл
//	reftersCost = this->reftersAmount * this->reftersPrice;
//	if (this->roofType == 0) {
//		slateCost = this->slateAmount * this->slatePrice;
//		generalRoofCost = reftersCost + slateCost;
//	}
//	else if (this->roofType == 1) {
//		tilingCost = this->tilingAmount * this->tilingPrice;
//		generalRoofCost = reftersCost + tilingCost;
//	}
//	else if (this->roofType == 2) {
//		ruberoidCost = this->ruberoidAmount * this->ruberoidPrice;
//		generalRoofCost = ruberoidCost;
//	}
//
//	cout << "General cost of the roof is: " << generalRoofCost << endl;
//}

void Roof::getReftersAmount(){
	this->reftersAmount;
}

void Roof::getSlateAmount(){
	this->slateAmount;
}

void Roof::getTilingAmount(){
	this->tilingAmount;
}

void Roof::getRuberoidAmount(){
	this->ruberoidAmount;
}