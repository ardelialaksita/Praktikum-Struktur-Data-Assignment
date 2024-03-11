#include <iostream> 
using namespace std;

int main() {
    char op;
    float num1, num2;
    
    cout << "Masukkan operator (+, -, *, /): ";
    cin >> op;
    
    cout << "Masukkan angka pertama: ";
    cin >> num1;
    cout << "Masukkan angka kedua: ";
    cin >> num2;

    switch (op) {
        case '+':
            cout << "Hasil Penjumlahan: " << num1 + num2;
            break;
        case '-':
            cout << "Hasil Pengurangan: " << num1 - num2;
            break;
        case '*':
            cout << "Hasil Perkalian: " << num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                cout << "Hasil Pembagian: " << num1 / num2;
            else
                cout << "Error! Nol tidak boleh sebagai pembagi.";
            break;
        default:
            cout << "Error! Operator is not correct";
    } 
    return 0;
}