# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Ardelia Rachma Laksita</p>

## Table of Contents
1. [Dasar Teori](#dasar-teori)
2. [Guided](#guided)
3. [Unguided](#unguided)
4. [Kesimpulan](#kesimpulan)
5. [Referensi](#referensi)

## Dasar Teori
Sorting merupakan proses pengurutan data yang sebelumnya disusun secara acak sehingga tersusun secara teratur menurut aturan tertentu[3]. Aturan atau kondisi yang menentukan pengurutan data tersebut ada 2 yaitu ascending (menaik) dan descending (menurun). Algoritma sorting berfungsi untuk mengurutkan data berdasarkan kondisi tertentu, misalnya dari abjad A sampai Z atau jumlah angka terbesar ke terkecil[3]. Hal ini dapat diterapkan untuk mengurutkan alfabet, mengurutkan karakter, mengurutkan angka dari terkecil ke terbesar atau dari terbesar ke terkecil, dan lain-lain. Kode yang digunakan pada proses sorting ascending dan descending berbeda. 

### Penerapan Algoritma Sorting :
1. **Selection Sort** merupakan teknik pengurutan elemen-elemen dengan cara mencari nilai tertinggi atau terendah pada array tersebut, kemudian ditempatkan sesuai posisinya. Selection sort akan membandingkan suatu array dengan array di sampingnya. Apabila diurutkan secara ascending, maka akan terjadi penukaran posisi jika elemen di sampingnya lebih kecil dibanding elemen sebelumnya. Apabila diurutkan secara descending, maka akan terjadi penukaran posisi jika elemen di sampingnya lebih besar dibanding elemen sebelumnya. Iterasi akan terus berlangsung hingga seluruh elemen diurutkan. 
2. **Insertion Sort** merupakan algoritma pengurutan sederhana yang mempunyai proses hampir sama seperti cara mengurutkan kartu remi[32]. Proses sorting algoritma ini yaitu dengan cara memecah elemen menjadi dua bagian yaitu diurutkan dan tidak diurutkan. Insertion Sort efisien untuk nilai data kecil[2]. Pada Insertion Sort, semua elemen akan terkena scan terlebih dahulu sehingga penukaran posisi dilakukan hanya jika terdapat suatu elemen yang posisinya tidak tepat. 
3. **Bubble Sort** merupakan salah satu algoritma pengurutan data dengan menerapkan konsep ascending atau descending secara sederhana[1]. Skema prosesnya dengan cara membandingkan elemen yang berdekatan, kemudian menukarnya apabila hasil urutannya tidak sesuai. Bubble sort merupakan gabungan dari selection sort dan insertion sort.

### Metode atau Teknik Sorting :
- **Ascending (menaik)** yaitu proses sorting atau pengurutan yang dilakukan mulai dari data yang terkecil menuju ke data yang terbesar.
- **Descending (menurun)** yaitu proses sorting atau pengurutan yang dilakukan mulai dari data yang terbesar menuju ke data yang terkecil.


## Guided 

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
#include <iostream>
using namespace std;

// fungsi untuk melakukan sorting menggunakan bubble sort secara ascending (menaik)
void bubble_sort(double arr[], int length) {
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++) {
            if (arr[i] > arr[i+1]) {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                not_sorted = true;
            } // end of if
        } // end of for loop
    } // end of while loop
} // end of bubble_sort

// mencetak dan menampilkan isi array
void print_array(double a[], int length) {

    for (int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {

    // menentukan panjang array (banyak data yang dimasukkan)
    int length = 5;
    // memasukkan bilangan sesuai panjang yang ditentukan
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};

    // menampilkan urutan bilangan sebelum diurutkan
    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    // memanggil fungsi untuk menjalankan bubble sort
    bubble_sort(a, length);

    // menampilkan urutan bilangan setelah diurutkan
    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
Kode di atas digunakan untuk mengurutkan bilangan secara ascending (dari terkecil ke terbesar) menggunakan algoritma bubble sort. Pertama-tama, buatlah fungsi menggunakan void untuk proses bubble sort secara ascending terlebih dahulu. Fungsi tersebut akan dipanggil pada _main program_. Pada program tersebut, j akan melakukan scan hingga bilangan terakhir dahulu, kemudian j baru akan melakukan _switch_ (tukar) bilangan apabila diperlukan. Jadi, j tidak harus hanya mengecek bilangan di sampingnya saja. `bool not_sorted = true;`, `int j=0;`, `double tmp;` merupakan deklarasi **j**, **tmp**, dan **not_sorted** dimana array belum diurutkan. 

- `not_sorted` digunakan untuk menentukan kapan proses iterasi berhenti.
- `arr[i] = arr[i+1]` merupakan perbandingan untuk menentukan apakah pertukaran posisi diperlukan atau tidak. Selain itu, kode tersebut juga akan melanjutkan iterasi dan proses sorting jika tidak ada pertukaran posisi lagi yang dilakukan.
- **While Loop** digunakan untuk melakukan iterasi selama proses sorting.
- **For Loop** digunakan untuk membandingkan antar elemen dan menukar posisi apabila diperlukan.
Selanjutnya, terdapat program untuk mencetak dan menampilkan isi array menggunakan fungsi void pada `void print_array(double a[], int length)`.

**Penjelasan main program :**
- `int length = 5;` merupakan deklarasi panjang array. 5 merupakan panjang array tersebut, artinya terdapat 5 bilangan pada array tersebut.
- `double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};` merupakan bilangan-bilangan dalam array tersebut.
- `cout << "Urutan bilangan sebelum sorting: " << endl;` dan `print_array(a, length);` digunakan untuk menampilkan urutan bilangan sebelum disorting (diurutkan) yaitu 22.1, 15.3, 8.2, 33.21, 99.99.
- `bubble_sort(a, length);` merupakan kode untuk memanggil fungsi untuk menjalankan proses sorting menggunakan algoritma bubble sort.
- `cout << "\nUrutan bilangan setelah sorting: " << endl;` dan `print_array(a, length);` digunakan untuk menampilkan urutan bilangan setelah disorting (diurutkan) secara ascending (dari terkecil ke terbesar) yaitu 8.2, 15.3, 22.1, 33.21, 99.99.
 
#### Output Guided 1:
![Modul 3  Guided 1 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/7689ac29-9156-4f33-98d6-05e68fe2420b)

### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

```C++
#include <iostream>
using namespace std;

// fungsi untuk melakukan sorting menggunakan insertion sort secara descending (menurun)
void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        } // end of while loop
    } // end of for loop
}

// mencetak dan menampilkan isi array
void print_array(char a[], int length) {
    
    for(int i=0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {

    // menentukan panjang array (banyak data yang dimasukkan)
    int length = 6;
    // memasukkan karakter sesuai panjang yang ditentukan
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    // menampilkan urutan karakter sebelum diurutkan
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    // memanggil fungsi untuk melakukan insertion sort
    insertion_sort(a, length);

    // menampilkan urutan karakter setelah diurutkan 
    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```
Kode tersebut digunakan untuk mengurutkan karakter secara descending (menurun, dari terbesar ke terkecil) menggunakan algoritma insertion sort. Pertama-tama, buatlah fungsi menggunakan void untuk proses bubble sort secara ascending terlebih dahulu. Fungsi tersebut akan dipanggil pada _main program_. Selanjutnya, buatlah kode untuk mencetak dan menampilkan isi array. Terakhir, buatlah main program untuk menjalankan proses sorting dan mencetak data yang belum diurutkan dan sudah diurutkan. 

- `arr[i] = arr[j-1]` merupakan perbandingan untuk menentukan apakah pertukaran posisi diperlukan atau tidak. Selain itu, kode tersebut juga akan melanjutkan iterasi dan proses sorting jika tidak ada pertukaran posisi lagi yang dilakukan.
- **While Loop** digunakan untuk melakukan iterasi selama proses sorting.
- **For Loop** digunakan untuk membandingkan antar elemen dan menukar posisi apabila diperlukan.
Selanjutnya, terdapat program untuk mencetak dan menampilkan isi array menggunakan fungsi void pada `void print_array(char a[], int length)`. Tipe datanya menggunakan `char` karena termasuk dalam tipe karakter.

**Penjelasan main program :**
- `int length = 6;` merupakan deklarasi panjang array. 6 merupakan panjang array tersebut, artinya terdapat 6 karakter pada array tersebut.
- `char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};` merupakan karakter-karakter dalam array tersebut.
- `cout << "Urutan karakter sebelum sorting: " << endl;` dan `print_array(a, length);` digunakan untuk menampilkan urutan karakter sebelum disorting yaitu c, f, a, z, d, p.
- `insertion_sort(a, length);` merupakan kode untuk memanggil fungsi untuk menjalankan proses sorting menggunakan algoritma insertion sort.
- `cout << "\nUrutan karakter setelah sorting: " << endl;` dan `print_array(a, length);` digunakan untuk menampilkan urutan karakter setelah disorting (diurutkan) secara descending (dari terbesar ke terkecil) yaitu z, p, f, d, c, a.

#### Output Guided 2:
![Modul 3  Guided 2 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/a9899ac1-ba81-41a3-9338-ffc0f0e78ac7)


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
![Modul 3  Unguided 1 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/84f140f5-e92d-4688-be3a-c91353bf0d04)

Kode tersebut digunakan untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil (descending) dengan menggunakan algoritma Selection Sort. Pertama-tama, buatlah fungsi menggunakan void untuk proses selection sort secara descending terlebih dahulu. Fungsi tersebut akan dipanggil pada _main program_. Selanjutnya, buatlah kode untuk mencetak dan menampilkan isi array. Terakhir, buatlah main program untuk menjalankan proses sorting dan mencetak data yang belum diurutkan dan sudah diurutkan. 

- `int posisiMaks;` dan `double temp;` digunakan untuk mendeklarasikan posisi maksimal suatu array dan temp.
- `if (array[j] > array[posisiMaks])` merupakan perbandingan untuk menentukan apakah pertukaran posisi diperlukan atau tidak. Selain itu, kode tersebut juga akan melanjutkan iterasi dan proses sorting jika tidak ada pertukaran posisi lagi yang dilakukan. **array[j] lebih besar daripada array[posisiMaks]** karena sorting dilakukan secara descending (menurun).
- **While Loop** digunakan untuk melakukan iterasi selama proses sorting.
- **For Loop** digunakan untuk membandingkan antar elemen dan menukar posisi apabila diperlukan.

Selanjutnya, terdapat program untuk mencetak dan menampilkan isi array menggunakan fungsi void pada `void print_array(double a[], int length)`. Pada selection sort, program akan membandingkan suatu array dengan array di sampingnya. Apabila diurutkan secara descending, maka akan terjadi penukaran posisi jika elemen di sampingnya lebih besar dibanding elemen sebelumnya. Iterasi akan terus berlangsung hingga seluruh elemen diurutkan.

**Proses Sorting :**
- 3.8, 2.9, 3.3, 4.0, 2.4
- 3.8, 3.3, 2.9, 4.0, 2.4
- 3.8, 3.3, 4.0, 2.9, 2.4
- 3.8, 4.0, 3.3, 2.9, 2.4
- 4.0, 3.8, 3.3, 2.9, 2.4

**Penjelasan main program :**
- `int length = 5;` merupakan deklarasi panjang array. 5 merupakan panjang array tersebut, artinya terdapat 5 nilai Indeks Prestasi Semester Mahasiswa pada array tersebut.
- `double a[length] = {3.8, 2.9, 3.3, 4.0, 2.4};` merupakan nilai-nilai Indeks Prestasi Semester Mahasiswa dalam array tersebut.
- `cout << "Indeks Prestasi Semester (IPS) Mahasiswa sebelum sorting: " << endl;` dan `print_array(a, length);` digunakan untuk menampilkan urutan IPS Mahasiswa sebelum diurutkan yaitu 3.8, 2.9, 3.3, 4.0, 2.4. 
- `selection_sort(a, length);` merupakan kode untuk memanggil fungsi untuk menjalankan proses sorting menggunakan algoritma selection sort yang telah dibuat programnya sebelumnya menggunakan void. 
- `cout << "\nIndeks Prestasi Semester (IPS) Mahasiswa setelah sorting dari terbesar ke terkecil: " << endl;` dan `print_array(a, length);` digunakan untuk menampilkan urutan karakter setelah disorting (diurutkan) secara descending (dari terbesar ke terkecil) yaitu 4.0, 3.8, 3.3, 2.9, 2.4.

### Analisis kompleksitas waktu dan ruang :
Pada program tersebut, selection sort memiliki perulangan for di dalam perulangan for sehingga terdapat 2 pengulangan yaitu `for (int i=0; i < n-1; i++)` dan `for (int j=i+1; j < n; j++)` di dalam perulangan for sebelumnya.
1. `for (int i=0; i < n-1; i++)` melakukan iterasi sebanyak `n-1` kali.
2. `for (int j=i+1; j < n; j++)` melakukan iterasi sebanyak `n-1` kali pada iterasi pertama, dan `n-2` pada iterasi kedua.

Jika hanya terdapat 1 perulangan, maka kompleksitas waktunya adalah **O(n)**. Namun, jika terdapat perulangan di dalam perulangan, maka kompleksitas waktunya adalah **O(n²)**. Operasi dasar pada algoritma tersebut dilakukan secara konstan sehingga kompleksitas waktu algoritma selection sort tersebut adalah `O(n²)`. Sedangkan kompleksitas ruangnya adalah `O(1)`. Kompleksitas waktunya bergantung secara kuadratik. Sedangkan kompleksitas ruangnya tidak bergantung pada ukuran array yang diurutkan. Total operasinya sebagai berikut.

`(n-1) + (n-2) + ... + n + 2 + 1`

Worse case dalam kompleksitas waktu algoritma tersebut terjadi ketika setiap elemen harus ditukar posisi secara berulang sehingga setiap elemen akan memerlukan iterasi penuh dari perulangan yang ada di dalam suatu perulangan. 

Jadi, algoritma selection sort memiliki kompleksitas waktu `O(n²)`dan kompleksitas ruang adalah `O(1)`.

#### Full code Screenshot:
![Modul 3  Unguided 1 Full SS (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/e9d6049a-1abd-4d6c-ac75-86c98b4d19ee)
![Modul 3  Unguided 1 Full SS (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/90c869ed-5552-4440-976a-ea251566d0ce)


### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan nama nama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort! (Score: 30)

#### Contoh Program :
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
![Modul 3  Unguided 2 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/7b214466-211c-48fb-93ae-b1c9ce6a244b)

Kode tersebut digunakan untuk mengurutkan nama-nama 10 warga sesuai dengan alfabet mulai A hingga Z dengan menggunakan algoritma Bubble Sort. Pertama-tama, buatlah fungsi menggunakan void untuk proses bubble sort secara ascending terlebih dahulu. Fungsi tersebut akan dipanggil pada _main program_. Selanjutnya, buatlah kode untuk mencetak dan menampilkan isi array. Terakhir, buatlah main program untuk menjalankan proses sorting dan mencetak data yang belum diurutkan dan sudah diurutkan. 

- `bool before_sorted = true;`, `int j=0;` dan `string tmp;` digunakan untuk mendeklarasikan array sebelum diurutkan, j, da tmp.
- `if (array[i] > array[i+1])` merupakan perbandingan untuk menentukan apakah pertukaran posisi diperlukan atau tidak. Selain itu, kode tersebut juga akan melanjutkan iterasi dan proses sorting jika tidak ada pertukaran posisi lagi yang dilakukan. **array[i] lebih kecil daripada array[i+1]** karena sorting dilakukan secara ascending (menaik).
- **While Loop** digunakan untuk melakukan iterasi selama proses sorting.
- **For Loop** digunakan untuk membandingkan antar elemen dan menukar posisi apabila diperlukan.
  
Selanjutnya, terdapat program untuk mencetak dan menampilkan isi array menggunakan fungsi void pada `void print_array(string nama_warga[], int length)`. `string` merupakan tipe data tersebut, sedangkan `nama_warga` merupakan nama variabel array.

**Penjelasan main program :**
- `int length = 10;` merupakan deklarasi panjang array. 10 merupakan panjang array tersebut, artinya terdapat 10 nama warga pada array tersebut.
- `string nama_warga[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};` merupakan isi dari array yaitu nama-nama warga yang akan diurutkan sesuai alfabet. 
- `ccout << "Urutan nama warga sebelum sorting: " << endl;` dan `print_array(nama_warga, length);` digunakan untuk menampilkan nama-nama warga sebelum sorting.  
- `bubble_sort(nama_warga, length);` merupakan kode untuk memanggil fungsi untuk menjalankan proses sorting menggunakan algoritma bubble sort yang telah dibuat programnya sebelumnya menggunakan void. 
- `cout << "\nUrutan nama warga sesuai alfabet (A-Z): " << endl;` dan `print_array(nama_warga, length);` digunakan untuk menampilkan urutan nama warga setela disorting secara ascending.

### Analisis kompleksitas waktu dan ruang :
Pada program tersebut, selection sort memiliki perulangan for di dalam perulangan while sehingga terdapat 2 pengulangan yaitu `while (before_sorted)` dan `for (int i = 0; i < length - j; i++)` di dalam perulangan sebelumnya.

Jika hanya terdapat 1 perulangan, maka kompleksitas waktunya adalah **O(n)**. Namun, jika terdapat perulangan di dalam perulangan, maka kompleksitas waktunya adalah **O(n²)**. Operasi dasar pada algoritma tersebut dilakukan secara konstan sehingga kompleksitas waktu algoritma selection sort tersebut adalah `O(n²)`. Sedangkan kompleksitas ruangnya adalah `O(1)`. Kompleksitas waktunya bergantung secara kuadratik. Sedangkan kompleksitas ruangnya tidak bergantung pada ukuran array yang diurutkan. Total operasinya sebagai berikut.

`(n-1) + (n-2) + ... + n + 2 + 1`

Worse case dalam kompleksitas waktu algoritma tersebut terjadi ketika setiap elemen harus ditukar posisi secara berulang sehingga setiap elemen akan memerlukan iterasi penuh dari perulangan yang ada di dalam suatu perulangan.  

Jadi, algoritma bubble sort memiliki kompleksitas waktu `O(n²)`dan kompleksitas ruang adalah `O(1)`.

#### Full code Screenshot:
![Modul 3  Unguided 2 Full SS (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/d77feaa4-7f88-4321-9ab3-6ae5b35b6603)
![Modul 3  Unguided 2 Full SS (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/d91d0a24-1c55-40ae-9e2d-080ac726889b)


### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)! (Score: 40)

![output program soal unguided 3 modul 3](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/c946c21c-896b-459d-bbaa-c793128a8739)

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

        while (j > 0 && arr[j - 1] < arr[j]) {
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

        while (j > 0 && arr[j - 1] > arr[j]) {
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
![Modul 3  Unguided 3 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/fb1f296c-f033-400e-b596-545d43c0cb57)

Kode tersebut digunakan untuk melakukan sorting secara menaik (ascending) dan menurun (descending) dengan bilangan dan karakter yang diinputkan oleh user. Algoritma sorting yang digunakan adalah insertion sort. Pertama-tama, buatlah fungsi menggunakan void untuk proses insertion sort secara ascending dan descending terlebih dahulu. Fungsi tersebut akan dipanggil pada _main program_. Selanjutnya, buatlah kode untuk mencetak dan menampilkan isi array. Terakhir, buatlah main program untuk menjalankan proses sorting dan mencetak data yang belum diurutkan dan sudah diurutkan. 

- `int i, j;` dan `char tmp;` digunakan untuk mendeklarasikan i, j, dan tmp. 
- `while (j > 0 && arr[j - 1] < arr[j])` dan `while (j > 0 && arr[j - 1] > arr[j])` merupakan perbandingan untuk menentukan apakah pertukaran posisi diperlukan atau tidak. Selain itu, kode tersebut juga akan melanjutkan iterasi dan proses sorting jika tidak ada pertukaran posisi lagi yang dilakukan.
1. `j > 0 && arr[j - 1] < arr[j]` untuk sorting yang dilakukan secara ascending (menaik).
2. `j > 0 && arr[j - 1] > arr[j]` untuk sorting yang dilakukan secara descending (menurun).
- **While Loop** digunakan untuk melakukan iterasi selama proses sorting.
- **For Loop** digunakan untuk membandingkan antar elemen dan menukar posisi apabila diperlukan.

Selanjutnya, terdapat program untuk mencetak dan menampilkan isi array menggunakan fungsi void pada `void print_array(char a[], int length)` dimana `char` merupakan tipe data yaitu karakter, sedangkan `a` sebagai nama variabel array tersebut.

**Penjelasan main program :**
- `int length;` merupakan deklarasi panjang array. Panjang array tidak langsung disebutkan (hanya dideklarasikan) karena nantinya akan diinput oleh user. 
- `cout << "input (n) = ";` dan `cin >> length;` akan meminta user untuk memasukkan (input) panjang array. 
- `char a[length];` merupakan deklarasi tipe data yang akan diinputkan oleh user sesuai dengan length (panjang) yang telah diinputkan sebelumnya. 
- `cout << "Masukkan " << length << " karakter: " << endl;` akan menampilkan jumlah karakter yang akan diinputkan oleh user. Selanjutnya, program akan meminta user untuk memasukkan karakter sesuai posisi array menggunakan perulangan for `for (int i = 0; i < length; i++)`, `cout << "Karakter ke-" << i + 1 << ": ";` dan `cin >> a[i];`.
- `cout << "Urutan karakter sebelum sorting: " << endl;` dan `print_array(a, length);` akan menampilkan urutan karakter sebelum diurutkan.
- `insertion_sort_ascending(a, length);` akan memanggil fungsi untuk melakukan proses insertion sort secara ascending.
- `cout << "Urutan karakter setelah ascending sort: " << endl;` dan `print_array(a, length);` akan menampilkan urutan karakter setelah diurutkan secara ascending (menaik).
- `insertion_sort_descending(a, length);` akan memanggil fungsi untuk melakukan proses insertion sort secara descending.
- `cout << "Urutan karakter setelah descending sort: " << endl;` dan `print_array(a, length);` akan menampilkan urutan karakter setelah diurutkan secara descending (menurun).

### Analisis kompleksitas waktu dan ruang :
Pada program tersebut, insertion sort memiliki perulangan while di dalam perulangan for sehingga terdapat 2 pengulangan pada masing-masing algoritma insertion sort ascending dan algoritma insertion sort descending. 

- **Insertion Sort Ascending** : setiap elemen array harus ditempatkan pada posisi dari terkecil ke terbesar (naik). Worse casenya adalah saat setiap elemen harus dipindahkan ke posisi awal sehingga setiap operasi dalam perulangan for akan memerlukan i operasi. Oleh karena itu, kompleksitas waktunya adalah `O(n²)`dan kompleksitas ruangnya adalah `O(1)`.
- **Insertion Sort Descending** : setiap elemen array harus ditempatkan pada posisi dari terbesar ke terkecil (turun). Worse casenya adalah saat setiap elemen harus dipindahkan ke posisi awal sehingga setiap operasi dalam perulangan for akan memerlukan i operasi. Oleh karena itu, kompleksitas waktunya adalah `O(n²)`dan kompleksitas ruangnya adalah `O(1)`. Ini serupa dengan konsep insertion sortascending.

Jika hanya terdapat 1 perulangan, maka kompleksitas waktunya adalah **O(n)**. Namun, jika terdapat perulangan di dalam perulangan, maka kompleksitas waktunya adalah **O(n²)**. Operasi dasar pada algoritma tersebut dilakukan secara konstan sehingga kompleksitas waktu algoritma insertion sort tersebut adalah `O(n²)`. Sedangkan kompleksitas ruangnya adalah `O(1)`. Kompleksitas waktunya bergantung secara kuadratik. Sedangkan kompleksitas ruangnya tidak bergantung pada ukuran array yang diurutkan. Total operasinya sebagai berikut.

`(n-1) + (n-2) + ... + n + 2 + 1`

Jadi, kedua algoritma insertion sort tersebut memiliki kompleksitas waktu `O(n²)`dan kompleksitas ruang adalah `O(1)`. 

Saat program dijalankan, maka user akan diminta untuk memasukkan panjang array. Selanjutnya, user akan diminta untuk memasukkan value array sesuai pada lokasinya masing-masing. User akan mengetahui lokasi value yang mereka inputkan terletak pada karakter ke berapa.

**Penjelasan Input dan Output sesuai data yang telah diinputkan oleh user :**
- `input (n) = 5` artinya user memasukkan 5 sebagai panjang array.
- `Masukkan 5 karakter` artinya user diminta memasukkan sebanyak 5 karakter sesuai panjang yang telah diinputkan sebelumnya.
- `Karakter ke-1: a' artinya a merupakan karakter pertama yang diinputkan oleh user.
- `Karakter ke-2: c' artinya c merupakan karakter kedua yang diinputkan oleh user.
- `Karakter ke-3: b' artinya b merupakan karakter ketiga yang diinputkan oleh user.
- `Karakter ke-4: e' artinya e merupakan karakter keempat yang diinputkan oleh user.
- `Karakter ke-5: d' artinya d merupakan karakter kelima yang diinputkan oleh user.

#### Full code Screenshot:
![Modul 3  Unguided 3 Full SS (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/a6f7f1f3-b0c5-4556-924b-4116ae431461)
![Modul 3  Unguided 3 Full SS (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/81715938-8326-4566-99c4-5c33e2e08750)
![Modul 3  Unguided 3 Full SS (3)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/d91fa308-8b4d-4384-a424-8018d803952c)
![Modul 3  Unguided 3 Full SS (4)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/9585a3e0-3389-4dd2-b3f1-c22653fe4d82)


## Kesimpulan
Sorting merupakan cara atau proses mengurutkan elemen-elemen baik itu dalam bentuk alfabet, karakter, maupun numerik sesuai dengan kondisi tertentu. Penerapan algoritma sorting ada 3 yaitu Selection Sort, Insertion Sort, dan Bubble Sort. Bubble Sort merupakan penggabungan antara algoritma Selection Sort dan Insertion Sort sehingga proses yang dijalankan lebih cepat. Kondisi yang menentukan pengurutan elemen-elemen ada dua yaitu secara ascending (menaik) dimana diurutkan dari terkecil ke terbesar, serta secara descending (menurun) dimana diurutkan dari terbesar ke terkecil.

## Referensi
- [1] Fakhruzzaman, M.N., et al., Buku Ajar Algoritma Pemrograman. Edisi Pertama. Surabaya : Airlangga University Press, 2023.
- [2] Nengsih, Y.G., et al., Konsep Algoritma dan Pemrograman : Mengenal Konsep Dasar dan Praktis dalam Bahasa Pascal dan C. Edisi
- [3] Pasaribu, S.A., Algoritma dan Pemrograman dalam Bahasa Pascal dan C++. Edisi Pertama. Yogyakarta : Deepublish, 2023.Pertama. Bandung : INDIE PRESS, 2022.
