#pragma once
class Wall

{
public:

	Wall();
	~Wall();

	void calcBrickCount();//метод расчета количества кирпичей 
	void calcCinderBlockCount();//метод расчета количества шлакоблока 
	void calcRakushnjakCount();//метод расчета количества ракушняка 
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
	int seam;//мм ширина растворного шва 
	int BrickLength, BrickWidth, BrickHeight;//Обьявляем переменную кирпича(ширина длинна высота)
	int CinderBlockLength, CinderBlockWidth, CinderBlockHeight;//Обьявляем переменую шлакоблока(ширина длинна высота)
	int RakushnjakLength, RakushnjakWidth, RakushnjakHeight;//Обьявляем переменную ракушняка(ширина длинна высота)
	int HouseHeight, StockHeight; // высота этажа дома и гаража
	double BuildingWidth_1, BuildingWidth_2;// Ширина первой и второй стены строения
	int calcBrickCountHouse, calcCinderBlockCountHouse, calcRakushnjakCountHouse, calcBrickCountStock, calcCinderBlockCountStock, calcRakushnjakCountStock; // Переменная:результаты  расчетов  материалов для строения 
	int command;
};
