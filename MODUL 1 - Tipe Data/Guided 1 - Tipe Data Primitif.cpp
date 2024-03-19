<<<<<<< HEAD
#include <iostream>
using namespace std;
// Main program
int main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cout << "Masukkan operator: ";
    cin >> op;
    // It allow user to enter the operands
=======
#include <iostream> 
using namespace std;

int main() {
    char op;
    float num1, num2;
    
    cout << "Masukkan operator (+, -, *, /): ";
    cin >> op;
    
>>>>>>> 3ccde11d7af4eda7d86130696f3e22238abe300b
    cout << "Masukkan angka pertama: ";
    cin >> num1;
    cout << "Masukkan angka kedua: ";
    cin >> num2;

<<<<<<< HEAD
    //Switch statement begins
    switch (op)
    {
        // If user enter +
        case '+':
        cout << num1 + num2;
        break;
        // If user enter -
        case '-':
        cout << num1 - num2;
        break;
        // If user enter *
        case '*':
        cout << num1 * num2;
        break;
        // If user enter /
        case '/':
        cout << num1 / num2;
        break;

        //If the operator is other than +, -, *, or /,
        // error message will display
        default:
        cout << "Error! Operator is not correct";
    } // Switch statement ends
    return 0;
}
=======
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
                cout << "Error! Nol tidak boleh digunakan sebagai pembagi.";
            break;
        default:
            cout << "Error! Operator is not correct";
    } 
    return 0;
}
>>>>>>> 3ccde11d7af4eda7d86130696f3e22238abe300b
