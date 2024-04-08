# <h1 align="center">Laporan Praktikum Modul Searching</h1>
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
**1. Sequential Search** yaitu 
**2. Binary Search** yaitu


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
#include <iostream>
#include <string>
using namespace std;

// deklarasi kalimat, vokal, konsonan, dan huruf
string kalimat;
int vokal = 0;
int konsonan = 0;
char huruf;

// program melakukan pencarian menggunakan binary search
bool binarysearch()
{
    // searching
    int awal, akhir, tengah;
    awal = 0;
    akhir = kalimat.size() - 1;
    while (awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        // jika indeks tengah pada kalimat sama dengan huruf, maka akan mengembalikan nilai true
        if (kalimat[tengah] == huruf)
        {
            return true;
        }
        // jika indeks tengah pada kalimat lebih kecil dari huruf, maka akan menjalankan awal = tengah + 1
        else if (kalimat[tengah] < huruf)
        {
            awal = tengah + 1;
        }
        // jika indeks tengah pada kalimat tidak lebih kecil dari huruf, maka akan menjalankan akhir = tengah - 1
        else
        {
            akhir = tengah - 1;
        }
    }
    return false;
}

// melakukan pencarian dan penghitungan jumlah huruf vokal dan huruf konsonan
void search_vokalkonsonan()
{
    for (int i = 0; i < kalimat.length(); i++)
    {
        // pencarian dan penghitungan jumlah huruf vokal
        char huruf = tolower(kalimat[i]);
        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o')
        {
            vokal++;
        }
        // pencarian dan penghitungan jumlah huruf konsonan
        else if (huruf == 'b' || huruf == 'c' || huruf == 'd' || huruf == 'f' || huruf == 'g' || huruf == 'h' || huruf == 'j' || huruf == 'k' || huruf == 'l' || huruf == 'm' || huruf == 'n' || huruf == 'p' || huruf == 'q' || huruf == 'r' || huruf == 's' || huruf == 't' || huruf == 'v' || huruf == 'w' || huruf == 'x' || huruf == 'y' || huruf == 'z')
        {
            konsonan++;
        }
    }
}

// main program
int main()
{
    // mencetak header pada program
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "===== Program Mencari Sebuah Huruf pada Suatu Kalimat Menggunakan Binary Search =====" << endl;
    // user memasukkan kalimat tanpa menggunakan huruf kapital
    cout << "Masukkan kalimat (tanpa kapital): ";
    getline(cin, kalimat);

    // user memasukkan huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin Anda cari : ";
    cin >> huruf;

    // melakukan pencarian menggunakan binary search
    bool ketemu = binarysearch();
    // memanggil fungsi untuk melakukan pencarian dan penghitungan jumlah huruf vokal dan konsonan
    search_vokalkonsonan();

    // tampilkan data setelah dilakukan pencarian
    // menampilkan output jika huruf yang dicari ditemukan pada kalimat yang diinput
    if (ketemu)
    {
        cout << "Huruf '" << huruf << "' ditemukan dalam kalimat." << endl;
        cout << "Jumlah huruf vokal dalam kalimat: " << vokal << endl;
        cout << "Jumlah huruf konsonan dalam kalimat: " << konsonan << endl;
    }
    // menampilkan output jika huruf yang dicari tidak ditemukan pada kalimat yang diinput
    else
    {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
        cout << "Jumlah huruf vokal dalam kalimat: " << vokal << endl;
        cout << "Jumlah huruf konsonan dalam kalimat: " << konsonan << endl;
    }
    
    // mencetak footer pada program
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << endl;
    return 0;
}
```

#### Output:
![Modul 4  Unguided 1 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/f1058331-ab5c-4560-969f-aea9cf5fd6a8)

Kode tersebut digunakan untuk mencari sebuah huruf pada sebuah kalimat yang sudah diinput dengan menggunakan Binary Search. Program tersebut juga akan menampilkan jumlah huruf vokal dan konsonan pada kalimat yang diinputkan oleh user. Pencarian menggunakan binary search dilakukan dengan mencari dan mendeklarasikan indeks awal, tengah, dan akhir. Kemudian, data array dibagi menjadi 2 dengan indeks tengah sebagai **midlle** atau patokan untuk melakukan pengecekan data. Kodenya yaitu `tengah = (awal + akhir) / 2;`. Apabila data atau huruf yang dicari lebih kecil dari indeks tengah, maka pencarian akan dilakukan pada data sebelum nilai tengah dengan menjalankan kode `awal = tengah + 1;`. Apabila data atau huruf yang dicari lebih besar dari indeks tengah, maka pencarian akan dilakukan pada data setelah nilai tengah dengan menjalankan kode `akhir = tengah - 1;`.

- `string kalimat;` merupakan deklarasi untuk tipe data kalimat yaitu string. `int vokal = 0;` merupakan deklarasi untuk huruf vokal dimana inisialisasinya dimulai dari indeks ke 0. `int konsonan = 0;` merupakan deklarasi untuk huruf konsonan dimana inisialisasinya dimulai dari indeks ke -. `char huruf;` merupakan deklarasi untuk tipe data dari huruf yang dicari yaitu berupa char (karakter) dimana user hanya dapat menginputkan 1 jenis huruf.
- `void search_vokalkonsonan()` merupakan fungsi untuk melakukan pencarian dan penghitungan jumlah huruf vokal dan konsonan pada suatu kalimat. Karena dalam suatu kalimat yang diinputkan bisa jadi terdapat huruf kapital, maka `tolower` perlu digunakan untuk mengkonversi semua huruf menjadi huruf kecil (tanpa kapital) supaya dapat dideteksi oleh program. `if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o')` merupakan contoh manfaat dari penggunaan tolower karena huruf yang dapat dideteksi oleh program hanyalah huruf kecil.
- Apabila ditemukan huruf vokal pada kalimat yang diinputkan oleh user, maka program akan menjalankan if dimana terdapat `vokal++;`. Artinya, iterasi akan terus berjalan hingga huruf vokal dalam kalimat tersebut sudah ditemukan semua.
- Apabila ditemukan huruf konsonan pada kalimat yang diinputkan oleh user, maka program akan menjalankan else dimana terdapat `konsonan++;`. Artinya, iterasi akan terus berjalan hingga huruf konsonan dalam kalimat tersebut sudah ditemukan semua.

