#include <iostream>	
#include <initializer_list>
using namespace std;

//1
template<typename T>
class Stack {
private:
	enum { EMPTY = -1 };
	T* arr = nullptr;
	int size = 0;
	int topIndex = EMPTY;
	
public:

	Stack(int size) :size(size)	
	{
		arr = new T[size];
		topIndex = EMPTY;
	}
	Stack(int size, initializer_list<T> values) :size(size)	
	{
		arr = new T[size];
		topIndex = EMPTY;
		for (T current : values)
		{
			Push(current);
		}
	}
	Stack(const Stack& other) = delete;
	~Stack()
	{
		if (arr != nullptr)
			delete[]arr;
	}
	bool IsFull(){

		return topIndex == size - 1;
	}
	bool Push(T value)
	{

		if (IsFull())
		{
			NEWSIZE();
		}
			arr[++topIndex] = value;
			return true;
		
		
	}
	bool IsEmpty()
	{	
		return topIndex == EMPTY;
	}
	T Pop()	

	{
		if (!IsEmpty())
		{
			return arr[topIndex--];
		}
		else {
			return T();
		}
	}
	int GetCount()
	{
		return topIndex + 1;
	}
	void Clear()
	{
		topIndex = EMPTY;
	}
	T Peek()
	{
		if (!IsEmpty())
		{
			return arr[topIndex];
		}
		return T();	
	
	}
	void Print()
	{
		for (int i = 0; i <= topIndex; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void NEWSIZE() {
		
			int new_size = size * 2;
			if (new_size == 0) {
				new_size = 1;
			}
			T* newArr = new T[new_size];
			for (int i = 0; i <= topIndex; i++)
			{
				newArr[i] = arr[i];

			}
			delete[]arr;
			arr = newArr;
			size = new_size;
			



	}
};

int main() {
	cout << boolalpha;
	Stack<char> st(4, { 'a', 'b', 'c', 'd' });
	st.Print();
	cout << "Count = " << st.GetCount() << endl;
	cout << "IsFull: " << st.IsFull() << endl;
	st.Push('e');
	st.Push('f');
	st.Print();
	cout << "IsFull: " << st.IsFull() << endl;   
	
	cout << "Count = " << st.GetCount() << endl;   

	cout << "Top: " << st.Peek()<<endl;
	while (!st.IsEmpty())
	{
		cout << "Delete element : " << st.Pop() << endl;
		st.Print();
	}
	cout << "Size = " << st.GetCount() << endl;
	cout << "IsEmpty = " << st.IsEmpty() << endl;
	st.Clear();
	cout <<"GetCount: "<< st.GetCount() << endl;
	cout<<"IsFull: " << st.IsFull() << endl;



	//Завдання N1
	//Реалізуйте клас стек для роботи з символами(символь -
	//ний стек).Стек повинен мати фіксований розмір.Також
	//реалізуйте набір операцій для роботи зі стеком : внесення
	//символу в стек, видалення символу зі стеку, підрахунок
	//кількості символів в стеці, перевірку, чи стек порожній,
	//перевірку, чи стек повний, очищення стеку, отримання
	//без видалення верхнього символу в стеці.

	//Завдання N2
	//Змініть стек з першого завдання зі статичного типу на
	//динамічний(за нестачі вільного місця потрібно змінити
	//розмір внутрішнього масиву без втрати даних).

	//Завдання 3:
	//До створеного класа Stack додати шаблонний тип для елементів масива.
	//Додати можливість в параметризований конструткор крім місткості передавати
	//набір значень стека, застосувати initializer_list.





} //
