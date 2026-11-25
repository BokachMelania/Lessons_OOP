#include <iostream>
#include <ctime>
using namespace std;

enum Season { NoneSeason, Summer, Winter, AllSeason };
enum Marks { NoneMark, Toyota, Volkswagen, BMW, Mercedes_Benz, Ford };
enum Countrys { NoneCountry, Japan, Germany, USA, South_Korea };
enum LightType { NoneLight, Low, High };
enum Open{NoneOpen, Up, ToTheSide};
enum Fuel{NonFuel, Petrol, Gas, Diesel, Electric};

class Wheel {
	string size;
	int prod_date;
	Season seasonality;
	int pressure;

public:
	Wheel() : size("no size"), prod_date(0), seasonality(NoneSeason), pressure(0) {}
	Wheel(string size, int p_d, Season seas, int p) : size(size), prod_date(p_d), seasonality(seas), pressure(p) {}

	void ShowInfo() const {
		cout << "Size: " << size << endl;
		cout << "Production date: " << prod_date << endl;
		cout << "Pressure: " << pressure << endl;
		cout << "Seasonality: ";
		switch (seasonality) {
		case NoneSeason:
			cout << "NoneSeason";
			break;
		case Summer:
			cout << "Summer";
			break;
		case Winter:
			cout << "Winter";
			break;
		case AllSeason:
			cout << "AllSeason";
			break;
		}
		cout << endl;
	}
};

class Body {
	Marks mark;
	string color;
	Countrys country_do;
	bool rolling;
	int year;
public:
	Body() : mark(NoneMark), color("no color"), country_do(NoneCountry), rolling(false), year(0) {}
	Body(Marks m, string color, Countrys c, bool r, int y) : mark(m), color(color), country_do(c), rolling(r), year(y) {}

	void ShowInfo() const {
		cout << "Mark: ";
		switch (mark) {
		case NoneMark: cout << "NoneMark"; break;
		case Toyota: cout << "Toyota"; break;
		case Volkswagen: cout << "Volkswagen"; break;
		case BMW: cout << "BMW"; break;
		case Mercedes_Benz: cout << "Mercedes_Benz"; break;
		case Ford: cout << "Ford"; break;
		}
		cout << endl;
		cout << "Color: " << color << endl;
		cout << "Country did: ";
		switch (country_do) {
		case NoneCountry: cout << "None"; break;
		case Japan: cout << "Japan"; break;
		case Germany: cout << "Germany"; break;
		case USA: cout << "USA"; break;
		case South_Korea: cout << "South_Korea"; break;
		}
		cout << endl;
		cout << "Rolling: " << rolling << endl;
		cout << "Year: " << year << endl;
	}
};

class Driver
{
	int age;
	bool isDrunk;
public:
	Driver() : age(0), isDrunk(false) {}
	Driver(int a, bool i) : age(a), isDrunk(i) {
// double - тип для дробових чисел (8 байтів, точніший за float)
// RAND_MAX - максимальне число, яке повертає rand() (у Visual Studio 32767)
		double randomnum = (double)rand() / RAND_MAX * 0.5; // (double) щоб ділення було дробове, результат 0.0-0.5
		isDrunk = randomnum > 0.2;
		if (isDrunk) {
			throw exception("You have to leave the vehicle!");
		}
		if (age < 18) {
			throw exception("You can't ride, you have no rights!");
		}
		cout << "You can drive" << endl;
	}
	void ShowInfo() const {
		cout << "Age: " << age << endl;
		cout << "Drunk: " << isDrunk << endl; 
	}
};

class Headlight {
	LightType light;
	int power;
public:
	Headlight() : light(NoneLight), power(0) {}
	Headlight(LightType l, int p) : light(l), power(p) {}
	void ShowInfo() const {
		cout << "Light: ";
		switch (light) {
		case NoneLight: cout << "NoneLight"; break;
		case Low: cout << "Low"; break;
		case High: cout << "High"; break;
		}
		cout << endl;
		cout << "Power: " << power << endl;
	}
};

