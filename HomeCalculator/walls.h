// 180915 расчет материала на стену.cpp: определяет точку входа для консольного приложения.
//

//Класс "Стена"
//Расчет количества материала для возведения стен этажей со стандартной высотой 2м.80 см
// как дял этажа так и подвала(нулевой этаж).

//сделать для подвала обдельно выбор материала!!!!(дом может быть из кирпича, а подвал из шлакоблока)

//высота стены гаража(склада) составляет для расчетов 4 метра
//Материалы: кирпич селикатный, шлакоблок, ракушняк

//размеры селикатного кирпича-двойной кирпич (камень силикатный) – 250x120x138 мм
//стандартный размеры шлакоблока   остается неизменным — 390×190х188 мм
//размер ракушняка 380мм*180мм*180мм
//расчет брать  учет растворного шва 5 мм

//для расчета перевести высоту и длинну стены в милиметры
//высоту * 1000/высоту кирпича(блока) <УМНОЖИТЬ>  длинну *1000/длинну кирпича(блока)

//формула расчета количества материала после выбора материала для дома или офиса:
//1.Расчет материала для первой стены -умножить на 2
//2.Расчет материала для второй стены- умножить на 2

//формула расчета количества материала после выбора материала для склада  или гаража:
//1.Расчет материала для первой стены -умножить на 2
//2.Расчет материала для второй стены- умножить на 2





#include"stdafx.h"
#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>

#include<stdlib.h>



using namespace std;

int command;//Переменная для выбора 

class Wall

{
public:

	Wall();
	~Wall();

	void calcBrickCount();//метод расчета количества кирпичей 
	void calcCinderBlockCount();//метод расчета количества шлакоблока 
	void calcRakushnjakCount();//метод расчета количества ракушняка 

	void setData(int data_BuildingWidth_1, int data_BuildingWidth_2)
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
	int BuildingWidth_1, BuildingWidth_2;// Ширина первой и второй стены строения
	int calcBrickCountHouse, calcCinderBlockCountHouse, calcRakushnjakCountHouse, calcBrickCountStock, calcCinderBlockCountStock, calcRakushnjakCountStock; // Переменная:результаты  расчетов  материалов для строения 

};

//=====================================================================================
Wall::Wall()
{
	//растворный шов
	const int seam = 5;//мм ширина растворного шва 

	//Параметры Кирпича в милиметрах 250x120x138 мм
	const int BrickLength = 250;//Длинна
	const int BrickWidth = 120;//Ширина 
	const int BrickHeight = 138;//Высота
	//Параметры Шлакоблока в милиметрах 390×190х188 мм
	const int CinderBlockLength = 390;//Длинна
	const int CinderBlockWidth = 190;//Ширина
	const int CinderBlockHeight = 188;//Высота
	//Параметры Ракушняка  в милиметрах 380мм*180мм*180мм
	const int RakushnjakLength = 380;//Длинна
	const int RakushnjakWidth = 180;//Ширина
	const int RakushnjakHeight = 180;//Высота

	const int HouseHeight = 2800; // высота этажа дома
	const int StockHeight = 4000; // высота склада(гаража)

	int BuildingWidth_1 = 0;
	int BuildingWidth_2 = 0;
}
Wall::~Wall()
{

}

//расчет кирпича 
void Wall::calcBrickCount()
{
	this->calcBrickCountHouse = ((HouseHeight / (BrickHeight + seam)) + 1)*(((BuildingWidth_1 + BuildingWidth_2) * 2 / (BrickWidth + seam)) + 1);//дом
	this->calcBrickCountStock = ((StockHeight / (BrickHeight + seam)) + 1)*(((BuildingWidth_1 + BuildingWidth_2) * 2 / (BrickWidth + seam)) + 1);//склад 

	//(высотудома  поделить на (высоту кирпича+толщина шва) +1) <УМНОЖИТЬ> (длиннну 1-Й стены + длинна
	// 2 стены ) <умножить> на 2 <поделить> на (длинну кирпича+толщина шва) )+1(округлить )
}

//расчет шлакоблока 
void Wall::calcCinderBlockCount()
{
	this->calcCinderBlockCountHouse = ((HouseHeight / (CinderBlockHeight + seam)) + 1)*(((BuildingWidth_1 + BuildingWidth_2) * 2 / (CinderBlockWidth + seam)) + 1);
	this->calcCinderBlockCountStock = ((StockHeight / (CinderBlockHeight + seam)) + 1)*(((BuildingWidth_1 + BuildingWidth_2) * 2 / (CinderBlockWidth + seam)) + 1);
}

//расчет ракушняка  
void Wall::calcRakushnjakCount()
{
	this->calcRakushnjakCountHouse = ((HouseHeight / (RakushnjakHeight + seam)) + 1)*(((BuildingWidth_1 + BuildingWidth_2) * 2 / (RakushnjakWidth + seam)) + 1);
	this->calcRakushnjakCountStock = ((StockHeight / (RakushnjakHeight + seam)) + 1)*(((BuildingWidth_1 + BuildingWidth_2) * 2 / (RakushnjakWidth + seam)) + 1);
}



