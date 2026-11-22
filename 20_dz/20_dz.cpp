#include <iostream>
#include <stdexcept>
using namespace std;

//1

class Stack {
private:
	enum { EMPTY = -1 };
	int* arr;
	int size;
	int topIndex;
public:
	Stack() = default;
	Stack(int size) :size(size)//100
	{
		if (size <= 0) {
			throw invalid_argument("invalid argument");	
			//  якщо тут буде помилка то буде кидати помилку
			//але не знає що саме напистаи користувачкеві
			//invalid_argument перед дужками: тип помилки.
		   //Текст у дужках "invalid argument": повідомлення, яке просто зберігається всередині об'єкта.
			// тест в дужках має бути оьовязково бо цього вимагає  <stdexcept>.
		}
		try {
			arr = new int[size];
			
		}
		catch (bad_alloc) {// не вдалося завантажити через нестачу пам'яті
			throw exception("not enough memory");
		}

		topIndex = EMPTY;
	
		
	}
	~Stack()
	{
		if (arr != nullptr)
			delete[]arr;
	}
	bool IsFull()
	{
		return topIndex == size - 1;
	}
	bool Push(int elem) {
	   
		if (IsFull()) {
			throw  exception("Stack is full");
			//в exception в дужках можна не писати адже він працює і без (stdexcept)
			// але тоді what() нічого не виведе
		}

		arr[++topIndex] = elem;
		return true;
	}
	bool IsEmpty()
	{
		return topIndex == EMPTY;
	}
	int Pop()
	{
		if (IsEmpty()) {
			throw exception("Stack is empty!");
		}
			return arr[topIndex--];
		
	}
	int GetCount()
	{
		return topIndex + 1;
	}
	void Clear()
	{
		topIndex = EMPTY;
	}
	int Peek()
	{
		if (IsEmpty()) {
			throw exception("Stack is empty!");
		}
			return arr[topIndex];
	}
	void Print()
	{
		for (int i = 0; i <= topIndex; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

};


//2

int StrConversion(const char* str) {
	// int          - тип значення, яке функція повертає (результат: число)
	// StrConversion - ім'я функції
	// const        - рядок тільки для читання, функція не може змінювати його символи
	// char*        - вказівник на символ (адреса першого символу рядка в стилі C)
	// str          - ім'я параметра, під яким рядок доступний усередині функції
	if (strlen(str) == 0) {
		throw exception("str is empty!");
	}

	for (int i = 0; i < strlen(str); i++)//strlen(str)-Рахує символи від початку до '\0'(нуль-термінатор,невидимий символ який позначає кфнеуь рядка) 
	{
		if (!isdigit(str[i]))  
			throw exception("argument must be digit!");	
	}
	long long num = atoll(str);	//atoll перетворює рядок цифр у число типу
								//(long long - бо саме такий ми вказали) 
	
	if (num > INT_MAX) { // INT_MAX - готова константа найбільше значення int(2147483647) 
		throw exception("number is biggest of range!");

	}
	return (int)num;	// (int) перетворює long long на int; безпечно, бо діапазон уже перевірено	
   //(int) - явне приведення типів (cast). (тип)значення
}

int main(){

//1
	try
	{
		Stack st(15);//10
		cout << "Size = " << st.GetCount() << endl;
		for (int i = 0; i < 7; i++)
		{
			st.Push(rand() % 50);
		}

		cout << "Size = " << st.GetCount() << endl;
		st.Print();
		while (!st.IsEmpty())
		{
			cout << "Delete element : " << st.Pop() << endl;
			st.Print();
		}
		cout << "Size = " << st.GetCount() << endl;
	}
	catch (invalid_argument in)
	{
		
		cout << "invalid_argument" << endl;	// пишемо причину поломки дял користуіача 
		cout << in.what() << endl;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)// користувацькі помилки на які не розраховулали
	{
		cout << "Unknown exception" << endl;
	}

//2

	const char* text[]{ "8312","abc","1000000000000" };	// масив із 3 рядків text[0] -"8312" і так далі

	for (int i = 0; i < 3; i++){

	try{
		cout << "Result: " << StrConversion(text[i]) << endl;	// передаємо рядок text[i] у функцію, виводимо число, яке вона повернула
	}
	catch (const exception& ex) {	// отримує виняток від throw; what() видає його текст
		cout<< ex.what() << endl;
	}
	catch (...) {
		cout << "Unknown exception" << endl;
	}

	}

	
	
}

//авдання 1:
//Перепишіть клас Stack(Queue) одного з попередніх домашніх завдань таким чином,
//щоб генерувати виключення для можливих некоректних ситуацій
//які можуть виникнути.
//Наприклад, неможливість виділити потрібну кількість пам’яті,
//переповнення стека, витяг з порожнього стека і т.д.Для
//реалізації даного завдання використати або створити власні
//класи - exception або ж взяти з біблеотеки <stdexcept>.

//		* Завдання 2:
//Написати функцію конвертації рядка символів, який представляє числове значення("8312") в змінну типу int.
//Передбачити випадок виходу за межі діапазону визначеного типом int("1000000000000") та випадок, коли рядок не відповідає запису числа в десятковій системі числення("abc").
//Використовуйте механізм винятків(exceptions).
//
//!Результат завантажити у вигляді.cpp файла.
//* – додаткове завдання

