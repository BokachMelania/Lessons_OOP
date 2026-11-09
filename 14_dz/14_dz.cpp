#include <iostream>
#include <string>
#include <vector>
using namespace std;

#pragma region task 1
class Student {
protected:
	string name;
	int age;
	int course;        
	double average;
	string speciality;
public:
	Student() :name("no name"), age(0), course(0), average(0), speciality("no speciality") {}
	Student(string n, int age, int  c, double aver, string spec)
	:name(n), age(age), course(c), average(aver), speciality(spec) {}
	void Print()const {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Course: " << course << endl;
		cout << "Averange: " << average << endl;
		cout << "Speciality: " << speciality << endl;
	}
};
class Aspirant : public Student {
	string topic_work;
	int number_pages;
public:
	Aspirant() : Student(), topic_work("no topic"), number_pages(0) {}
	
	Aspirant(string topic, int pages): Student(), topic_work(topic), number_pages(pages) {
	}

	Aspirant(string n, int age, int c, double aver, string spec, string topic, int pages)
		: Student(n, age, c, aver, spec), topic_work(topic), number_pages(pages) {}
	void WriteDissertation(int addpages) {
		cout << "------------------Write a Dissertation------------------" << endl;
		number_pages += addpages;
		cout << "Write a dissertation (add pages): " << number_pages << std::endl;
		cout << endl;
	}
	void  ProtectDissertation() {
		cout << "---------------------Protect---------------------------" << endl;
		if (number_pages >= 500) {
			cout << "Congratulation, now you are a doctor of science" << endl;
		}
		else {
			cout << "you didn't pass, you need at least 500 pages." << endl;
		}
		cout << endl;
	}
	void Print()const {
		Student::Print();
		cout << "Topic work: " << topic_work << endl;
		cout << "Number pages: " << number_pages << endl;
		cout << endl;
	}
};
#pragma endregion

#pragma region task 2
class Pasport {
protected:
	string name;
	string last_name;
	string full_name;
	string birthday;
	string sex;
	int number_pasport;
	int ID;
public:
	Pasport() :name("no name"), last_name("no last name"), full_name("no full name"), birthday("00.00.0000"), sex("None"),number_pasport(0),ID(0){}
	Pasport(string name, string last_name, string full_name, string birthday, string sex, int number_pasport, int ID)
		: name(name), last_name(last_name), full_name(full_name), birthday(birthday), sex(sex), number_pasport(number_pasport), ID(ID) {}
	void Print()const {
		cout << "Name: " << name << endl;
		cout << "Lastname: " << last_name << endl;
		cout << "Fullname: " << full_name << endl;
		cout << "Birthday: " << birthday << endl;
		cout << "Sex: " << sex << endl;
		cout << "Number pasport: " << number_pasport << endl;
		cout << "ID: " << ID << endl;
   }

};

class  ForeignPassport : public Pasport {
	string foreignNumber;
	vector<string> visas;
public:
	ForeignPassport() : Pasport(), foreignNumber("000"), visas() {}	//
	ForeignPassport(string foreignNumber, vector<string> visas): Pasport(),foreignNumber(foreignNumber),visas(visas){}

	ForeignPassport(string name, string last_name, string full_name, string birthday,
		string sex, int number_pasport, int ID, string foreignNumber)
		: Pasport(name, last_name, full_name, birthday, sex, number_pasport, ID),
		foreignNumber(foreignNumber) {
	}	
	ForeignPassport(string name, string last_name, string full_name, string birthday,
		string sex, int number_pasport, int ID, string foreignNumber, vector<string> visas)
		: Pasport(name, last_name, full_name, birthday, sex, number_pasport, ID),
		foreignNumber(foreignNumber), visas(visas) {
	}
	void Print()const {
		Pasport::Print();
		cout << "ForeignNumber: " << foreignNumber << endl;
		cout << "Visas:";
		for (string v : visas) {	  //
			cout << "  " << v;
		}
		cout << endl;
	}

};

#pragma endregion 
	int main() {
		
		ForeignPassport fr;
		cout << "----Default Foreign Passport-----" << endl;
		fr.Print();
		cout << endl;
		ForeignPassport fr1("Andrii","Shevchenko","Vasylovich","10.05.1995","Male",123456,98765432,"AB123456",
			{ "USA", "Poland", "Germany", "Canada" });

		cout << "-----Parametrized Foreign Passport----" << endl;
		fr1.Print();
		

		//    Завдання N2
//    Створіть клас Passport(паспорт), який буде містити
//    паспортну інформацію про громадянина України.
//    За допомогою механізму успадкування, реалізуйте
//    клас ForeignPassport(закордонний паспорт) похідний
//    від Passport.
//    Нагадаємо, що закордонний паспорт містить крім
//    паспортних даних, також дані про візи, номер закордон -
//    ного паспорта.
	  
		Aspirant as;
		cout << "----Default Aspirant----" << endl;
		as.Print();
		as.WriteDissertation(200);
		as.ProtectDissertation();

		Aspirant as1("Oleg", 22, 5, 6.2, "Data Science", "Big Data Analytics in Finance", 320);
		cout << "---Parametrized Aspirant-----" << endl;
		as1.Print();
		as1.ProtectDissertation();
		as1.WriteDissertation(200);
		as1.ProtectDissertation();

		//Завдання N1
		//Створіть клас Student, який міститиме інформацію
		//про студента.
		//За допомогою механізму успадкування, реалізуйте клас
		//Aspirant(аспірант — студент, який готується до захисту
		//    кандидатської роботи) похідний від Student.
		//    До класу аспірант додати тему кандидатської роботи
		//    та кількість написаних сторінок.
		//    Додати метод Писати дисертацію(плюсуємо сторінки)
		//    Захистити дисертацію.
		

	}




