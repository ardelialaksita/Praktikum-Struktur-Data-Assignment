#include <iostream>
#include <string>
using namespace std;

// fungsi untuk melakukan proses pencarian menggunakan sequential search untuk menghitung berapa kali suatu angka muncul pada array
int sequential_search(int arrData[], int panjangArray, int count_number) {
    // deklarasi inisialisasi variabel untuk menghitung berapa kali suatu angka dalam array muncul 
    int count = 0; 
    // for loop untuk melakukan inisialisasi dan memeriksa apakah suatu elemen sama seperti angka yang dihitung banyak kemunculannya atau tidak
    for (int i = 0; i < panjangArray; i++) {
        // melakukan pengecekan elemen (apakah sama seperti angka yang ingin dihitiung banyak kemunculannya atau tidak)
        if (arrData[i] == count_number) {
            count++;
        }
    }
    // return count untuk mengembalikan jumlah kemunculan suatu angka yang dihitung banyak kemunculannya
    return count;
}

// main program
int main () {
    // deklarasi untuk inisalisasi angka yang ingin dihitung banyak kemunculannya
    int n = 10;
    // data array bilangan
    int arrData[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    // masukkan angka yang ingin dihitung banyak kemunculannya 
    int count_number = 4;
    
    // menghitung panjang array
    int panjangArray = sizeof(arrData) / sizeof(arrData[0]);
    // memanggil fungsi sequential search 
    int count = sequential_search(arrData, panjangArray, count_number);

    // menampilkan angka dan banyaknya kemunculan angka tersebut 
    cout << "Angka " << count_number << " pada data tersebut muncul sebanyak " << count << " kali." << endl;
    // return 0 sebagai kode bahwa program telah selesai dan berhasil 
    return 0;
}