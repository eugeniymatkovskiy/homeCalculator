#pragma once
class Wall

{
public:

	Wall();
	Wall(double length, double width, int buildType, int floors, int mrtlType);
	~Wall();

	void init();		//инициализаци€
	void calculate();	//расчет 

	void calcBrickCount();//метод расчета количества кирпичей 
	void calcCinderBlockCount();//метод расчета количества шлакоблока 
	void calcRakushnjakCount();//метод расчета количества ракушн€ка 

	int getBrickCount();
	int getCinderBlockCount();
	int getRakushnjakCount();

	void addMaterials(vector<MATERIAL*>*,
		vector<MATERIAL*>*);	//считать и добавить материалы в новый список

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
	int seam;//мм ширина растворного шва 
	int BrickLength, BrickWidth, BrickHeight;//ќбь€вл€ем переменную кирпича(ширина длинна высота)
	int CinderBlockLength, CinderBlockWidth, CinderBlockHeight;//ќбь€вл€ем переменую шлакоблока(ширина длинна высота)
	int RakushnjakLength, RakushnjakWidth, RakushnjakHeight;//ќбь€вл€ем переменную ракушн€ка(ширина длинна высота)
	int HouseHeight, StockHeight; // высота этажа дома и гаража
	double BuildingWidth_1, BuildingWidth_2;// Ўирина первой и второй стены строени€

	int Doors = 2; // оличество дверей дл€ этажа по умолчанию 2 дл€ первого этажа 
	int Gate = 1; // оличество ворот по умолчанию в расчетах 1
	int Floor = 1;// оличество этажей по умолчанию 1 и ¬ыбираетс€ пользователем

	int buildType;	//building type
	int mrtlType;	//material type

	//переменна€ количества материала, которое необходимо исключить в св€зи с установкой одного  окна дл€ зданий из разн матиериал. 
	int BrickWindows, CinderBlockWindows, RakushnjakWindows;

	//количество окон на этаж(кирпич:дом, склад /  газоблок:дом, склад  / ракушн€к: дом, склад ) и считаем  общее количество материала кот. нужно исключить  
	int calcBrickWindowsHouse, calcBrickWindowsStock, calcCinderBlockWindowsHouse, calcCinderBlockWindowsStock, calcRakushnjakWindowsHouse, calcRakushnjakWindowsStock;

	//переменна€ количества материала, которое необходимо исключить в св€зи с установкой одной двери
	int BrickDoors, CinderBlockDoors, RakushnjakDoors;

	// оличество дверей на этаж...и общий расчет материала что нужно исключить в св€зи с установкой   
	int calcBrickDoorsHouse, calcCinderBlockDoorsHouse, calcRakushnjakDoorsHouse;

	//ѕеременна€ количество материала которое необходимо исключить в св€зи с установкой одних ворот
	int BrickGate, CinderBlocGate, RakushnjakGate;

	// оличество ворот
	int calcBrickGateStock, calcCinderBlocGateStock, calcRakushnjakGateStock;

	// ѕеременна€:результаты  расчетов  материалов дл€ строени€ (только стены без окон)
	int calcBrickHouse, calcBrickStock, calcCinderBlockHouse, calcCinderBlockStock, calcRakushnjakHouse, calcRakushnjakStock;



	int calcBrickCountHouse, calcCinderBlockCountHouse, calcRakushnjakCountHouse, calcBrickCountStock, calcCinderBlockCountStock, calcRakushnjakCountStock;


	//int command;
};