class Door {
	string color;
	Open open_door;
public:
 Door(): color("no color"), open_door(NoneOpen){}
 Door(string c, Open d): color(c), open_door(d){}
 void ShowInfo() const  {
	 cout << "Color: "<<color << endl;
	 cout << "How to open: ";
	 switch (open_door) {
	 case NoneOpen :cout<<"NoneOpen"; break;
	 case Up :cout<<"Up"; break;
	 case ToTheSide :cout<<"ToTheSide"; break;
	 }
	 cout << endl;
 }

};

class Engine {
	int power;
	int volume;
	Fuel type_fuel;
public:
	Engine() : power(0), volume(0), type_fuel(NonFuel) {}
	Engine(int p, int v, Fuel t) : power(p), volume(v), type_fuel(t) {}
	void ShowInfo() const {
		cout << "Power: " << power << endl;
		cout << "Volume: " << volume << endl;
		cout << "Type of fuel: ";
		switch (type_fuel) {
		case NonFuel: cout << "NoFuel"; break;
		case Petrol: cout << "Petrol"; break;
		case Gas: cout << "Gas"; break;
		case Diesel: cout << "Diesel"; break;
		case Electric: cout << "Electric"; break;
		}
		cout << endl;
	}
};

class Car {
	Wheel wheel[4];
	Body body;
	Driver* driver; // агрегація
	Headlight headlight[2];
	Door door[4];
	Engine engine;
public:
	Car() : driver(nullptr) {}

	// Усі складові приходять з параметрів, driver = nullptr (водія ще немає).
	// Масиви заповнюємо в тілі конструктора копіями переданих об'єктів.
	Car(Body b, Engine e, Wheel w, Door d, Headlight h) : body(b), driver(nullptr), engine(e) {
		for (int i = 0; i < 4; i++)
			wheel[i] = w;	// заповнюємо всі 4 елементи масиву копіями одного колеса w
		for (int i = 0; i < 4; i++)
			door[i] = d;
		for (int i = 0; i < 2; i++)
			headlight[i] = h;
	}
	
	void AggregateDriver(Driver* d) {
		driver = d; // зберігаємо адресу водія, копії немає (агрегація)
	}
	void RemoveDriver() {
		driver = nullptr; // машина забуває водія, сам об'єкт Driver не видаляється
	}

	void ShowInfo() const {
		cout << "---------------------- CAR INFO----------------------" << endl;
		cout << "--- -BODY -----" << endl;
		body.ShowInfo();

		cout << "----- ENGINE -----" << endl;
		engine.ShowInfo();

		cout << "--- WHEELS ---" << endl;
		for (int i = 0; i < 4; i++) {
			cout << "Wheel " << i + 1 << ":" << endl; // i + 1: нумерація показу  з 1, а не з 0
			wheel[i].ShowInfo();
		}
		cout << "---- HEADLIGHTS ----" << endl;
		for (int i = 0; i < 2; i++) {
			cout << "Headlight " << i + 1 << ":" << endl;
			headlight[i].ShowInfo();
		}

		cout << "---- DOORS ------" << endl;
		for (int i = 0; i < 4; i++) {
			cout << "Door " << i + 1 << ":" << endl;
			door[i].ShowInfo();
		}

		cout << "---- DRIVER ----" << endl;
		if (driver != nullptr)
			driver->ShowInfo();
		else
			cout << "error driver" << endl;
	}
};

int main() {
	srand(time(0));
	cout << boolalpha;

	Body body(Toyota, "Red", Japan, true, 2020);
	Engine engine(150, 2000, Petrol);
	Wheel wheel("R17", 2020, Summer, 32);
	Door door("Red", ToTheSide);
	Headlight headlight(Low, 55);

	Car car(body, engine, wheel, door, headlight);

	car.ShowInfo();

	try {
		Driver d(30, false);
		car.AggregateDriver(&d);//Якби передавали без &, треба було б приймати копію, а тоді це вже була б не агрегація.
		car.ShowInfo();
		car.RemoveDriver();
	}
	catch (exception& e) {	//& означає, що e це посилання: catch не робить копію винятку, а працює з самим об'єктом, який кинув throw.
		cout << e.what() << endl;
	}
}

//Завдання 1:
//Розробити клас Car з набором необхідних параметрів та складових(двигун, кузов, колеса, двері, коробка передач, фари і тд.)
//Кожна складова описується окремим класом та міститься як композиція в класі Car.
//Набір необхідних характеристик та методів описати на ваш розсуд.