# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Ardelia Rachma Laksita</p>

## Table of Contents
1. [Dasar Teori](#dasar-teori)
2. [Guided](#guided)
3. [Unguided](#unguided)
4. [Kesimpulan](#kesimpulan)
5. [Referensi](#referensi)

## Dasar Teori
Array merupakan sekumpulan variabel yang menyimpan sekumpulan data dengan tipe sama. Data yang diinput memiliki alamat atau lokasi dan memori yang berbeda-beda. Hal ini disebut dengan elemen array. Array dapat digunakan untuk mengakses elemen secara individual melalui penomoran indeks [2]. Untuk mengakses elemen array dapat menggunakan indeks yang terdapat di dalamnya. Penulisan indeks array menggunakan [2]. Pada saat sebuah array dideklarasikan, kita dapat langsung melakukan inisialisasi nilai terhadap elemen-elemen array di dalamnya. Melalui deklarai array, program dapat mendeklarasikan banyak variabel sekaligus dan setip variabel dapat diakses menggunakan indeks [2]. Inisiasialisasi array hanya boleh dilakukan ketika mendefinisikan suatu array [1]. Untuk menampilkan nilai yang terdapat pada array dapat menggunakan perulangan. Array dari karakter disebut dengan string. 

### Karakteristik Array :
Berikut merupakan karakteristik array :
- Mempunyai batasan dari pemesanan alokasi memori (bersifat statis) [2].
- Mempunyai tipe data sama [2].
- Dapat diakses secara acak [2].

### Deklarasi Array :
Pendeklarasian array memuat hal-hal berikut.
- Tipe data array [2]
- Nama variable array [2].
- Subskrip atau indeks array [2].

### Penggunaan Array :
Berikut merupakan contoh-contoh penggunaan array.
- Untuk suatu database.
- Untuk suatu operasi matematika.
- Array digunakan dalam bentuk struktur data lain [2]. 

### Jenis-jenis Array
#### 1. Array Satu Dimensi
Array satu dimensi adalah array yang hanya terdiri atas n kolom atau satu subskrip array [1]. Setiap elemennya dapat diakss melalui indeks yang terdapat di dalamnya [1]. Indeks harus berupa integer atau ekspresi integer. Bentuk umum pendeklarasiannya yaitu `tipe_namaArray_array[ukuran];`.

#### 2. Array Dua Dimensi
Array dua dimensi adalah array yang terdiri atas m buah baris dan n buah kolom [1]. Array dua dimensi memiliki dua buah subskrip atau indeks yaitu baris dan kolom. Bentuk umum pendeklarasiannya yaitu `tipe_namaArray_array[jumlah_elemen-baris][jumlah_elemen_kolom];`

##### 3. Array Multidimensi 
Array multidimensi adalah array yang memiliki ukuran lebih dari dua dimensi [1]. Subskrip atau indeks yang dimiliki juga lebih dari 2. Bentuk umum pendeklarasiannya yaitu `tipe_namaArray_array[ukuran1][ukuran2]...[ukuranN];`

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

### 2. Mencari Nilai Maksimal Array

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
#include <iostream>
using namespace std;

int main ()
{
    // user memasukkan panjang array
    int a;
    cout << "Masukkan panjang array: ";
    cin >> a;

    // deklarasi array
    int array[a];

    // user memasukkan value array sesuai panjang array yang telah diinput sebelumnya
    cout << "Masukkan value array: " << endl;
    for (int i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }

    // menampilkan data array
    cout << "Data Array: ";
    for (int i = 0; i < a; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";

    // menampilkan nomor genap pada elemen array menggunakan modulo % 2 menghasilkan angka 0 (habis)
    cout << "Nomor Genap: ";*
    for (int i = 0; i < a; i++)
    {
        if (array[i] % 2 == 0)
        {
            cout << array[i] << " ";
        }
    }
    cout << "\n";

    // menampilkan nomor ganjil pada array menggunakan modulo % 2 menghasilkan angka bukan 0 (tidak habis)
    cout << "Nomor Ganjil: ";
    for (int i = 0; i < a; i++)
    {
        if (array[i] % 2 != 0)
        {
            cout << array[i] << " ";
        }
    }
    cout << "\n";

    return 0;
}
```

#### Output:
![Modul 2  Unguided 1 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/0783e4b6-264e-4358-bf51-094bcf4d1e50)
Kode tersebut digunakan untuk mengetahui value array yang termasuk dalam nomor ganjil dan nomor genap menggunakan data yang diinputkan oleh user. Pertama-tama, user akan diminta memasukkan panjang array. Selanjutnya, user akan diminta memasukkan value array sesuai panjang array. Saat memasukkan value array, `cout << "Array ke-" << (i) << ": ";` akan membuat program menampilkan lokasi array sehingga user mengetahui value yang dimasukkan akan terletak pada array ke berapa. Kemudian, `cout << "Data Array: ";` dan perulangan for akan membuat program menampilkan semua data array yang telah diinputkan oleh user. 
- **Program menampilkan nomor genap pada elemen :** Untuk menampilkan nomor genap pada elemen, maka menggunakan perulangan for dan fungsi if `array[i] % 2 == 0` yang artinya jika bilangan tersebut dibagi 2 dapat menghasilkan 0, maka bilangan tersebut termasuk nomor genap. Program akan melakukan iterasi hingga ke value array terakhir dan hingga semua bilangan genap ditemukan.
- **Program menampilkan nomor ganjil pada elemen :** Untuk menampilkan nomor ganjil pada elemen, maka menggunakan perulangan for dan fungsi if `array[i] % 2 != 0` yang artinya jika bilangan tersebut dibagi 2 menghasilkan angka tidak sama dengan 0, maka bilangan tersebut termasuk nomor ganji. Program akan melakukan iterasi hingga ke value array terakhir dan hingga semua bilangan ganjil ditemukan.

**Input Panjang Array dan Value Array oleh user :**
- Masukkan panjang array : 10
- Masukkan value array :
- Array ke-0: 1
- Array ke-1: 2
- Array ke-2: 3
- Array ke-3: 4
- Array ke-4: 5
- Array ke-5: 6
- Array ke-6: 7
- Array ke-7: 8
- Array ke-8: 9
- Array ke-9: 10

#### Full code Screenshot:
![Modul 2  Unguided 1 Full SS (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/4a17f608-b3a2-4a82-9c4b-43dd8972ae09)
![Modul 2  Unguided 1 Full SS (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/b0db847f-0870-4298-960c-46a74960ac5e)

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

#### Contoh Program :
```C++
#include <iostream>
using namespace std;

int main()
{
  int rows, columns, cubes;

  // input ukuran array 3 dimensi oleh user
  cout << "Masukkan dimensi pertama array: ";
  cin >> rows;
  cout << "Masukkan dimensi kedua array: ";
  cin >> columns;
  cout << "Masukkan dimensi ketiga array: ";
  cin >> cubes;

  // deklarasi array
  int arr[rows][columns][cubes];

  // inisialisasi dan input elemen array tiga dimensi
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      for (int z = 0; z < cubes; z++)
      {
        cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
        cin >> arr[x][y][z];
      }
    }
    cout << endl;
  }
  // output elemen array yang telah diinput
  cout << "\nArray elements: \n";
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      for (int z = 0; z < cubes; z++)
      {
        cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
      }
    }
  }
  cout << endl;

  // tampilan array
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      for (int z = 0; z < cubes; z++)
      {
        cout << arr[x][y][z] << ends;
      }
      cout << endl;
    }
    cout << endl;
  }
}
```

#### Output:
![Modul 2  Unguided 2 Output (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/b2402bae-c84b-4b65-9bf6-992fab9afc18)
![Modul 2  Unguided 2 Output (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/79ab1093-6fd7-4323-a4b4-2ec556042bc9)

Kode di atas digunakan untuk menampilkan array tiga dimensi menggunakan data yang telah diinputkan oleh user. Array tiga dimensi terdiri atas rows, columns, dan cubes. Pada program harus terdapat deklarasi dan inisialisasi array. `int arr[rows][columns][cubes];` merupakan deklarasi array. 
- **// input ukuran array 3 dimensi oleh user** digunakan untuk menginputkan ukuran array yaitu [x] untuk rows, [y] untuk columns, dan [z] untuk cubes. Pada `cout << "Masukkan dimensi pertama array: ";` dan `cin >> rows;`, user akan memasukkan dimensi pertama array yaitu banyak sekelompok array yang diinginkan. Pada `cout << "Masukkan dimensi kedua array: ";` dan `cin >> columns;`, user akan memasukkan dimensi kedua array yaitu panjang array yang diinginkan. Pada `cout << "Masukkan dimensi ketiga array: ";` dan `cin >> cubes;`, user akan memasukkan dimensi ketiga array yaitu lebar array yang diinginkan. 
- **// inisialisasi dan input elemen array tiga dimensi** digunakan untuk melakukan inisialisasi pada array. Program akan melakukan inisialisasi secara urut mulai dari dimensi pertaqma hingga ketiga yaitu [x][y][z] menggunakan perulangan for, `cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";` dan `cin >> arr[x][y][z];`. Pada bagian ini, user akan menginputkan value array sesuai dengan dimensi yang telah diinputkan sebelumnya.
- **// output elemen array yang telah diinput** digunakan untuk menampilkan semua array yang telah diinput menggunakan perulangan for dan `cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;`.
- Untuk menampilkan seluruh array dalam bentuk seperti matriks, program akan kembali menjalankan perulangan for dan mencetak tampilan array menggunakan `cout << arr[x][y][z] << ends;`.

