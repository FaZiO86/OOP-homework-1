#include "classes.h"
#include <string>
#include <iostream>
using namespace std;

		//�������

Human::Human(string humanName,
			 string surName,
			 string patron, int day, int mon, int year){
	birthday.tm_mday = day;	//���
	birthday.tm_mon = mon;	//������
	birthday.tm_year = year;	//���
	name = humanName;
	surname = surName;
	patronymic = patron;
	
}

string Human::fullName() {
	string str;
	str += name;
	str += " ";
	str += surname;
	str += " ";
	str += patronymic;
	return str;
}

		//�������

Student::Student(Human name,
	string numberGroup,
	string nameGroup,
	int countMarks,
	int* marks) {
	name_person = name;
	number_group = numberGroup;
	name_group = nameGroup;
	
		marks_student = new int [countMarks];
		for (int i = 0; i < countMarks; i++){
			marks_student[i] = marks[i];
		}
		count_marks = countMarks;
}

Student::~Student() {
	if (marks_student) {
		delete[]marks_student;
	}
}

void Student::setCountMarks(int countMarks) {
	if (marks_student) {
		delete[]marks_student;
	}
	marks_student = new int[countMarks];
	count_marks = countMarks;
}

void Student::setMarksStudent(int mark, int count) {
	marks_student[count] = mark;
}

void Student::getMark() {
	for (int i = 0; i < count_marks; i++) {
		cout << marks_student[i] << ", ";
	}
	cout << "\b\b.\n";
}

int Student::rating() {
	double sum = 0;
	for (int i = 0; i < count_marks; i++) {
		sum += marks_student[i];
	}
	return sum / count_marks;
}

		//��������

Flat::Flat(string flatAdress, double apartamentSize, Human* resident, unsigned int countR) {
	adress = flatAdress;
	apartament_size = apartamentSize;
	
	residents = new Human[countR];
	for (int i = 0; i < countR; i++) {
		residents[i] = resident[i];
	}
	count_resident = countR;
}

Flat::~Flat() {
	if (residents) {
		delete[] residents;
	}
}

void Flat::setCountResident(unsigned int countR) {
	if (residents) {
		Human* tmp = new Human[count_resident];
		for (int i = 0; i < count_resident; i++) {
			tmp[i] = residents[count_resident];
		}
		delete[] residents;
		residents = new Human[countR];
		for (int i = 0; i < count_resident; i++) {
			residents[i] = tmp[i];
		}
		delete[] tmp;
	}
	else
		residents = new Human[countR];
	count_resident = countR;
}

void  Flat::showResidents() {
	for (int i = 0; i < count_resident; i++) {
		cout << i + 1 << " �����: " << getResident(i).fullName() << " - "
			<< getResident(i).getBirthday() << " ���� ��������" << endl;
	}
}

int Flat::showCoeff(int count) {
	if (count <= 0) {
		return 0;
	}
	else
		if (count >= 3) {
			return 18;
		}
	switch (count) {
	case 1:return 33;
	case 2:return 42;
	}
}

