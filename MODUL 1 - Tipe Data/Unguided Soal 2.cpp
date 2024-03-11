//CONTOH PROGRAM STRUCT
#include <iostream>
#include <string>
using namespace std;

//Struct
struct Fruit {
    string name;
    string colour;
    string taste;
};

int main() 
{
    struct Fruit fruit1, fruit2;
    fruit1.name = "Durian";
    fruit1.colour = "Kuning";
    fruit1.taste = "Manis";
    fruit2.name = "Lemon";
    fruit2.colour = "Kuning";
    fruit2.taste = "Asam";

    cout << "===== BUAH 1 =====" << endl;
    cout << "Nama Buah : " << fruit1.name << endl;
    cout << "Warna Buah : " << fruit1.colour << endl;
    cout << "Rasa Buah: " << fruit1.taste << endl;
    cout << "===== BUAH 2 =====" << endl;
    cout << "Nama Buah : " << fruit2.name << endl;
    cout << "Warna Buah : " << fruit2.colour << endl;
    cout << "Rasa Buah: " << fruit2.taste << endl;
    return 0;
}
