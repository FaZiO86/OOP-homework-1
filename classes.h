#pragma once
#include <string>
#include <ctime>
using namespace std;

class Human {

public:
	Human(){}
	Human(string humanName,
		  string surName,
		  string patron,
		  int day,int mon,int year);
	void setName(string n) {
		name = n;
	}
	const string getName() {
		return name;
	}
	void setSureName(string s) {
		surname = s;
	}
	const string getSureName() {
		return surname;
	}
	void setpatronymic(string p) {
		patronymic = p;
	}
	const string getPatronymic() {
		return patronymic;
	}
	void setBirthday(int day, int mon, int year) {
		birthday.tm_mday = day;	
		birthday.tm_mon = mon;	
		birthday.tm_year = year;
	}
	const string getBirthday() {
		return to_string(birthday.tm_mday) + "." + to_string(birthday.tm_mon) + "." + to_string(birthday.tm_year);
	}

	string fullName();

private:
	
	string name = "";
	string surname = "";
	string patronymic = "";
	tm birthday{0};

};

class Student {
	

public:
	
	Student(Human name,
			string numberGroup,
			string nameGroup,
			int countMarks,
			int *marks);
	Student() {}
	~Student();
	
	string nameStudent() {			//Обработать!
		return name_person.fullName();
	}
	void setNumberGroup(string a) {
		number_group = a;
	}
	string getNumberGroup() {
		return number_group;
	}
	void setNameGroup(string a) {
		name_group = a;
	}
	string getNameGroup() {
		return name_group;
	}
	void setCountMarks(int countMarks);
	void setMarksStudent(int mark, int count);
	int getMarksStudent() {
		return marks_student[count_marks];
	}
	
	void getMark();
	
	int rating();

private:
	Human name_person;		//Обработать!
	int count_marks = 0;
	int* marks_student = nullptr;
	string name_group = "";
	string number_group = "";

};

class Flat {

public:
	
	Flat(string flatAdress, double apartamentSize, Human* resident, unsigned int countR);
	Flat() {}
	~Flat();
	void setAdress(string a) {
		adress = a;
	}
	const string getAdress() {
		return adress;
	}
	void setApartamentSize(double a) {
		apartament_size = a;
	}
	const double getApartamentSize() {
		return apartament_size;
	}
	void setCountResident(unsigned int countR);
	const unsigned int getCountResident() {
		return count_resident;
	}
	void setResident(Human resident, int index) {
		residents[index] = resident;
	}
	Human getResident(int index) {
		return residents[index];
	}
	void  showResidents();
	int showCoeff(int count);


private:
	string adress = "";
	double apartament_size = 0;
	int count_resident = 0;
	Human* residents = nullptr;
};

