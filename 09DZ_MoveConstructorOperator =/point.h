# pragma once
#include <iostream>
using namespace std;

//Завдання 1:
//Створити клас Point – точка на площині(x, y).Реалізувати набір відповідних констуркторів, 
// метод Print() та перевантажити наступні оператори :
//•-- ++– збільшує / зменшує кожну координату на 1
//• > < – перевіряє точки на розташування(ближче / далі) відносно початкової координати(0:0)
//  •  !– змінює значення координат на протилежне
//  Class Point
//{
//int x;
//int y;
//}

class Point
{
private:
    int x;
    int y;
public:

    Point();
    Point(int x, int y);
    Point(const Point& other);
    void Print()const;
    Point& operator ++();
    Point& operator --();

    Point& operator !();

    bool operator >(const Point& other)const;

    bool operator <(const Point& other) const;



};

//Завдання 2:
//Наступним класом є Vector, який описується набором точок на площині.
// Клас містить динамічний масив точок та їх кількість.
//class Vector
//{
//	Point* points;
//	int countPoint;
//}
//Для класу потрібно реалізувати весь необхідний набір конструкторів(копіювання та переміщення обов'язково),
// оператор =, деструткор, метод Add() для додавання нової точки та Print() для виводу інформації на екран. 
//	* Реалізувати вивів точок у відповідних координатах на консолі.Для цього можна використати функцію gotoxy
//	!Результат завантажити у вигляді.cpp файла.
//	* – додаткове завдання

class Vector
{
private:
    Point* points;
    int countPoint;
public:
    Vector(const Vector& other);

    Vector();

    ~Vector();

    Vector& operator=(const Vector& other);

    Vector(Vector&& other);

    Vector& operator=(Vector&& other);

    void Add(const Point& v);

    void Print()const;

};
