
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

Queue menggunakan objek yang terdiri atas deque atau list (_sequential container class_) sebagai kontainer yang mendasarinya dan menyediakan sekumpulan fungsi anggota tertentu untuk mengakses elemen-elemennya [1]. Queue harus terdiri atas queue element, head pointer, dan tail pointer sebagai _data members_ [2]. Queue berguna untuk simulator yang berbasis waktu simulasi peristiwa dengan prioritasnya, _real-time games_, _searching_, _routing_, dan _compression_ [7]. 

### Fungsi atau Kegunaan Queue:
- Simulasi antrian : yaitu untuk membuat model antrian dari kegiatan sehari-hari, misalnya antrian pelanggan di kasir supermarket.
- Buffering : yaitu untuk menyangga data sementara, misalnya untuk menampung data yang dikirimkan ke jaringan secara bertahap.
- BFS (Breadth-First Search) : yaitu untuk pencarian BFS pada algoritma struktur data, misalnya pada graph dan tree.
- Synchronization: yaitu digunakan dalam aplikasi dimana data ditransfer secara _asynchronus_ di antara 2 proses [6].
- Call Center Systems : yaitu digunakan untuk menampung panggilan masuk dan menyelesaikannya secara satu per satu [6].
- CPU Scheduling : yaitu digunakan untuk menangani interupssi dalam sistem waktu nyata dan ideal untuk penjadwalan disk dan CPU [6].

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
Queue diimplementasikan sebagai _adapter class_ dan biasanya didasarkan pada kontainer yang mendasarinya [3]. Adapter bukan kontainer kelas-pertama (_first class_) karena tidak menyediakan implementasi struktur data aktual dimana i dalamnya elemen-elemen dapat disimpan dan karena adaptor tidak mendukung iterator [8]. Berikut merupakan implementasi pada queue.

![queue implementation](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/e0626a7e-ce15-4bca-9e58-e2e23471ff85)

**Source: Sitasi [4] Daftar Pustaka**

Elemen yang ditambahkan paling akhir akan dihapus terlebih dahulu [4]. Implementasi queue pada C++ dapat dilakukan menggunakan STL (Standard Template Library) yang menyediakan kelas queue dalam header file <queue> [5]. Implementasi queue dapat dilakukan menggunakan array maupun linked list.

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
Kode di atas digunakan untuk menambahkan, menghapus, menghitung, mengosongkan, dan menampilkan data antrian menggunakan Queue. Konsep yang diterapkan adalah FIFO (First In First Out). Elemen ditambahkan pada ujung belakang (back / rear) antrian. Elemen dihapus dari ujung depan (front) antrian. Pertama-tama, deklarasikan terlebih dahulu variabel yang diperlukan yaitu `const int maksimalQueue = 5`, `int front = 0;`, `int back = 0;`, dan `string queueTeller[5];`. `string queueTeller[5];` artinya banyak antrian maksimal yang dapat ditampung oleh queue tersebut adalah 5. Antrian akan didefinisikan penuh apabila telah mencapai jumlah maksimal yaitu 5. Berikut penjelasan kode lainnya:

Pengecekan apakah antrian dalam keadaan penuh atau kosong:
- `bool isFull()` digunakan untuk mengecek apakah antrian penuh atau tidak.
- `bool isEmpty()` digunakan untuk mengecek apakah antrian kosong atau tidak.

Fungsi untuk menambahkan, menghapus, menghitung, mengosongkan, dan menampilkan data dalam antrian:
- `void enqueueAntrian(string data)` digunakan untuk menambahkan antrian baru.
- `void dequeueAntrian()` digunakan untuk menghapus antrian. Antrian yang dihapus yaitu data front (depan).
- `int countQueue()` digunakan untuk menghitung jumlah seluruh data yang saat ini ada di dalam antrian.
- `void clearQueue()` digunakan untuk menghapus seluruh data di dalam antrian sehingga antrian menjadi kosong.
- `void viewQueue()` digunakan untuk melihat data yang saat ini berada di dalam antrian.

