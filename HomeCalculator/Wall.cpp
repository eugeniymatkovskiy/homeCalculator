#include "stdafx.h"
#include "Wall.h"
#include "HomeCalculator.h"


Wall::Wall()
{
	this->init();
}

Wall::Wall(double length, double width, int floorCount, int buildType, int mrtlType)
{
	this->init();

	this->setData(length, width);
	this->buildType = buildType;
	this->Floor = floorCount;
	this->mrtlType = mrtlType;
}

Wall::~Wall()
{

}

void Wall::init()
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

	//	== == == == = переменные которые вводит пользователь == == == == == == == =
	this->BuildingWidth_1 = 0;//Длинна
	this->BuildingWidth_2 = 0;//Ширина 
	this->Doors = 2;// Количество дверей(на будущие версии) 
	this->Gate = 1;// Количество ворот(на будущие версии)
	this->Floor = 1;//Количество этажей 
}

//расчет 
void Wall::calculate()
{
	switch (this->mrtlType)
	{
	case WALL_BRICK_ID:
		this->calcBrickCount();
		break;
	case WALL_CINDER_ID:
		this->calcCinderBlockCount();
		break;
	case WALL_RAKUSHNJAK_ID:
		this->calcRakushnjakCount();
		break;
	}
}

int Wall::getBrickCount()
{
	if (this->mrtlType == WALL_BRICK_ID)
	{
		switch (this->buildType)
		{
		case 0:
		case 1:
			return this->calcBrickCountHouse;
			break;
		case 2:
		case 3:
			return this->calcBrickCountStock;
			break;
		}
	}
	else
	{
		return 0;
	}
}
int Wall::getCinderBlockCount()
{
	if (this->mrtlType == WALL_CINDER_ID)
	{
		switch (this->buildType)
		{
		case 0:
		case 1:
			return this->calcCinderBlockCountHouse;
			break;
		case 2:
		case 3:
			return this->calcCinderBlockCountStock;
			break;
		}
	}
	else
	{
		return 0;
	}
}
int Wall::getRakushnjakCount()
{
	if (this->mrtlType == WALL_RAKUSHNJAK_ID)
	{
		switch (this->buildType)
		{
		case 0:
		case 1:
			return this->calcRakushnjakCountHouse;
			break;
		case 2:
		case 3:
			return this->calcRakushnjakCountStock;
			break;
		}
	}
	else
	{
		return 0;
	}
}

