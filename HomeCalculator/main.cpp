#include "HomeCalculator.h"
#include "Foundation.h"

//debug function
void debugFoundation()
{
	cout << "<<<<<<<<< Отладка класса фундамент >>>>>>>>>" << endl;
	cout << endl;

	Foundation f1(20, 10, 5, FOUND_BLOCK, 0);

	
	cout << "длина: " << f1.getLength() << " м" << endl;
	cout << "ширина: " << f1.getWidth() << " м" << endl;
	cout << "высота: " << f1.getHeight() << " м" << endl;
	cout << "толщина: " << f1.getThickness() << " м" << endl;
	cout << "к-во этажей: " << f1.getFloorCount() << endl;
	if (f1.getBasement())
		cout << "подвал: есть" << endl;
	else
		cout << "подвал: нет" << endl;
	switch (f1.getMaterial())
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
	cout << "площадь: " << f1.getArea() << " м2" << endl;
	cout << "обьем: " << f1.getVolume() << " м3" << endl;
	cout << "вес бетона: " << f1.getConcreteWeight() << " кг" << endl;
	cout << "вес камня: " << f1.getStoneWeight() << " кг" << endl;
	cout << "к-во блоков: " << f1.getBlocksCount() << " шт" << endl;
	cout << "длина блока: " << f1.getSelectedBlock().length << " мм" << endl;
	cout << "ширина блока: " << f1.getSelectedBlock().width << " мм" << endl;
	cout << "высота блока: " << f1.getSelectedBlock().height << " мм" << endl;
	cout << "вес блока: " << f1.getSelectedBlock().weight << " кг" << endl;
	cout << "тип блока: " << f1.getSelectedBlock().type << endl;

}


int main(){

	//set up language preference
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	
	//отладка класса фундамент
	debugFoundation();

	system("Pause");

	return 0;
}