#### Penjelasan Main Program :
- `enqueueAntrian("Andi");` dan `enqueueAntrian("Maya");` digunakan untuk menambahkan data ke dalam antrian. Data saat ini ditampilkan dengan `queueTeller.viewQueue();`. `cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;` akan menampilkan banyaknya data dalam antrian saat ini yaitu 2. Terdapat data Andi pada antrian 1 dan data Maya pada antrian 2.
- `dequeueAntrian();` digunakan untuk menghapus data di dalam antrian, khususnya yaitu data front karena menerapkan FIFO. Data saat ini (setelah dihapus) akan ditampilkan dengan `queueTeller.viewQueue();`. `cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;` akan menampilkan banyaknya data dalam antrian saat ini yaitu 1. Data saat ini tersisa Maya karena Andi telah dihapus.
- `clearQueue();` digunakan untuk menghapus seluruh antrian sehingga antrian menjadi kosong. Data saat ini (setelah dikosongkan) akan ditampilkan dengan `queueTeller.viewQueue();`. Karena data saat ini sudah kosong, maka Data antrian teller kosong. `cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;` akan menampilkan banyaknya data dalam antrian saat ini yaitu 0. 

#### Output Guided 1:
![Cuplikan layar 2024-05-13 132931](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/d84c90e1-efaf-4d8a-8bd1-85ff3238552e)


## Unguided 

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list.

```C++
#include <iostream>
using namespace std;

// struct Node
struct Node {
    // deklarasi data
    string data;
    Node *next;
};

// class Queue
class Queue {
// bagian public dari class Queue
public :
    Queue() {
        // deklarasi size, data front, dan data back
        size = 0;
        front = NULL;
        back = NULL;
    }

    // mengecek apakah data antrian penuh atau tidak
    bool isFull() {
        return false;
    }

    // mengecek apakah antrian kosong atau tidak
    bool isEmpty() {
        return size == 0;
    }

    // tambahkan data ke dalam antrian
    void enqueueAntrian(string data) {
        Node* baru = new Node();
        baru->data = data;
        baru->next = NULL;

        // apabila antrian kosong, maka front dan back dimulai dari node baru
        if (isEmpty()) {
            front = baru;
            back = baru;
        // apabila antrian tidak kosong, maka dimulai dari node sebelumnya (back)
        } else {
            back->next = baru;
            back = baru;
        }

        size++;
    }

    // hapus data dalam antrian (otomatis menghapus front)
    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian Kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    // lihat jumlah data dalam antrian
    int countQueue() {
        return size;
    }

    // hapus seluruh data dalam antrian (kosongkan antrian)
    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    // lihat data antrian teller 
    void viewQueue() {
        cout << "Data antrian teller: " << endl;
        Node* current = front;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << "." << current->data << endl;
            current = current->next;
        }
    }

    ~Queue() {
        clearQueue();
    }

// bagian private dari class Queue
private:
    // deklarasi data front, back, dan size
    Node* front;
    Node* back;
    int size;
};

// main program (program utama)
int main() {
    // deklarasi queueTeller dengan menggunakan fungsi di dalam class queue
    Queue queueTeller;
    // tambahkan data ke antrian
    queueTeller.enqueueAntrian("Andi");
    queueTeller.enqueueAntrian("Maya");
    // lihat data di dalam antrian saat ini
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;
    // hapus data dalam antrian (otomatis hapus data front)
    queueTeller.dequeueAntrian();
    // lihat data di dalam antrian saat ini
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;
    // kosongkan atau bersihkan seluruh data antrian 
    queueTeller.clearQueue();
    // lihat data di dalam antrian saat ini
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;

    return 0;
}

```

Kode tersebut merupakan perubahan dari guided 1 dari array menjadi linked list. Pada array, tidak diperlukan class sehingga pada main program bisa langsung menggunakan `enqueueAntrian("Andi")`. Sedangkan pada linked list dimana terdapat class Queue, program harus menggunakan variabel yang kemudian memanggil fungsi-fungsi di dalam kelas, misalnya `queueTeller.enqueueAntrian("Andi");`. `queueTeller` merupakan variabelnya, sedangkan `enqueueAntrian` merupakan fungsi yang digunakan dengan cara memanggil fungsi tersebut dari kelas. Sebelum menggunakan fungsi-fungsi di dalam class Queue, queueTeller harus dideklarasikan dulu dengan class yang akan digunakan sehingga deklarasinya adalah `Queue queueTeller;`. 

