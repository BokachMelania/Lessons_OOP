#include <iostream>
#include <string>
using namespace std;

#pragma region	task 1

class Employer {
public:
	virtual void Print() = 0;
	virtual ~Employer() {}
};

class President : public Employer {
	double salary;
	string name_country;
	string private_transport;
	string experience;
public:
	President() : salary(0), name_country("no name country"), private_transport("no private transport"), experience("no experience") {}
	President(double s, string n_c, string p_t, string e)
		: salary(s), name_country(n_c), private_transport(p_t), experience(e) {
	}

	void Print() override {
		cout << "Salary: " << salary << endl;
		cout << "Name country: " << name_country << endl;
		cout << "Private transport: " << private_transport << endl;
		cout << "Experience: " << experience << endl;
	}
};

class Manager : public Employer {
	string department;
	int count_projects;
	int countemployers;
public:
	Manager() : department("no department"), count_projects(0), countemployers(0) {}
	Manager(string d, int cp, int ce) : department(d), count_projects(cp), countemployers(ce) {}

	void Print() override {
		cout << "Department: " << department << endl;
		cout << "Count projects: " << count_projects << endl;
		cout << "Count employers: " << countemployers << endl;
	}
};

class Worker : public Employer {
	string specialty;
	string grafic_roboty;
	string lunch;
public:
	Worker() : specialty("no specialty"), grafic_roboty("no grafic roboty"), lunch("no lunch") {}
	Worker(string specialty, string grafic_roboty, string lunch)
		: specialty(specialty), grafic_roboty(grafic_roboty), lunch(lunch) {
	}

	void Print() override {
		cout << "Specialty: " << specialty << endl;
		cout << "Grafic roboty: " << grafic_roboty << endl;
		cout << "Time lunch: " << lunch << endl;
	}
};
#pragma endregion


#pragma region	task 2

class Vehicle {
protected:
	string name;
	double count_passengers;
	double fare;          
	double speed;         
	double weight;      
	double loads_fare;
public:
	Vehicle() : name("no name"), count_passengers(0), fare(0), speed(1), weight(0), loads_fare(0) {}
	Vehicle(string n, double c_p, double f, double s, double w, double l_f)
		: name(n), count_passengers(c_p), fare(f), speed(s), weight(w), loads_fare(l_f) {
	}

	virtual void countTime(int distance) = 0;
	virtual void countCost(int distance) = 0;
	virtual void Print() {
		cout << "Name: " << name << endl;
		cout << "Count passengers: " << count_passengers << endl;
		cout << "Fare per passenger per km: " << fare << endl;
		cout << "Speed: " << speed << endl;
		cout << "LOads weight: " << weight << endl;
		cout << "LOads fare per kg per km: " << loads_fare << endl;
	}
	virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
	Car() : Vehicle() {}
	Car(string n, double c_p, double f, double s, double w, double l_f) : Vehicle(n, c_p, f, s, w, l_f) {}

	void countTime(int distance) override {
		cout << "Time = " << distance / speed << " hours" << endl;
	}
	void countCost(int distance) override {
		double pas = distance * fare * count_passengers;
		double loads = distance * loads_fare * weight;
		cout << "Cost passengers = " << pas << " grn" << endl;
		cout << "Cost loads = " << loads<< " grn" << endl;
		cout << "Total = " << pas +loads << " grn" << endl;
	}
};

class Bike : public Vehicle {
public:
	Bike() : Vehicle() {}
	Bike(string n, double c_p, double f, double s, double w, double l_f) : Vehicle(n, c_p, f, s, w, l_f) {}

	void countTime(int distance) override {
		cout << "Time = " << distance / speed << " hours" << endl;
	}
	void countCost(int distance) override {
		double pas = distance * fare * count_passengers;
		double loads = distance * loads_fare * weight;
		cout << "Cost passengers = " << pas << " grn" << endl;
		cout << "Cost loads = " << loads << " grn" << endl;
		cout << "Total = " << pas + loads << " grn" << endl;
	}
};

class Viz : public Vehicle {
public:
	Viz() : Vehicle() {}
	Viz(string n, double c_p, double f, double s, double w, double l_f) : Vehicle(n, c_p, f, s, w, l_f) {}

	void countTime(int distance) override {
		cout << "Time = " << distance / speed << " hours" << endl;
	}
	void countCost(int distance) override {
		double pas = distance * fare * count_passengers;
		double loads = distance * loads_fare * weight;
		cout << "Cost passengers = " << pas << " grn" << endl;
		cout << "Cost loads = " << loads << " grn" << endl;
		cout << "Total = " << pas + loads << " grn" << endl;
	}
};
#pragma endregion


int main() {

// 1
	President president(100000, "Italy", "Plane", "10 years");
	Manager manager("IT", 5, 20);
	Worker worker("Engineer", "9-18", "13:00-14:00");

	Employer* arr[3] = { &president, &manager, &worker };

	for (int i = 0; i < 3; ++i) {
		arr[i]->Print();
		cout << endl;
	}

	//2
	Car car("Car",4,60,100,300,10 );
	Bike bike("Bike", 1, 5, 15, 40,8 );
	Viz viz("Viz", 2, 1, 5, 250,4 );

	Vehicle* v[3] = { &car, &bike, &viz };

	int distance = 50;

	for (int i = 0; i < 3; ++i) {
		v[i]->Print();
		v[i]->countTime(distance);
		v[i]->countCost(distance);
		cout << endl;
	}

}