// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
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
	string type;		//���
	double length;		//�����
	double width;		//������
	double height;		//������
	double count;		//�-��
	int unit;			//��. ���������
	int price;
};
//������� ���������
enum Units
{
	NONE,		//������������
	KILOS,		//���������
	PIECES,		//����
};
#endif


// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
