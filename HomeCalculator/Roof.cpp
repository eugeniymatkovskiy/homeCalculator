#include "Roof.h"
#include "HomeCalculator.h"

Roof::Roof(double houseLength, double houseWidth, int roofType, int typeBuild) {
	this->houseLength = houseLength;
	this->houseWidth = houseWidth;
	this->roofType = roofType;
	this->typeBuild = typeBuild;
	this->frontonHeight = 4;//������ ��������
	this->reftersLength = 4.5;// ������� �������
	this->reftersWidthBetween = 1; //������� �� ���������
	this->reftersWidth = 0.50;// ������ �������
	this->slateWidth = 1.13;// ������ ������
	this->slateLength = 1.75;// ������� ������
	this->slateLayingOn = 0.20;//������ ���������� ������

	//��������� ��� �� ��������
	//this->reftersPrice = reftersPrice; //�� ���� ���������� ������
	//this->slatePrice = slatePrice;
	//this->tilingPrice = tilingPrice;
	//this->ruberoidPrice = ruberoidPrice;
}

Roof::~Roof() {
}

void Roof::PifagorTheorem() {
	this->roofLength = sqrt((this->houseWidth / 2) * (this->houseWidth / 2) + this->frontonHeight * this->frontonHeight); //������� �����
}

void Roof::roofSize() {
	this->PifagorTheorem();// ���������� ������� �����

	//���������� ������� ������ � ���� ����� �������
	double reftersAmountHeight = ceil(this->roofLength / this->reftersLength); //������� ������ �� �����
	double reftersAmountInMeter = (ceil(this->houseLength / (this->reftersWidth + this->reftersWidthBetween) + 1) * reftersAmountHeight) * 2; //�������� ������� ������ � ���� ����� �������
	this->reftersAmount = (this->reftersLength * this->reftersWidth * 0.50) * reftersAmountInMeter;

	//cout << "Enter the type of root: 0 for slate, 1 for tiling" << endl;
	//cin >> roofType;

	//���������� ������� ������
	if (this->roofType == ROOF_SLATE_ID) {
		double slateAmountHeight = 1; //������� ����������� ������ �� �����
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
		this->slateAmount = (int)(ceil(this->houseLength / this->slateWidth) * slateAmountHeight) * 2; //�������� ������� ������ = ��������� ������� ������ �� ������ ������� ��������� �� ������� �� ����� 
		//cout << "General slate amount: " << this->slateAmount << endl;
		//cout << "General refters amount: " << this->reftersAmount << endl;
	}
	//���������� ������� ��������������
	else if (this->roofType == ROOF_TILING_ID) {
		double squareHomeRoof;
		squareHomeRoof = this->houseLength * this->roofLength * 2; //����� ����� � ���� ����
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

//������� � �������� ��������� � ����� ������
void Roof::addMaterials(vector<MATERIAL*>* mtrl, vector<MATERIAL*>* calcMtrl){

	MATERIAL* tmpMaterial;


	//************ ��������� �-�� ������� **************

	//��������� ������� ������� ��� ������������ �����
	if (this->getReftersAmount())
	{
		for (int i = 0; i < mtrl->size(); i++)
		{
			if ((*mtrl)[i]->id == ROOF_REFTERS_ID)
			{
				//�������� ��������
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*mtrl)[i];
				//��������� �-�� ���������
				tmpMaterial->count = this->getReftersAmount();
				//��������� �������� � ����� ������
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}

	//************ ��������� �-�� ������ **************

	//��������� ������� ������ ��� ������������ �����
	if (this->getSlateAmount())
	{
		for (int i = 0; i < mtrl->size(); i++)
		{
			if ((*mtrl)[i]->id == ROOF_SLATE_ID)
			{
				//�������� ��������
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*mtrl)[i];
				//��������� �-�� ���������
				tmpMaterial->count = this->getSlateAmount();
				//��������� �������� � ����� ������
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}

	//************ ��������� �-�� �������������� **************

	//��������� ������� �������������� ��� ������������ �����
	if (this->getTilingAmount())
	{
		for (int i = 0; i < mtrl->size(); i++)
		{
			if ((*mtrl)[i]->id == ROOF_TILING_ID)
			{
				//�������� ��������
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*mtrl)[i];
				//��������� �-�� ���������
				tmpMaterial->count = this->getTilingAmount();
				//��������� �������� � ����� ������
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}

	//************ ��������� �-�� ��������� **************

	//��������� ������� ��������� ��� ������������ �����
	if (this->getRuberoidAmount())
	{
		for (int i = 0; i < mtrl->size(); i++)
		{
			if ((*mtrl)[i]->id == ROOF_RUBEROID_ID)
			{
				//�������� ��������
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*mtrl)[i];
				//��������� �-�� ���������
				tmpMaterial->count = this->getRuberoidAmount();
				//��������� �������� � ����� ������
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}
}