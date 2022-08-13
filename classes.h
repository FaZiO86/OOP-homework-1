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
	void setName(string n)noexcept {
		name = n;
	}
	const string getName()noexcept {
		return name;
	}
	void setSureName(string s)noexcept {
		surname = s;
	}
	const string getSureName() noexcept {
		return surname;
	}
	void setpatronymic(string p)noexcept {
		patronymic = p;
	}
	const string getPatronymic() noexcept {
		return patronymic;
	}
	void setBirthday(int day, int mon, int year)noexcept {
		birthday.tm_mday = day;	
		birthday.tm_mon = mon;	
		birthday.tm_year = year;
	}
	const string getBirthday() noexcept {
		return to_string(birthday.tm_mday) + "." + to_string(birthday.tm_mon) + "." + to_string(birthday.tm_year);
	}

	string fullName()noexcept;

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
	
	string nameStudent() noexcept {
		return name_person.fullName();
	}
	void setNumberGroup(string a) noexcept {
		number_group = a;
	}
	string getNumberGroup() noexcept {
		return number_group;
	}
	void setNameGroup(string a)noexcept {
		name_group = a;
	}
	string getNameGroup() noexcept {
		return name_group;
	}
	void setCountMarks(int countMarks);
	void setMarksStudent(int mark, int count);
	int getMarksStudent() noexcept {
		return marks_student[count_marks];
	}
	
	void getMark()noexcept;
	
	int rating()noexcept;

private:
	Human name_person;		
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
	void setAdress(string a)noexcept {
		adress = a;
	}
	const string getAdress() noexcept {
		return adress;
	}
	void setApartamentSize(double a) noexcept {
		apartament_size = a;
	}
	const double getApartamentSize()noexcept {
		return apartament_size;
	}
	void setCountResident( int countR);
	const unsigned int getCountResident()noexcept {
		return count_resident;
	}
	void setResident(Human resident, int index);
	Human getResident(int index);
	void  showResidents()noexcept;
	int showCoeff(int count)noexcept;


private:
	string adress = "";
	double apartament_size = 0;
	int count_resident = 0;
	Human* residents = nullptr;
};

