#include "Point.h"

 Point::Point() {
    x = 0;
    y = 0;
}

 Point::Point(int x, int y) {

    this->x = x;
    this->y = y;
}

 Point::Point(const Point& other) {
    this->x = other.x;
    this->y = other.y;
}

 void Point::Print() const {
    cout << "X: " << x<<" " << "Y: " << y << endl;;

}

 Point& Point::operator++() {
    x++;
    y++;
    return *this;//поверни той самий об'єкт, який щойно змінили»
}

 Point& Point::operator--() {
    x--;
    y--;
    return *this;
}

 Point& Point::operator!() {
    x = -x;
    y = -y;
    return*this;


}

bool Point::operator >(const Point& other)const {
    return((this->x + this->y) > (other.x + other.y));

}

bool Point::operator<(const Point& other) const
{
    return ((this->x + this->y) < (other.x + other.y));
}
//2

 Vector::Vector(const Vector& other) {
    this->countPoint = other.countPoint;
    points = new Point[countPoint];
    for (int i = 0; i < countPoint; i++)
    {
        this->points[i] = other.points[i];
    }
}

 Vector::Vector() {
    points = nullptr;
    countPoint = 0;
}

 Vector::~Vector()
{
    if (points != nullptr)
        delete[] points;
}

 Vector& Vector::operator=(const Vector& other)
{
    if (this == &other)
        return *this;

    this->countPoint = other.countPoint;
    if (points != nullptr)
        delete[]points;
    this->points = new Point[countPoint];
    for (int i = 0; i < countPoint; i++)
    {
        this->points[i] = other.points[i];
    }
    return *this;
}

 Vector::Vector(Vector&& other)
{
    this->countPoint = other.countPoint;
    this->points = other.points;
    other.points = nullptr;
    other.countPoint = 0;
}

 Vector& Vector::operator=(Vector&& other) {
    if (this == &other) return *this;
    if (points != nullptr)
        delete[] points;
    points = other.points;
    countPoint = other.countPoint;
    other.points = nullptr;
    other.countPoint = 0;
    return *this;
}

 void Vector::Add(const Point& v)
{
    Point* temp = new Point[countPoint + 1];
    for (int i = 0; i < countPoint; i++)
    {
        temp[i] = points[i];
    }
    temp[countPoint] = v;
    if (points != nullptr)
        delete[] points;
    countPoint++;
    points = temp;
}

 void Vector::Print() const {
    for (int i = 0; i < countPoint; i++)
    {
        points[i].Print();
    }
    cout << endl;
}

