#include <iostream>
#include <string>
using namespace std;

/*
//Завдання 1
//Створити клас «Time», який буде описувати час 3 - ма характеристиками : години, хвилини, секунди.
class Time {
private:
	int hours{};
	int minutes{};
	int seconds{};

public:
//	В класі потрібно реалізувати наступні конструктори :
//•	Конструктор по замовчуванню() – встановлюватиме початкові дані
	Time() {
		hours,minutes,seconds = 0;
	}
//•	Параметризований(hours, minutes, seconds) – встановлює кожну властивість
	Time(int h, int m, int s) {
		hours = h;
		minutes = m;
		seconds = s;
	}
//•	Параметризований(seconds) – створює клас перевівши дану кількість секунд в години, хвилини, секунди
// .Наприклад : 5555 = 1год 32хв 35сек
//•	5555 / 3600 - h; 5555 / 60 % 60 – m; 5555 % 60 - s	
//	Використайте explicit для деяких конструкторів.	
	explicit Time(int seconds) {
		this -> hours = seconds / 3600;
		this -> minutes = (seconds / 60) % 60;
		this -> seconds = seconds % 60;
	}

//1 Виводу часу на екран в форматі hh : mm:ss
friend void Print(const Time& time);

//2.Збільшення часу на одну секунду(11:59 : 59)++ -> 12 : 00 : 00
	Time& operator++() {
		seconds++;
		if (seconds == 60) {
			seconds = 0;
			minutes++;
		}
		if (minutes == 60) {
			minutes = 0;
			hours++;
		}
		return *this;
	}
	Time operator++(int) {
		// Time перед temp це тип даних
		Time temp = *this; //Time temp = *this; створює нову змінну з іменем temp, 
		//яка є об'єктом класу Time, і кладе в неї копію *this.
		++(*this);
		return temp;
	}

	int Total_count_of_sec() const {
		return hours * 3600 + minutes * 60 + seconds;
	}

//Клас повинен мати перевантаження наступних бінарних операторів :
//• + – * / виконується певна арифметична операція з часом та повертається результат у вигляді нового об'єкту Time
	Time operator + (const Time& other) const {
		return Time(this -> Total_count_of_sec() + other.Total_count_of_sec());
	}					    
	Time operator - (const  Time& other) const {
		return Time(this -> Total_count_of_sec() - other.Total_count_of_sec());
	}					    
	Time operator * (const  Time& other) const {
		return Time(this -> Total_count_of_sec() * other.Total_count_of_sec());
	}					    
	Time operator / (const  Time& other) const {
		return Time(this -> Total_count_of_sec() / other.Total_count_of_sec());
	}

//• > < >= <=	перевіряється, який об’єкт містить більшу / меншу кількість часу та повертається результат у вигляді типу bool

	bool operator > (const Time& other) const {
		return this -> Total_count_of_sec() > other.Total_count_of_sec();
	}
	bool operator < (const Time& other) const {
		return this -> Total_count_of_sec() < other.Total_count_of_sec();
	}			    
	bool operator >= (const Time& other) const {
		return this -> Total_count_of_sec() >= other.Total_count_of_sec();
	}			    
	bool operator <= (const Time& other) const {
		return this -> Total_count_of_sec() <= other.Total_count_of_sec();
	}
//•	==  перевіряється чи класи мають не / однаковий час
	bool operator == (const Time& other) const {
		return this -> Total_count_of_sec() == other.Total_count_of_sec();
	}			    
	bool operator!= (const Time& other) const {
		return this  -> Total_count_of_sec() != other.Total_count_of_sec();
	}
};

void Print(const Time& time) { // функція не належить об'єкту, тому об'єкт передаємо параметром; через нього читаємо поля (доступ до private дає friend)time
	if (time.hours < 10) cout << "0";
	cout << time.hours << ":";
	if (time.minutes < 10) cout << "0";
	cout << time.minutes << ":";
	if (time.seconds < 10) cout << "0";
	cout << time.seconds << endl;
}
*/


//Завданя 2
class Array
{
	int* arr;
	int size;
	int no_found;

public:
#pragma region Constructors
	Array()
	{
		size = 0;
		arr = nullptr;
		no_found = 0;
	}
	explicit Array(int size)
	{
		this->size = size;
		no_found = 0;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}

	Array(int size, int num)
	{
		this->size = size;
		no_found = 0;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = num;
		}
	}
	~Array()
	{
		if (arr != nullptr)
			delete[]arr;
	}
	int getSize()const
	{
		return size;
	}
	int getValue(int index)
	{
		return arr[index];
	}
	void setValue(int num, int index)
	{
		arr[index] = num;
	}
	void display(int index)const;
#pragma endregion

#pragma region operator overload
	//[] – повертає елемент за вказаним індексом(по посиланню)
	int& operator[](int index)	// & - повертає посилання 
	{
		if (index >= 0 && index < size)
			return arr[index];
		else {
			cout << "Index not found" << endl;
			return  no_found;
		}
	}
	//() – збільшує всі елементи масиву на зазначену величину
	Array& operator()(int value) {
		for (int i = 0; i < size; i++)
		{
			arr[i] += value;
		}
		return *this;
	}
};
#pragma endregion 

#pragma region

void Array::display(int index) const
{
	cout << arr[index] << " ";
}
void PrintArray(const Array& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		arr.display(i);
	}
	cout << endl;
}
void Print(string name)
{

}
void Test(int a) {}
#pragma endregion 








