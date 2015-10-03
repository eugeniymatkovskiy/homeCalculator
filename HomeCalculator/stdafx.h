// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//



#include "targetver.h"
#pragma once
#include <stdio.h>
#include "iostream"
#include "string"
#include "math.h"
#include "fstream"

#include <vector>
#include <urlmon.h>
#include <time.h>
#include <atltime.h>
#include <sys/types.h>
#include <sys/stat.h>

#define URLFORDOWNLOAD "https://demo-project-lestat90-2.c9.io/test.txt"
#define MATERIALPRICES "materialPrices.txt"
#define COUNTRELEVANTDAYFORMATERIALPRICES 2

#pragma comment(lib, "urlmon.lib")

using namespace std;

#ifndef MATERIAL_STRUCT
#define MATERIAL_STRUCT
struct MATERIAL
{
	int id;
	int groupId;
	string type;		//тип
	double length;		//длина
	double width;		//ширина
	double height;		//высота
	double count;		//к-во
	int unit;			//ед. измерени€
	int price;
};
//единици измерени€
enum Units
{
	NONE,		//неопределено
	KILOS,		//килограмм
	PIECES,		//штук
};
#endif


// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
