#include <iostream>
#include <string>
using namespace std;

enum People { Guest = 1, Administrator = 2, Manager = 3, Director = 4 };

struct Document
{
	string name;
	string position;
	int priority;
	void Print() {
		cout << "[" << priority << "] " << position << " -> " << name;
	}
};

template< typename T>
class QueueWithPriority
{
	T* elements;
	int count;
public:
	QueueWithPriority() : elements(nullptr), count(0) {}
	~QueueWithPriority()
	{
		if (elements != nullptr)
			delete[]elements;
	}
	void Enqueue(T el)
	{
		int index = 0;
		while (index < count && elements[index].priority >= el.priority)index++;
		T* temp = new T[count + 1];
		for (int i = 0; i < index; i++)
		{
			temp[i] = elements[i];
		}
		temp[index] = el;
		for (int i = index; i < count; i++)
		{
			temp[i + 1] = elements[i];
		}
		if (elements != nullptr)
			delete[]elements;
		elements = temp;
		count++;
	}
	bool IsEmpty()const
	{
		return count == 0;
	}
	T Dequeue()
	{
		if (!IsEmpty())
		{
			T first = elements[0];
			for (int i = 0; i < count - 1; i++)
			{
				elements[i] = elements[i + 1];
			}
			count--;
			return first;
		}
	return T();
	}
	void Print()
	{
		cout << "------------- Queue -------------" << endl;
		for (int i = 0; i < count; i++)
		{
			elements[i].Print();
			cout << endl;
		}
		cout << "---------------------------------" << endl;
	}
};

int main()
{
    QueueWithPriority<Document> queue;
    Document document;
    char menu = '1';

    while (menu != '0')
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Add document to queue" << endl;
        cout << "2. Print document from queue" << endl;
        cout << "3. Show queue" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> menu;

        switch (menu)
        {
        case '1':
        {
            int choice{};
            cout << "Select your position:" << endl;
            cout << "1 - Guest\n2 - Administrator\n3 - Manager\n4 - Director" << endl;
            cout << "Enter your character: "<<endl;
            cin >> choice;
            cout << "Enter file name: "<<endl;
            cin >> document.name;

            document.priority = choice;
            switch (choice)
            {
            case 1:
                document.position = "Guest";
                break;
            case 2:
                document.position = "Administrator";
                break;
            case 3:
                document.position = "Manager";
                break;
            case 4:
                document.position = "Director";
                break;
            }
            if (document.priority > 0 && document.priority < 5)
            {
                queue.Enqueue(document);
                cout << "Document added to queue." << endl;
            }
            else
            {
                cout << "incorrect priority" << endl;
            }
            break;
        }
        case '2': 
        {
            if (!queue.IsEmpty())
            {
                cout << "\nPrinting document:" << endl;
                queue.Dequeue().Print();
                cout << endl;
            }
            else
            {
                cout << "Queue is empty!" << endl;
            }
            break;
        }
        case '3':
            queue.Print();
            break;
        case '0':
            cout << "Goodbye" << endl;
            break;
        default:
            cout << " incorrect menu choice" << endl;
            break;


        }
    }
    
	
//ТЕМА: DYNAMIC DATA STRUCTURES.PRIORITY QUEUE.
//Завдання 1 :
//Розробити додаток, що імітує чергу друку принтера.
//Програма надає меню з наступними можливостями :
//•Додати документ в чергу.
//Користувач повинен ввести ім’я файлу та
//вибрати свою посаду.В залежності від посади,
//документу надається певний пріорітет
//(до прикладу : гість – 1, адміністратор – 2, менеджер – 3,
//директор – 4 і тд.)
//•Виконати друк.Відображається на екран документ,
//який наразі друкується(з максимальним пріорітетом).
//Для збереження колекції документів використати динамічну
//структуру даних – Queue(черга з пріорітетним включенням).
//Клас черга має бути шаблонним.
}

	






