
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

//******************** ��������� **********************

//��� ����������
enum FoundMaterial
{
	FOUND_CONCRETE = 1,		//�����
	FOUND_BLOCK,			//����
	FOUND_STONE				//������
};
//��� ���������
//string MTRL_CONCRETE = "�����";
//string MTRL_STONE = "������";
//string MTRL_BLOCK = "����";
//��������� ��� �������� ������ ������ ������������ ������
struct BLOCK
{
	string type;		//��� 
	double length;		//�����
	double width;		//������
	double height;		//������
	double weight;		//���
};
//���������
const double BASEMENT_HEIGHT = 2.0;				//������ ������� (�)
const double FOUND_HEIGHT_1FLOOR = 0.5;			//������ ���������� ��� 1 ����� (�)
const double FOUND_HEIGHT_2FLOOR = 1.0;			//������ ���������� ��� 2 ������ (�)
const double FOUND_HEIGHT_3FLOOR = 1.5;			//������ ���������� ��� 3 ������ (�)
const double FOUND_HEIGHT_4FLOOR = 2.0;			//������ ���������� ��� 4 ������ (�)
const double FOUND_HEIGHT_5FLOOR = 2.5;			//������ ���������� ��� 5 ������ (�)
const double FOUND_THICK_1FLOOR = 0.2;			//������� ���������� ��� 1 ����� (�)
const double FOUND_THICK_2FLOOR = 0.3;			//������� ���������� ��� 2 ������ (�)
const double FOUND_THICK_3FLOOR = 0.4;			//������� ���������� ��� 3 ������ (�)
const double FOUND_THICK_4FLOOR = 0.5;			//������� ���������� ��� 4 ������ (�)
const double FOUND_THICK_5FLOOR = 0.6;			//������� ���������� ��� 5 ������ (�)

//id ���������� ����������
const int FOUND_CONCRETE_ID = 1000;
const int FOUND_STONE_ID = 1001;
const int FOUND_BLOCK_ID = 1002;

//��������� ������������� �����
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

//******************** ������ **********************

#ifndef MATERIAL_STRUCT
#define MATERIAL_STRUCT
struct MATERIAL
{
	int id;				//id ���������
	int groupId;		//id ����� ����������
	string type;		//���
	double length;		//�����
	double width;		//������
	double height;		//������
	double count;		//�-��
	int unit;			//��. ���������

	double price;		//���� �� �������
};
//������� ���������
enum Units
{
	NONE,		//������������
	KILOS,		//���������
	PIECES,		//����
};
#endif
