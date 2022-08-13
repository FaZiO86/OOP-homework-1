#include <iostream>
#include <string>
#include <ctime> //tm хранит в себе дату, время.
#include <conio.h>
#include "classes.h"

using namespace std;




int main(){
	setlocale(LC_ALL, "Russian");
	system("chcp 1251>nul");
	unsigned int kolvo = 3;
	
	Human h("Андронов", "Александр", "Николаевич", 07, 04, 1986);
	Human* residents = new Human[kolvo]{
		{"Иванов","Иван","Иванович", 12,8,1988},
		{"Алексанров","Александр","Александрович",21,01,1986},
		{"Андреев","Андрей","Андреевич", 15,03,2000}
	};
	Student s(h, "БВ-111", "Разработчик програмного обеспечения", 10, new int[10]{12,6,12,11,9,8,11,12,10,10});
	Flat f("Лермонтова 37, кв 45", 52.4, residents, kolvo);

			//Человек

	cout << "Определение человека:\n\n" << h.fullName() << endl;
	cout << "Год рождения: " << h.getBirthday() << endl << endl;

			//Студент

	cout << "Студент: " << s.nameStudent() << endl;
	cout << "Группа: " << s.getNumberGroup() << "\nНаименование специальности: " << s.getNameGroup();
	cout << "\nУспеваемость студента :\nОценки: ";
	s.getMark();
	cout << "Средний балл студента: "
	 << s.rating() << endl << endl;

			//Квартира
	cout << "Квартира по адресу: " << f.getAdress() << endl;
	cout << "Площадь квартиры: " << f.getApartamentSize() << endl;
	cout << "Список жильцов:\n";
	f.showResidents();
	cout << "Коэффицент прожиточного минимума: " << f.showCoeff(kolvo) << " кв.м на человека" << endl;
	if (f.showCoeff(kolvo) * kolvo > f.getApartamentSize()) {
		cout << "Требуется квартира больше для " << kolvo << " жильцов" << endl << endl;
	}
	else {
		cout << "Квартира подходит для " << kolvo << " жильцов" << endl << endl;
	}
			
	
			//Исключения
	try {
		//s.setCountMarks(-30);
		//s.setMarksStudent(0, -5);
		
		
		//пробовал 2 варианта.
		//f.getResident(3);
	}
	catch(const char * ex) {
		cout << "Ошибка: " << ex << endl;
	}
	//f.setCountResident(-2);
			//вот это исключение так и не получилось обработать! 
	f.setResident(h,2);// например f.setResident(h,4);
			//Туту тоже не смог обработать исключение.
	f.getResident(2);// например f.getResident(3);
	//вроде бы исключение обрабатывается, тоесть выводит данные об ошибке, но программа не останавливается.
	
	
	
	
	
	return 0;
}