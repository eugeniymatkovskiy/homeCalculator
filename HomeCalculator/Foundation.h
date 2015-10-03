#pragma once
#include "HomeCalculator.h"


class Foundation
{
	private:
		double length;				//����� (�)
		double width;				//������ (�)
		double height;				//������ (�)
		double thickness;			//������� (�)
		int floorCount;				//�-�� ������
		bool basement;				//������� �������
		int material;				//��������
		double area;				//������� (�2)
		double volume;				//����� (�3) 
		//���� ��������� �� ������
		double concreteWeight;		//��� (��)
		//���� ��������� �� �����
		double stoneWeight;			//��� (��)
		//���� ��������� �� ������
		BLOCK block;				//������ ��������� ������������� �����
		int blocksCount;			//�-�� ������ � ����������

	protected:
		void init();					//������������� �������
		void selectBlockType();			//������� ���� ��� ����������
		void calcHeight();				//���������� ������ ����������
		void calcThickness();			//���������� ������� ����������
		void calcArea();				//���������� ������� ����������
		void calcVolume();				//���������� ����� ����������
		void calcConcreteWeight();		//���������� ��� ������ � ����������
		void calcStoneWeight();			//���������� ��� ����� � ����������
		void calcBlocksCount();			//���������� �-�� ������ ����������

	public:
		Foundation(double, double, int, int, bool);
		Foundation(const Foundation&);
		void setLength(double);						//���������� ����� ���������� (�)
		void setWidth(double);						//���������� ������ ���������� (�)
		void setHeight(double);						//���������� ������ ���������� (�)
		void setThickness(double);					//���������� ������� ���������� (�)
		void setFloorCount(int);					//���������� �-�� ������
		void setBasement();							//���������� ������� �������
		void resetBasement();						//���������� ���������� �������
		void setMaterial(int);						//���������� �������� ���������� (FoundMaterial)
		double getLength();							//�������� ����� ���������� (�)
		double getWidth();							//�������� ������ ���������� (�)
		double getHeight();							//�������� ������ ���������� (�)
		double getThickness();						//�������� ������� ���������� (�)
		int getFloorCount();						//�������� �-�� ������
		bool getBasement();							//�������� ������� �������
		int getMaterial();							//�������� �������� ���������� (FoundMaterial)
		double getArea();							//�������� ������� ���������� (�2)
		double getVolume();							//�������� ����� ���������� (�3)
		double getConcreteWeight();					//�������� ��� ������� � ���������� (��)
		double getStoneWeight();					//�������� ��� ����� � ���������� (��)
		BLOCK getSelectedBlock();					//�������� ��� ��������� �����
		int getBlocksCount();						//�������� �-�� ������ � ����������
		void calculate();							//���������� ��� �������������� ����������
		void addMaterials(vector<MATERIAL*>*);		//�������� ��������� � ������
		void unitTest(double, double,
						int, int, bool);			//�������
		virtual ~Foundation();
};