**Penjelasan Input dan Output sesuai data yang telah diinputkan oleh user :**
Array 3 dimensi memiliki deklarasi `int arr[x][y][z];`. Pada output di atas, user menginputkan [2][3][3] yang artinya terdapat 2 kelompok array dengan masing-masing kelompok memiliki panjang dan lebar 3 x 3. Angka yang dimasukkan pada masing-masing dimensi yaitu sebanyak 9 angka. Pada dimensi pertama, user memasukkan angka 1,2,3,4,5,6,7,8,9 secara berurutan dari terkecil ke terbesar. Pada dimensi kedua, user memasukkan angka 9,8,7,6,5,4,3,2,1 secara berurutan dari terbesar ke terkecil. Selanjutnyam program akan menampilkan data array yang telah diinputkan sebelumnya. Kemudian, program akan menampilkan array dalam bentuk seperti matriks.

#### Full code Screenshot:
![Modul 2  Unguided 2 Full SS (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/104848ee-f6a2-435c-8438-93a484de62ea)
![Modul 2  Unguided 2 Full SS (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/b30976de-d9c5-4bd8-a96b-81594dccdd9d)
![Modul 2  Unguided 2 Full SS (3)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/cac33dd2-59d3-419d-a8b2-eafc38e87af1)

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
![Modul 2  Unguided 3 Output (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/759457ae-7d71-41c9-b17b-dd8e7d5f5343)
![Modul 2  Unguided 3 Output (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/a8d35a95-01ae-47a1-803e-97dca8da84ae)

Kode di atas digunakan untuk mencari nilai maksimum, nilai minimum, dan nilai rata-rata pada array menggunakan program menu. `maks` merupakan variabel dari nilai maksimum. `lokasiMaks` digunakan untuk mengetahui posisi nilai maksimum terdapat pada array ke berapa. `min` merupakan varibel dari nilai minimum. `lokasiMin` digunakan untuk mengetahui posisi nilai minimum terdapat pada array ke berapa. `mean` merupakan variabel dari nilai rata-rata. `total = 0` dan `static_cast<double>(total) / a` digunakan untuk mencari nilai rata-rata.

Saat program dijalankan, maka user akan diminta untuk memasukkan panjang array. Selanjutnya, user akan diminta untuk memasukkan value array sesuai pada lokasinya masing-masing. User akan mengetahui lokasi value yang mereka inputkan terletak pada Array ke berapa. Setelah itu, program akan mencetak program menu dan menjalankan switch statement sesuai case. User memilih apakah mereka akan mencari nilai maksimum dengan menginputkan angka 1, milai minimum dengan menginputkan angka 2, nilai rata-rata dengan menginputkan angka 3, dan keluar dari program menu dengan menginputkan angka 4. 

**switch statement:**
- `case 1` : jika user memasukkan angka 1, maka program akan menjalankan case 1 yaitu pencarian nilai maksimum pada `maks` dan lokasi nilai tersebut pada `lokasiMaks`. Kemudian, program akan mencetak **"Nilai maksimum adalah ... berada pada Array ke ..."**
- `case 2` : jika user memasukkan angka 2, maka program akan menjalankan case 2 yaitu pencarian nilai minimum pada `min` dan lokasi nilai tersebut pada `lokasiMin`. Kemudian, program akan mencetak **"Nilai minimum adalah ... berada pada Array ke ..."**
- `case 3` : jika user memasukkan angka 3, maka program akan menjalankan case 3 yaitu pencarian nilai maksimum pada `mean`. Kemudian, program akan mencetak **"Nilai rata-rata adalah adalah ... "**. Pada pencarian nilai rata-rata, program tidak akan menampilkan lokasinya terletak pada Array ke berapa karena terdapat formula sendiri untuk mencari nilai rata-rata dimana tidak ada korelasinya dengan lokasi array. 
- `case 4` : jika user memasukkan angka 4, maka program akan menjalankan case 4 yaitu keluar dari program menu dan mencetak **"Program pencarian selesai. Terima kasih!"**.
- Apabila user menginputkan angka selain 1, 2, 3, dan 4, maka program akan error dan mencetak **"Error! Pilihan tidak valid. Silakan pilih menu lainnya."** karena pilihannya hanya sampai 4. 

#### Full code Screenshot:
![Modul 2  Unguided 3 Full SS (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/41c04754-b271-4fdf-b7d8-c1ddc65d6916)
![Modul 2  Unguided 3 Full SS (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/056d37a6-2429-4165-a6c5-017bb80749bb)
![Modul 2  Unguided 3 Full SS (3)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/189eb1e6-5d44-469a-812b-c2f6e90789bd)
![Modul 2  Unguided 3 Full SS (4)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/88f26838-dc87-422d-903d-773d03232172)

## Kesimpulan
 

## Referensi
- [1] Siahaan, V. dan Sianipar, R.H., Buku Pintar Pemrograman C++. Sumatera Utara : Balige Publishing, 2020.
