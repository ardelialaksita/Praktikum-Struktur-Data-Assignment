#include <iostream>
using namespace std;

// Ardelia Rachma Laksita (2311110051) S1SD-04 A

// PROGRAM FUNGSI REKURSIF YANG MENERIMA SEBUAH BILANGAN BULAT DAN MENGEMBALIKAN NILAI FAKTORIAL DARI N

int faktorial(int n) {
    if (n > 1) {
        return n * faktorial(n - 1);
    }
    else {
        return 1;
    }
}

// main program
int main() {
    int n;

    // user memasukkan bilangan bulat positif
    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    // apabila bilangan yang dimasukkan kurang dari 0 (bilangan bulat negatif)
    if (n < 0) {
        cout << "Bilangan yang Anda masukkan tidak valid karena kurang dari 0." << endl;
    }
    // apabila bilangan yang dimasukkan sesuai yaitu bilangan bukat positif
    else {
        cout << "Faktorial dari " << n << " adalah " << faktorial(n) << endl;
    }
    return 0;
}
