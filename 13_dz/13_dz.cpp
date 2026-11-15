#include <iostream>
#include <string>
using namespace std;


struct Vagon {
    int Number_wagon;
    int Number_seats;
    int Number_passengers;
};

ostream& operator<<(ostream& os, const Vagon& v)
{
    os << "Number wagon " << v.Number_wagon << endl;
    os << "Number seat: " << v.Number_seats << endl
        << "Number passengers: " << v.Number_passengers;
    os << endl;
    return os;
}


template <typename T>
class List
{
    struct Node
    {
        Node* prev;
        T value;
        Node* next;
        Node() : prev(nullptr), value(), next(nullptr) {}
        Node(Node* p, T v, Node* n) : prev(p), value(v), next(n) {}
    };

private:
    Node* head;
    Node* tail;
    int count;
public:
    List()
    {
        head = tail = nullptr;
        count = 0;
    }

    List(const List& other)
    {
        head = tail = nullptr;
        count = 0;
        for (Node* i = other.head; i != nullptr; i = i->next)
        {
            AddToTail(i->value);
        }
    }

    ~List()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }

    bool IsEmpty() const
    {
        return head == nullptr;
    }

    void AddToHead(T value)
    {
        Node* newNode = new Node(nullptr, value, head);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    void AddToTail(T value)
    {
        Node* newNode = new Node(tail, value, nullptr);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void DeleteFromHead()
    {
        if (IsEmpty()) return;

        Node* current = head;
        head = head->next;

        if (head == nullptr)
            tail = nullptr;
        else
            head->prev = nullptr;

        delete current;
        count--;
    }

    void DeleteFromTail()
    {
        if (IsEmpty()) return;

        if (tail->prev == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        count--;
    }

    void Print() const
    {
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value << endl;
        }
    }
};

class Train
{
private:
    string model;
    int countVagons;
    List<Vagon> vagons;
public:
    Train()
    {
        model = "None";
        countVagons = 0;
    }

    Train(string model)
    {
        this->model = model;
        this->countVagons = 0;
    }

    Train(const Train& other) : vagons(other.vagons)
    {
        this->model = other.model;
        this->countVagons = other.countVagons;
    }

    void Show() const
    {
        cout << "Model: " << model << endl;
        cout << "Vagons: " << countVagons << endl;
        vagons.Print();
        cout << endl;
    }

    void AddVagonToHead(Vagon v)
    {
        vagons.AddToHead(v);
        countVagons++;
    }

    void AddVagonToTail(Vagon v)
    {
        vagons.AddToTail(v);
        countVagons++;
    }

    void DeleteVagonFromHead()
    {
        if (countVagons == 0) return;
        vagons.DeleteFromHead();
        countVagons--;
    }

    void DeleteVagonFromTail()
    {
        if (countVagons == 0) return;
        vagons.DeleteFromTail();
        countVagons--;
    }


};

int main()
{
    Train t("Urban");

    Vagon v1 = { 1, 30, 36 };
    Vagon v2 = { 2, 15, 20 };
    Vagon v3 = { 3, 5, 30 };

    t.AddVagonToTail(v2);
    t.AddVagonToHead(v1);
    t.Show();

    t.DeleteVagonFromHead();
    t.DeleteVagonFromTail();
    t.Show();

    Train copy(t);            
    copy.AddVagonToTail(v3);
    cout << "Original:" << endl;
    t.Show();
    cout << "Copy:" << endl;
    copy.Show();

   
}

//1. Для масиву вагонів створити окрему структуру
//з наступними полями :
//struct Vagon
//    номер вагону
//    кількість місць
//    кількість пасажирів
//    2.class Train
//    Створити клас Потяг.У класі оголосити поля(змінні члени класу) :
//    модель
//    кількість вагонів
//    для збереження масиву вагонів викорисати List<Vagon> vagons;
//В класі потяг оголосити дефолтний конструктор
//і перезавантажений конструктор.
//Реалізувати метод Show()
//Додати методи додавання вагона в початок / кінець та видалення з
//початку / кінця.
//Реалізувати конструктор копіювання
//
//3. Додати метод DeleteFromHead для класу двозв * язного списку.
//Завдання 4:
//На 12 балів зробити видалення по позиції та додавання по позиції
//
//class Train
//{
//private:
//    string model;
//    int countVagons;
//    List<Vagon> vagons;
//}
