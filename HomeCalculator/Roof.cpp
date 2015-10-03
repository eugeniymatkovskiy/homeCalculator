#include "Roof.h"

Roof::Roof(double houseLength, double houseWidth, int roofType, double reftersPrice, double slatePrice, double tilingPrice, double ruberoidPrice) {
	this->houseLength = houseLength;
	this->houseWidth = houseWidth;
	this->roofType = roofType;
	this->frontonHeight = 4;//������ ��������
	this->reftersLength = 4;// ������� �������
	this->reftersWidth = 0.50;// ������� �� ���������
	this->slateWidth = 0.98;// ������ ������
	this->slateLength = 1.75;// ������� ������
	this->slateLayingOn = 0.20;//������ ���������� ������
	this->tilingWidth = 1.50;//������ ��������������
	this->tilingLength = 4.50;//������� ��������������
	this->tilingLayingOn = 0.30;//������ ���������� ��������������

	//��������� ��� �� ��������
	this->reftersPrice = reftersPrice; //�� ���� ���������� ������
	this->slatePrice = slatePrice;
	this->tilingPrice = tilingPrice;
	this->ruberoidPrice = ruberoidPrice;
}

Roof::~Roof() {
}

void Roof::PifagorTheorem() {
	this->roofLength = sqrt((this->houseWidth / 2) * (this->houseWidth / 2) + this->frontonHeight * this->frontonHeight); //������� �����
}

void Roof::roofSize() {
	this->PifagorTheorem();// ���������� ������� �����

	//���������� ������� ������ � ���� ����� �������
	double reftersAmountHeight = ceil(this->roofLength / this->reftersLength); //������������� �� �����
	this->reftersAmount = ((ceil(this->houseLength / this->reftersWidth) + 1) * reftersAmountHeight) * 2; //�������� ������� ������ � ���� ����� �������

	cout << "Enter the type of root: 0 for slate, 1 for tiling" << endl;
	cin >> roofType;

	//���������� ������� ������
	if (this->roofType == 0) {
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
		cout << "General slate amount: " << this->slateAmount << endl;
		cout << "General refters amount: " << this->reftersAmount << endl;
	}
	//���������� ������� ��������������
	else if (this->roofType == 1) {
		double tilingAmountHeight = 1; //������� ��������� �������������� �� �����
		double tmp = this->tilingLength - this->tilingLayingOn;
		while (true) {
			if (this->tilingLength >= this->roofLength) {
				break;
			}
			else {
				tilingAmountHeight++;
				this->tilingLength += tmp;
			}
		}
		this->tilingAmount = (ceil(this->houseLength / this->tilingWidth) * tilingAmountHeight) * 2; //�������� ������� �������������� = ��������� ������� �������������� �� ������ ������� ��������� �� ������� �� ����� 
		cout << "General tiling amount: " << this->tilingAmount << endl;
		cout << "General refters amount: " << this->reftersAmount << endl;
	}
	else if (this->roofType == 2) {
		this->squareRoof = this->houseLength * this->houseWidth;
		cout << "General amount square meters of ruberoid: " << this->squareRoof << endl;
	}	
}

void Roof::roofPrice() {
	this->roofSize();

	double reftersCost, slateCost, tilingCost, ruberoidCost, generalRoofCost;
	//������� ������
	reftersCost = this->reftersAmount * this->reftersLength * this->reftersPrice;
	if (this->roofType == 0) {
		slateCost = this->slateAmount * this->slatePrice;
		generalRoofCost = reftersCost + slateCost;
	}
	else if (this->roofType == 1) {
		tilingCost = this->tilingAmount * this->tilingPrice;
		generalRoofCost = reftersCost + tilingCost;
	}
	else if (this->roofType == 2) {
		ruberoidCost = this->squareRoof * this->ruberoidPrice;
		generalRoofCost = ruberoidCost;
	}

	cout << "General cost of the roof is: " << generalRoofCost << endl;
}

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
	this->squareRoof;
}