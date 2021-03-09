#include <iostream>
using namespace std;
const double pi=3.14;

class Cone {
private:
    int *radius, *height;

public:
    Cone() {
        cout << "Викликаємо конструктор..." << endl;
        radius = new int;
        height = new int;
        *radius = *height = 0;
    }

    Cone(int Radius, int Height) {
        cout << "Викликаємо конструктор..." << endl;
        radius = new int;
        height = new int;
        *radius = Radius;
        *height = Height;
    }

    Cone(const Cone &obj) {
        cout << "Конструктор копіювання..." << endl;
        this -> radius = obj.radius;
        this -> height = obj.height;
    }

    ~Cone() {
        cout << "Викликаємо деструктор..." << endl;
        delete radius;
        delete height;
    }

    double GetRadius() {
        return *radius;
    }

    double GetHeight() {
        return *height;
    }

    void SetRadius(int Radius) {
        while (Radius <= 0) {
            cout << "Некоректно значення радіуса! Введіть ще раз: ";
            cin >> Radius;
        }
        *radius = Radius;
    }

    void SetHeight(int Height) {
        while (Height <= 0) {
            cout << "Некоректно значення висоти! Введіть ще раз: ";
            cin >> Height;
        }
        *height = Height;
    }

    void Print() {
        cout << "Радіус: " << *radius << "\tВисота: " << *height << "\n\n";
    }

    double Volume() {
        return (pi * *radius * *radius * *height) / 3;
    }

    double Area() {
        double l = sqrt(*height * *height + *radius * *radius); // твірна конуса
        return pi * *radius * (*radius + l); // повна площа поверхні конуса
    }
};

int main() {
    system("chcp 1251");

    Cone obj1(4, 5);
    cout << "Радіус: " << obj1.GetRadius() << "\tВисота: " << obj1.GetHeight() << endl;
    obj1.SetRadius(-1);
    obj1.SetHeight(0);
    obj1.Print();
    cout << "Об'єм конуса: " << obj1.Volume() << endl;
    cout << "Площа повної поверхні конуса: " << obj1.Area() << "\n\n";

    Cone obj2(obj1);
    obj2.Print();

    Cone obj3;
    cout << "Радіус: " << obj3.GetRadius() << "\tВисота: " << obj3.GetHeight() << endl;
    cout << "\nВикликаємо сеттери:\n";
    obj3.SetRadius(1);
    obj3.SetHeight(2);
    obj3.Print();
    cout << "Об'єм конуса: " << obj3.Volume() << endl;
    cout << "Площа повної поверхні конуса: " << obj3.Area() << endl;

    getchar();getchar();
    return 0;
}
