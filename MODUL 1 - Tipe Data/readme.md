# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Ardelia Rachma Laksita</p>

## Dasar Teori

Tipe data merupakan klasifikasi jenis-jenis data yang berfungsi untuk menentukan data serta variabel yang dapat digunakan dalam suatu sistem dan operasi-operasi tertentu. Adanya klasifikasi data juga dapat membantu operasi komputer mengenali nilai data beserta instruksinya. Tipe data dibagi menjadi 3, antara lain :

1. Tipe Data Primitif
   Tipe data primitif merupakan tipe data yang dapat menyimpan satu nilai dan telah ditentukan oleh sistem. Tipedata primitif adalah tipe yang sederhana sehingga kesulitan menjangkau data kompleks yang tingkat kerumitannya tinggi. Beberapa macam tipe data primitif :
   a) Boolean (bool) : digunakan untuk menyimpan nilai logika dan hanya memiliki 2 nilai yaitu true dan false.
   b) Integer (int) : digunakan untuk angka tanpa pecahan baik positif maupun negatif. Contoh : 10,11,12.
   c) Float (float) : digunakan untuk angka pecahan. Contoh : 10.1, 11.5, 12.4.
   d) Character (char) : digunakan untuk satu karakter. Contoh : 'a','A'.
   e) String (string) : digunakan untuk menyimpan nilai lebih dari 1 karakter. Contoh : 'Apel', 'Strawberry'.
   
2. Tipe Data Abstrak

4. Tipe Data Koleksi

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

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

//Fungsi untuk mengecek apakah suatu bilangan adalah bilangan ganjil (odd number)
bool isOdd(int num) {
    return num % 2 != 0;
}

//Fungsi untuk mengecek apakah suatu bilangan adalah bilangan genap (even number)
bool isEven(int num){
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
![240302_00h00m06s_screenshot][(https://github.com/ardelialaksita/photo/blob/e4310b9e24bfbc039d23be0af0d5f3d47be707c0/%5BModul%201%5D%20Unguided%201%20Output.png)]

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/ardelialaksita/photo/blob/e4310b9e24bfbc039d23be0af0d5f3d47be707c0/%5BModul%201%5D%20Unguided%201%20Full%20SS.png)

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
//CONTOH PROGRAM STRUCT
#include <iostream>
#include <string>
using namespace std;

//Struct
struct Fruit {
    string name;
    string colour;
    string taste;
};

int main() 
{
    struct Fruit fruit1, fruit2;
    fruit1.name = "Durian";
    fruit1.colour = "Kuning";
    fruit1.taste = "Manis";
    fruit2.name = "Lemon";
    fruit2.colour = "Kuning";
    fruit2.taste = "Asam";

    cout << "===== BUAH 1 =====" << endl;
    cout << "Nama Buah : " << fruit1.name << endl;
    cout << "Warna Buah : " << fruit1.colour << endl;
    cout << "Rasa Buah: " << fruit1.taste << endl;
    cout << "===== BUAH 2 =====" << endl;
    cout << "Nama Buah : " << fruit2.name << endl;
    cout << "Warna Buah : " << fruit2.colour << endl;
    cout << "Rasa Buah: " << fruit2.taste << endl;
    return 0;
}
```

```C++
//CONTOH PROGRAM CLASS
#include <iostream>
#include <string>
using namespace std;

//Class
class FruitClass {
    private:
    string name;
    string colour;
    string taste;

    public:
    string getname() {return name};
    string getcolour() {return colour};
    string gettaste() {return taste};

};

int main() 
{
    class FruitClass fruit1, fruit2;
    fruit1.getname = "Durian";
    fruit1.getcolour = "Kuning";
    fruit1.gettaste = "Manis";
    fruit2.getname = "Lemon";
    fruit2.getcolour = "Kuning";
    fruit2.gettaste = "Asam";

    cout << "===== BUAH 1 =====" << endl;
    cout << "Nama Buah : " << fruit1.getname << endl;
    cout << "Warna Buah : " << fruit1.getcolour << endl;
    cout << "Rasa Buah: " << fruit1.gettaste << endl;
    cout << "===== BUAH 2 =====" << endl;
    cout << "Nama Buah : " << fruit2.getname << endl;
    cout << "Warna Buah : " << fruit2.getcolour << endl;
    cout << "Rasa Buah: " << fruit2.gettaste << endl;
    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot][(https://github.com/ardelialaksita/photo/blob/e4310b9e24bfbc039d23be0af0d5f3d47be707c0/%5BModul%201%5D%20Unguided%201%20Output.png)]

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/ardelialaksita/photo/blob/e4310b9e24bfbc039d23be0af0d5f3d47be707c0/%5BModul%201%5D%20Unguided%201%20Full%20SS.png)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
