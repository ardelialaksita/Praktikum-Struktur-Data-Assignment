
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
Kode di atas digunakan untuk menampilkan bilangan sebanyak n yang diisi dalam fungsi `countdown(n)`. Angka yang ditampilkan semakin lama semakin kecil karena countdown. Dapat dikatakan pula bahwa urutan angkanya secara menurun. n pada program tersebut ada 5 dimana akan dimulai dari 5 hingga 0 karena n == 0 pada `if (n == 0)`. `void countdown(int n)` merupakan fungsi yang akan dipanggil pada main program untuk menampilkan angka countdown.

#### Penjelasan Main Program:
`cout << "Rekursif langsung: ";` digunakan untuk menampilkan **'Rekursif langsung:'**. Kemudian, untuk menampilkan bilangan countdown yang diiterasikan dengan rekursif langsung yaitu dengan memanggil fungsi void countdown menggunakan kode `countdown(5);`. n-nya adalah 5. `cout << endl;` digunakan untuk mencetak baris baru.

#### Output Guided 1:
![output guided 1](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/acd6b576-dda4-4d08-8b57-31afac2e1191)

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
Kode di atas hampir sama seperti guided 1. Yang membedakan adalah pada guided 1 menggunakan rekursif langsung dimana rekursifnya langsung dipanggil dan cukup apabila hanya menggunakan 1 fungsi void. Sedangkan pada guided 2 memerlukan beberapa fungsi karena rekursifnya dilakukan dengan tidak langsung. 

`functionB` pada line awal sengaja dikosongkan karena akan dipanggil pada fungsi `functionA`. 

#### Penjelasan Main Program:

#### Output Guided 2:
![output guided 1](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/acd6b576-dda4-4d08-8b57-31afac2e1191)


## Unguided 

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!
**Kode Program**
```C++
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

```

Kode tersebut digunakan untuk mencari faktorial dari suatu bilangan bulat. Bilangan bulat yang dicari disimbolkan dengan n. `int faktorial(int n)` merupakan fungsi yang akan dipanggil untuk menjalankan proses faktorial. Apabila n > 1, maka program akan terus melakukan iterasi perkalian dari bilangan faktorial hingga mencapai n - 1 = 1. 

#### Penjelasan Main Program:


#### Output:
![output unguided 1](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/45f5f770-f386-42a2-a3a9-f38c3fb52a53)

**Penjelasan Output:**
Pada output tersebut, user memasukkan bilangan 5 untuk dicari faktorialnya. Kemudian, program menjalankan iterasi fungsi rekursif dengan cara n = 5 dikali dengan n-1 dikali dengan n-2 dikali dengan n - 3 dikali dengan n - 4 hingga 1. Karena n-4 = 1, maka iterasi dihentikan dan ditemukan faktorial dari 5 adalah 120. 

#### Full code Screenshot:
![full ss unguided 1](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/d3b4dc4e-fe71-45bb-9636-a53dee537026)

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!
**Kode Program**
```C++
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

```

Kode tersebut digunakan untuk 

#### Penjelasan Kode:
Berikut kode-kode dan fungsi yang terdapat pada program tersebut:


#### Penjelasan Main Program:


#### Output:
![output unguided 2](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/a717b8dd-437f-4a43-b33b-ba646dc06b37)

**Penjelasan Output:**
Sama seperti yang telah dijelaskan pada output unguided 1. Pada output tersebut, user memasukkan bilangan 5 untuk dicari faktorialnya. Kemudian, program menjalankan iterasi fungsi rekursif dengan cara n = 5 dikali dengan n-1 dikali dengan n-2 dikali dengan n - 3 dikali dengan n - 4 hingga 1. Karena n-4 = 1, maka iterasi dihentikan dan ditemukan faktorial dari 5 adalah 120. 


#### Full code Screenshot:
![full ss unguided 2](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/abc92386-93a1-42db-9bf3-7a436f84b822)


## Kesimpulan
Kesimpulan yang dapat diambil dari praktikum modul Rekursif adalah rekursif merupakan fungsi yang dapat memanggildirinya sendiri. Implementasinya dalam beberapa kasus juga sangat membantu efisiensi dan efektivitas waktu sehingga tidak memerlukan banyak memori. Hal tersebut menjadi kelebihan dari rekursif. Sedangkan kekurangan dari rekursif adalah memerlukan memori yang cukup banyak karena melakukan iterasi secara berulang hingga suatu fungsi tersebut terpenuhi. 

## Referensi
- [1]A. A. Youztima, “Fungsi Rekursif Dengan C++,” Medium, Jan. 02, 2023. Available: https://medium.com/@anggaalhusaini/fungsi-rekursif-dengan-c-433c9250c73d. [Accessed: May 25, 2024]
- [2]A. E. Putra et al., Dasar Pemrograman Logika Dengan C++, Pertama. SIEGA Publisher, 2024. Available: https://www.google.co.id/books/edition/Dasar_Pemrograman_Logika_Dengan_C++/SdsFEQAAQBAJ?hl=id&gbpv=0. [Accessed: May 27, 2024]
- [3]M. F. Rizky, “Programming: Mengapa Pendekatan Rekursif Penting,” Medium, Mar. 11, 2024. Available: https://medium.com/@fathurwithyou/programming-mengapa-pendekatan-rekursif-penting-f348649b1bd4. [Accessed: May 27, 2024]
- [4]W. Hartanto, “Implementasi Algoritma Rekursif dengan Bahasa Pemrograman Python,” BINUS UNIVERSITY BANDUNG - Kampus Teknologi Kreatif, Dec. 04, 2019. Available: https://binus.ac.id/bandung/2019/12/implementasi-algoritma-rekursif-dengan-bahasa-pemrograman-python/. [Accessed: May 26, 2024]
