#include "stdafx.h"
#include "Roof.h"

Roof::Roof() {
}

Roof::~Roof() {
}

void Roof::getSizes() {
	string str, size;
	int found;
	Read.open("roofMaterialsSizes.txt");
	if (!Read.is_open()) {
		cout << "Could not open file!!!" << endl;
	}
	else {
			getline(Read, str);
			found = str.find_first_of(" ");
			size = str.substr(found + 1);
			frontonHeight = stod(size);

			getline(Read, str);
			found = str.find_first_of(" ");
			size = str.substr(found + 1);
			reftersLength = stod(size);

			getline(Read, str);
			found = str.find_first_of(" ");
			size = str.substr(found + 1);
			reftersWidth = stod(size);

			getline(Read, str);
			found = str.find_first_of(" ");
			size = str.substr(found + 1);
			slateWidth = stod(size);

			getline(Read, str);
			found = str.find_first_of(" ");
			size = str.substr(found + 1);
			slateLength = stod(size);

			getline(Read, str);
			found = str.find_first_of(" ");
			size = str.substr(found + 1);
			slateLayingOn = stod(size);

			getline(Read, str);
			found = str.find_first_of(" ");
			size = str.substr(found + 1);
			tilingWidth = stod(size);

			getline(Read, str);
			found = str.find_first_of(" ");
			size = str.substr(found + 1);
			tilingLength = stod(size);

			getline(Read, str);
			found = str.find_first_of(" ");
			size = str.substr(found + 1);
			tilingLayingOn = stod(size);
		}
	Read.close();
}

void Roof::getPrices() {
	string str, price;
	int found;
	Read.open("roofMaterialsPrices.txt");
	if (!Read.is_open()) {
		cout << "Could not open file!!!" << endl;
	}
	else {
		getline(Read, str);
		found = str.find_first_of(" ");
		price = str.substr(found + 1);
		reftersPrice = stod(price);

		getline(Read, str);
		found = str.find_first_of(" ");
		price = str.substr(found + 1);
		slatePrice = stod(price);

		getline(Read, str);
		found = str.find_first_of(" ");
		price = str.substr(found + 1);
		tilingPrice = stod(price);
	}
	Read.close();
}

void Roof::PifagorTheorem() {
	this->getSizes();
	roofLength = sqrt((houseWidth/2) * (houseWidth/2) + frontonHeight * frontonHeight); //довжина криші
}

void Roof::roofSize() {
	this->getSizes();

	// визначення довжини криші
	this->PifagorTheorem();

	//визначення кількості стропіл з двох сторін будинку
	double reftersAmountHeight = ceil(roofLength / reftersLength); //кількістьстропіл по висоті
	reftersAmount = ((ceil(houseLength / reftersWidth) + 1) * reftersAmountHeight) * 2; //загальна кількість стропіл з двох сторін будинку

	cout << "Enter the type of root: 0 for slate, 1 for tiling" << endl;
	cin >> roofType;

	//визначення кількості шиферу
	if (roofType == 0) {
		double slateAmountHeight = 1; //кількість необхідного шиферу по висоті
		double tmp = slateLength - slateLayingOn;
		while (true) {
			if (slateLength >= roofLength) {
				break;
			}
			else {
				slateAmountHeight++;
				slateLength += tmp;
			}
		}

		slateAmount = (int) (ceil(houseLength / slateWidth) * slateAmountHeight) * 2; //загальна кількість шиферу = визначена кількість шиферу по довжині будинку помножена на кількість по висоті 
	}
	//визначення кількості металочерепиці
	else if (roofType == 1) {
		double tilingAmountHeight = 1; //кількість необхідної металочерепиці по висоті
		double tmp = tilingLength - tilingLayingOn;
		while (true) {
			if (tilingLength >= roofLength) {
				break;
			}
			else {
				tilingAmountHeight++;
				tilingLength += tmp;
			}
		}

		tilingAmount = (ceil(houseLength / tilingWidth) * tilingAmountHeight) * 2; //загальна кількість металочерепиці = визначена кількість металочерепиці по довжині будинку помножена на кількість по висоті 
	}
	else if (roofType == 3) {
		squareRoof = houseLength * houseWidth;
	}
}

void Roof::roofPrice() {
	this->getSizes();
	this->getPrices();
	this->roofSize();

	double reftersCost, slateCost, tilingCost, ruberoidCost, generalRoofCost;
	//вартість стропіл
	reftersCost = reftersAmount * reftersLength * reftersPrice;
	//вартість шиферу або металочерепиці
	if (roofType == 0) {
		slateCost = slateAmount * slatePrice;
		generalRoofCost = reftersCost + slateCost;
	}
	else if (roofType == 1) {
		tilingCost = tilingAmount * tilingPrice;
		generalRoofCost = reftersCost + tilingCost;
	}
	else if (roofType == 3) {
		ruberoidCost = squareRoof * ruberoidPrice;
	}

	cout << "General cost of the roof is: " << generalRoofCost << endl;
}