##### Penjelasan main program:
- `cout << "Masukkan kalimat (tanpa kapital): ";` dan `getline(cin, kalimat);` merupakan kode dimana user dapat memasukkan kalimat untuk dilakukan pencarian suatu huruf.
- `cout << "Masukkan huruf yang ingin Anda cari : ";` dan `cin >> huruf;` merupakan kode dimana user diminta untuk memasukkan suatu huruf yang ingin dicari.
- `bool ketemu = binarysearch();` akan membuat program melakukan pencarian huruf menggunakan binary search pada kalimat yang telah diinput.
- `search_vokalkonsonan();` akan membuat program melakukan pencarian dan penhitungan jumlah huruf vokal dan konsonan pada kalimat yang telah diinput.
- Apabila huruf yang dicari ditemukan pada kalimat, maka program akan menampilkan hasil menggunakan `cout << "Huruf '" << huruf << "' ditemukan dalam kalimat." << endl;` dan menghasilkan output **Huruf '...' ditemukan dalam kalimat.**. Program juga akan mencetak banyaknya huruf vokal dan huruf konsonan pada kalimat tersebut.
- Apabila huruf yang dicari tidak ditemukan pada kalimat, maka program akan menampilkan hasil menggunakan `out << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;` dan menghasilkan output **Huruf '...' tidak ditemukan dalam kalimat.**.. Program juga tetap akan mencetak banyaknya huruf vokal dan huruf konsonan pada kalimat tersebut.

Pertama-tama, user akan diminta untuk memasukkan kalimat dengan huruf kecil pada semua karakternya. Selanjutnya, user diminta untuk memasukkan huruf yang ingin dicari. Huruf yang dicari bebas sesuai keinginan user, boleh terdapat pada kalimat, boleh juga yang tidak ada pada kalimat. Selanjutnya, program akan menjalankan pencarian menggunakan binary search untuk memproses apakah huruf yang dicari oleh user ditemukan pada kalimat atau tidak. 

##### Penjelasan input oleh user:
- **Masukkan kalimat (tanpa kapital): arra is a cat miaw** artinya user memasukkan kalimat "arra is a cat miaw".
- **Masukkan huruf yang ingin Anda cari : a** artinya user ingin mencari huruf a pada kalimat tersebut.
- **Huruf 'a' ditemukan dalam kalimat.** artinya huruf 'a' ada pada kalimat "arra is a cat miaw".
- **Jumlah huruf vokal dalam kalimat: 7** artinya terdapat 7 huruf vokal pada kalimat tersebut yaitu a, a, i, a, a, i, a.
- **Jumlah huruf konsonan dalam kalimat: 7** artinya terdapat 7 huruf konsonan pada kalimat tersebut yaitu r, r, s, c, t, m, w.

