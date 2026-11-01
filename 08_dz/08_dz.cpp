#include <iostream>
using namespace std;

template<typename T>
class Array
{
	T* arr;
	int size;
public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	explicit Array(int size)
	{
		this->size = size;
		arr = new T[size]{};
	}
	Array(initializer_list<T> list)
	{
		this->size = list.size();
		arr = new T[size];
		int i = 0;
		for (T elem : list)
		{
			arr[i] = elem;
			i++;
		}
	}
	void Fill(initializer_list<T> list);
	~Array()
	{
		if (arr != nullptr)
			delete[] arr;
	}
	void Print()const 
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

#pragma region task 2

	T Getmax();


	T Getmin();

	void  Sort();

	int BinarySearch(T key);

	void ChangeElement(int index, T value);

#pragma endregion 

};

template<typename T>
void Array<T>::Fill(initializer_list<T> list)
{
	if (arr != nullptr)
		delete[] arr;
	this->size = list.size();
	arr = new T[size];
	int i = 0;
	for (T elem : list)
	{
		arr[i] = elem;
		i++;
	}

}


#pragma region task 2 out
template<typename T>
 T Array<T>::Getmax()
{
	T max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

template<typename T>
 T Array<T>::Getmin() {
	T min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

template<typename T>
void Array<T>::Sort() {
	T temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template<typename T>
int Array<T>::BinarySearch(T key) {
	int B = 0, E = size - 1;
	while (true)
	{
		int p = (B + E) / 2;

		if (key > arr[p])
		{
			B = p + 1;
		}
		else if (key < arr[p])
		{
			E = p - 1;
		}
		else if (key == arr[p])
			return p;
		if (B > E) return -1;
	}
}

template<typename T>
void Array<T>::ChangeElement(int index, T value) {
	if (index < 0 || index >= size) {
		cout << "error index" << endl;
	}
	else {
		arr[index] = value;
	}
}

#pragma endregion





int main()
{
//Завдання 2
//Реалізуйте шаблонні функції для пошуку максимуму,
//мінімуму, сортування масиву (будь-яким алгоритмом
//сортування), двійкового пошуку в масиві, заміни елемента
//масиву на передане значення. Ці методи винести за межі класу

	Array<int> intnum = { 3, 6, 4, 8, 7 };
	Array<double> doublenum = { 3.14, -0.001, 42.0, 123.456, 9.99 };
	Array<float> floatnum = { 0.15, 0.695, 56.54, 1.65, 1.0 };


	cout << "Arr int: ";
	intnum.Print();
	cout << "Min: " << intnum.Getmin() << endl;
	cout << "Max: " << intnum.Getmax() << endl;
	cout << endl;

	cout << "Arr double: ";
	doublenum.Print();
	cout << "Min: " << doublenum.Getmin() << endl;
	cout << "Max: " << doublenum.Getmax() << endl;
	cout << endl;

	intnum.Sort();
	cout << "Sort int: ";
	intnum.Print();
	cout << endl;

	cout << "Binary Search float index(0.695) : "<< floatnum.BinarySearch(0.695)<<endl;
	
	doublenum.Sort();
	cout << "Sort double: ";
	doublenum.Print();
	cout << endl;

	cout << "Before change: ";
	intnum.Print();
	intnum.ChangeElement(2, 67);
	cout << "After change: ";
	intnum.Print();
	cout << endl;



	 /*
	//Завдання 1
	//Перетворити раніше створений клас Array на шаблон, який дозволить
	//зберігати елементи будь - якого типу.Функціональність залишити на
	//тому ж рівні.
	//Додати можливість створювати об'єкт та присвоювати йому 
	//значення шляхом спискової ініціалізації : { 1, 2, 3...}
	*/
	Array<int> arr(5);
	arr.Print();

	Array<int> arr2({ 5, 7, 8, 9, 6, 2, 4, 8, 77, 88, 99, 111 });
	arr2.Print();

	arr2.Fill({ 3, 2, 1 });
	arr2.Print();

	Array<double> arr3 = { 1.5, 2.5, 3.5 };
	arr3.Print();
	



}