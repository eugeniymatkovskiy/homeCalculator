#pragma once
class Wall

{
public:

	Wall();
	Wall(double length, double width, int buildType, int floors, int mrtlType);
	~Wall();

	void init();		//�������������
	void calculate();	//������ 

	void calcBrickCount();//����� ������� ���������� �������� 
	void calcCinderBlockCount();//����� ������� ���������� ���������� 
	void calcRakushnjakCount();//����� ������� ���������� ��������� 

	int getBrickCount();
	int getCinderBlockCount();
	int getRakushnjakCount();

	void addMaterials(vector<MATERIAL*>*,
		vector<MATERIAL*>*);	//������� � �������� ��������� � ����� ������

	// void menu();
	// void FunkHouse();
	// void FunkStock();

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

	int Doors = 2; //���������� ������ ��� ����� �� ��������� 2 ��� ������� ����� 
	int Gate = 1; //���������� ����� �� ��������� � �������� 1
	int Floor = 1;//���������� ������ �� ��������� 1 � ���������� �������������

	int buildType;	//building type
	int mrtlType;	//material type

	//���������� ���������� ���������, ������� ���������� ��������� � ����� � ���������� ������  ���� ��� ������ �� ���� ���������. 
	int BrickWindows, CinderBlockWindows, RakushnjakWindows;

	//���������� ���� �� ����(������:���, ����� /  ��������:���, �����  / ��������: ���, ����� ) � �������  ����� ���������� ��������� ���. ����� ���������  
	int calcBrickWindowsHouse, calcBrickWindowsStock, calcCinderBlockWindowsHouse, calcCinderBlockWindowsStock, calcRakushnjakWindowsHouse, calcRakushnjakWindowsStock;

	//���������� ���������� ���������, ������� ���������� ��������� � ����� � ���������� ����� �����
	int BrickDoors, CinderBlockDoors, RakushnjakDoors;

	//���������� ������ �� ����...� ����� ������ ��������� ��� ����� ��������� � ����� � ����������   
	int calcBrickDoorsHouse, calcCinderBlockDoorsHouse, calcRakushnjakDoorsHouse;

	//���������� ���������� ��������� ������� ���������� ��������� � ����� � ���������� ����� �����
	int BrickGate, CinderBlocGate, RakushnjakGate;

	//���������� �����
	int calcBrickGateStock, calcCinderBlocGateStock, calcRakushnjakGateStock;

	// ����������:����������  ��������  ���������� ��� �������� (������ ����� ��� ����)
	int calcBrickHouse, calcBrickStock, calcCinderBlockHouse, calcCinderBlockStock, calcRakushnjakHouse, calcRakushnjakStock;



	int calcBrickCountHouse, calcCinderBlockCountHouse, calcRakushnjakCountHouse, calcBrickCountStock, calcCinderBlockCountStock, calcRakushnjakCountStock;


	//int command;
};
