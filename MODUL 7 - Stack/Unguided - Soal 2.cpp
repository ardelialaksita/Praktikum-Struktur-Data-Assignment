#include <iostream>
#include <windows.h>

using namespace std;

// deklarasi stack yang menyimpan karakter
struct Stack {
    char isi[30];
    int top;
} huruf;

// tambahkan huruf ke dalam stack
void push(char x) {
    if (huruf.top == 30) {
        cout << "Stack sudah penuh";
        return;
    }
    huruf.isi[++huruf.top] = x;
}

// keluarkan huruf dari stack
char pop() {
    if (huruf.top == 0) {
        cout << "Stack sudah kosong";
        return ' ';
    }
    return huruf.isi[huruf.top--];
}

// main program (program utama)
int main() {
    char kalimat[30];
    huruf.top = 0;

    // head of the program (judul program)
    cout << "=== PROGRAM MEMBALIK KALIMAT (REVERSE SENTENCES) ===" << endl;
    
    // user input kalimat (boleh lebih dari 3 kata)
    cout << "Masukkan kalimat: ";
    cin.getline(kalimat, sizeof(kalimat));

    // program menampilkan kalimat asli yang diinput user
    cout << "Kalimat asli: " << kalimat;

    // setiap huruf dimasukkan ke dalam stack dengan memanggil fungsi push
    for (int i = 0; kalimat[i] != '\0'; i++) {
        push(kalimat[i]);
    }

    // program menampilkan kalimat yang telah dibalik
    cout << "\nKalimat setelah dibalik: ";

    // balik kalimat dengan mengeluarkan seluruh huruf dari stack dengan memanggil fungsi pop
    while (huruf.top > 0) {
        cout << pop();
    }
    cout << endl;

    return 0;
}
