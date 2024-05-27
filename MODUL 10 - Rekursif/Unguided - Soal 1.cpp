// import library
#include<iostream>
using namespace std;

// PROGRAM REKURSIF LANGSUNG MENCARI FAKTORIAL BILANGAN BULAT POSITIF

// fungsi faktorial dengan n sebagai bilangan yang dicari faktorialnya
int faktorial(int n) {
    // jika n lebih besar dari 1
    if(n > 1)
        // lakukan return dikali dengan bilangan n - 1
        return n * faktorial(n - 1);
    // jika n tidak lebih besar dari 1
    else
        // lakukan return 1
        return 1;
}

// main program (program utama)
int main() {
    // deklarasi n
    int n;

    // user input bilangan bulat positif
    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    // tampilkan output jika user input n kurang dari 0
    if (n < 0) {
        cout << "Input tidak valid. Harap masukkan bilangan bulat positif." << endl;
    } 
    // tampilkan output jika user input n lebih dari 0
    else {
        cout << "Faktorial dari " << n << " adalah: " << faktorial(n) << endl;
    }
    // return code
    return 0;
}
