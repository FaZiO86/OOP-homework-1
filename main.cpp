#include <iostream>
#include <string>
#include <ctime> //tm ������ � ���� ����, �����.
#include <conio.h>
#include "classes.h"

using namespace std;




int main(){
	setlocale(LC_ALL, "Russian");
	system("chcp 1251>nul");
	unsigned int kolvo = 3;
	
	Human h("��������", "���������", "����������", 07, 04, 1986);
	Human* residents = new Human[kolvo]{
		{"������","����","��������", 12,8,1988},
		{"����������","���������","�������������",21,01,1986},
		{"�������","������","���������", 15,03,2000}
	};
	Student s(h, "��-111", "����������� ����������� �����������", 10, new int[10]{12,6,12,11,9,8,11,12,10,10});
	Flat f("���������� 37, �� 45", 52.4, residents, kolvo);

			//�������

	cout << "����������� ��������:\n\n" << h.fullName() << endl;
	cout << "��� ��������: " << h.getBirthday() << endl << endl;

			//�������

	cout << "�������: " << s.nameStudent() << endl;
	cout << "������: " << s.getNumberGroup() << "\n������������ �������������: " << s.getNameGroup();
	cout << "\n������������ �������� :\n������: ";
	s.getMark();
	cout << "������� ���� ��������: "
	 << s.rating() << endl << endl;

			//��������
	cout << "�������� �� ������: " << f.getAdress() << endl;
	cout << "������� ��������: " << f.getApartamentSize() << endl;
	cout << "������ �������:\n";
	f.showResidents();
	cout << "���������� ������������ ��������: " << f.showCoeff(kolvo) << " ��.� �� ��������" << endl;
	if (f.showCoeff(kolvo) * kolvo > f.getApartamentSize()) {
		cout << "��������� �������� ������ ��� " << kolvo << " �������" << endl << endl;
	}
	else {
		cout << "�������� �������� ��� " << kolvo << " �������" << endl << endl;
	}
			
	
			//����������
	try {
		//s.setCountMarks(-30);
		//s.setMarksStudent(0, -5);
		
		
		//�������� 2 ��������.
		//f.getResident(3);
	}
	catch(const char * ex) {
		cout << "������: " << ex << endl;
	}
	//f.setCountResident(-2);
			//��� ��� ���������� ��� � �� ���������� ����������! 
	f.setResident(h,2);// �������� f.setResident(h,4);
			//���� ���� �� ���� ���������� ����������.
	f.getResident(2);// �������� f.getResident(3);
	//����� �� ���������� ��������������, ������ ������� ������ �� ������, �� ��������� �� ���������������.
	
	
	
	
	
	return 0;
}