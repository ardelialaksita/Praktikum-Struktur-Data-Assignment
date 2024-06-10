#include <iostream>
using namespace std;

// Ardelia Rachma Laksita (2311110051) S1SD-04 A

// PROGRAM MENCARI SUATU ANGKA TERLETAK PADA INDEKS KE BERAPA

int main() { 
    int n = 6; 
    int data[n] = {1,2,3,4,5,5};
    int cari = 5; // angka yang dicari adalah 5
    int ketemu;
    int i; // untuk mengetahui indeks
    
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    // Apabila angka ditemukan di dalam data
    if(ketemu) {
        cout << "Angka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } 
    // Apabila angka tidak ditemukan di dalam data
    else {
        cout << "Angka " << cari << " tidak ditemukan pada data tersebut." << endl;
    }
    return 0;
}