Di dalam bagian dari private class Queue terdapat deklarasi data front, back, dan size.

Di dalam bagian dari public class Queue terdapat kode-kode berikut.
- `bool isFull()` digunakan untuk mengecek apakah antrian penuh atau tidak.
- `bool isEmpty()` digunakan untuk mengecek apakah antrian kosong atau tidak.
- `void enqueueAntrian(string data)` digunakan untuk menambahkan antrian baru.
- `void dequeueAntrian()` digunakan untuk menghapus antrian. Antrian yang dihapus yaitu data front (depan).
- `int countQueue()` digunakan untuk menghitung jumlah seluruh data yang saat ini ada di dalam antrian.
- `void clearQueue()` digunakan untuk menghapus seluruh data di dalam antrian sehingga antrian menjadi kosong.
- `void viewQueue()` digunakan untuk melihat data yang saat ini berada di dalam antrian.

#### Output:
![Cuplikan layar 2024-05-13 111423](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/cf414028-539f-4b87-a537-06bcefff6678)

#### Penjelasan Output dan Main Program:

![Cuplikan layar 2024-05-13 111448](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/a30fb9c5-fc59-4998-90af-04f309c25389)

`queueTeller.enqueueAntrian("Andi");` dan `queueTeller.enqueueAntrian("Maya");` akan menambahkan nama Andi dan Maya di dalam antrian. Andi pada antrian pertama, sedangkan Maya pada antrian kedua. Selanjutnya, data saat ini ditampilkan dengan `queueTeller.viewQueue();`. `cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;` akan menampilkan banyaknya data dalam antrian saat ini yaitu 2.

![Cuplikan layar 2024-05-13 111510](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/8b1f6e1b-e5b3-465c-a43e-2300de878c0d)

`queueTeller.dequeueAntrian();` akan menghapus data front di dalam antrian tersebut yaitu "Andi" sehingga di dalam antrian saat ini hanya tersisa "Maya". Selanjutnya, data saat ini ditampilkan dengan `queueTeller.viewQueue();`. `cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;` akan menampilkan banyaknya data dalam antrian saat ini yaitu 1.

![Cuplikan layar 2024-05-13 111521](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/be67853a-ee3a-4d1c-b133-d56c6b563031)

`queueTeller.clearQueue();` akan menghapus seluruh data di dalam antrian sehingga antrian menjadi kosong. Selanjutnya, data saat ini ditampilkan dengan `queueTeller.viewQueue();`. Tidak ada antrian sama sekali saat ini sehingga Data antrian teller kosong. `cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;` akan menampilkan banyaknya data dalam antrian saat ini yaitu 0.

#### Full code Screenshot:
![Cuplikan layar 2024-05-13 111354](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/e3749dd4-8e96-4213-b357-c132f3e34fea)


### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa.