//	Перевантаження логічних операцій виконати за допомогою дружніх функцій.
//	При виконанні операцій, потрібно перевіряти чи не перебільшено максимальну
//	кількість пасажирів.
//	!Результат завантажити у вигляді.cpp файла.


//Створити клас Airplane(літак), який буде мати наступні характеристики :
//	• Модель
//	• Тип
//	• Кількість пасажирів
//	• Максимальна кількість пасажирів
class Airplane {
private:
	string model{};
	string type{};
	int count_passengers{};
	int max_count_passengers{};
public:
	Airplane(string model, string type, int count_passengers, int max_count_passengers) {
		this->model = model;
		this->type = type;
		this->count_passengers = count_passengers;
		this->max_count_passengers = max_count_passengers;
	
		if (this->count_passengers > this->max_count_passengers) {
			this->count_passengers = this->max_count_passengers;
		}
	}
	void Print()const {
		cout << "Model: " << model << endl;
		cout << "Type: " << type << endl;
		cout << "Count passengers: " << count_passengers << endl;
		cout << "Max count passengers: " << max_count_passengers << endl;
	}

//	За допомогою перевантаження операторів реалізувати :

//	1. Перевірку на рівність типів літаків(операція == ) friend
	friend bool operator ==(const Airplane& left, const Airplane& right);
//	2. Збільшення і зменшення пасажирів в салоні літака(операції ++ та --
//	в префіксній формі)
	Airplane& operator++() {
		if (count_passengers < max_count_passengers) {
			++count_passengers;
			return *this;
		} else {
			cout << "Salon is full" << endl;
			return *this;
		}
	}
	Airplane& operator--() {
		if (count_passengers > 0) {
			--count_passengers;
			return *this;
		} else {
			cout << "No passengers to delete" << endl;
			return *this;
		}
	}
	 
//	3. Порівняння двох літаків по максимально можливій кількості пасажирів
//	на борту(операція > ) friend
	friend bool operator>(const Airplane& left, const Airplane& right);

//	4. Збільшити кількість пасажирів на певне значення(оператор(15))
	Airplane& operator()(int value) {
		if (count_passengers + value <= max_count_passengers) {
			count_passengers += value;
		}
		else {
			cout << "Salon is full" << endl;
			
		}
		return *this;
	}

};
//1
bool operator ==(const Airplane& left, const Airplane& right) {
	return (left.type == right.type);
}
//3
bool operator >(const Airplane& left, const Airplane& right) {
	return (left.max_count_passengers > right.max_count_passengers);
}




int main() {

	cout << boolalpha;
	Airplane airplane1("Gulfstream G700","Private jet",11,19);
	cout << "airplane1:" << endl;
	airplane1.Print();
	cout << endl;

	Airplane airplane2("Boeing 747-8","Passenger airliner",467,605);
	cout << "airplane2:"<<endl;
	airplane2.Print();

	cout << endl;
	cout << "airplane1 > airplane2: " <<( airplane1 > airplane2) << endl;
	cout << "airplane2 > airplane1: " <<(airplane2 > airplane1) << endl;
	cout << endl;

	airplane1(15);
	cout << "airplane1:" << endl;
	airplane1.Print();
	cout << endl;

	airplane2(5);
	cout << "airplane2:" << endl;
	airplane2.Print();
	cout << endl;

	cout << "airplane1 == airplane2: " << (airplane1 == airplane2) << endl;
	cout << endl;

	Airplane airplane3("Concorde", "Passenger airliner", 520, 700);
	cout << "airplane3 == airplane2: " << (airplane3 == airplane2) << endl;
	cout << endl;

	cout << "airplane3" << endl;
	airplane3.Print();
	cout << endl;

	++airplane3;
	cout << "airplane3:" << endl;
	airplane3.Print();
	cout << endl;

	--airplane3;
	cout << "airplane3:" << endl;
	airplane3.Print();
	cout << endl;


#pragma region task 2
//Завдання 2 
//До раніше створеного класу Array додайте перевантаження оператора [], ()
	Array arr(5, 12);
	PrintArray(arr);

	arr[2] = 45;
	PrintArray(arr);

	arr[10] = 9;	  //index not found
	PrintArray(arr);

	arr(5);
	PrintArray(arr);

	Array arr2(4);
	PrintArray(arr2);
	
	arr[12];   //index not found

#pragma endregion

		

/*
#pragma region tast 1
	
	//Завдання 1 :
	Time t;
	cout << "t0: ";Print(t);

	Time t1(12,60,33);
	cout << "t1: ";Print(t1);

	Time t2(1111);
	cout << "t2: "; Print(t2);

	cout << "prefix: ";
	Time time3(10, 59, 29);
	++time3; 
	Print(time3);

	cout << "posfix: ";
	Time time4(12, 9, 20);
	time4++; 
	Print(time4);

	Time result1 = t1 + t2;
	cout << "t1 + t2: "; Print(result1);

	Time result2 = t1 - t2;
	cout << "t1 - t2: "; Print(result2);

	Time result3 = t1 / t2;
	cout << "t1 / t2: "; Print(result3);

	Time result4 = t1 * t2;
	cout << "t1 * t2: "; Print(result4);

	cout << boolalpha; // переводить 0/1 на True/False
	cout << "t2 < t1: " << (t2 < t1) << endl;
	cout << "t2 > t1: " << (t2 > t1) << endl;
	cout << "t2 <= t1: " << (t2 <= t1) << endl;
	cout << "t2 >= t1: " << (t2 >= t1) << endl;
	cout << "t2 != t1: " << (t2 != t1) << endl;
	cout << "t2 == t1: " << (t2 == t1) << endl;
#pragma endregion 
*/

}//--------
