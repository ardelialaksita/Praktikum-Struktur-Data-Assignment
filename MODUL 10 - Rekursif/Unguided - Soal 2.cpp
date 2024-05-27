// import library
#include<iostream>
using namespace std;

// PROGRAM REKURSIF TIDAK LANGSUNG MENCARI FAKTORIAL BILANGAN BULAT POSITIF

// fungsi faktorialB yang masih kosong
int faktorialB(int n);

// fungsi faktorialA dengan n sebagai bilangan yang dicari faktorialnya
int faktorialA(int n) {
    // jika n lebih dari 1
    if(n > 1)
        // lakukan return dengan memanggil fungsi faktorialB
        return n * faktorialB(n - 1);
    // jika n tidak lebih dari 1
    else
        // lakukan return 1
        return 1;
}

// fungsi faktorialB dengan n sebagai bilangan yang dicari faktorialnya
int faktorialB(int n) {
    // jika n lebih dari 1
    if(n > 1)
        // lakukan return dengan memanggil fungsi faktorialA
        return n * faktorialA(n - 1);
    // jika n tidak lebih dari 1
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
        cout << "Faktorial dari " << n << " adalah: " << faktorialB(n) << endl;
    }
    // return code
    return 0;
}
