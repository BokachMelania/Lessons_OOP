#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

struct Point {
    int x;
    int y;
};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Shape {
protected:
    string type;
public:
    Shape() : type("no type") {}
    Shape(string type) : type(type) {}

    virtual void Print()const = 0;// pure virtual method
    // Чисто віртуальний: кожна фігура сама пише свої дані у файл.
    // Потік приходить у дужках, щоб усі фігури писали в один файл (інакше кожен Save перезаписував би його).
    // & бо потік не копіюється; const бо фігура не змінюється.
    virtual void Save(ofstream& file) const = 0;  //
    virtual ~Shape() {}
};

class Line : public Shape {
    Point start;
    Point end;
public:
    Line() : start{ 0, 0 }, end{ 0, 0 }, Shape("Line") {}
    Line(Point start, Point end) : start(start), end(end), Shape("Line") {}
    void Print()const override {
        gotoxy(start.x, start.y);
        cout << "*";
        gotoxy(end.x, end.y);
        cout << "*";
    }
    void Save(ofstream& file) const override {
        file << type << " " << start.x << " " << start.y << " " << end.x << " " << end.y << endl;
    }
};

class RRectangle : public Shape {
    Point upperLeftCoor;
    int width;//ширину
    int length;//довжину
public:
    RRectangle() :upperLeftCoor{ 0, 0 }, width(0), length(0), Shape("Rect") {}
    RRectangle(Point u, int w, int l) :upperLeftCoor(u), width(w), length(l), Shape("Rect") {}
    void Print()const override {
        int x = upperLeftCoor.x;
        int y = upperLeftCoor.y;
        for (int i = y; i < y + length; i++)
        {
            for (int j = x; j < x + width; j++)
            {
                gotoxy(j, i);
                cout << "*";
            }
        }
    }
    void Save(ofstream& file) const override {
        file << type << " " << upperLeftCoor.x << " " << upperLeftCoor.y << " " << width << " " << length << endl;
    }
};

class PPolyline : public Shape {
    Point* points;
    int count;
public:
    PPolyline() :points(nullptr), count(0), Shape("Polyline") {}
    PPolyline(initializer_list<Point> list) : Shape("Polyline") {
        this->count = list.size();
        points = new Point[count];
        int i = 0;
        for (Point p : list) {
            points[i] = p;
            i++;
        }
    }

    void Print()const override {
        for (int i = 0; i < count; i++)
        {
            gotoxy(points[i].x, points[i].y);
            cout << "*";
        }
    }
    void Save(ofstream& file) const override {
        file << type << " " << count;
        for (int i = 0; i < count; i++) {
            file << " " << points[i].x << " " << points[i].y;
        }
        file << endl;
    }
    ~PPolyline() override {
        if (points != nullptr)
            delete[] points;
    }
};

int main() {
    Point start = { 7, 9 };
    Point end = { 14, 18 };

    Shape* shape[3] = {
        new Line(start, end),
        new RRectangle(Point{ 20, 5 }, 6, 8),
        new PPolyline({ {12,15},{15,20},{23,27} })
    };

    //Створює об'єкт потоку запису з іменем file і одразу відкриває файл shapes.txt
    ofstream file("shapes.txt");

    for (int i = 0; i < 3; i++)
    {
        shape[i]->Print();
        shape[i]->Save(file);
        delete shape[i];
    }
    file.close();

    gotoxy(0, 30);
}
//ТЕМА: VIRTUAL DESTRUCTOR
//Завдання 1 :
//  Створити абстрактний клас Shape(фігура).Яка містить тип та чисто віртуальний метод Print(), для показу фігури на консоль.
//  Реалізувати похідні класи :
//• Line – містить координати початку та кінця(дві точки)
//• Rectangle – містить координати верхнього лівого кута, ширину та довжину
//• Polyline – містить масив точок
//Всі похідні класи повинні перевизначати метод Print(), друкуючи фігуру на консолі враховуючи її параметри.Додати деструктор в класи, які його потребують.
//Для зручності можна створити структуру struct Point { int x, y }; та скористатися методом gotoxy().
//* Додати метод Save() для запису фігури в файл.