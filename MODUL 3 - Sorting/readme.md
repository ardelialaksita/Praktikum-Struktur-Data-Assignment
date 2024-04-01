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

#### Penerapan Algoritma Sorting :
1. **Selection Sort** merupakan teknik pengurutan elemen-elemen dengan cara mencari nilai tertinggi atau terendah pada array tersebut, kemudian ditempatkan sesuai posisinya. Selection sort akan membandingkan suatu array dengan array di sampingnya. Apabila diurutkan secara ascending, maka akan terjadi penukaran posisi jika elemen di sampingnya lebih kecil dibanding elemen sebelumnya. Apabila diurutkan secara descending, maka akan terjadi penukaran posisi jika elemen di sampingnya lebih besar dibanding elemen sebelumnya. Iterasi akan terus berlangsung hingga seluruh elemen diurutkan. 
2. **Insertion Sort** merupakan algoritma pengurutan sederhana yang mempunyai proses hampir sama seperti cara mengurutkan kartu remi[32]. Proses sorting algoritma ini yaitu dengan cara memecah elemen menjadi dua bagian yaitu diurutkan dan tidak diurutkan. Insertion Sort efisien untuk nilai data kecil[2]. Pada Insertion Sort, semua elemen akan terkena scan terlebih dahulu sehingga penukaran posisi dilakukan hanya jika terdapat suatu elemen yang posisinya tidak tepat. 
3. **Bubble Sort** merupakan salah satu algoritma pengurutan data dengan menerapkan konsep ascending atau descending secara sederhana[1]. Skema prosesnya dengan cara membandingkan elemen yang berdekatan, kemudian menukarnya apabila hasil urutannya tidak sesuai. Bubble sort merupakan gabungan dari selection sort dan insertion sort.

#### Metode atau Teknik Sorting :
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
- `bubble_sort(a, length);` merupakan kode untuk memanggil fungsi u.ntuk menjalankan proses sorting menggunakan algoritma bubble sort.
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
Kode tersebut digunakan untuk mengurutkan karakter secara descending (menurun, dari terbesar ke terkecil) menggunakan algoritma insertion sort. 

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
            // array[j] lebih besar daripada array[post_maks] karena sorting dilakukan secara descending (menurun)
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

Kode tersebut digunakan untuk 

#### Full code Screenshot:


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


Kode di atas digunakan untuk 


#### Full code Screenshot:


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


Kode di atas digunakan untuk 

Saat program dijalankan, maka user akan diminta untuk memasukkan panjang array. Selanjutnya, user akan diminta untuk memasukkan value array sesuai pada lokasinya masing-masing. User akan mengetahui lokasi value yang mereka inputkan terletak pada Array ke berapa.

**Penjelasan Input dan Output sesuai data yang telah diinputkan oleh user :**


#### Full code Screenshot:


## Kesimpulan
Sorting merupakan cara atau proses mengurutkan elemen-elemen baik itu dalam bentuk alfabet, karakter, maupun numerik sesuai dengan kondisi tertentu. Penerapan algoritma sorting ada 3 yaitu Selection Sort, Insertion Sort, dan Bubble Sort. Bubble Sort merupakan penggabungan antara algoritma Selection Sort dan Insertion Sort sehingga proses yang dijalankan lebih cepat. Kondisi yang menentukan pengurutan elemen-elemen ada dua yaitu secara ascending (menaik) dimana diurutkan dari terkecil ke terbesar, serta secara descending (menurun) dimana diurutkan dari terbesar ke terkecil.

## Referensi
- [1] Fakhruzzaman, M.N., et al., Buku Ajar Algoritma Pemrograman. Edisi Pertama. Surabaya : Airlangga University Press, 2023.
- [2] Nengsih, Y.G., et al., Konsep Algoritma dan Pemrograman : Mengenal Konsep Dasar dan Praktis dalam Bahasa Pascal dan C. Edisi
- [3] Pasaribu, S.A., Algoritma dan Pemrograman dalam Bahasa Pascal dan C++. Edisi Pertama. Yogyakarta : Deepublish, 2023.Pertama. Bandung : INDIE PRESS, 2022.
