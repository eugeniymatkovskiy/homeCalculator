
#pragma once
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



using namespace std;

//******************** ФУНДАМЕНТ **********************

//тип фундамента
//enum FoundMaterial
//{
//	FOUND_CONCRETE = 1,		//бетон
//	FOUND_BLOCK,			//блок
//	FOUND_STONE				//камень
//};

const int FOUND_CONCRETE = 105;		//бетон
const int FOUND_BLOCK = 106;		//блок
const int FOUND_STONE = 107;		//камень

//тип материала
//string MTRL_CONCRETE = "бетон";
//string MTRL_STONE = "камень";
//string MTRL_BLOCK = "блок";
//структура для хранения данных разных фундаментных блоков
struct BLOCK
{
	int id;				//id
	string type;		//тип 
	double length;		//длина
	double width;		//ширина
	double height;		//высота
	double weight;		//вес
};
//фундамент
const double BASEMENT_HEIGHT = 2.0;				//высота подвала (м)
const double FOUND_HEIGHT_1FLOOR = 0.5;			//высота фундамента для 1 этажа (м)
const double FOUND_HEIGHT_2FLOOR = 1.0;			//высота фундамента для 2 этажей (м)
const double FOUND_HEIGHT_3FLOOR = 1.5;			//высота фундамента для 3 этажей (м)
const double FOUND_HEIGHT_4FLOOR = 2.0;			//высота фундамента для 4 этажей (м)
const double FOUND_HEIGHT_5FLOOR = 2.5;			//высота фундамента для 5 этажей (м)
const double FOUND_THICK_1FLOOR = 0.2;			//толщина фундамента для 1 этажа (м)
const double FOUND_THICK_2FLOOR = 0.3;			//толщина фундамента для 2 этажей (м)
const double FOUND_THICK_3FLOOR = 0.4;			//толщина фундамента для 3 этажей (м)
const double FOUND_THICK_4FLOOR = 0.5;			//толщина фундамента для 4 этажей (м)
const double FOUND_THICK_5FLOOR = 0.6;			//толщина фундамента для 5 этажей (м)

//id материалов фундамента
const int FOUND_CONCRETE_ID = 105;
const int FOUND_STONE_ID = 107;
const int FOUND_BLOCK_FBS936_ID = 101;
const int FOUND_BLOCK_FBS946_ID = 102;
const int FOUND_BLOCK_FBS956_ID = 103;
const int FOUND_BLOCK_FBS966_ID = 104;

//id материалов этажа
const int WALL_BRICK_ID = 203;
const int WALL_CINDER_ID = 202;
const int WALL_RAKUSHNJAK_ID = 204;

//id материалов крыши
const int ROOF_REFTERS_ID = 1001;
const int ROOF_SLATE_ID = 501;
const int ROOF_TILING_ID = 601;
const int ROOF_RUBEROID_ID = 901;

//параметры фундаментного блока
const double BLOCK_LENGTH_890 = 890;			//длина фундаментного блока (мм)
const double BLOCK_WIDTH_300 = 300;				//ширина фундаментного блока (мм)
const double BLOCK_WIDTH_400 = 400;				//ширина фундаментного блока (мм)
const double BLOCK_WIDTH_500 = 500;				//ширина фундаментного блока (мм)
const double BLOCK_WIDTH_600 = 600;				//ширина фундаментного блока (мм)
const double BLOCK_HEIGTH_580 = 580;			//высота фундаментного блока (мм)
const string BLOCK_FBS936 = "ФБС9-3-6";			//тип фундаментного блока
const string BLOCK_FBS946 = "ФБС9-4-6";			//тип фундаментного блока
const string BLOCK_FBS956 = "ФБС9-5-6";			//тип фундаментного блока
const string BLOCK_FBS966 = "ФБС9-6-6";			//тип фундаментного блока
//удельный вес
const double FOUND_CONCRETE_WEIGHT = 1800;		//вес 1м3 бетона марки М200 (кг)
const double FOUND_BLOCK_WEIGHT = 2260;			//вес 1м3 фундаментного блока (кг)
const double FOUND_STONE_WEIGHT = 1700;			//вес 1м3 бутового камня (кг)
//процентная доля цемента в 1м3
const double FOUND_CONCRETE_IN_STONE = 0.30;	//при использовании камня (%)
const double FOUND_CONCRETE_IN_BLOCK = 0.10;	//при использовании блоков (%)

//******************** ЗДАНИЕ **********************

#ifndef MATERIAL_STRUCT
#define MATERIAL_STRUCT
struct MATERIAL
{
	int id;				//id материала
	int groupId;		//id групы материалов
	string type;		//тип
	double length;		//длина
	double width;		//ширина
	double height;		//высота
	double count;		//к-во
	int unit;			//ед. измерения

	double price;		//цена за единицу
};
//единици измерения
enum Units
{
	NONE,		//неопределено
	KILOS,		//килограмм
	PIECES,		//штук
};
#endif
