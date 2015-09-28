#include "HomeCalculator.h"
#include "Building.h"
#include "Foundation.h"



int main(){

	//set up language preference
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	//список всех материалов 
	vector<MATERIAL> materials(0);

	//отладка класса фундамент
	Foundation f1(20, 10, 2, FOUND_BLOCK, 0);
	f1.calculate();
	f1.addMaterials(materials);

	f1.unitTest(20, 10, 2, FOUND_BLOCK, 1);

	system("Pause");

	return 0;
}