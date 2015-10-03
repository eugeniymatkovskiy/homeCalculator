#pragma once
#include "HomeCalculator.h"


class Foundation
{
	private:
		double length;				//длина (м)
		double width;				//ширина (м)
		double height;				//высота (м)
		double thickness;			//толщина (м)
		int floorCount;				//к-во этажей
		bool basement;				//наличие подвала
		int material;				//материал
		double area;				//площадь (м2)
		double volume;				//обьем (м3) 
		//если фундамент из бетона
		double concreteWeight;		//вес (кг)
		//если фундамент из камня
		double stoneWeight;			//вес (кг)
		//если фундамент из блоков
		BLOCK block;				//данные выбраного фундаментного блока
		int blocksCount;			//к-во блоков в фундаменте

	protected:
		void init();					//инициализация свойств
		void selectBlockType();			//выбрать блок для фундамента
		void calcHeight();				//рассчитать высоту фундамента
		void calcThickness();			//рассчитать толщину фундамента
		void calcArea();				//рассчитать площадь фундамента
		void calcVolume();				//рассчитать обьем фундамента
		void calcConcreteWeight();		//рассчитать вес бетона в фундаменте
		void calcStoneWeight();			//рассчитать вес камня в фундаменте
		void calcBlocksCount();			//рассчитать к-во блоков фундамента

	public:
		Foundation(double, double, int, int, bool);
		Foundation(const Foundation&);
		void setLength(double);						//установить длину фундамента (м)
		void setWidth(double);						//установить ширину фундамента (м)
		void setHeight(double);						//установить высоту фундамента (м)
		void setThickness(double);					//установить толщину фундамента (м)
		void setFloorCount(int);					//установить к-во этажей
		void setBasement();							//установить наличие подвала
		void resetBasement();						//установить отсутствие подвала
		void setMaterial(int);						//установить материал фундамента (FoundMaterial)
		double getLength();							//получить длину фундамента (м)
		double getWidth();							//получить ширину фундамента (м)
		double getHeight();							//получить высоту фундамента (м)
		double getThickness();						//получить толщину фундамента (м)
		int getFloorCount();						//получить к-во этажей
		bool getBasement();							//получить наличие подвала
		int getMaterial();							//получить материал фундамента (FoundMaterial)
		double getArea();							//получить площадь фундамента (м2)
		double getVolume();							//получить обьем фундамента (м3)
		double getConcreteWeight();					//получить вес цемента в фундаменте (кг)
		double getStoneWeight();					//получить вес камня в фундаменте (кг)
		BLOCK getSelectedBlock();					//получить тип выбраного блока
		int getBlocksCount();						//получить к-во блоков в фундаменте
		void calculate();							//рассчитать все характеристики фундамента
		void addMaterials(vector<MATERIAL*>*);		//добавить материалы в список
		void unitTest(double, double,
						int, int, bool);			//отладка
		virtual ~Foundation();
};

