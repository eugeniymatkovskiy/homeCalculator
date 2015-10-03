#include "stdafx.h"
#include "Wall.h"


Wall::Wall()
{
	//растворный шов
	this->seam = 5;//мм ширина растворного шва 

	//Параметры Кирпича в милиметрах 250x120x138 мм
	this->BrickLength = 250;//Длинна
	this->BrickWidth = 120;//Ширина 
	this->BrickHeight = 138;//Высота
	//Параметры Шлакоблока в милиметрах 390×190х188 мм
	this->CinderBlockLength = 390;//Длинна
	this->CinderBlockWidth = 190;//Ширина
	this->CinderBlockHeight = 188;//Высота
	//Параметры Ракушняка  в милиметрах 380мм*180мм*180мм
	this->RakushnjakLength = 380;//Длинна
	this->RakushnjakWidth = 180;//Ширина
	this->RakushnjakHeight = 180;//Высота

	this->HouseHeight = 2800; // высота этажа дома
	this->StockHeight = 4000; // высота склада(гаража)

	this->BuildingWidth_1 = 0;
	this->BuildingWidth_2 = 0;

	this->menu();

	int command;
	cin >> command;
	switch (command)
	{
	case 1:
	{
		system("cls");
		cout << "Меню выбора материала для дома \n"
			<< "1. Кирпич\n"
			<< "2. Шлакоблок\n"
			<< "3. Ракушняк \n"
			<< "Сделайте выбор ?:";

		
		FunkHouse();//Расчет материалов для дома 	
	}

	case 2:
	{
		system("cls");
		cout << "Меню выбора материала для склада(гаража ) \n"
			<< "1. Кирпич\n"
			<< "2. Шлакоблок\n"
			<< "3. Ракушняк \n"
			<< "Сделайте выбор ?:";

		FunkStock();//Расчет материалов для гаража 

	case 3:
	{
		exit(0);
	}

	default:
		break;
	}

	

}


Wall::~Wall()
{

}

//расчет кирпича 
void Wall::calcBrickCount()
{
	
	this->calcBrickCountHouse = ((HouseHeight / (BrickHeight + seam)) + 1)*((((BuildingWidth_1*1000) + (BuildingWidth_2*1000)) * 2 / (BrickWidth + seam)) + 1);//дом

	this->calcBrickCountStock = ((StockHeight / (BrickHeight + seam)) + 1)*((((BuildingWidth_1*1000) + (BuildingWidth_2*1000)) * 2 / (BrickWidth + seam)) + 1);//склад 

	//(высотудома  поделить на (высоту кирпича+толщина шва) +1) <УМНОЖИТЬ> (длиннну 1-Й стены + длинна
	// 2 стены ) <умножить> на 2 <поделить> на (длинну кирпича+толщина шва) )+1(округлить )
}

//расчет шлакоблока 
void Wall::calcCinderBlockCount()
{
	this->calcCinderBlockCountHouse = ((HouseHeight / (CinderBlockHeight + seam)) + 1)*((((BuildingWidth_1*1000) + (BuildingWidth_2*1000)) * 2 / (CinderBlockWidth + seam)) + 1);
	this->calcCinderBlockCountStock = ((StockHeight / (CinderBlockHeight + seam)) + 1)*((((BuildingWidth_1*1000) + (BuildingWidth_2*1000)) * 2 / (CinderBlockWidth + seam)) + 1);
}

//расчет ракушняка  
void Wall::calcRakushnjakCount()
{
	this->calcRakushnjakCountHouse = ((HouseHeight / (RakushnjakHeight + seam)) + 1)*((((BuildingWidth_1*1000) + (BuildingWidth_2*1000)) * 2 / (RakushnjakWidth + seam)) + 1);
	this->calcRakushnjakCountStock = ((StockHeight / (RakushnjakHeight + seam)) + 1)*((((BuildingWidth_1*1000) + (BuildingWidth_2*1000)) * 2 / (RakushnjakWidth + seam)) + 1);
}

//Меню
void Wall::menu(){
	cout << "\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
	cout << "Мею выбора типа строения \n\a"
		<< "1. Жилой дом (офис)\n\a"
		<< "2. Склад (гараж)\n"
		<< "0. Выход\n"
		<< "Сделайте выбор ?:";
}


//Расчет материалов для дома 
void Wall::FunkHouse()
{
	cin >> command;
	switch (command)
	{
	case 1:
	{
		system("cls");

		cout << "Введите ширину дома метрах:"; cin >> BuildingWidth_1;
		cout << "\n";


		cout << "Введите длинну  дома метрах:"; cin >> BuildingWidth_2;
		cout << "\n";

		calcBrickCount();
		cout << "Для постройки дома необходимо закупить" << getBrickCountHouse() << " кирпича" << endl;
		// можно переводить количество кирпича в пачки и т.д.
		system("pause");
		exit(0);
	}
	case 2:
	{
		system("cls");
		cout << "Введите ширину дома метрах:"; cin >> BuildingWidth_1;
		cout << "\n";
		cout << "Введите длинну  дома метрах:"; cin >> BuildingWidth_2;
		cout << "\n";

		calcCinderBlockCount();
		cout << "Для постройки дома необходимо закупить" << getCinderBlockCountHouse() << " шлакоблока" << endl;
		// можно переводить количество кирпича в пачки и т.д.
		system("pause");
		exit(0);
	}
	case 3:
	{
		system("cls");
		cout << "Введите ширину дома метрах:"; cin >> BuildingWidth_1;
		cout << "\n";
		cout << "Введите длинну  дома метрах:"; cin >> BuildingWidth_2;
		cout << "\n";

		calcRakushnjakCount();
		cout << "Для постройки дома необходимо закупить" << getRakushnjakCountHouse() << " ракушняка" << endl;
		// можно переводить количество кирпича в пачки и т.д.	
		system("pause");
		exit(0);
	}
	default:
		break;
	}
}

//Расчет материалов для склада
void Wall::FunkStock()
{
	cin >> command;
	switch (command)
	{
	case 1:
	{
		system("cls");
		cout << "Введите ширину склада метрах:"; cin >> BuildingWidth_1;
		cout << "\n";
		cout << "Введите длинну  склада метрах:"; cin >> BuildingWidth_2;
		cout << "\n";

		calcBrickCount();
		cout << "Для постройки склада необходимо закупить" << getBrickCountStock() << " кирпича" << endl;
		// можно переводить количество кирпича в пачки и т.д.
		system("pause");
		exit(0);
	}
	case 2:
	{
		system("cls");
		cout << "Введите ширину склада метрах:"; cin >> BuildingWidth_1;
		cout << "\n";
		cout << "Введите длинну  склада метрах:"; cin >> BuildingWidth_2;
		cout << "\n";

		calcCinderBlockCount();
		cout << "Для постройки склада необходимо закупить" << getCinderBlockCountStock() << " шлакоблока" << endl;
		// можно переводить количество кирпича в пачки и т.д.
		system("pause");
		exit(0);
	}
	case 3:
	{
		system("cls");
		cout << "Введите ширину склада метрах:"; cin >> BuildingWidth_1;
		cout << "\n";
		cout << "Введите длинну  склада метрах:"; cin >> BuildingWidth_2;
		cout << "\n";

		calcRakushnjakCount();
		cout << "Для постройки склада необходимо закупить" << getRakushnjakCountStock() << " ракушняка" << endl;
		// можно переводить количество кирпича в пачки и т.д.	
		system("pause");
		exit(0);
	}
	default:
		break;
	}
}