//считать и добавить материалы в новый список
void Wall::addMaterials(vector<MATERIAL*>* materials, vector<MATERIAL*>* calcMtrl)
{

	MATERIAL* tmpMaterial;

	//************ добавляем к-во кирпича **************

	//проверяем наличие бетона для изготовления фундамента
	if (this->getBrickCount())
	{
		for (int i = 0; i < materials->size(); i++)
		{
			if ((*materials)[i]->id == WALL_BRICK_ID)
			{
				//копируем материал
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*materials)[i];
				//добавляем к-во материала
				tmpMaterial->count = (double)this->getBrickCount();
				//добавляем материал в новый список
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}

	//************ добавляем к-во газоблока **************

	//проверяем наличие камня для изготовления фундамента
	if (this->getCinderBlockCount())
	{
		for (int j = 0; j < materials->size(); j++)
		{
			if ((*materials)[j]->id == WALL_CINDER_ID)
			{
				//копируем материал
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*materials)[j];
				//добавляем к-во материала
				tmpMaterial->count = (double)this->getCinderBlockCount();
				//добавляем материал в новый список
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}

	//************ добавляем к-во ракушняка **************

	//проверяем наличие камня для изготовления фундамента
	if (this->getRakushnjakCount())
	{
		for (int k = 0; k < materials->size(); k++)
		{
			if ((*materials)[k]->id == WALL_RAKUSHNJAK_ID)
			{
				//копируем материал
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*materials)[k];
				//добавляем к-во материала
				tmpMaterial->count = this->getRakushnjakCount();
				//добавляем материал в новый список
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}
}


	//расчет кирпича 
	void Wall::calcBrickCount()
	{
		//расчет количества материала для стен без окон
		//(высотудома  поделить на (высоту кирпича+толщина шва) +1) <УМНОЖИТЬ> (длиннну 1-Й стены + длинна
		// 2 стены ) <умножить> на 2 <поделить> на (длинну кирпича+толщина шва) )+1(округлить )

		//1. для дома

		calcBrickHouse = ((HouseHeight / (BrickHeight + seam)) + 1)*((((BuildingWidth_1 * 1000) + (BuildingWidth_2 * 1000)) * 2 / (BrickWidth + seam)) + 1);
		//2. для склада 
		calcBrickStock = ((StockHeight / (BrickHeight + seam)) + 1)*((((BuildingWidth_1 * 1000) + (BuildingWidth_2 * 1000)) * 2 / (BrickWidth + seam)) + 1);//склад 

		//для расчетов стандартные размеры окна составляют:1300х1400
		//расчет количества кирпича которое  нужно исключить  в связи с установкой одного окна 
		BrickWindows = (1400 / (BrickHeight + seam))*(1300 / (BrickWidth + seam));

		//расчет количества окон на этаж исходя из размеров длинны и ширины здания (1 но окно на 5 метров)
		calcBrickWindowsHouse = (((BuildingWidth_1 / 5) * 2) + ((BuildingWidth_2 / 5) * 2))*BrickWindows;//дом
		calcBrickWindowsStock = (((BuildingWidth_1 / 5) * 2) + (BuildingWidth_2 / 5))*BrickWindows;//гараж

		//включаем в расчет количество дверей  для расчета метериала который нужно исключить 
		BrickDoors = (2000 / (BrickHeight + seam))*(800 / (BrickWidth + seam));

		calcBrickDoorsHouse = Doors*BrickDoors;

		//ворота для склада стандартные размеры высота 2 метра, ширина 2,3
		BrickGate = (2000 / (BrickHeight + seam))*(2300 / (BrickWidth + seam));
			calcBrickGateStock = Gate*BrickGate;


		//окончательный расчет материала  "кирпич" для дома и для склада 
		this->calcBrickCountHouse = (calcBrickHouse - calcBrickWindowsHouse)*Floor - calcBrickDoorsHouse;//дом общее значение материала 
		this->calcBrickCountStock = calcBrickStock - calcBrickWindowsStock - calcBrickDoorsHouse - calcBrickGateStock;// склад обще значнение материала 

	}

	//расчет шлакоблока 
	void Wall::calcCinderBlockCount()
	{
		calcCinderBlockHouse = ((HouseHeight / (CinderBlockHeight + seam)) + 1)*((((BuildingWidth_1 * 1000) + (BuildingWidth_2 * 1000)) * 2 / (CinderBlockWidth + seam)) + 1);
		calcCinderBlockCountStock = ((StockHeight / (CinderBlockHeight + seam)) + 1)*((((BuildingWidth_1 * 1000) + (BuildingWidth_2 * 1000)) * 2 / (CinderBlockWidth + seam)) + 1);
		CinderBlockWindows = (1400 / (CinderBlockHeight + seam))*(1300 / (CinderBlockWidth + seam));

		CinderBlockDoors = (2000 / (CinderBlockHeight + seam))*(800 / (CinderBlockWidth + seam));
		calcCinderBlockHouse = Doors*CinderBlockDoors;

		CinderBlocGate = (2000 / (CinderBlockHeight + seam))*(2300 / (CinderBlockWidth + seam));
			calcCinderBlocGateStock = Gate*CinderBlocGate;

		calcCinderBlockWindowsHouse = (((BuildingWidth_1 / 5) * 2) + ((BuildingWidth_2 / 5) * 2))*CinderBlockWindows;//дом
		calcCinderBlockWindowsStock = (((BuildingWidth_1 / 5) * 2) + (BuildingWidth_2 / 5))*CinderBlockWindows;//гараж

		//окончательный расчет материала  "газоблок" для дома и для склада 
		this->calcCinderBlockCountHouse = (calcCinderBlockHouse - calcCinderBlockWindowsHouse)*Floor - calcBrickDoorsHouse;
		this->calcCinderBlockCountStock = calcCinderBlockCountStock - calcCinderBlockWindowsStock - calcCinderBlockDoorsHouse - calcCinderBlocGateStock;
	}

	//расчет ракушняка  
	void Wall::calcRakushnjakCount()
	{
		calcRakushnjakHouse = ((HouseHeight / (RakushnjakHeight + seam)) + 1)*((((BuildingWidth_1 * 1000) + (BuildingWidth_2 * 1000)) * 2 / (RakushnjakWidth + seam)) + 1);
		calcRakushnjakStock = ((StockHeight / (RakushnjakHeight + seam)) + 1)*((((BuildingWidth_1 * 1000) + (BuildingWidth_2 * 1000)) * 2 / (RakushnjakWidth + seam)) + 1);
		RakushnjakWindows = (1400 / (RakushnjakHeight + seam))*(1300 / RakushnjakWidth + seam);
		//расчет количества окон на этаж исходя из размеров длинны и ширины здания (1 но окно на 5 метров)
		calcRakushnjakWindowsHouse = (((BuildingWidth_1 / 5) * 2) + ((BuildingWidth_2 / 5) * 2))*RakushnjakWindows;//дом
		calcRakushnjakWindowsStock = (((BuildingWidth_1 / 5) * 2) + (BuildingWidth_2 / 5))*RakushnjakWindows;//гараж

		RakushnjakDoors = (2000 / (RakushnjakHeight + seam))*(800 / (RakushnjakWidth + seam));
		calcRakushnjakDoorsHouse = Doors*RakushnjakDoors;

		//ворота для склада 
		RakushnjakGate = (2000 / (RakushnjakHeight + seam))*(2300 / (RakushnjakWidth + seam));
			calcRakushnjakGateStock = Gate*RakushnjakGate;

		//окончательный расчет материала  "Ракушняк" для дома и для склада 
		this->calcRakushnjakCountHouse = (calcRakushnjakHouse - calcRakushnjakWindowsHouse)*Floor - calcRakushnjakDoorsHouse;
		this->calcRakushnjakCountStock = calcRakushnjakStock - calcRakushnjakWindowsStock - calcRakushnjakGateStock - calcRakushnjakDoorsHouse;
	}

	//Меню
	// void Wall::menu(){
	// 	cout << "\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
	// 	cout << "Мею выбора типа строения \n\a"
	// 		<< "1. Жилой дом (офис)\n\a"
	// 		<< "2. Склад (гараж)\n"
	// 		<< "0. Выход\n"
	// 		<< "Сделайте выбор ?:";
	// }


	// //Расчет материалов для дома 
	// void Wall::FunkHouse()
	// {
	// 	cin >> command;
	// 	switch (command)
	// 	{
	// 	case 1:
	// 	{
	// 		system("cls");

	// 		cout << "Введите ширину дома метрах:"; cin >> BuildingWidth_1;
	// 		cout << "\n";


	// 		cout << "Введите длинну  дома метрах:"; cin >> BuildingWidth_2;
	// 		cout << "\n";

	// 		calcBrickCount();
	// 		cout << "Для постройки дома необходимо закупить" << getBrickCountHouse() << " кирпича" << endl;
	// 		// можно переводить количество кирпича в пачки и т.д.
	// 		system("pause");
	// 		exit(0);
	// 	}
	// 	case 2:
	// 	{
	// 		system("cls");
	// 		cout << "Введите ширину дома метрах:"; cin >> BuildingWidth_1;
	// 		cout << "\n";
	// 		cout << "Введите длинну  дома метрах:"; cin >> BuildingWidth_2;
	// 		cout << "\n";

	// 		calcCinderBlockCount();
	// 		cout << "Для постройки дома необходимо закупить" << getCinderBlockCountHouse() << " шлакоблока" << endl;
	// 		// можно переводить количество кирпича в пачки и т.д.
	// 		system("pause");
	// 		exit(0);
	// 	}
	// 	case 3:
	// 	{
	// 		system("cls");
	// 		cout << "Введите ширину дома метрах:"; cin >> BuildingWidth_1;
	// 		cout << "\n";
	// 		cout << "Введите длинну  дома метрах:"; cin >> BuildingWidth_2;
	// 		cout << "\n";

	// 		calcRakushnjakCount();
	// 		cout << "Для постройки дома необходимо закупить" << getRakushnjakCountHouse() << " ракушняка" << endl;
	// 		// можно переводить количество кирпича в пачки и т.д.	
	// 		system("pause");
	// 		exit(0);
	// 	}
	// 	default:
	// 		break;
	// 	}
	// }

	// //Расчет материалов для склада
	// void Wall::FunkStock()
	// {
	// 	cin >> command;
	// 	switch (command)
	// 	{
	// 	case 1:
	// 	{
	// 		system("cls");
	// 		cout << "Введите ширину склада метрах:"; cin >> BuildingWidth_1;
	// 		cout << "\n";
	// 		cout << "Введите длинну  склада метрах:"; cin >> BuildingWidth_2;
	// 		cout << "\n";

	// 		calcBrickCount();
	// 		cout << "Для постройки склада необходимо закупить" << getBrickCountStock() << " кирпича" << endl;
	// 		// можно переводить количество кирпича в пачки и т.д.
	// 		system("pause");
	// 		exit(0);
	// 	}
	// 	case 2:
	// 	{
	// 		system("cls");
	// 		cout << "Введите ширину склада метрах:"; cin >> BuildingWidth_1;
	// 		cout << "\n";
	// 		cout << "Введите длинну  склада метрах:"; cin >> BuildingWidth_2;
	// 		cout << "\n";

	// 		calcCinderBlockCount();
	// 		cout << "Для постройки склада необходимо закупить" << getCinderBlockCountStock() << " шлакоблока" << endl;
	// 		// можно переводить количество кирпича в пачки и т.д.
	// 		system("pause");
	// 		exit(0);
	// 	}
	// 	case 3:
	// 	{
	// 		system("cls");
	// 		cout << "Введите ширину склада метрах:"; cin >> BuildingWidth_1;
	// 		cout << "\n";
	// 		cout << "Введите длинну  склада метрах:"; cin >> BuildingWidth_2;
	// 		cout << "\n";

	// 		calcRakushnjakCount();
	// 		cout << "Для постройки склада необходимо закупить" << getRakushnjakCountStock() << " ракушняка" << endl;
	// 		// можно переводить количество кирпича в пачки и т.д.	
	// 		system("pause");
	// 		exit(0);
	// 	}
	// 	default:
	// 		break;
	// 	}
	// }
