#include "HomeCalculator.h"
#include "Foundation.h"

//debug function
void debugFoundation()
{
	cout << "<<<<<<<<< ������� ������ ��������� >>>>>>>>>" << endl;
	cout << endl;

	Foundation f1(20, 10, 5, FOUND_BLOCK, 0);

	
	cout << "�����: " << f1.getLength() << " �" << endl;
	cout << "������: " << f1.getWidth() << " �" << endl;
	cout << "������: " << f1.getHeight() << " �" << endl;
	cout << "�������: " << f1.getThickness() << " �" << endl;
	cout << "�-�� ������: " << f1.getFloorCount() << endl;
	if (f1.getBasement())
		cout << "������: ����" << endl;
	else
		cout << "������: ���" << endl;
	switch (f1.getMaterial())
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
	cout << "�������: " << f1.getArea() << " �2" << endl;
	cout << "�����: " << f1.getVolume() << " �3" << endl;
	cout << "��� ������: " << f1.getConcreteWeight() << " ��" << endl;
	cout << "��� �����: " << f1.getStoneWeight() << " ��" << endl;
	cout << "�-�� ������: " << f1.getBlocksCount() << " ��" << endl;
	cout << "����� �����: " << f1.getSelectedBlock().length << " ��" << endl;
	cout << "������ �����: " << f1.getSelectedBlock().width << " ��" << endl;
	cout << "������ �����: " << f1.getSelectedBlock().height << " ��" << endl;
	cout << "��� �����: " << f1.getSelectedBlock().weight << " ��" << endl;
	cout << "��� �����: " << f1.getSelectedBlock().type << endl;

}


int main(){

	//set up language preference
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	
	//������� ������ ���������
	debugFoundation();

	system("Pause");

	return 0;
}