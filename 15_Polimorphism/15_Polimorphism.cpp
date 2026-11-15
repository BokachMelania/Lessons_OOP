#include <iostream>
#include <Windows.h>
using namespace std;

class Car
{
private:
    string model;
    int year;
protected:
    int speed;
    float volume;
public:
    //дефолтний -  без параметрів, значення задаємо самі
    //Клас() : поле1(значення), поле2(значення), поле3(значення) {}
    Car() :model("no model"), year(0), speed(0), volume(0) {}

    //параметризований - значення беремо з параметрів
    //Клас(тип а, тип б) : поле1(а), поле2(б), поле3(0) {}
    Car(string m, int y, float v) :model(m), year(y), speed(0), volume(v) {}



    // virtual — дозволяє нащадкам перевизначити (замінити) метод батька.
    // Тоді через Car& або Car* викличеться версія реального об'єкта (поліморфізм).
    virtual void Drive() const
    {
        cout << "I am a Car! I can drive with speed : " << speed << "km/h" << endl;
    }
    //virtual потрібен, щоб через вказівник
    // /посилання на батька викликалась версія нащадка.
    /*
    void TestDrive(Car& car) { car.Drive(); }
        TestDrive(police);
        */


    void setSpeed(int speed)
    {
        if (speed > 0)
            this->speed = speed;
        else
            speed = 0;
    }
    virtual void Print()const
    {
        cout << "---------------Car------------------" << endl;
        cout << "Model : " << model << endl;
        cout << "Year : " << year << endl;
        cout << "Speed : " << speed << endl;
        cout << "Volume : " << volume << endl;
    }
};

class PoliceCar : public Car
{
    int soundVolume;
public:
    //ініціалізує власне поле( PoliceCar() : soundVolume(0))
    //викликає конструктор батька (дефолтний), 
    // щоб він ініціалізував успадковані частини -, Car() {}
    PoliceCar() : soundVolume(0), Car() {} //Car(){} делегування 
    PoliceCar(string n, int y, float v, int sound) : soundVolume(sound),
        Car(n, y, v) {
    }
    void Drive()const
    {
        cout << "I am a Police Car. I can drive with speed " << speed << " km/h" << endl;
    }
    //Override (перевизначення) — це заміна реалізації віртуального методу батьківського класу в дочірньому класі.
    void Print()const override
    {
        Car::Print();//  // викликаємо від батьківськаго(::);використовується для того щоб не дублювати код а виводити спільну частину(model, year, speed, volume) 
        cout << "Sound Volume : " << soundVolume << "db" << endl;
    }
    void BeepBeep(){   
        //cout << "\a";
        Beep(400, 200);
        Beep(500, 100);
        Beep(100, 300);

    }
};

class SportCar : public Car  // наслідування 
{
    int turboSpeed;
public:
    SportCar() : turboSpeed(0), Car() {}   //Car(){} делегування( виклик конструктора батька)
    //Car() у списку = виклик конструктора батька

    SportCar(string n, int y, float v, int ts) : turboSpeed(ts),
        Car(n, y, v) { // ініціалізація   Car(n, y, v)  для того щоб в  SportCar задати базові параментри як ізнаходяться в Car для всіх машин
    }
    void Drive()const
    {
        cout << "I am a Sport Car. I can drive with speed " << speed << " km/h" << endl;
    }
    void Print()const override
    {
        Car::Print();  //  // викликаємо від батьківськаго
        cout << "Turbo Speed : " << turboSpeed << "db" << endl;
    }
    void Nitro()
    {
        speed += turboSpeed;
        cout << "Turbo speed " << speed << "km/h" << endl;
    }
};

void TestDrive(Car& car) //поліморфізм працює тільки з ориганілом
{
    car.setSpeed(70);
    car.Drive();
    car.Print();
    cout << endl;

}
int main()
{

    Car car("BMV", 2024, 3.0);
    car.setSpeed(280);
    car.Drive();
    car.Print();

    cout << "------------------------------" << endl;
    PoliceCar police("Renult Duster", 2015, 1.6, 500);
    police.setSpeed(220);
    police.Drive();
    police.Print();

    SportCar sport("Formula 1", 2025, 2.5, 100);
    sport.setSpeed(150);
    sport.Drive();
    sport.Print();
    //police.BeepBeep();
    TestDrive(car);
    TestDrive(police);
    TestDrive(sport);


    Car* cars[3]{
        new Car("BMV", 2024, 3.0),
        new PoliceCar("Renult Duster",2015,1.6,500),
        new SportCar("Formula 1", 2025, 2.5, 100)
    };

    for (int i = 0; i < 3; i++)
    {
        cars[i]->Drive();
        cars[i]->Print();
        delete cars[i];
    }







}