Foundation::Foundation(double length,		//длина фундамента
	double width,		//ширина фундамента
	int floorCount,		//к-во этажей над фундаментом
	int material,		//материал фундамента
	bool basement)		//наличие подвала
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
//инициализация
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
//установить длину фундамента (м)
void Foundation::setLength(double length)
{
	this->length = length;
}
//установить ширину фундамента (м)
void Foundation::setWidth(double width)
{
	this->width = width;
}
//установить высоту фундамента (м)
void Foundation::setHeight(double height)
{
	this->height = height;
}
//установить толщину фундамента (м)
void Foundation::setThickness(double thickness)
{
	this->thickness = thickness;
}
//установить к-во этажей
void Foundation::setFloorCount(int floorCount)
{
	this->floorCount = floorCount;
}
//установить наличие подвала
void Foundation::setBasement()
{
	this->basement = true;
}
//установить отсутствие подвала
void Foundation::resetBasement()
{
	this->basement = false;
}
//установить материал фундамента (FoundMaterial)
void Foundation::setMaterial(int material)
{
	this->material = material;
}
//получить длину фундамента (м)
double Foundation::getLength()
{
	return this->length;
}
//получить ширину фундамента (м)
double Foundation::getWidth()
{
	return this->width;
}
//получить высоту фундамента (м)
double Foundation::getHeight()
{
	return this->height;
}
//получить толщину фундамента (м)
double Foundation::getThickness()
{
	return this->thickness;
}
//получить к-во этажей
int Foundation::getFloorCount()
{
	return this->floorCount;
}
//получить наличие подвала
bool Foundation::getBasement()
{
	return this->basement;
}
//получить материал фундамента (FoundMaterial)
int Foundation::getMaterial()
{
	return this->material;
}
//получить площадь фундамента (м2)
double Foundation::getArea()
{
	return this->area;
}
//получить обьем фундамента (м3)
double Foundation::getVolume()
{
	return this->volume;
}
//получить вес цемента в фундаменте (кг)
double Foundation::getConcreteWeight()
{
	return this->concreteWeight;
}
//получить вес камня в фундаменте (кг)
double Foundation::getStoneWeight()
{
	return this->stoneWeight;
}
//получить тип выбраного блока
BLOCK Foundation::getSelectedBlock()
{
	return this->block;
}
//получить к-во блоков в фундаменте
int Foundation::getBlocksCount()
{
	return this->blocksCount;
}
//выбрать блок для фундамента
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
//рассчитать высоту фундамента
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
//рассчитать толщину фундамента
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
//рассчитать площадь фундамента
void Foundation::calcArea()
{
	double commonArea = this->length * this->width;
	double emptyArea =
		(this->length - this->thickness * 2) *
		(this->width - this->thickness * 2);
	this->area = commonArea - emptyArea;
}
//рассчитать обьем фундамента
void Foundation::calcVolume()
{
	this->volume = this->area * this->height;
}
//рассчитать вес цемента в фундаменте
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
//рассчитать вес камня в фундаменте
void Foundation::calcStoneWeight()
{
	if (this->material == FOUND_STONE)
	{
		double stoneVolume = this->volume * (1 - FOUND_CONCRETE_IN_STONE);
		this->stoneWeight = stoneVolume * FOUND_STONE_WEIGHT;
	}
}
//рассчитать к-во блоков фундамента
void Foundation::calcBlocksCount()
{
	int levelsCount;		//к-во ярусов
	int blocksSideA;		//к-во блоков вдоль фундамента
	int blocksSideB;		//к-во блоков поперек фундамента
	int blocksOneLevel;		//к-во блоков в одном ярусе
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
		//размеры блока в метрах
		blkLength = (this->block.length + 10) / 1000;
		blkWidth = (this->block.width / 1000);
		blkHeight = (this->block.height + 20) / 1000;

		//к-во ярусов
		levelsCount = ceil(this->height / blkHeight);
		//изменяем высоту фундамента в соответствии с количеством блоков
		this->height = ((double)levelsCount) * blkHeight;
		//к-во блоков вдоль фундамента
		blocksSideA = ceil((this->length - blkWidth) / blkLength);
		//к-во блоков поперек фундамента
		blocksSideB = ceil((this->width - blkWidth) / blkLength);
		//к-во блоков в одном ярусе
		blocksOneLevel = (blocksSideA + blocksSideB) * 2;
		//общее к-во блоков
		this->blocksCount = blocksOneLevel * levelsCount;

	}

}
//рассчитать все характеристики фундамента
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
//добавить материалы в список
void Foundation::addMaterials(vector<MATERIAL*>* materials)
{
	
	//MATERIAL tmpMaterial;				//временный материал для добавления текущего материала в список 
	//vector<MATERIAL>::iterator it;	//итератор переданого в метод вектора
	vector<MATERIAL*>* tmpMaterials;	//временный указатель на вектор
	bool mtrlAdded;						//флаг - материал добавлен

	tmpMaterials = materials;

	//MATERIAL* m1 = new MATERIAL();

	//m1->id = FOUND_CONCRETE_ID;
	//tmpMaterials->push_back(m1);

	//m1->id = FOUND_STONE_ID;
	//tmpMaterials->push_back(m1);

	//m1->id = FOUND_BLOCK_ID;
	//tmpMaterials->push_back(m1);


//************ добавляем к-во бетона **************
	
	//проверяем наличие бетона для изготовления фундамента
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

//************ добавляем к-во камня **************

	//проверяем наличие камня для изготовления фундамента
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

//************ добавляем к-во блоков **************

	//проверяем наличие камня для изготовления фундамента
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

	////проверяем наличие бетона для изготовления фундамента
	//if (this->getConcreteWeight())
	//{
	//	//сбрасываем флаг
	//	mtrlAdded = false;


	//	tmpMaterial = new MATERIAL;
	//	//заполняем параметры материала для добавления в список
	//	tmpMaterial.type = MTRL_CONCRETE;
	//	tmpMaterial.length = 0;
	//	tmpMaterial.width = 0;
	//	tmpMaterial.height = 0;
	//	tmpMaterial.count = this->getConcreteWeight();
	//	tmpMaterial.unit = KILOS;
	//	
	//	//проверяем или в списке уже есть текущий материал
	//	//если есть, то добавляем к-во к нему
	//	for (it = materials.begin(); it != materials.end(); it++)
	//	{
	//		if ((*it).type == MTRL_CONCRETE && (*it).unit == KILOS)
	//		{
	//			(*it).count += this->getConcreteWeight();
	//			mtrlAdded = true;
	//			break;
	//		}
	//	}
	//	//если текущего материала нет в списке - добавляем его в конец
	//	if (!mtrlAdded) materials.push_back(tmpMaterial);
	//}

//************ добавляем к-во камня **************

	//for (int i = 0; i < tmpMaterials->size(); i++)
	//{
	//	if ((*tmpMaterials)[i]->id == FOUND_STONE_ID)
	//	{
	//		(*tmpMaterials)[i]->count = this->getConcreteWeight();
	//		break;
	//	}
	//}

//	//проверяем наличие камня для изготовления фундамента
//	if (this->getStoneWeight())
//	{
//		//сбрасываем флаг
//		mtrlAdded = false;
//
//		//заполняем параметры материала для добавления в список
//		tmpMaterial.type = MTRL_STONE;
//		tmpMaterial.length = 0;
//		tmpMaterial.width = 0;
//		tmpMaterial.height = 0;
//		tmpMaterial.count = this->getStoneWeight();
//		tmpMaterial.unit = KILOS;
//
//		//проверяем или в списке уже есть текущий материал
//		//если есть, то добавляем к-во к нему
//		for (it = materials.begin(); it != materials.end(); it++)
//		{
//			if ((*it).type == MTRL_STONE && (*it).unit == KILOS)
//			{
//				(*it).count += this->getStoneWeight();
//				mtrlAdded = true;
//				break;
//			}		
//		}
//		//если текущего материала нет в списке - добавляем его в конец
//		if (!mtrlAdded) materials.push_back(tmpMaterial);
//	}
//
////************ добавляем к-во блоков **************
//
//	//проверяем наличие блоков для изготовления фундамента
//	if (this->getBlocksCount())
//	{
//		//сбрасываем флаг
//		mtrlAdded = false;
//
//		//заполняем параметры материала для добавления в список
//		tmpMaterial.type = this->getSelectedBlock().type;
//		tmpMaterial.length = this->getSelectedBlock().length;
//		tmpMaterial.width = this->getSelectedBlock().width;
//		tmpMaterial.height = this->getSelectedBlock().height;
//		tmpMaterial.count = this->getBlocksCount();
//		tmpMaterial.unit = PIECES;
//
//		//проверяем или в списке уже есть текущий материал
//		//если есть, то добавляем к-во к нему
//		for (it = materials.begin(); it != materials.end(); it++)
//		{
//			if ((*it).type == this->getSelectedBlock().type && (*it).unit == PIECES)
//			{
//				(*it).count += this->getBlocksCount();
//				mtrlAdded = true;
//				break;
//			}
//		}
//		//если текущего материала нет в списке - добавляем его в конец
//		if (!mtrlAdded) materials.push_back(tmpMaterial);
//	}

}
void Foundation::unitTest(double length,		//длина фундамента
							double width,		//ширина фундамента
							int floorCount,		//к-во этажей над фундаментом
							int material,		//материал фундамента
							bool basement)		//наличие подвала
{
	this->init();
	this->length = length;
	this->width = width;
	this->floorCount = floorCount;
	this->material = material;
	this->basement = basement;
	this->calculate();

	cout << "<<<<<<<<< Тест класса фундамент >>>>>>>>>" << endl;
	cout << endl;

	cout << "длина: " << this->getLength() << " м" << endl;
	cout << "ширина: " << this->getWidth() << " м" << endl;
	cout << "высота: " << this->getHeight() << " м" << endl;
	cout << "толщина: " << this->getThickness() << " м" << endl;
	cout << "к-во этажей: " << this->getFloorCount() << endl;

	if (this->getBasement())
		cout << "подвал: есть" << endl;
	else
		cout << "подвал: нет" << endl;

	switch (this->getMaterial())
	{
		case FOUND_CONCRETE:
			cout << "материал: Бетон" << endl;
			break;
		case FOUND_STONE:
			cout << "материал: Камень" << endl;
			break;
		case FOUND_BLOCK:
			cout << "материал: Блок" << endl;
			break;
		default:
			cout << "материал: не выбран" << endl;
			break;
	}
	cout << "площадь: " << this->getArea() << " м2" << endl;
	cout << "обьем: " << this->getVolume() << " м3" << endl;
	cout << "вес бетона: " << this->getConcreteWeight() << " кг" << endl;
	cout << "вес камня: " << this->getStoneWeight() << " кг" << endl;
	cout << "к-во блоков: " << this->getBlocksCount() << " шт" << endl;
	cout << "длина блока: " << this->getSelectedBlock().length << " мм" << endl;
	cout << "ширина блока: " << this->getSelectedBlock().width << " мм" << endl;
	cout << "высота блока: " << this->getSelectedBlock().height << " мм" << endl;
	cout << "вес блока: " << this->getSelectedBlock().weight << " кг" << endl;
	cout << "тип блока: " << this->getSelectedBlock().type << endl;
}
Foundation::~Foundation()
{
}