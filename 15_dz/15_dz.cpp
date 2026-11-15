#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape {
protected:
	string name;
	string type;
	int area;
public:
	Shape() : name("no name"), type("no type"), area(0) {}
	Shape(string n, string t) : name(n), type(t), area(0) {}

	virtual void Show() const {
		cout << "Name of figures: " << name << endl;
		cout << "Type of figures: " << type << endl;
	}
	virtual void ShowFigures() const {}

	virtual void GetArea(int area) {
		this->area = area > 0 ? area : 0;
	}
};

class Rectangle : public Shape {
	int width;
	int length;
public:
	Rectangle() : width(0), length(0), Shape() {}
	Rectangle(string n, string t, int w, int l) : width(w), length(l), Shape(n, t) { 
		GetArea(0); }

	void GetArea(int area) override {
		Shape::GetArea(width * length);
	}

	void Show() const override {
		cout << "------Rectangle---------" << endl;
		cout << endl;
		Shape::Show();
		cout << "Area of rectangle = " << area << " cm^2" << endl;
		cout << endl;
	}

	void ShowFigures() const override {
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << "=";
			}
			cout << "\n";
		}
		cout << endl;
	}
};

class Circle : public Shape {
	int radius;
public:
	Circle() : radius(0), Shape() {}
	Circle(string n, string t, int rad) : radius(rad), Shape(n, t) {
		GetArea(0);
	}

	void GetArea(int area) override {
		Shape::GetArea(3.14 * pow(radius, 2));
	}

	void Show() const override {
		cout << "------Circle-----------------" << endl;
		cout << endl;
		Shape::Show();
		cout << "Area of circle = " << area << " cm^2" << endl;
		cout << endl;
	}

	void ShowFigures() const override {
		float dist;
		for (int i = 0; i <= 2 * radius; i++) {
			for (int j = 0; j <= 2 * radius; j++) {
				dist = sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius));

				if (dist > radius - 0.5 && dist < radius + 0.5) {
					cout << "* ";
				}
				else {
					cout << "  ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
};

class RightTriangle : public Shape {
	int a;
	int b;
public:
	RightTriangle() : a(0), b(0), Shape() {}
	RightTriangle(string n, string t, int a, int b) : a(a), b(b), Shape(n, t) {
		GetArea(0);
	}

	void GetArea(int area) override {
		Shape::GetArea((a * b) / 2);
	}

	void Show() const override {
		cout << "------RightTriangle---------" << endl;
		cout << endl;
		Shape::Show();
		cout << "Area of RightTriangle = " << area << " cm^2" << endl;
		cout << endl;
	}

	void ShowFigures() const override {
		for (int i = 1; i <= a; i++) {
			int stars = (b * i) / a;
			if (stars == 0) stars = 1;

			for (int j = 1; j <= stars; j++) {
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

class Triangle : public Shape {
	int side_triangle;
	int height;
public:
	Triangle() : side_triangle(0), height(0), Shape() {}
	Triangle(int s, int h, string n, string t) :
		side_triangle(s), height(h), Shape(n, t) {
		GetArea(0);
	}

	void GetArea(int area) override {
		Shape::GetArea((side_triangle * height) / 2);
	}

	void Show() const override {
		cout << "------Triangle---------" << endl;
		cout << endl;
		Shape::Show();
		cout << "Area of Triangle = " << area << " cm^2" << endl;
		cout << endl;
	}

	void ShowFigures() const override {
		for (int i = 1; i <= height; ++i) {
			for (int j = 1; j <= height - i; ++j) {
				cout << " ";
			}
			for (int l = 1; l <= 2 * i - 1; ++l) {
				if (l == 1 || l == 2 * i - 1 || i == height) {
					cout << "+";
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
};

class Trapezoid : public Shape {
	int side_a;
	int side_b;
	int height;
public:
	Trapezoid() : side_a(0), side_b(0), height(0), Shape() {}
	Trapezoid(string n, string t, int sa, int sb, int h) : side_a(sa), side_b(sb), height(h), Shape(n, t) {
		GetArea(0);
	}

	void GetArea(int area) override {
		Shape::GetArea((side_a + side_b) * height / 2);
	}

	void Show() const override {
		cout << "------Trapezoid---------" << endl;
		cout << endl;
		Shape::Show();
		cout << "Area of Trapezoid = " << area << " cm^2" << endl;
		cout << endl;
	}

	void ShowFigures() const override {
		for (int j = 0; j < height; ++j) {
			cout << " ";
		}
		for (int k = 0; k < side_a * 2; ++k) {
			cout << "_";
		}
		cout << endl;
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < height - i - 1; ++j) {
				cout << " ";
			}
			cout << "/";

			int inner_width = side_a * 2 + i * 2;

			for (int k = 0; k < inner_width; ++k) {
				if (i == height - 1) {
					cout << "_";
				}
				else {
					cout << " ";
				}
			}
			cout << "\\" << endl;
		}
		cout << endl;
	}
};

void TestShape(Shape& s)
{  
	s.ShowFigures();  
}

int main() {
	Rectangle rec("Rectangle", "Quadrilateral", 10, 5);
	rec.Show();
	TestShape(rec);

	RightTriangle r("Righttriangle", "triangle", 6, 6);
	r.Show();
	TestShape(r);

	Circle cir("Circle", "None", 3);
	cir.Show();
	TestShape(cir);

	Triangle t(3, 6, "Triangle", "triangle");
	t.Show();
	TestShape(t);

	Trapezoid trap("Trapezoid", "trapezoid", 4, 5, 5);
	trap.Show();
	TestShape(trap);
}

//Завдання 1:
//Створіть клас Shape який містить загальні параметри
//будь - якої фігури(ім, я, тип і тд).Визначте віртуальні методи :
//•Show – вивід на екран інформації про фігуру; •Show
//•GetArea – обчислення площі фігури; (•GetArea)
//Визначте похідні класи : прямокутник, коло, прямокутний трикутник, трикутник,
//трапеція зі своїми функціями площі.– кожний з яких буде
//містити притаманні даній фігурі характеристики та перевизначати(override)
//алгоритми методів базового класу Shape.
//Також створити функцію TestShape, яка приймає фігуру та відображає її
//інформацію включаючи площу.
//В main протестувати роботу, передавши в функцію різні фігури.