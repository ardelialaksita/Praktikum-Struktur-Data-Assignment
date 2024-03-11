# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Ardelia Rachma Laksita</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream> 
using namespace std;

int main() {
    char op;
    float num1, num2;
    
    cout << "Masukkan operator (+, -, *, /): ";
    cin >> op;
    
    cout << "Masukkan angka pertama: ";
    cin >> num1;
    cout << "Masukkan angka kedua: ";
    cin >> num2;

    switch (op) {
        case '+':
            cout << "Hasil Penjumlahan: " << num1 + num2;
            break;
        case '-':
            cout << "Hasil Pengurangan: " << num1 - num2;
            break;
        case '*':
            cout << "Hasil Perkalian: " << num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                cout << "Hasil Pembagian: " << num1 / num2;
            else
                cout << "Error! Nol tidak boleh sebagai pembagi.";
            break;
        default:
            cout << "Error! Operator is not correct";
    } 
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>

// Struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{

    // Menggunakan struct
    struct Mahasiswa mhs1, mhs2;

    // Mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // Mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);

    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    
    return 0;
    
}
```

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;
int main()
{
    // deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
    return 0;
}
```

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. 
Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

//Fungsi untuk mengecek apakah suatu bilangan adalah bilangan ganjil (odd number)
bool isOdd(int num) 
{
    return num % 2 != 0;
}

//Fungsi untuk mengecek apakah suatu bilangan adalah bilangan genap (even number)
bool isEven(int num)
{
    return num % 2 == 0;
}

int main() {
    int num;
    cout << "Masukkan bilangan: ";
    cin >> num;

    if (isOdd(num)) {
        cout << num << " adalah bilangan ganjil" << endl;
    }
    else if (isEven(num)) {
        cout << num << " adalah bilangan genap" << endl;
    }
    else {
        cout << num << " adalah bilangan 0 (bukan bilangan ganjil dan genap)" << endl;
    }
        
    return 0; 
        
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/ardelialaksita/photo/blob/dad89cdee3ea9748551fcbd669aea985674cd999/ss%20full%20screen%20no%201%20tugas%201.png)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
