#include <iostream>
using namespace std;

//Fungsi untuk mengecek apakah suatu bilangan adalah bilangan ganjil (odd number)
bool isOdd(int num) {
    return num % 2 != 0;
}

//Fungsi untuk mengecek apakah suatu bilangan adalah bilangan genap (even number)
bool isEven(int num){
    return num % 2 == 0;
}

int main() {
    int num;
    cout << "Masukkan bilangan: ";
    cin >> num;

    if (isOdd(num)) {
        cout << num << " adalah bilangan ganjil" << endl;
    }
    else if (isEven(num)) {
        cout << num << " adalah bilangan genap" << endl;
    }
    else {
        cout << num << " adalah bilangan 0 (bukan bilangan ganjil dan genap)" << endl;
    }
        
    return 0; 
        
}

