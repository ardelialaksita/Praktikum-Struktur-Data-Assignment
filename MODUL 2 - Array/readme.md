# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Ardelia Rachma Laksita</p>

## Dasar Teori

## Guided 

### 1. Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
  // Deklarasi array
  int arr[2][3][3];
  // Input elemen
  for (int x = 0; x < 2; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 3; z++)
      {
        cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
        cin >> arr[x][y][z];
      }
    }
    cout << endl;
  }
  // Output Array
  for (int x = 0; x < 2; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 3; z++)
      {
        cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
      }
    }
  }
  cout << endl;
  // Tampilan array
  for (int x = 0; x < 2; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 3; z++)
      {
        cout << arr[x][y][z] << ends;
      }
      cout << endl;
    }
    cout << endl;
  }
}
```
Kode di atas digunakan untuk input dan cetak array tiga dimensi. Array 3 dimensi memiliki deklarasi `int arr[x][y][z];` yang artinya terdapat 2 kelompok array dengan masing-masing kelompok memiliki panjang dan lebar 3 x 3. Dimensi yang paling menjorok merupakan dimensi yang paling rendah sehingga tidak bisa melihat dimensi yang lebih tinggi
- Program pada **// Input elemen** digunakan untuk memasukkan nilai pada masing-masing indeks array.
- Program pada **// Output Array** digunakan untuk menampilkan data array yang telah diinputkan.
- Program pada **// Tampilan array** digunakan untuk menampilkan semua array yang telah diinput sebelumnya dalam bentuk seperti matriks. 
 
#### Output Guided 1:
![Modul 2  Guided 1 (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/0c1d5895-7356-41a1-be0d-51171c3dbfca)
![Modul 2  Guided 1 (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/8057f8c8-52ec-494e-9b2e-38b342486700)

### 2. Mencari Nilai Maksimal

```C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array : ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
Kode tersebut digunakan untuk mencari nilai maksimal pada array. Program harus memuat deklarasi, inisialisasi, dan mencetak suatu array. `int array[a];` merupakan deklarasi array. 
- `cout << "Masukkan panjang array : ";` dan `cin >> a;` digunakan untuk memasukkan panjang array. Contoh : User memasukkan 5 sebagai panjang array, maka array yang akan ditampilkan juga ada 5 mulai dari Array ke-0 hingga Array ke-4.
- `cout << "Masukkan " << a << " angka\n";` digunakan untuk input nilai array sesuai panjang array yang telah diinputkan sebelumnya. Selanjutnya, program akan menjalankan perulangan for untuk mencetak `"Array ke-"` sesuai panjang array.
- Perulangan for dan fungsi if digunakan untuk mencari nilai maksimum dan lokasi nilai maksimum pada array. Program akan terus melakukan iterasi hingga menemukan nilai dan lokasi nilai maksimum array. Kemudian, program akan mencetak `"Nilai maksimum adalah ... berada di Array ke ... "`.

#### Output Guided 2:
![Modul 2  Guided 2](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/b2cbaa3d-9e86-475f-8c97-800e5c97204b)


## Unguided 

### 1. Buatlah program untuk menampilkan output seperti berikut dengan data yang diinputkan oleh user!
![output soal unguided 1](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/06318e08-f1c9-411c-9d33-0c81dfcd7ae8)

```C++

```

#### Output:


#### Full code Screenshot:


### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

#### Contoh Program :
```C++

```

#### Output:


Kode di atas digunakan untuk  

#### Full code Screenshot:


### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum, dan Nilai rata-rata dari suatu array dengan input yang dimasukkan oleh user!

```C++
#include <iostream>
using namespace std;

int main()
{
    // deklarasi maksimum, minimum, rata-rata, total, dan lokasi
    int maks, min, total = 0, a, i = 0, lokasiMaks, lokasiMin;
    double mean;

    // user memasukkan panjang array
    cout << "Masukkan panjang array : ";
    cin >> a;

    // deklarasi array
    int arr[a];

    // user memasukkan value array dan menampilkan value tersebut berada pada array ke berapa
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> arr[i];

        // menambahkan elemen pada total
        total += arr[i];
    }

    // mencari nilai maksimum pada array
    maks = arr[0];
    lokasiMaks = 0;
    for (i = 0; i < a; i++)
    {
        if (arr[i] > maks)
        {
            maks = arr[i];
            lokasiMaks = i;
        }
    }

    // mencari nilai minimum pada array
    min = arr[0];
    lokasiMin = 0;
    for (i = 0; i < a; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            lokasiMin = i;
        }
    }

    // menghitung nilai rata-rata
    mean = static_cast<double>(total) / a;
    cout << endl;

    // program menu
    int pilihan;
    do
    {
        cout << "\n=========== Menu =============" << endl;
        cout << "1. Nilai maksimum pada array" << endl;
        cout << "2. Nilai minimum pada array" << endl;
        cout << "3. Nilai rata-rata pada array" << endl;
        cout << "4. Selesai." << endl;
        cout << "==============================" << endl;
        cout << "Apa yang ingin Anda cari? : ";
        cin >> pilihan;

        // switch statement begins
        switch (pilihan) {
            // if user enter 1, programs will run case 1
            case 1:
                cout << "Nilai maksimum adalah " << maks << " berada pada Array ke-" << lokasiMaks << endl;
                break;
            // if user enter 2, programs will run case 2
            case 2:
                cout << "Nilai minimum adalah " << min << " berada pada Array ke-" << lokasiMin << endl;
                break;
            // if user enter 3, programs will run case 3
            case 3:
                cout << "Nilai rata-rata adalah " << mean << endl;
                break;
            // if user enter 4, programs will run case 4
            case 4:
                cout << "Program pencarian selesai. Terima kasih!" << endl;
                break;
            // if user input the menu other than 1, 2, 3, 4
            // error message will display cause the menu isn't valid
            default:
                cout << "Error! Pilihan tidak valid. Silakan pilih menu lainnya." << endl;
                break;
            // switch statement ends
        }
    } while (pilihan != 4);

    cout << endl;
    cout << "Code by : Ardelia Rachma Laksita" << endl;
    
    return 0;
}
```
#### Output:


Kode di atas digunakan untuk mencari nilai maksimujm, nilai minimum, dan nilai rata-rata pada array menggunakan program menu. `maks` merupakan variabel dari nilai maksimum. `lokasiMaks` digunakan untuk mengetahui posisi nilai maksimum terdapat pada array ke berapa. `min` merupakan varibel dari nilai minimum. `lokasiMin` digunakan untuk mengetahui posisi nilai minimum terdapat pada array ke berapa. `mean` merupakan variabel dari nilai rata-rata. `total = 0` dan `static_cast<double>(total) / a` digunakan untuk mencari nilai rata-rata.

Saat program dijalankan, maka user akan diminta untuk memasukkan panjang array. 

**switch statement:**


#### Full code Screenshot:


## Kesimpulan
 

## Referensi
- [1] 
- [2]  
- [3] 
- [4] 
