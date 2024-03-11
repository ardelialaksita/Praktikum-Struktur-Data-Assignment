#include <iostream>
#include <map>
using namespace std;

int main() {
    // Membuat map dengan integer key
    map<int, string> animals = {{1, "Kucing"}, {2, "Unicorn"}, {3, "Dinosaurus"}};

    // Menambahkan elemen baru
    animals.insert(make_pair(4, "Paus"));

    // Mengakses elemen-elemen map
    cout << animals[1] << endl;
    cout << animals[2] << endl;
    cout << animals[3] << endl;
    cout << animals[4] << endl;

    // Menghapus elemen dari map
    animals.erase(2);

    // Membersihkan map
    animals.clear();

    return 0;
}
