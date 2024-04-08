#include <iostream>
#include <string>
using namespace std;

// deklarasi kalimat dan vokal
string kalimat;
int vokal = 0;

// mencari huruf vokal menggunakan fungsi void 
void search_vokal() {
    // for loop untuk melakukan iterasi
    for (int i = 0; i < kalimat.length(); i++) {
        // mengkonversi seluruh karakter menjadi huruf kecil 
        char huruf = tolower(kalimat[i]);
        if (huruf == 'a'|| huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
            vokal++;
        }
    }
}

// menampilkan hasil jumlah huruf vokal pada suatu kalimat
void print_array() {
    // jika ada huruf vokal dalam kalimat
    if (vokal > 0) {
        cout << "Jumlah huruf vokal = " << vokal;
    }
    // jika tidak ada huruf vokal dalam kalimat
    else {
        cout << "Huruf vokal tidak ditemukan pada kalimat tersebut.";
    }
    // mencetak endline untuk pindah ke baris berikutnya
    cout << endl;
}

// main program
int main () {
    
    // mencetak header pada program
    cout << "----------------------------------------------------" << endl;
    cout << "========== Program Menghitung Huruf Vokal ==========" << endl;
    
    // user memasukkan kata atau kalimat
    cout << "Masukkan kata atau kalimat: ";
    getline(cin, kalimat);

    // memanggil fungsi untuk mencari dan menghitung huruf vokal
    search_vokal();
    // memanggil fungsi untuk menampilkan hasil pencarian dan penghitungan huruf vokal
    print_array();

    // mencetak footer pada program
    cout << "----------------------------------------------------";
    cout << endl;

    // return 0 untuk menandakan bahwa program berhasil 
    return 0;
}