#### Full code Screenshot:
![Modul 4  Unguided 1 Full SS (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/726e6ea3-a817-4aa0-b935-c0efc4bbfb2e)
![Modul 4  Unguided 1 Full SS (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/1c79d7b8-4bb1-4fdb-8377-4ffaba48fc01)
![Modul 4  Unguided 1 Full SS (3)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/a7d1ba4c-5e8a-4161-b6b8-75c01890000d)

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!
```C++
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
```

#### Output:
![Modul 4  Unguided 2 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/2c63a954-702d-4983-a8f2-871376b9f83f)

Kode tersebut digunakan untuk menghitung banyaknya huruf vocal dalam sebuah kalimat. Pertama-tama, user akan diminta untuk memasukkan kalimat bebas menggunakan huruf kapital maupun huruf kecil. `char huruf = tolower(kalimat[i]);` akan digunakan untuk mengkonversi seluruh huruf menjadi huruf kecil. Selanjutnya, program akan menjalankan pencarian menggunakan binary search untuk memproses jumlah huruf vokal pada kalimat tersebut.  

- `string kalimat;` merupakan deklarasi untuk tipe data kalimat yaitu string. `int vokal = 0;` merupakan deklarasi untuk huruf vokal dimana inisialisasinya dimulai dari indeks ke 0.
- `void search_vokal()` merupakan fungsi untuk melakukan pencarian huruf vokal pada suatu kalimat yang diinputkan oleh user.
- `if (huruf == 'a'|| huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o')` merupakan huruf vokal. Apabila ditemukan huruf-huruf tersebut dalam kalimat, maka program akan melakukan pencarian atau iterasi selanjutnya menggunakan `vokal++;` hingga semua huruf vokal pada kalimat tersebut ditemukan.
- `void print_array()` akan mencetak jumlah huruf vokal yang ditemukan pada kalimat.
- Apabila huruf vokal ditemukan pada kalimat tersebut atau `if (vokal > 0)`, maka program akan menjalankan `cout << "Jumlah huruf vokal = " << vokal;` dan menampilkan output **Jumlah huruf vokal = ...**.
- Apabila huruf vokal tidak ditemukan pada kalimat tersebut, maka program akan menjalankan `cout << "Huruf vokal tidak ditemukan pada kalimat tersebut.";` dan menampilkan output **Huruf vokal tidak ditemukan pada kalimat tersebut.**

##### Penjelasan main program:
- `cout << "Masukkan kata atau kalimat: ";` dan `getline(cin, kalimat);` akan meminta user untuk memasukkan kalimat yang ingin dilakukan pengecekan huruf vokalnya.
- `search_vokal();` akan memanggil fungsi untuk mencari dan menghitung jumlah huruf vokal pada kalimat yang telah diinput.
- `print_array();` akan memanggil fungsi untuk menampilkan hasil pencarian dan peghitungan huruf vokal pada kalimat yang telah diinput.

##### Penjelasan input oleh user:
- **Masukkan kata atau kalimat: Ini hari sabtu** artinya user memasukkan "Ini hari sabtu" sebagai kalimat yang akan dilakukan pengecekan huruf vokalnya.
- **Jumlah huruf vokal = 6** artinya terdapat 6 huruf vokal pada kalimat tersebut setelah dilakukan pencarian dan penghitungan oleh program. Huruf vokalnya yaitu i, i, a, i, a, u.

#### Full code Screenshot:
![Modul 4  Unguided 2 Full SS (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/bcd88b54-088c-4097-a38b-17cc08daf88b)
![Modul 4  Unguided 2 Full SS (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/20c1d71b-6a92-40d2-9730-f2370a40f35f)
![Modul 4  Unguided 2 Full SS (3)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/d6fa7db4-94b8-4b42-91bf-ce48e1bb96ea)

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
![Modul 4  Unguided 3 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/637724ac-d59f-4890-98f6-ab2332a27a5c)

Kode tersebut digunakan untuk ...

#### Full code Screenshot:
![Modul 4  Unguided 3 Full SS (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/dfc85afc-8241-49e8-aa6a-84220d09ef05)
![Modul 4  Unguided 3 Full SS (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/e2902ee4-1af2-467c-8e27-397a6f05ebaa)


## Kesimpulan


## Referensi
- [1] 
- [2] 
