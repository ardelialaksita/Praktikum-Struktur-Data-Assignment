# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Ardelia Rachma Laksita</p>

## Table of Contents
1. [Dasar Teori](#dasar-teori)
2. [Guided](#guided)
3. [Unguided](#unguided)
4. [Kesimpulan](#kesimpulan)
5. [Referensi](#referensi)

## Dasar Teori
Searching merupakan ... 

### Penerapan Algoritma Searching :
1. 


## Guided 

### 1. Buatlah sebuah project dengan menggunakan Sequential Search sederhana untuk melakukan pencarian data.

```C++
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // algoritma sequential search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << " data : {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu) {
        cout << "\n angka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```
Kode di atas digunakan untuk ...

#### Output Guided 1:


### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int Data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) {
        min = i;
        for (j = i + 1; j < 7; j++) {
            if (Data[j] < Data[min]) {
                min = j;
            }
        }
        temp = Data[i];
        Data[i] = Data[min];
        Data[min] = temp;
    }
}

void binarysearch() {
    // searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 7;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (Data[tengah] == cari) {
            b_flag = 1;
            break;
        }
        else if (Data[tengah] < cari) {
            awal = tengah + 1;
        }
        else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    }
    else {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main () {
    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";

    //tampilkan data awal
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << Data[x];
    }
    cout << endl;

    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";

    // urutkan data dengan selection sort
    selection_sort();

    // tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << Data[x];
    }
    cout << endl;

    binarysearch();

    _getche();
    return EXIT_SUCCESS;
}
```
Kode tersebut digunakan untuk ...

#### Output Guided 2:


## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah diinput dengan menggunakan Binary Search!
```C++

```

#### Output:


Kode tersebut digunakan untuk ...

#### Full code Screenshot:


### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!
```C++

```

#### Output:


Kode tersebut digunakan untuk ...

#### Full code Screenshot:


### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!
```C++
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
```

#### Output:


Kode tersebut digunakan untuk ...

#### Full code Screenshot:



## Kesimpulan


## Referensi
- [1] 
- [2] 
