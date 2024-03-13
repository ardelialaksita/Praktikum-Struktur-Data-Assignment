#include <iostream>
#include <string>
using namespace std;

// Struct
struct Fruit
{
    string name;
    string colour;
    string taste;
};

class FruitClass
{
    string name;
    string colour;
    string taste;
};

class FruitClass1
{
public:
    string name;
    string colour;
    string taste;
};

int main()
{
    Fruit frt;
    FruitClass1 frt1;

    frt.name = "Apple";
    frt.colour = "Red";
    frt.taste = "Sweet";

    frt1.name = "Orange";
    frt1.colour = "Orange";
    frt1.taste = "Sour";

    cout << "===== BUAH 1 =====" << endl;
    cout << "Nama Buah : " << frt.name << endl;
    cout << "Warna Buah : " << frt.colour << endl;
    cout << "Rasa Buah: " << frt.taste << endl;

    cout << "\n===== BUAH 2 =====" << endl;
    cout << "Nama Buah : " << frt1.name << endl;
    cout << "Warna Buah : " << frt1.colour << endl;
    cout << "Rasa Buah: " << frt1.taste << endl;

    return 0;
}
