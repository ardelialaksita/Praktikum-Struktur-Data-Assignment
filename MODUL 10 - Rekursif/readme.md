
# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Dasar Teori](#dasar-teori)
2. [Guided](#guided)
3. [Unguided](#unguided)
4. [Kesimpulan](#kesimpulan)
5. [Referensi](#referensi)

## Dasar Teori
Rekursif adalah suatu proses dari sebuah fungsi yang dapat memanggil dirinya sendiri secara berulang-ulang [1]. Beberapa kasus yang menggunakan fungsi rekursif akan jauh lebih mudah, cepat, dan efisien. Hanya membutuhkan _space_ memori yang cukup banyak karena iterasinya yang harus dipanggil secara terus menerus. Fungsi rekursif akan terus menjalankan iterasi hingga suatu kondisi yang ditetapkan pada fungsi tersebut terpenuhi. 

### Tujuan Rekursif:
Tujuan rekursif adalah untuk melakukan pengulangan, atau looping seperti for dan while, namun dengan cara yang berbeda [4].

### Kelebihan dan Kekurangan Rekursif:
**Kelebihan:** Mempermudah penyelesaian suatu kasus sehingga menjadi lebih cepat, efektif, dan efisien.
**Kekurangan:** Membutuhkan _space_ memori yang cukup banyak karena melakukan iterasi secara berulang-ulang hingga suatu kondisi pada fungsi tersebut terpenuhi.

### Implementasi Rekursif:
**Faktorial** 

Yaitu digunakan untuk mencari bilangan faktorial dari suatu bilangan bulat positif. Bilangan faktorial dilakukan dengan cara mengalikan n bilangan dengan (n-1) hingga n-1 = 1. 0 tidak ikut dikalikan dengan bilangan yang dicari faktorialnya (n).

**Luas Lingkaran**

Yaitu digunakan untuk menghtiung luas lingkaran dengan r sebagai jari-jarinya.

**Menghitung bintang pada suatu input** 

Yaitu digunakan untuk menghitung bintang beserta langkah-langkahnya pada suatu input. Berikut contoh penerapannya:

![implementasi bintang](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/a9d1b068-0d6d-4e11-b737-671311f03f13)

**_Source : Sitasi 3_**

**Permutasi String** 

Yaitu digunakan untuk membantuk mempersingkat waktu pencarian permutasi. Permutasi yang tidak dilakukan dengan fungsi rekursi akan membutuhkan waktu yang banyak dan cukup melelahkan. Berikut pohon rekursi permutasi string [3].

![implementasi permutasi](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/6448162c-7d04-4e74-bc26-718e199c1368)

**_Source : Sitasi 3_**


## Guided 

### 1. Program Rekursif Langsung
**Kode Program**
```C++
#include <iostream>

using namespace std;

// PROGRAM REKURSIF LANGSUNG

// fungsi countdown
void countdown(int n) {
    if (n == 0) {
        return;
    }

    // tampilkan bilangan countdown
    cout << n << " ";
    countdown(n -1);
}

// main program
int main() {
    // tampilkan rekursif langsung
    cout << "Rekursif langsung: ";
    // panggil fungsi countdown
    countdown(5);
    cout << endl;
    return 0;
}
```
Kode di atas digunakan 


#### Penjelasan Main Program:


#### Output Guided 1:


### 2. Program Rekursif Tidak Langsung
**Kode Program**
```C++
#include <iostream>

using namespace std;

// PROGRAM REKURSIF TIDAK LANGSUNG

// fungsi B
void functionB(int n);

// fungsi A hyang akan memanggil fungsi B
void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

// fungsi B yang akan memanggil fungsi A
void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

// main program
int main() {
    // deklarasi bilangan num 
    int num = 3;
    // tampilkan rekursi tidak langsung
    cout << "Rekursif tidak langsung: ";
    // panggil fungsi A
    functionA(num);
    return 0;
}

```
Kode di atas digunakan untuk 

#### Penjelasan Main Program:

#### Output Guided 2:



## Unguided 

### 1. Modifikasi guided di atas yang mana heap dikonstruksi secara manual berdasarkan user.
**Kode Program**
```C++

```

Kode tersebut digunakan untuk 

#### Penjelasan Kode:
Berikut kode-kode dan fungsi yang terdapat pada program tersebut:


#### Penjelasan Main Program:


#### Output:


**Penjelasan Output :**


#### Full code Screenshot:



## Kesimpulan
Kesimpulan yang dapat diambil dari praktikum modul Rekursif adalah rekursif merupakan fungsi yang dapat memanggildirinya sendiri. Implementasinya dalam beberapa kasus juga sangat membantu efisiensi dan efektivitas waktu sehingga tidak memerlukan banyak memori. Hal tersebut menjadi kelebihan dari rekursif. Sedangkan kekurangan dari rekursif adalah memerlukan memori yang cukup banyak karena melakukan iterasi secara berulang hingga suatu fungsi tersebut terpenuhi. 

## Referensi
- [1]A. A. Youztima, “Fungsi Rekursif Dengan C++,” Medium, Jan. 02, 2023. Available: https://medium.com/@anggaalhusaini/fungsi-rekursif-dengan-c-433c9250c73d. [Accessed: May 25, 2024]
- [2]A. E. Putra et al., Dasar Pemrograman Logika Dengan C++, Pertama. SIEGA Publisher, 2024. Available: https://www.google.co.id/books/edition/Dasar_Pemrograman_Logika_Dengan_C++/SdsFEQAAQBAJ?hl=id&gbpv=0. [Accessed: May 27, 2024]
- [3]M. F. Rizky, “Programming: Mengapa Pendekatan Rekursif Penting,” Medium, Mar. 11, 2024. Available: https://medium.com/@fathurwithyou/programming-mengapa-pendekatan-rekursif-penting-f348649b1bd4. [Accessed: May 27, 2024]
- [4]W. Hartanto, “Implementasi Algoritma Rekursif dengan Bahasa Pemrograman Python,” BINUS UNIVERSITY BANDUNG - Kampus Teknologi Kreatif, Dec. 04, 2019. Available: https://binus.ac.id/bandung/2019/12/implementasi-algoritma-rekursif-dengan-bahasa-pemrograman-python/. [Accessed: May 26, 2024]
