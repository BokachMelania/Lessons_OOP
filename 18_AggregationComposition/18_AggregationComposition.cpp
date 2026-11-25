#include <iostream>
using namespace std;

 //еонстанкні цілочисеоьні змінні - enum
 enum Type{None,Standart,XL,XXL};

class Document {
	string name;
	string format;
	int pages;
public:
	Document(): name("none"), format("none"), pages(0){}
	Document(string n, string f, int a) : name(n), format(f), pages(a) {}
	void ShowInfo()const {
		cout << "Document: " << name << endl;
		cout << "Format: " << format << endl;
		cout << "Pages: " << pages << endl;
	}
};
class Catridge {
	float volume;
	string color;
	Type type;
public:
	Catridge() : volume(0),color("no color"),type(None){}
	Catridge(float v, string c, Type t) : volume(v),color(c),type(t){}
	void ShowInfo() const {
		cout << "Volume: " << volume << endl;
		cout << "Color: " << color << endl;
		cout << "Type: ";
		switch (type)
		{
		case None:cout << "None";break;
		case Standart:cout << "Standart";break;
		case XL:cout << "XL";break;
		case XXL:cout << "XXL";break;
		}
		cout << endl;
	}
};
class Scanner {
	float scanResolution;
	float height, width;
public:
	Scanner() : scanResolution(0),height(0),width(0){}
	Scanner(float s, int h, int w) : scanResolution(s),height(h),width(w){}
	void ShowInfo()const {
		cout << "Scan resolution " << scanResolution << endl;
		cout << "Area scanning " << height << "x" << width << endl;

	}

};
class Printer {
	string model;
	Catridge* catridges;
	int countcatridges; 
	Scanner scanner;
	//Aggregation
	Document* doc;
public:
	Printer(): model("none"),catridges(nullptr), countcatridges(0), doc(nullptr) {}
	Printer(string m, float s, int h, int w) :model(m), doc(nullptr) ,scanner(s,h,w){
		countcatridges = 4;
		catridges = new Catridge[countcatridges];
		catridges[0] = Catridge(300, "Red", Type::XXL);
		catridges[1] = Catridge(300, "Green", Type::XL);
		catridges[2] = Catridge(300, "Blue", Type::Standart);
		catridges[3] = Catridge(300, "Black", Type::Standart);

	}
	~Printer()
	{
		if (catridges != nullptr)
			delete[]catridges;
	}
	void Scan() {
		cout << "Scanning..................." << endl;

	}
	void PrintDocument() {
		if(doc != nullptr){
			cout << "Print document........." << endl;
			doc->ShowInfo();
		}
		else {
			cout << "No document" << endl;
		}

	}
	void PrintSettings() {
		for (int i = 0; i < countcatridges; i++)
		{
			catridges[i].ShowInfo();
		}
		scanner.ShowInfo();
	}
	void AddDoc(Document* doc) {
		this->doc = doc;
	}

};

int main(){
	Printer printer("Samsung", 300, 30, 50);
	printer.PrintDocument();
	printer.Scan();
	printer.PrintSettings();

	Document d1("Passport", "A5", 16);
	Document d2("c++ FOR begginers", "A4", 1520);

	printer.AddDoc(&d1);
	printer.PrintDocument();

	printer.AddDoc(&d2);
	printer.PrintDocument();




  
}
