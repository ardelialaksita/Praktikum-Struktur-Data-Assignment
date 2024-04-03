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

### 1. Buatlah sebuah project dengan menggunakan **Sequential Search** sederhana untuk melakukan pencarian data.

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


### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan **Binary Search**.

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

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort! (Score: 30)

```C++
#include <iostream>
using namespace std;

// selection sort secara descending menggunakan fungsi void 
void selection_sort(double array[], int n) {

    // deklarasi posisiMaks dan temp
    int posisiMaks; 
    double temp;

    // perulangan for untuk menjalankan proses sorting secara descending (terbesar ke terkecil)
    for (int i=0; i < n-1; i++) {
        posisiMaks = i;
        for (int j=i+1; j < n; j++) {
            // array[j] lebih besar daripada array[posisiMaks] karena sorting dilakukan secara descending (menurun)
            if (array[j] > array[posisiMaks]) {
                posisiMaks = j;
            } // end of if
        } // end of for loop

        if (posisiMaks != i) {
                temp = array[i];
                array[i] = array[posisiMaks];
                array[posisiMaks] = temp;
        } // end of if
    } // end of for loop
}

// mencetak dan menampilkan array
void print_array(double a[], int length) {

    for (int i=0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {
    
    // menentukan panjang array (banyak data yang dimasukkan)
    int length = 5;
    // memasukkan data array
    double a[length] = {3.8, 2.9, 3.3, 4.0, 2.4};  

    // menampilkan data Indeks Prestasi Semester Mahasiswa sebelum diurutkan 
    cout << "Indeks Prestasi Semester (IPS) Mahasiswa sebelum sorting: " << endl;
    print_array(a, length);

    // memanggil fungsi untuk menjalankan selection sort
    selection_sort(a, length);

    // menampilkan data Indeks Prestasi Semester Mahasiswa setelah diurutkan secara descending (dari terbesar ke terkecil)
    cout << "\nIndeks Prestasi Semester (IPS) Mahasiswa setelah sorting dari terbesar ke terkecil: " << endl;
    print_array(a, length);

}
```

#### Output:


Kode tersebut digunakan untuk ...

#### Full code Screenshot:


### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan nama nama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort! (Score: 30)

```C++
#include <iostream>
#include <string>
using namespace std;

// melakukan sorting menggunakan bubble sort secara ascending (menaik)
void bubble_sort(string array[], int length) {
    bool before_sorted = true;
    int j=0;
    string tmp;

    // while loop untuk melakukan iterasi selama proses sorting
    while (before_sorted){
        before_sorted = false;
        j++;
        
        // for loop untuk membandingkan antar elemen dan menukar posisi 
        for (int i = 0; i < length - j; i++) {
            if (array[i] > array[i+1]) {
                tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
                before_sorted = true;
            } // end of if
        } // end of for loop
    } // end of while loop
} // end of bubble_sort

// mencetak dan menampilkan array
void print_array(string nama_warga[], int length) {

    for (int i = 0; i < length; i++) {
        cout << nama_warga[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {

    // mengisi panjang array (tanpa menggunakan input oleh user)
    int length = 10;
    // mengisi nama-nama warga dalam array sesuai panjang (length) yang telah ditentukan sebelumnya
    string nama_warga[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    // menampilkan nama warga sebelum diurutkan
    cout << "Urutan nama warga sebelum sorting: " << endl;
    print_array(nama_warga, length);

    // memanggil fungsi untuk melakukan bubble sort secara ascending
    bubble_sort(nama_warga, length);

    // menampilkan nama warga setelah diurutkan sesuai alfabet (A-Z)
    cout << "\nUrutan nama warga sesuai alfabet (A-Z): " << endl;
    print_array(nama_warga, length);
}
```

#### Output:


Kode tersebut digunakan untuk ...

#### Full code Screenshot:


### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)! (Score: 40)

```C++
#include <iostream>
using namespace std;

// melakukan sorting menggunakan insertion sort secara ascending (menaik)
void insertion_sort_ascending(char arr[], int length) {

    //deklarasi i, j, dan tmp
    int i, j;
    char tmp;

    // for loop dan while loop untuk inisialisasi pada proses insertion sort secara ascending
    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        } // end of while loop
    } // end of for loop
} // end of void function

// melakukan sorting menggunakan insertion sort secara descending (menurun)
void insertion_sort_descending(char arr[], int length) {

    //deklarasi i, j, dan tmp
    int i, j;
    char tmp;

    // for loop dan while loop untuk inisialisasi pada proses insertion sort secara descending
    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        } // end of while loop
    } // end of for loop
} // end of void function

// mencetak dan menampilkan array
void print_array(char a[], int length) {
    
    for(int i=0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {

    // deklarasi length untuk menyimpan panjang array
    int length;
    
    // user memasukkan panjang array
    cout << "input (n) = ";
    cin >> length;

    // deklarasi array bertipe karakter dengan length yang ditentukan oleh user
    char a[length];

    // user memasukkan beberapa karakter sesuai dengan panjang yang telah diinput
    cout << "Masukkan " << length << " karakter: " << endl;
    
    // for looping untuk mnenampilkan karakter ke-berapa yang akan diisi oleh user
    for (int i = 0; i < length; i++) {
        cout << "Karakter ke-" << i + 1 << ": ";
        cin >> a[i];
    }
    cout << endl;
    
    // menampilkan karakter sebelum sorting
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    // memanggil fungsi untuk mengurutkan karakter secara ascending
    insertion_sort_ascending(a, length);

    // menampilkan karakter setelah diurutkan secara ascending
    cout << "\nUrutan karakter setelah ascending sort: " << endl;
    print_array(a, length);

    // memanggil fungsi untuk mengurutkan karakter secara descending
    insertion_sort_descending(a, length);
    
    // menampilkan karakter setelah diurutkan secara descending
    cout << "\nUrutan karakter setelah descending sort: " << endl;
    print_array(a, length);

}
```
#### Output:


Kode tersebut digunakan untuk ...

#### Full code Screenshot:



## Kesimpulan


## Referensi
- [1] 
- [2] 
