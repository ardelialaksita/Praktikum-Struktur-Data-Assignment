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
Kode di atas digunakan untuk 
#### Contoh penggunaan program :
 
#### Output Guided 1:


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
    cout << "Masukkan " << a << "angka\n";
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
Kode tersebut digunakan untuk mencari nilai maksimal pada array. Program harus memuat deklarasi, inisialisasi, dan mencetak suatu array. 
#### Output Guided 2:



## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++

```

#### Output:


#### Full code Screenshot:


### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya.


#### Contoh Program :
```C++

```

#### Output:


Kode di atas digunakan untuk  

#### Full code Screenshot:


### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

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
