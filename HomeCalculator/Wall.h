#pragma once
class Wall

{
public:

	Wall();
	~Wall();

	void calcBrickCount();//����� ������� ���������� �������� 
	void calcCinderBlockCount();//����� ������� ���������� ���������� 
	void calcRakushnjakCount();//����� ������� ���������� ��������� 
	void menu();
	void FunkHouse();
	void FunkStock();

	void setData(double data_BuildingWidth_1, double data_BuildingWidth_2)
	{
		BuildingWidth_1 = data_BuildingWidth_1;
		BuildingWidth_2 = data_BuildingWidth_2;

	}
	int getBrickCountHouse()
	{
		return this->calcBrickCountHouse;
	}
	int getBrickCountStock()
	{
		return this->calcBrickCountStock;
	}
	int getCinderBlockCountHouse()
	{
		return this->calcCinderBlockCountHouse;
	}

	int getCinderBlockCountStock()
	{
		return this->calcCinderBlockCountStock;
	}

	int getRakushnjakCountHouse()
	{
		return this->calcRakushnjakCountHouse;
	}
	int getRakushnjakCountStock()
	{
		return this->calcRakushnjakCountStock;
	}



private:
	int seam;//�� ������ ����������� ��� 
	int BrickLength, BrickWidth, BrickHeight;//��������� ���������� �������(������ ������ ������)
	int CinderBlockLength, CinderBlockWidth, CinderBlockHeight;//��������� ��������� ����������(������ ������ ������)
	int RakushnjakLength, RakushnjakWidth, RakushnjakHeight;//��������� ���������� ���������(������ ������ ������)
	int HouseHeight, StockHeight; // ������ ����� ���� � ������
	double BuildingWidth_1, BuildingWidth_2;// ������ ������ � ������ ����� ��������
	int calcBrickCountHouse, calcCinderBlockCountHouse, calcRakushnjakCountHouse, calcBrickCountStock, calcCinderBlockCountStock, calcRakushnjakCountStock; // ����������:����������  ��������  ���������� ��� �������� 
	int command;
};