Foundation::Foundation(double length,		//����� ����������
	double width,		//������ ����������
	int floorCount,		//�-�� ������ ��� �����������
	int material,		//�������� ����������
	bool basement)		//������� �������
{
	this->init();
	this->length = length;
	this->width = width;
	this->floorCount = floorCount;
	this->material = material;
	this->basement = basement;
}
Foundation::Foundation(const Foundation& obj)
{
	this->init();

	this->length = obj.length;
	this->width = obj.width;
	this->height = obj.height;
	this->thickness = obj.thickness;
	this->floorCount = obj.floorCount;
	this->basement = obj.basement;
	this->material = obj.material;
	this->area = obj.area;
	this->volume = obj.volume;
	this->concreteWeight = obj.concreteWeight;
	this->stoneWeight = obj.stoneWeight;
	this->block = obj.block;
	this->blocksCount = obj.blocksCount;
}
//�������������
void Foundation::init()
{
	this->length = 0.0;
	this->width = 0.0;
	this->height = 0.0;
	this->thickness = 0.0;
	this->floorCount = 0;
	this->basement = false;
	this->material = 0;
	this->area = 0.0;
	this->volume = 0.0;
	this->concreteWeight = 0.0;
	this->stoneWeight = 0.0;
	this->block.length = 0.0;
	this->block.width = 0.0;
	this->block.height = 0.0;
	this->block.weight = 0.0;
	this->block.type = "";
	this->blocksCount = 0;
}
//���������� ����� ���������� (�)
void Foundation::setLength(double length)
{
	this->length = length;
}
//���������� ������ ���������� (�)
void Foundation::setWidth(double width)
{
	this->width = width;
}
//���������� ������ ���������� (�)
void Foundation::setHeight(double height)
{
	this->height = height;
}
//���������� ������� ���������� (�)
void Foundation::setThickness(double thickness)
{
	this->thickness = thickness;
}
//���������� �-�� ������
void Foundation::setFloorCount(int floorCount)
{
	this->floorCount = floorCount;
}
//���������� ������� �������
void Foundation::setBasement()
{
	this->basement = true;
}
//���������� ���������� �������
void Foundation::resetBasement()
{
	this->basement = false;
}
//���������� �������� ���������� (FoundMaterial)
void Foundation::setMaterial(int material)
{
	this->material = material;
}
//�������� ����� ���������� (�)
double Foundation::getLength()
{
	return this->length;
}
//�������� ������ ���������� (�)
double Foundation::getWidth()
{
	return this->width;
}
//�������� ������ ���������� (�)
double Foundation::getHeight()
{
	return this->height;
}
//�������� ������� ���������� (�)
double Foundation::getThickness()
{
	return this->thickness;
}
//�������� �-�� ������
int Foundation::getFloorCount()
{
	return this->floorCount;
}
//�������� ������� �������
bool Foundation::getBasement()
{
	return this->basement;
}
//�������� �������� ���������� (FoundMaterial)
int Foundation::getMaterial()
{
	return this->material;
}
//�������� ������� ���������� (�2)
double Foundation::getArea()
{
	return this->area;
}
//�������� ����� ���������� (�3)
double Foundation::getVolume()
{
	return this->volume;
}
//�������� ��� ������� � ���������� (��)
double Foundation::getConcreteWeight()
{
	return this->concreteWeight;
}
//�������� ��� ����� � ���������� (��)
double Foundation::getStoneWeight()
{
	return this->stoneWeight;
}
//�������� ��� ��������� �����
BLOCK Foundation::getSelectedBlock()
{
	return this->block;
}
//�������� �-�� ������ � ����������
int Foundation::getBlocksCount()
{
	return this->blocksCount;
}
//������� ���� ��� ����������
void Foundation::selectBlockType()
{
	if ((this->material == FOUND_BLOCK)
		&& (this->thickness > 0)
		&& (this->thickness <= (BLOCK_WIDTH_600 / 1000)))
	{
		block.length = BLOCK_LENGTH_890;
		block.height = BLOCK_HEIGTH_580;

		if (this->thickness <= (BLOCK_WIDTH_600 / 1000) &&
			this->thickness > (BLOCK_WIDTH_500 / 1000))
		{
			this->thickness = BLOCK_WIDTH_600 / 1000;
			block.width = BLOCK_WIDTH_600;
			block.type = BLOCK_FBS966;
		}
		if (this->thickness <= (BLOCK_WIDTH_500 / 1000) &&
			this->thickness > (BLOCK_WIDTH_400 / 1000))
		{
			this->thickness = BLOCK_WIDTH_500 / 1000;
			block.width = BLOCK_WIDTH_500;
			block.type = BLOCK_FBS956;
		}
		if (this->thickness <= (BLOCK_WIDTH_400 / 1000) &&
			this->thickness > (BLOCK_WIDTH_300 / 1000))
		{
			this->thickness = BLOCK_WIDTH_400 / 1000;
			block.width = BLOCK_WIDTH_400;
			block.type = BLOCK_FBS946;
		}
		if (this->thickness <= (BLOCK_WIDTH_300 / 1000))
		{
			this->thickness = BLOCK_WIDTH_300 / 1000;
			block.width = BLOCK_WIDTH_300;
			block.type = BLOCK_FBS936;
		}
	}
}
//���������� ������ ����������
void Foundation::calcHeight()
{
	switch (this->floorCount)
	{
	case 1:
		this->height = FOUND_HEIGHT_1FLOOR;
		break;
	case 2:
		this->height = FOUND_HEIGHT_2FLOOR;
		break;
	case 3:
		this->height = FOUND_HEIGHT_3FLOOR;
		break;
	case 4:
		this->height = FOUND_HEIGHT_4FLOOR;
		break;
	case 5:
		this->height = FOUND_HEIGHT_5FLOOR;
		break;
	default:
		this->height = 0;
		break;
	}
	if (this->basement && this->height < BASEMENT_HEIGHT)
		this->height = BASEMENT_HEIGHT;
}
//���������� ������� ����������
void Foundation::calcThickness()
{
	switch (this->floorCount)
	{
	case 1:
		this->thickness = FOUND_THICK_1FLOOR;
		break;
	case 2:
		this->thickness = FOUND_THICK_2FLOOR;
		break;
	case 3:
		this->thickness = FOUND_THICK_3FLOOR;
		break;
	case 4:
		this->thickness = FOUND_THICK_4FLOOR;
		break;
	case 5:
		this->thickness = FOUND_THICK_5FLOOR;
		break;
	default:
		this->thickness = 0;
		break;
	}
}
//���������� ������� ����������
void Foundation::calcArea()
{
	double commonArea = this->length * this->width;
	double emptyArea =
		(this->length - this->thickness * 2) *
		(this->width - this->thickness * 2);
	this->area = commonArea - emptyArea;
}
//���������� ����� ����������
void Foundation::calcVolume()
{
	this->volume = this->area * this->height;
}
//���������� ��� ������� � ����������
void Foundation::calcConcreteWeight()
{
	double concreteVolume;

	switch (this->material)
	{
	case FOUND_CONCRETE:
		this->concreteWeight = this->volume * FOUND_CONCRETE_WEIGHT;
		break;
	case FOUND_BLOCK:
		concreteVolume = this->volume * FOUND_CONCRETE_IN_BLOCK;
		this->concreteWeight = concreteVolume * FOUND_CONCRETE_WEIGHT;
		break;
	case FOUND_STONE:
		concreteVolume = this->volume * FOUND_CONCRETE_IN_STONE;
		this->concreteWeight = concreteVolume * FOUND_CONCRETE_WEIGHT;
		break;
	default:
		this->concreteWeight = 0;
		break;
	}
}
//���������� ��� ����� � ����������
void Foundation::calcStoneWeight()
{
	if (this->material == FOUND_STONE)
	{
		double stoneVolume = this->volume * (1 - FOUND_CONCRETE_IN_STONE);
		this->stoneWeight = stoneVolume * FOUND_STONE_WEIGHT;
	}
}
//���������� �-�� ������ ����������
void Foundation::calcBlocksCount()
{
	int levelsCount;		//�-�� ������
	int blocksSideA;		//�-�� ������ ����� ����������
	int blocksSideB;		//�-�� ������ ������� ����������
	int blocksOneLevel;		//�-�� ������ � ����� �����
	double blkLength;
	double blkWidth;
	double blkHeight;


	if (this->block.height > 0 &&
		this->block.width > 0 &&
		this->block.length > 0 &&
		this->length > 0 &&
		this->width > 0 &&
		this->height > 0)
	{
		//������� ����� � ������
		blkLength = (this->block.length + 10) / 1000;
		blkWidth = (this->block.width / 1000);
		blkHeight = (this->block.height + 20) / 1000;

		//�-�� ������
		levelsCount = ceil(this->height / blkHeight);
		//�������� ������ ���������� � ������������ � ����������� ������
		this->height = ((double)levelsCount) * blkHeight;
		//�-�� ������ ����� ����������
		blocksSideA = ceil((this->length - blkWidth) / blkLength);
		//�-�� ������ ������� ����������
		blocksSideB = ceil((this->width - blkWidth) / blkLength);
		//�-�� ������ � ����� �����
		blocksOneLevel = (blocksSideA + blocksSideB) * 2;
		//����� �-�� ������
		this->blocksCount = blocksOneLevel * levelsCount;

	}

}
//���������� ��� �������������� ����������
void Foundation::calculate()
{
	this->calcHeight();
	this->calcThickness();
	this->calcArea();
	this->calcVolume();

	if (this->material == FOUND_CONCRETE)
	{
		this->calcConcreteWeight();
	}
	if (this->material == FOUND_STONE)
	{
		this->calcStoneWeight();
		this->calcConcreteWeight();
	}
	if (this->material == FOUND_BLOCK)
	{
		this->selectBlockType();
		this->calcBlocksCount();
		this->calcConcreteWeight();
	}

}
//�������� ��������� � ������
void Foundation::addMaterials(vector<MATERIAL*>* materials)
{
	
	//MATERIAL tmpMaterial;				//��������� �������� ��� ���������� �������� ��������� � ������ 
	//vector<MATERIAL>::iterator it;	//�������� ���������� � ����� �������
	vector<MATERIAL*>* tmpMaterials;	//��������� ��������� �� ������
	bool mtrlAdded;						//���� - �������� ��������

	tmpMaterials = materials;

	//MATERIAL* m1 = new MATERIAL();

	//m1->id = FOUND_CONCRETE_ID;
	//tmpMaterials->push_back(m1);

	//m1->id = FOUND_STONE_ID;
	//tmpMaterials->push_back(m1);

	//m1->id = FOUND_BLOCK_ID;
	//tmpMaterials->push_back(m1);


//************ ��������� �-�� ������ **************
	
	//��������� ������� ������ ��� ������������ ����������
	if (this->getConcreteWeight())
	{
		for (int i = 0; i < tmpMaterials->size(); i++)
		{
			if ((*tmpMaterials)[i]->id == FOUND_CONCRETE_ID)
			{
				(*tmpMaterials)[i]->count = this->getConcreteWeight();
				break;
			}
		}
	}

//************ ��������� �-�� ����� **************

	//��������� ������� ����� ��� ������������ ����������
	if (this->getStoneWeight())
	{
		for (int j = 0; j < tmpMaterials->size(); j++)
		{
			if ((*tmpMaterials)[j]->id == FOUND_STONE_ID)
			{
				(*tmpMaterials)[j]->count = this->getStoneWeight();
				break;
			}
		}
	}

//************ ��������� �-�� ������ **************

	//��������� ������� ����� ��� ������������ ����������
	if (this->getBlocksCount())
	{
		for (int k = 0; k < tmpMaterials->size(); k++)
		{
			if ((*tmpMaterials)[k]->id == FOUND_BLOCK_ID)
			{
				(*tmpMaterials)[k]->count = this->getBlocksCount();
				break;
			}
		}
	}

	materials = tmpMaterials;

	//delete tmpMaterials;

	////��������� ������� ������ ��� ������������ ����������
	//if (this->getConcreteWeight())
	//{
	//	//���������� ����
	//	mtrlAdded = false;


	//	tmpMaterial = new MATERIAL;
	//	//��������� ��������� ��������� ��� ���������� � ������
	//	tmpMaterial.type = MTRL_CONCRETE;
	//	tmpMaterial.length = 0;
	//	tmpMaterial.width = 0;
	//	tmpMaterial.height = 0;
	//	tmpMaterial.count = this->getConcreteWeight();
	//	tmpMaterial.unit = KILOS;
	//	
	//	//��������� ��� � ������ ��� ���� ������� ��������
	//	//���� ����, �� ��������� �-�� � ����
	//	for (it = materials.begin(); it != materials.end(); it++)
	//	{
	//		if ((*it).type == MTRL_CONCRETE && (*it).unit == KILOS)
	//		{
	//			(*it).count += this->getConcreteWeight();
	//			mtrlAdded = true;
	//			break;
	//		}
	//	}
	//	//���� �������� ��������� ��� � ������ - ��������� ��� � �����
	//	if (!mtrlAdded) materials.push_back(tmpMaterial);
	//}

//************ ��������� �-�� ����� **************

	//for (int i = 0; i < tmpMaterials->size(); i++)
	//{
	//	if ((*tmpMaterials)[i]->id == FOUND_STONE_ID)
	//	{
	//		(*tmpMaterials)[i]->count = this->getConcreteWeight();
	//		break;
	//	}
	//}

//	//��������� ������� ����� ��� ������������ ����������
//	if (this->getStoneWeight())
//	{
//		//���������� ����
//		mtrlAdded = false;
//
//		//��������� ��������� ��������� ��� ���������� � ������
//		tmpMaterial.type = MTRL_STONE;
//		tmpMaterial.length = 0;
//		tmpMaterial.width = 0;
//		tmpMaterial.height = 0;
//		tmpMaterial.count = this->getStoneWeight();
//		tmpMaterial.unit = KILOS;
//
//		//��������� ��� � ������ ��� ���� ������� ��������
//		//���� ����, �� ��������� �-�� � ����
//		for (it = materials.begin(); it != materials.end(); it++)
//		{
//			if ((*it).type == MTRL_STONE && (*it).unit == KILOS)
//			{
//				(*it).count += this->getStoneWeight();
//				mtrlAdded = true;
//				break;
//			}		
//		}
//		//���� �������� ��������� ��� � ������ - ��������� ��� � �����
//		if (!mtrlAdded) materials.push_back(tmpMaterial);
//	}
//
////************ ��������� �-�� ������ **************
//
//	//��������� ������� ������ ��� ������������ ����������
//	if (this->getBlocksCount())
//	{
//		//���������� ����
//		mtrlAdded = false;
//
//		//��������� ��������� ��������� ��� ���������� � ������
//		tmpMaterial.type = this->getSelectedBlock().type;
//		tmpMaterial.length = this->getSelectedBlock().length;
//		tmpMaterial.width = this->getSelectedBlock().width;
//		tmpMaterial.height = this->getSelectedBlock().height;
//		tmpMaterial.count = this->getBlocksCount();
//		tmpMaterial.unit = PIECES;
//
//		//��������� ��� � ������ ��� ���� ������� ��������
//		//���� ����, �� ��������� �-�� � ����
//		for (it = materials.begin(); it != materials.end(); it++)
//		{
//			if ((*it).type == this->getSelectedBlock().type && (*it).unit == PIECES)
//			{
//				(*it).count += this->getBlocksCount();
//				mtrlAdded = true;
//				break;
//			}
//		}
//		//���� �������� ��������� ��� � ������ - ��������� ��� � �����
//		if (!mtrlAdded) materials.push_back(tmpMaterial);
//	}

}
void Foundation::unitTest(double length,		//����� ����������
							double width,		//������ ����������
							int floorCount,		//�-�� ������ ��� �����������
							int material,		//�������� ����������
							bool basement)		//������� �������
{
	this->init();
	this->length = length;
	this->width = width;
	this->floorCount = floorCount;
	this->material = material;
	this->basement = basement;
	this->calculate();

	cout << "<<<<<<<<< ���� ������ ��������� >>>>>>>>>" << endl;
	cout << endl;

	cout << "�����: " << this->getLength() << " �" << endl;
	cout << "������: " << this->getWidth() << " �" << endl;
	cout << "������: " << this->getHeight() << " �" << endl;
	cout << "�������: " << this->getThickness() << " �" << endl;
	cout << "�-�� ������: " << this->getFloorCount() << endl;

	if (this->getBasement())
		cout << "������: ����" << endl;
	else
		cout << "������: ���" << endl;

	switch (this->getMaterial())
	{
		case FOUND_CONCRETE:
			cout << "��������: �����" << endl;
			break;
		case FOUND_STONE:
			cout << "��������: ������" << endl;
			break;
		case FOUND_BLOCK:
			cout << "��������: ����" << endl;
			break;
		default:
			cout << "��������: �� ������" << endl;
			break;
	}
	cout << "�������: " << this->getArea() << " �2" << endl;
	cout << "�����: " << this->getVolume() << " �3" << endl;
	cout << "��� ������: " << this->getConcreteWeight() << " ��" << endl;
	cout << "��� �����: " << this->getStoneWeight() << " ��" << endl;
	cout << "�-�� ������: " << this->getBlocksCount() << " ��" << endl;
	cout << "����� �����: " << this->getSelectedBlock().length << " ��" << endl;
	cout << "������ �����: " << this->getSelectedBlock().width << " ��" << endl;
	cout << "������ �����: " << this->getSelectedBlock().height << " ��" << endl;
	cout << "��� �����: " << this->getSelectedBlock().weight << " ��" << endl;
	cout << "��� �����: " << this->getSelectedBlock().type << endl;
}
Foundation::~Foundation()
{
}