```C++
#include <iostream>
#include <string>
using namespace std;

// struct Node
struct Node {
    // deklarasi Nama dan Nim
    string Nama;
    string Nim;
    Node *next;
};

// class Queue
class Queue {
// bagian public dari class Queue
public:
    Queue() {
        // deklarasi size, data front dan data back
        size = 0;
        front = NULL;
        back = NULL;
    }

    // mengecek apakah antrian penuh atau tidak
    bool isFull() {
        return false;
    }

    // mengecek apakah antrian kosong atau tidak
    bool isEmpty() {
    return size == 0;
    }

    // tambahkan data ke dalam antrian 
    void enqueueAntrian(string Nama, string Nim) {
        Node* baru = new Node();
        baru->Nama = Nama;
        baru->Nim = Nim;
        baru->next = NULL;

        // apabila antrian kosong, maka front dan back dimulai dari node baru
        if (isEmpty()) {
            front = baru;
            back = baru;
        // apabila antrian tidak kosong, maka dimulai dari node sebelumnya (back)
        } else {
            back->next = baru;
            back = baru;
        }

        size++;
    }

    // hapus data dalam antrian (otomatis menghapus front)
    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian Kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    // lihat jumlah data dalam antrian 
    int countQueue() {
        return size;
    }

    // hapus seluruh data dalam antrian (kosongkan antrian)
    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    // lihat data antrian teller dengan atribut nama dan NIM mahasiswa
    void viewQueue() {
        cout << "Data antrian teller: " << endl;
        Node* current = front;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". Nama: " << current->Nama << " (Nim: " << current->Nim << ")" << endl;
            current = current->next;
        }
    }

    ~Queue() {
        clearQueue();
    }

// bagian private dari class Queue
private:
    // deklarasi data front, back, dan size
    Node* front;
    Node* back;
    int size;
};

// main program (program utama)
int main() {
    // deklarasi class Queue serta tipe data Nama dan Nim
    Queue queueTeller;
    string Nama, Nim;

    // user input nama dan NIM mahasiswa pertama
    cout << "Masukkan Nama mahasiswa: ";
    cin >> Nama;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> Nim;
    // panggil fungsi untuk menambahkan data ke dalam antrian
    queueTeller.enqueueAntrian(Nama, Nim);

    // user input nama dan NIM mahasiswa kedua
    cout << "Masukkan Nama mahasiswa: ";
    cin >> Nama;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> Nim;
    // panggil fungsi untuk menambahkan data ke dalam antrian
    queueTeller.enqueueAntrian(Nama, Nim);

    // lihat data di dalam antrian saat ini
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;

    // hapus antrian (data yang dihapus adalah front)
    queueTeller.dequeueAntrian();
    // lihat data di dalam antrian saat ini (setelah data front sebelumnya dihapus)
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini 
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;

    // bersihkan atau hapus seluruh antrian sehingga antrian kosong
    queueTeller.clearQueue();
    // lihat data di dalam antrian saat ini (setelah semua antrian dihapus)
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;

    return 0;
}

```

Kode tersebut digunakan untuk menambahkan, menghapus, menghitung, mengosongkan, dan menampilkan data antrian dengan atribut nama dan NIM mahasiswa. Program tersebut hampir sama seperti pada unguided 1. Yang membedakan adalah pada main program dimana user perlu menginputkan nama dan NIM mahasiswa melalui terminal setelah kode dijalankan. Berikut penjelasan kodenya:

Di dalam bagian dari private class Queue terdapat deklarasi data front, back, dan size.

Di dalam bagian dari public class Queue terdapat kode-kode berikut.
- `bool isFull()` digunakan untuk mengecek apakah antrian penuh atau tidak.
- `bool isEmpty()` digunakan untuk mengecek apakah antrian kosong atau tidak.
- `void enqueueAntrian(string data)` digunakan untuk menambahkan antrian baru.
- `void dequeueAntrian()` digunakan untuk menghapus antrian. Antrian yang dihapus yaitu data front (depan).
- `int countQueue()` digunakan untuk menghitung jumlah seluruh data yang saat ini ada di dalam antrian.
- `void clearQueue()` digunakan untuk menghapus seluruh data di dalam antrian sehingga antrian menjadi kosong.
- `void viewQueue()` digunakan untuk melihat data yang saat ini berada di dalam antrian.

#### Penjelasan Main Program:
- `cout << "Masukkan Nama mahasiswa: ";` akan meminta user untuk memasukkan nama mahasiswa.
- `cin >> Nama;` akan menampilkan nama yang telah diinput oleh user.
- `cout << "Masukkan NIM mahasiswa: ";` akan meminta user untuk memasukkan nim mahasiswa.
- `cin >> Nim;` akan menampilkan nim yang telah diinput oleh user.
- `queueTeller.enqueueAntrian(Nama, Nim);` akan memanggil fungsi enqueueAntrian di dalam class Queue untuk menambahkan data nama dan  nim yang telah diinput oleh user.
- Selanjutnya, data saat ini ditampilkan dengan `queueTeller.viewQueue();`.
- `cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;` akan menampilkan banyaknya data dalam antrian.

#### Output:
![Cuplikan layar 2024-05-13 120354](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/3f258bba-3add-4fdd-8aaa-1de8bd9fba7c)

**Penjelasan Output :**

