#include "Roof.h"
#include "HomeCalculator.h"

Roof::Roof(double houseLength, double houseWidth, int roofType, int typeBuild) {
	this->houseLength = houseLength;
	this->houseWidth = houseWidth;
	this->roofType = roofType;
	this->typeBuild = typeBuild;
	this->frontonHeight = 4;//висота фронтону
	this->reftersLength = 4.5;// довжина стропіли
	this->reftersWidthBetween = 1; //відстань між стропілами
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

	//cout << "Enter the type of root: 0 for slate, 1 for tiling" << endl;
	//cin >> roofType;

	//визначення кількості шиферу
	if (this->roofType == ROOF_SLATE_ID) {
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
		//cout << "General slate amount: " << this->slateAmount << endl;
		//cout << "General refters amount: " << this->reftersAmount << endl;
	}
	//визначення кількості металочерепиці
	else if (this->roofType == ROOF_TILING_ID) {
		double squareHomeRoof;
		squareHomeRoof = this->houseLength * this->roofLength * 2; //площа криші з обох боків
		this->tilingAmount = ceil(squareHomeRoof);
 
		//cout << "General tiling amount: " << this->tilingAmount << endl;
		//cout << "General refters amount: " << this->reftersAmount << endl;
	}
	else if (this->typeBuild == 2 || this->typeBuild == 3) {
		double squareGarageRoof;
		squareGarageRoof = this->houseLength * this->houseWidth;
		this->tilingAmount = ceil(squareGarageRoof);
		//cout << "General amount square meters of ruberoid: " << this->ruberoidAmount << endl;
	}	
}

int Roof::getReftersAmount(){
	return this->reftersAmount;
}

int Roof::getSlateAmount(){
	return this->slateAmount;
}

int Roof::getTilingAmount(){
	return this->tilingAmount;
}

int Roof::getRuberoidAmount(){
	return this->ruberoidAmount;
}

int Roof::getRoofType(){
	return this->roofType;
}

//считать и добавить материалы в новый список
void Roof::addMaterials(vector<MATERIAL*>* mtrl, vector<MATERIAL*>* calcMtrl){

	MATERIAL* tmpMaterial;


	//************ добавляем к-во стропил **************

	//проверяем наличие стропил для изготовления крыши
	if (this->getReftersAmount())
	{
		for (int i = 0; i < mtrl->size(); i++)
		{
			if ((*mtrl)[i]->id == ROOF_REFTERS_ID)
			{
				//копируем материал
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*mtrl)[i];
				//добавляем к-во материала
				tmpMaterial->count = this->getReftersAmount();
				//добавляем материал в новый список
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}

	//************ добавляем к-во шифера **************

	//проверяем наличие шифера для изготовления крыши
	if (this->getSlateAmount())
	{
		for (int i = 0; i < mtrl->size(); i++)
		{
			if ((*mtrl)[i]->id == ROOF_SLATE_ID)
			{
				//копируем материал
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*mtrl)[i];
				//добавляем к-во материала
				tmpMaterial->count = this->getSlateAmount();
				//добавляем материал в новый список
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}

	//************ добавляем к-во металочерепици **************

	//проверяем наличие металочерепици для изготовления крыши
	if (this->getTilingAmount())
	{
		for (int i = 0; i < mtrl->size(); i++)
		{
			if ((*mtrl)[i]->id == ROOF_TILING_ID)
			{
				//копируем материал
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*mtrl)[i];
				//добавляем к-во материала
				tmpMaterial->count = this->getTilingAmount();
				//добавляем материал в новый список
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}

	//************ добавляем к-во рубероида **************

	//проверяем наличие рубероида для изготовления крыши
	if (this->getRuberoidAmount())
	{
		for (int i = 0; i < mtrl->size(); i++)
		{
			if ((*mtrl)[i]->id == ROOF_RUBEROID_ID)
			{
				//копируем материал
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*mtrl)[i];
				//добавляем к-во материала
				tmpMaterial->count = this->getRuberoidAmount();
				//добавляем материал в новый список
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}
}