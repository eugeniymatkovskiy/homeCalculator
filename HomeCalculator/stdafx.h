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

//******************** ��������� **********************

//��� ����������
enum FoundMaterial
{
	FOUND_CONCRETE,			//�����
	FOUND_BLOCK,			//����
	FOUND_STONE				//������
};
//��������� ��� �������� ������ ������ ������������ ������
struct BLOCK
{
	string type;		//��� 
	double length;		//�����
	double width;		//������
	double height;		//������
	double weight;		//���
};
const double BLOCK_LENGTH_890 = 890;			//����� ������������� ����� (��)
const double BLOCK_WIDTH_300 = 300;				//������ ������������� ����� (��)
const double BLOCK_WIDTH_400 = 400;				//������ ������������� ����� (��)
const double BLOCK_WIDTH_500 = 500;				//������ ������������� ����� (��)
const double BLOCK_WIDTH_600 = 600;				//������ ������������� ����� (��)
const double BLOCK_HEIGTH_580 = 580;			//������ ������������� ����� (��)
const string BLOCK_FBS936 = "���9-3-6";			//��� ������������� �����
const string BLOCK_FBS946 = "���9-4-6";			//��� ������������� �����
const string BLOCK_FBS956 = "���9-5-6";			//��� ������������� �����
const string BLOCK_FBS966 = "���9-6-6";			//��� ������������� �����
//�������� ���
const double FOUND_CONCRETE_WEIGHT = 1800;		//��� 1�3 ������ ����� �200 (��)
const double FOUND_BLOCK_WEIGHT = 2260;			//��� 1�3 ������������� ����� (��)
const double FOUND_STONE_WEIGHT = 1700;			//��� 1�3 �������� ����� (��)
//���������� ���� ������� � 1�3
const double FOUND_CONCRETE_IN_STONE = 0.30;	//��� ������������� ����� (%)
const double FOUND_CONCRETE_IN_BLOCK = 0.10;	//��� ������������� ������ (%)
