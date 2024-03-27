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

// Class (akses default private)
class FruitClass
{
    string name;
    string colour;
    string taste;
};

// Class (akses default public)
class FruitClass1
{
public:
    string name;
    string colour;
    string taste;
};

int main()
{
    // mengisi nilai ke class 
    Fruit frt; 
    FruitClass1 frt1;

    // mengisi nilai class menggunakan nama, warna, dan rasa buah apel
    frt.name = "Apple";
    frt.colour = "Red";
    frt.taste = "Sweet";

    // mengisi nilai class menggunakan nama, warna, dan rasa buah lemon
    frt1.name = "Lemon";
    frt1.colour = "Yellow";
    frt1.taste = "Sour";

    // mencetak isi class pada frt1 (buah apel)
    cout << "===== BUAH 1 =====" << endl;
    cout << "Nama Buah : " << frt.name << endl;
    cout << "Warna Buah : " << frt.colour << endl;
    cout << "Rasa Buah: " << frt.taste << endl;

    // mencetak isi class pada frt2 (buah lemon)
    cout << "\n===== BUAH 2 =====" << endl;
    cout << "Nama Buah : " << frt1.name << endl;
    cout << "Warna Buah : " << frt1.colour << endl;
    cout << "Rasa Buah: " << frt1.taste << endl;

    return 0;
}