![Cuplikan layar 2024-05-13 120416](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/48bbf23e-ad43-44da-a99b-0e837bcd5367)

User memasukkan nama dan nim mahasiswa yang pertama yaitu Aliana dengan NIM 231111008. Kemudian, user memasukkan nama dan nim mahasiswa yang kedua yaitu Ardelia dengan NIM 2311110051. Kemudian, data ditampilkan sehingga menghasilkan output sebagai berikut.

![Cuplikan layar 2024-05-13 120427](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/da356168-e5eb-487d-9b1b-bdeb1e04b5b5)

Selanjutnya, program akan menjalankan dequeue sehingga menghapus data front pada antrian tersebut. Data yang dihapus yaitu Aliana dengan NIM 2311110008. Saat ini, hanya ada 1 antrian yaitu Ardelia dengan NIM 2311110051 yang naik menjadi posisi 1. Berikut tampilan outputnya.

![Cuplikan layar 2024-05-13 120456](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/b1a1117c-29ce-4f07-9092-5fb84f3ca4b9)

Terakhir, user mengosongkan list menggunakan clearQueue sehingga seluruh antrian dihapus. Saat ini tidak ada antrian sama sekali sehingga jumlah data antriannya adalah 0. Berikut output yang dihasilkan.

![Cuplikan layar 2024-05-13 120510](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/a129db29-b4d2-4d2b-94db-1244fe7309c5)

#### Full code Screenshot:
![Cuplikan layar 2024-05-13 120326](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/6e22024f-e4f1-487d-827d-dd1eea4ebc38)

## Kesimpulan
Kesimpulan yang dapat diambil dari praktikum modul Queue yaitu data yang paling awal dimasukkan akan dihapus paling awal saat user melakukan dequeue antrian. Hal ini karena Queue menerapkan FIFO (First In Firt Out). Konsep yang diterapkan adalah FIFO (First In First Out). Elemen ditambahkan pada ujung belakang (back / rear) antrian. Elemen dihapus dari ujung depan (front) antrian. Dalam Queue kita dapat menambahkan (enqueue), menghapus (dequeue), menghitung (count), mengosongkan (clear), dan menampilkan (view) data antrian. Queue dapat membantu mengatur urutan data dan mempertahankan prioritas saat memproses elemen-elemen di dalamnya. Queue harus terdiri atas queue element, head pointer, dan tail pointer sebagai _data members_.

## Referensi
- [1] Aditya, "Queue in C++ Standard Template Library (STL)," geeksforgeeks.org, 22 April 2023. [Online]. Tersedia : https://www.geeksforgeeks.org/queue-cpp-stl/ [Diakses: 12 Mei 2024].
- [2] F. Yang dan Y. Dong, C++ Programming. Edisi Pertama.  Germany : De Gruyter, 2019.
- [3] J. Farrier, Data Structures and Algorithms with the C++ STL. Edisi Pertama. Birmingham : Packt Publishing Ltd, 2024.
- [4] R. Pathak, "Queue C++  STL," PreBytes Blog, 20 Juli 2022. [Online]. Tersedia : https://www.prepbytes.com/blog/queues/queue-c-stl/ [Diakses: 12 Mei 2024].
- [5] R. Pratama, “Queue: Pengealan, Implementasi, Operasi Dasar, dan Aplikasi,” Medium, 25 Mei 2023. [Online]. Tersedia : https://medium.com/@furatamarizuki/queue-pengenalan-implementasi-operasi-dasar-dan-aplikasi-c5eed7e871a3 [Diakses: 11 Mei 2024].
- [6] Simplilearn, "Queue in C++ Function: Syntax, Types and Advantages," Simplilearn, 2 Maret 2023. [Online]. Tersedia : https://www.simplilearn.com/tutorials/cpp-tutorial/queue-in-cpp [Diakses: 12 Mei 2024].
- [7] S.N. Mohanty dan P. K. Tripathy, Data Structure and Algorithms Using C++. New York City : Wiley Publishing, 2021.
- [8] V.  Siahaan dan R.H. Sianipar, THREE COOKBOOKS IN ONE: Visual C++, Visual Basic, Visual C#. Sumatera Utara : Balige Publishing, 2020. 
