# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Dasar Teori](#dasar-teori)
2. [Guided](#guided)
3. [Unguided](#unguided)
4. [Kesimpulan](#kesimpulan)
5. [Referensi](#referensi)

## Dasar Teori
Queue adalah salah satu struktur data yang menerapkan prinsip FIFO (First In First Out) dimana elemen yang pertama masuk ke antrian akan menjadi elemen pertama yang keluar antrian. Dalam prinsip FIFO, Queue dapat membantu mengatur urutan data dan mempertahankan prioritas saat memproses elemen-elemen di dalamnya [5].

### Fungsi atau Kegunaan Queue:
- Simulasi antrian : yaitu untuk membuat model antrian dari kegiatan sehari-hari, misalnya antrian pelanggan di kasir supermarket.
- Buffering : yaitu untuk menyangga data sementara, misalnya untuk menampung data yang dikirimkan ke jaringan secara bertahap.
- BFS (Breadth-First Search) : yaitu untuk pencarian BFS pada algoritma struktur data, misalnya pada graph dan tree.

### Karakteristik Queue:
Karakteristik FIFO (First In First Out) yaitu menerapkan algoritma berikut.
- Elemen ditambahkan pada ujung belakang (back / rear) antrian. 
- Elemen dihapus dari ujung depan (front) antrian.

### Jenis-jenis Queue:
- **Queue Linear** : implementasi queue yang menggunakan struktur data linear, seperti array atau linked list [5]. Ketika queue penuh, maka tidak bisa menampung elemen baru meskipun masih ada ruang kosong. Ini karena queue linear memiliki batasan ukuran tetap.
- **Queue Circular** : implementasi queue yang menggunakan struktur data linear dengan pemanfaatan siklus [5]. Ketika queue penuh, maka elemen-elemen baru masih dapat ditambahkan ke front.
- **Priority Queue** : implementasi queue dimana setiap elemen memiliki prioritas tertentu [5]. Implementasinya menggunakan struktur data seperti head untuk memastikan elemen-elemen terurut secara tetap [5].

### Operasi pada Queue:
- **Enqueue (menambahkan elemen ke dalam queue)** : elemen baru ditambahkan di posisi belakang queue (rear). Penunjuk rear maju ke posisi berikutnya untuk menunjuk elemen baru.
- **Dequeue (menghapus elemen dari queue)** : elemen yang dihapus berada di posisi depan queue (front). Penunjuk front maju ke posisi berikutnya untuk menunjuk elemen selanjutnya. Elemen yang dihapus tidak masuk lagi dalam queue.
- **Front (mendapatkan elemen pertama dalam queue)** : operasi ini akan membantu kita melihat elemen pertama (yang akan dikeluarkan) dari queue tanpa mengubah dan menghapus struktur queue.
- **Rear (mendapatkan elemen terakhir dalam queue)** : operasi ini akan membantu kita melihat elemen terakhir (yang telah ditambahkan) pada queue tanpa mengubah dan menghapus struktur queue. 
- **Size (mendapatkan jumlah atau ukuran elemen dalam queue)** : digunakan untuk mengetahui berapa banyak elemen yang saat ini berada di dalam queue tanpa mengubah struktur atau menghapus elemen dari queue itu sendiri.
- **IsFull (mengecek apakah queue penuh)** : apabila queue mencapai batas elemen maksimal, maka IsFull akan mengembalikan nilai true yang artinya queue dalam keadaan penuh. Begitu pun sebaliknya, apabila queue belum mencapai batas maksimal, maka IsFull akan mengambalikan nilai false yang artinya queue belum penuh dan user masih bisa menambahkan data lagi ke dalam queue tersebut.
- **IsEmpty (mengecek apakah queue kosong)** : apabila queue memiliki elemen di dalamnya, maka IsEmpty akan mengembalikan nilai false yang artinya queue tidak kosong. Begitu pun sebaliknya, apabila queue tidak memiliki elemen sama sekali, maka IsEmpty akan mengembalikan nilai True yang artinya queue kosong.
- **Peek (mengambil data dari queue)** : digunakan untuk mengambil data dari queue tanpa mengubah atau menghapus struktur dari queue.

### Implementasi Queue :

Berikut merupakan implementasi pada queue.



(penjelasan)

## Guided 

### 1. Program Antrian

```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull() {
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian (string data) {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i+1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() {
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i+1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}

```
Kode di atas digunakan untuk 

`string arrayBuku[5];
int maksimal = 5, top = 0;`
Kode tersebut artinya panjang array bukunya adalah 5 yaitu terdapat 5 buku pada array tersebut. Karena int maksimal adalah 5, maka banyak bukunya boleh kurang dari 5, namun tidak boleh lebih dari 5. 

- Apabila stack (tumpukan) sudah penuh, maka kode `bool isFull()` akan membuat program menjalankan `return (top == maksimal);` karena telah mencapai jumlah maksimal buku yang bisa disimpan oleh array yaitu sebanyak 5. Tipe data yang digunakan adalah boolean.
- Apabila stack (tumpukan) masih kosong, maka kode `bool isEmpty()` akan membuat program menjalankan `return (top == 0);` karena jumlahnya masih 0. Tidak ada buku sama sekali yang disimpan oleh array tersebut. Tipe data yang digunakan adalah boolean.
- `void pushArrayBuku(string data)` merupakan fungsi void yang digunakan untuk menambahkan buku pada array. Program akan menampilkan "Data telah penuh" apabila data yang disimpan array sudah penuh. Apabila data masih belum penuh, maka program akan tetap menambahkan buku pada _top_ array menggunakan `arrayBuku[top] = data;` hingga `top++;`. Tipe datanya adalah string.
- `void popArrayBuku()` nerupakan fungsi void yang digunakan untuk menghapus data pada list atau array. Apabila tidak ada data pada array atau `if (isEmpty())`, maka program akan mencetak output "Tidak ada data yang dihapus menggunakan `cout << "Tidak ada data yang dihapus" << endl;`. Apabila terdapat data pada aray atau list tersebut, maka program akan menghapus salah satu datanya menggunakan `arrayBuku[top - 1] = "";` dan `top--;`. Array akan terus berkurang karena menggunakan indeks top--;
- `void peekArrayBuku(int posisi)` merupakan fungsi void yang digunakan untuk melihat isi array buku berdasarkan posisinya. Jika tidak ada data pada array atau `if (isEmpty())`, maka program akan menjalankan `cout << "Tidak ada data yang bisa dilihat" << endl;` dan mencetak output "Tidak ada data yang bisa dilihat". Jika terdapat data pada array tersebut, maka program akan menjalankan perulangan for yaitu `for (int i = 1; i <= posisi; i++)` dan `cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;` untuk mencetak **"Posisi ke (posisi buku) adalah (nama buku)"**.
- `int countStack()` digunakan untuk menghitung banyaknya data pada stack.
- `void changeArrayBuku(int posisi, string data)` digunakan untuk mengubah isi array buku memasukkan posisinya terlebih dahulu. Apabila posisinya melebihi data maksimal yang ada, maka program akan menjalankan `cout << "Posisi melebihi data yang ada" << endl;` dan mencetak **"Posisi melebihi data yang ada"**.
- `void destroyArrayBuku()` digunakan untuk menghapus seluruh isi array sehingga list buku menjadi kosong.
- `void cetakArrayBuku() ` digunakan untuk menampilkan isi list atau array tersebut yang terdiri atas data-data buku. Jika tidak ada buku pada array, maka outputnya adalah **"Tidak ada data yang dicetak"**.

#### Penjelasan Main Program :


Pada main program, user menggunakan push array sebanyak 5 kali yaitu `pushArrayBuku("Kalkulus");`, `pushArrayBuku("Struktur Data");`, `pushArrayBuku("Matematika Diskrit");`, `pushArrayBuku("Dasar Multimedia");`, dan `pushArrayBuku("Inggris");` sehingga pada array tersebut terdapat 5 data buku yaitu Kalkulus, Struktur Data, Matematika Diskrit, Dasar Multimedia, dan Inggris. Data yang terbaru akan ditambahkan ke posisi depan. Berikut urutan posisi datanya.

- Posisi 1 : Inggris (top)
- Posisi 2 : Dasar Multimedia
- Posisi 3 : Matematika Diskrit
- Posisi 4 : Struktur Data
- Posisi 5 : Kalkulus

Selanjutnya, user mencetak array tersebut dengan cara memanggil fungsi `cetakArrayBuku();`.

![Cuplikan layar 2024-05-06 190637](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/9b4eb5d5-099f-4bca-90f0-a365c1c8508e)

Kode `cout << "Apakah data stack penuh? " << isFull() << endl;` dan `cout << "Apakah data stack kosong? " << isEmpty() << endl;` digunakan untuk mencetak pertanyaan **"Apakah data stack penuh? "** dan **"Apakah data stack kosong? "** pada output. 1 merupakan True yang artinya stack tersebut penuh. Sedangkan 0 merupakan False yang artinya stack tersebut tidak kosong.

![Cuplikan layar 2024-05-06 190708](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/07c7ceec-c8a9-4f39-b052-73a9a48bf237)

`peekArrayBuku(2);` digunakan untuk melihat data pada posisi kedua. Data pada posisi kedua adalah buku dengan judul "Dasar Multimedia".

![Cuplikan layar 2024-05-06 190723](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/010dc67c-4b3d-40fd-aa06-f6c4799f1d60)

`popArrayBuku();` digunakan untuk menghapus data yang berada pada posisi top yaitu Inggris sehingga datanya sekarang tinggal 4. Berikut posisi bukunya.

- Posisi 1 : Dasar Multimedia (top)
- Posisi 2 : Matematika Diskrit
- Posisi 3 : Struktur Data
- Posisi 4 : Kalkulus

![Cuplikan layar 2024-05-06 190731](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/bbaa7076-cb6a-45e6-809e-690642e19d29)

`changeArrayBuku(2, "Bahasa Jerman");` digunakan untuk mengubah data kedua menjadi buku berjudul "Bahasa Jerman". Pada posisi kedua diduduki oleh "Matematika Diskrit" sehingga posisi buku setelah data diubah yaitu sebagai berikut.

- Posisi 1 : Dasar Multimedia (top)
- Posisi 2 : Bahasa Jerman
- Posisi 3 : Struktur Data
- Posisi 4 : Kalkulus

`cetakArrayBuku();` digunakan untuk menampilkan isi data array tersebut

`destroyArrayBuku();` digunakan untuk menghapus seluruh isi array sehingga array atau list tersebut menjadi kosong. 

![Cuplikan layar 2024-05-06 194514](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/15116276-4861-4bf5-a168-a255b820fc86)

`cout << "Jumlah data setelah dihapus: " << top << endl;` dan `cetakArrayBuku();` digunakan untuk mencetak jumlah data setelah dihapus yaitu 0.

#### Output Guided 1:
![Cuplikan layar 2024-05-06 194537](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/14da4c36-5b2e-4c66-ac9e-75e4d5ccb98d)

## Unguided 

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list.

```C++

```

Kode tersebut digunakan untuk 

#### Output dan Penjelasan:


#### Penjelasan main program:
- Variabel-variabel yang digunakan dalam program harus dideklarasikan tipe datanya terlebih dahulu. Tipe data variabel kata adalah string karena terdapat lebih dari 1 karakter. 

#### Full code Screenshot:



### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa.

```C++

```

Kode tersebut digunakan untuk  

#### Penjelasan Main Program:


#### Output:


Penjelasan Output :


#### Full code Screenshot:


## Kesimpulan


## Referensi
- [1] 
