#include <iostream>
using namespace std;

template<typename T>
class List
{
    struct Node
    {
        T value;
        Node* next;
        Node() : value(), next(nullptr) {}
        Node(T value, Node* next) : value(value), next(next) {}
    };
    Node* head;
public:
    List() : head(nullptr) {}

    List(const List& other) : head(nullptr)
    {
        Node* current = other.head;
        while (current != nullptr)
        {
            AddToTail(current->value);
            current = current->next;
        }
    }

    ~List()
    {
        while (head != nullptr)
        {
            Node* current = head;
            head = head->next;
            delete current;
        }
    }

    void AddToHead(T value)
    {
        head = new Node(value, head);
    }

    void AddToTail(T value)
    {
        Node* newNode = new Node(value, nullptr);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
    }

    void DeleteFromHead()
    {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void DeleteFromTail()
    {
        if (head == nullptr) return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr)
            current = current->next;
        delete current->next;
        current->next = nullptr;
    }

    void Print()
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

class Point
{
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    friend ostream& operator<<(ostream& os, const Point& p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

class Vector
{
    List<Point> points;
public:
    Vector() {}
    Vector(const Vector& other) : points(other.points) {}

    void AddToHead(Point p)
    {
        points.AddToHead(p);
    }
    void AddToTail(Point p)
    {
        points.AddToTail(p);
    }
    void DeleteFromHead()
    {
        points.DeleteFromHead();
    }
    void DeleteFromTail()
    {
        points.DeleteFromTail();
    }
    void Print()
    {
        points.Print();
    }
};

int main(){
    Vector v;
    v.AddToTail(Point(1, 2));
    v.AddToTail(Point(3, 4));
    v.AddToHead(Point(0, 0));
    v.Print();

    v.DeleteFromHead();
    v.Print();

    v.DeleteFromTail();
    v.Print();

    Vector v2(v);


}


//Завдання 1:
//-Написати метод видалення з голови.
//- зробити ліст шаблонним

//Завдання 2 :
//    Реалізувати клас Vector, який містить колекцію точок на площині.
//    Точки зберігаються у вигляді списка(змінна типу List).
//    Для класу потрібно реалізувати необхідний набір конструкторів,
//    методи для видалення, додавання нової точки на початок та в кінець
//    та метод Print() для виводу точок на екран.
//class List {}
//class Point {}
//class Vector
//{
//    int size;
//    //Point * points;
//    List<Point> points;
//}