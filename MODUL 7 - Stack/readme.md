# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Ardelia Rachma Laksita - 2311110051</p>

## Table of Contents
1. [Dasar Teori](#dasar-teori)
2. [Guided](#guided)
3. [Unguided](#unguided)
4. [Kesimpulan](#kesimpulan)
5. [Referensi](#referensi)

## Dasar Teori
Stack adalah struktur data yang mengoperasikan teknik berdasarkan LIFO (Last In First Out) []. 

### Operasi pada Stack :
- push : digunakan untuk menambahkan (push) suatu item ke dalam stack.
- pop : digunakan untuk menghapus (pops) suatu item dari dalam stack.
- peek : digunakan untuk mengembalikan _top item_ dari stack tanpa menghilangkannya.
- isFull : digunakan untuk mengecek apakah stack penuh atau tidak.
- isEmpty : digunakan untuk mengecek apakah stack kosong atau tidak. 

### Implementasi Stack :

Berikut merupakan implementasi pada stack.
![Cuplikan layar 2024-05-06 143446](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/08dd1e3c-4280-46b8-a0a0-6355fb2fb481)

## Guided 

### 1. Data Stack Buku

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty(){
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    }

    else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }

        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top; i > 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang 70 dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya Data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";
    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();
    return 0;
}

```
Kode di atas digunakan untuk menampilkan data stack buku dimana isinya terdapat deretan atau tumpukan judul buku, posisi buku, pengecekan apakah data kosong atau tidak, pengecekan apakah data penuh atau tidak, banyak data pada stack (tumpukan) tersebut, serta jumlah data pada stack (tumpukan) tersebut setelah dihapus.

`string arrayBuku[5];
int maksimal = 5, top = 0;`
Kode tersebut artinya panjang array bukunya adalah 5 yaitu terdapat 5 buku pada array tersebut. Karena int maksimal adalah 5, maka banyak bukunya boleh kurang dari 5, namun tidak boleh lebih dari 5. 

- Apabila stack (tumpukan) sudah penuh, maka kode `bool isFull()` akan membuat program menjalankan `return (top == maksimal);` karena telah mencapai jumlah maksimal buku yang bisa disimpan oleh array yaitu sebanyak 5. Tipe data yang digunakan adalah boolean.
- Apabila stack (tumpukan) masih kosong, maka kode `bool isEmpty()` akan membuat program menjalankan `return (top == 0);` karena jumlahnya masih 0. Tidak ada buku sama sekali yang disimpan oleh array tersebut. Tipe data yang digunakan adalah boolean.
- `void pushArrayBuku(string data)` merupakan fungsi void yang digunakan untuk menambahkan buku pada array. Program akan menampilkan "Data telah penuh" apabila data yang disimpan array sudah penuh. Apabila data masih belum penuh, maka program akan tetap menambahkan buku pada _top_ array menggunakan `arrayBuku[top] = data;` hingga `top++;`. Tipe datanya adalah string.
- `void popArrayBuku()` nerupakan fungsi void yang digunakan untuk menghapus data pada list atau array. Apabila tidak ada data pada array atau `if (isEmpty())`, maka program akan mencetak output "Tidak ada data yang dihapus menggunakan `cout << "Tidak ada data yang dihapus" << endl;`. Apabila terdapat data pada aray atau list tersebut, maka program akan menghapus salah satu datanya menggunakan `arrayBuku[top - 1] = "";` dan `top--;`. Array akan terus berkurang karena menggunakan indeks top--;
- `void peekArrayBuku(int posisi)` merupakan fungsi void yang digunakan untuk melihat isi array buku berdasarkan posisinya. Jika tidak ada data pada array atau `if (isEmpty())`, maka program akan menjalankan `cout << "Tidak ada data yang bisa dilihat" << endl;` dan mencetak output "Tidak ada data yang bisa dilihat". Jika terdapat data pada array tersebut, maka program akan menjalankan perulangan for yaitu `for (int i = 1; i <= posisi; i++)` dan `cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;` untuk mencetak **"Posisi ke (posisi buku) adalah (nama buku)"**.
- 


#### Output Guided 1:


## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++

```

#### Output:


Kode tersebut digunakan untuk 

#### Penjelasan main program:


#### Full code Screenshot:



### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat.

```C++

```
#### Output:


#### Full code Screenshot:



## Kesimpulan


## Referensi
- [1] Nordeen, A., C++ Learn in 24 Hours. Edisi Pertama. Delaware : Guru99, 2022.
- [1] 
