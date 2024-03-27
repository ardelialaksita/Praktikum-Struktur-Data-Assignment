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
    cout << "Masukkan angka pertama: ";
    cin >> num1;
    cout << "Masukkan angka kedua: ";
    cin >> num2;

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