// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

//#include "targetver.h"
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

//******************** ФУНДАМЕНТ **********************

//тип фундамента
enum FoundMaterial
{
	FOUND_CONCRETE,			//бетон
	FOUND_BLOCK,			//блок
	FOUND_STONE				//камень
};
//структура для хранения данных разных фундаментных блоков
struct BLOCK
{
	string type;		//тип 
	double length;		//длина
	double width;		//ширина
	double height;		//высота
	double weight;		//вес
};
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
