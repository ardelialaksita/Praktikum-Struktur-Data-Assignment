# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Ardelia Rachma Laksita</p>

## Table of Contents
1. [Dasar Teori](#dasar-teori)
2. [Guided](#guided)
3. [Unguided](#unguided)
4. [Kesimpulan](#kesimpulan)
5. [Referensi](#referensi)

## Dasar Teori
Linked List artinya 'senarai berkait' yaitu struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling berkaitan dan bersambungan, dinamis, dan terbatas. Terdapat simpul dalam linked list atau yang biasa dikenal dengan _node_. Setiap node akan memiliki _field_ bertipe struct yang sama untuk digunakan sebagai pointer. Linked list dapat menjadi suboptimal, tapi hanya untuk beberapa kasus yang spesifik (diutamakan pada tipe data dan datasets yang sangat luas) [1]. Linked list bagus digunakan untuk menulis algoritma yang bekerja untuk seluruh koleksi linear sehingga tidak perlu diimplementasikan berulang kali untuk setiap tipe linear [3]. 

Terdapat 4 _fields_ pada linked list yang didefinisikan dengan nama berikut:
- Row : indeks dari row dimana elemen bukan 0 diposisikan [2].
- Column : indeks dari kolom dimana elemen bukan 0 diposisikan [2].
- Value : nilai dari elemen bukan 0 diposisikan pada indeks (row, column) [2].
- Next node : menempatkan alamat atau _address_ dari node selanjutnya [2].

Linked list terdiri atas jumlah nodes beserta nilainya dimana dihasilkan dari _runtime_ [3]. Linked list ada 2 yaitu :
1) Single linked list : satu arah, hanya ada satu pointer yang menghubungkan setiap nodenya.
2) Double linked list : dua arah, ada lebih dari 1 pointer yang menghubungkan setiap nodenya. Double linked List memiliki karakteristik yang bermanfaat dalamm situasi _multi-thread_ atau berkesinambungan, tetapi juga memerlukan kehati-hatian [1].

### Jenis-jenis Linked List :
- Linked List Circular

Linked List Circular adalah linked list yang berguna untuk menyimpan data yang membutuhkan akses secara berulang. Node terakhirnya tidak memiliki value (NULL). Pada linked list circular, node tail terhubung dengan node head sehingga membutuhkan _dummy node_ bernama _current_. Operasi pada linked list circular yaitu deklarasi node, membuat dan menginisialisasi pointer head dan tail, pengecekan kondisi linked list, pembuatan node, penambahan node, pengubahan node, penghapusan node, dan menampilkan data linked list. 

- Linked List Non Circular

Linked List Non Circular adalah linked list yang tidak memiliki keterkaitan antara node head (node pertama) dan node tail (node terakhir) sehingga tidak saling terhubung. Operasinya yaitu ada deklarasi node, membuat dan menginisialisasi pointer head dan tail, pengecekan kondisi linked list, penambahan node, pengubahan node, penghapusan node, dan menampilkan data linked list.

## Guided 

### 1. Single Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next; // Tanda * mendefinisikan variabel pointer yaitu menyimpan alamat dari variabel lain
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() { // Menggunakan void supaya tidak perlu memberikan return value
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru; // 1 node ini terdapat head, tail, dan variabel baru
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init(); // Harus ada untuk menginisialisasi capsul nodenya
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}

```
Kode di atas digunakan untuk mengoperasikan suatu data menggunakan single linked list dimana terdapat opsi untuk menambah, menghapus, membersihkan, dan mengubah data pada suatu list. Pada main program harus terdapat init(); untuk menginisialisasi capsul nodenya. Selanjutnya, kita hanya perlu memanggil fungsi void yang diinginkan. Angka yang ada pada tanda kurung ( ) merupakan data yang akan ditambahkan, dihapus, dan diubah sesuai dengan posisinya. Return 0 digunakan sebagai tanda bahwa program telah selesai dan berhasil. Int merupakan deklarasi suatu variabel bahwa tipe data variabel tersebut adalah integer. 

Insert data bisa dilakukan di depan list menggunakan `void insertDepan(int nilai)` dimana node baru akan ditambahkan pada head, sedangkan node head sebelumnya akanberpindah posisi menjadi data tengah. Insert data bisa juga dilakukan di belakang list menggunakan `void insertBelakang(int nilai)` dimana node baru akan ditambahkan pada tail, sedangkan node tail sebelumnya akan berpindah posisi menjadi data tengah. Insert data di tengah dapat menggunakan `void insertTengah(int data, int posisi)` dimana node baru akan ditambahkan pada tengah-tengah data sesuai dengan posisi yang dimasukkan. Pada Insert Tengah ini sedikit berbeda dengan Insert Depan dan Insert Belakang karena harus menentukan posisi mana yang ingin diubah menggunakan indeks [i].

Hapus depan menggunakan kode `void hapusDepan()` bertujuan untuk menghapus data yang berada di posisi head, lalu data yang berada pada next posisi head akan dipindahkan menjadi posisi head. Hapus belakang menggunakan kode `void hapusBelakang()` bertujuan untuk menghapus data yang berada di posisi tail, lalu data yang berada pada previous posisi tail akan dipindahkan menjadi posisi tail. Hapus tengah menggunakan kode `void hapusTengah(int posisi)` akan menghapus data di tengah sesuai dengan posisi yang dimasukkan. Hapus seluruh list juga dapat dilakukan yaitu dengan menggunakan `void clearList()` dimana semua node akan dihapus sehingga list menjadi kosong.

Ubah depan menggunakan kode `void ubahDepan(int data)` bertujuan untuk mengubah data pada posisi head sesuai dengan angka baru yang dimasukkan. Ubah belakang menggunakan kode `void ubahBelakang(int data)` bertujuan untuk mengubah data pada posisi tail sesuai dengan angka baru yang dimasukkan. Ubah tengah menggunakan kode `void ubahTengah(int data, int posisi)` bertujuan untuk mengubah data yang ada di posisi tengah sesuai dengan posisi yang dimasukkan. 

#### Output Guided 1:
![Modul 6  Guided 1 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/dc0e27f0-f13a-44a8-aba5-a0d4064e654f)

### 2. Double Linked List 

```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev; // Previous digunakan untuk melihat data sebelumnya
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next; // Akan next terus sampai currentnya berhenti
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}

```
Kode tersebut digunakan untuk menambah, menghapus, memperbarui, membersihkan, dan menampilkan data. Program tersebut menggunakan class node dan class DoublyLinkedList. Terdapat program menu juga yang memuat Add data, Delete data, Update Data, Clear Data, dan Display Data pada masing-masing casenya. Void push digunakan untuk menambahkan data (Add data) yang dipanggil pada case 1. Void pop digunakan untuk menghapus data (Delete data) yang dipanggil pada case 2. Void update digunakan untuk memperbarui data (update) yang dipanggil pada case 3. Void deleteAll digunakan untuk membersihkan atau menghapus seluruh isi list (Clear data) yang dipanggil pada case 4. Void display digunakan untuk menampilkan seluruh data saat ini (Display data) yang dipanggil pada case 5. Sedangkan case 6 digunakan apabila user ingin keluar (exit). Apabila pilihan yang dimasukkan tidak terdapat pada case 1,2,3,4,5, dan 6, maka program akan menjalankan default yaitu menampilkan "Invalid Choice". Terakhir, return 0 merupakan tanda bahwa program telah selesai dan berhasil.

Pada output berikut, user memilih menu 1 untuk menambahkan data. Kemudian user menambahkan angka 1. Program akan menampilkan program menu lagi dan user diminta memilih menu kembali. User memilih 1 untuk Add data lagi yaitu angka 2. Proses ini berlangsung hingga angka 5 secara berurutan sehingga saat ini terdapat 5 angka dalam list. Selanjutnya, user memilih menu 5 untuk menampilkan seluruh data menggunakan (Display Data). 

#### Output Guided 2:
![Modul 6  Guided 2 Output (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/e6a3fd75-b71d-4a0d-a2b0-68675ae08611)
![Modul 6  Guided 2 Output (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/9d774885-6db2-4261-9378-59ebc2caceb6)

### 3. Linked List Circular

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init() {
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan
void insertDepan(string data) {
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data) {
    // Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi -1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // transvering
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            bantu = hapus-> next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil terhapus!" << endl;
}

// Tampilan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);

        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}

```
Kode tersebut digunakan untuk menambahkan data (insert) dan menghapus data (hapus). Program dapat melakukan insert data di depan, tengah, dan belakang. Program juga dapat menghapus data di depan, tengah, belakang, bahkan menghapus seluruh data sehingga list menjadi kosong. Data ditampilkan menggunakan fungsi void tampil( ). Pada main program, ditambahkan data ayam pada head data menggunakan insertDepan. Selanjutnya data ditampilkan. Lalu, ditambahkan bebek pada head lagi sehingga ayam berpindah posisi menjadi data belakang karena hanya terdapat 2 data yaitu depan dan belakang. Selanjutnya, ditambahkan data pada tail menggunakan insertBelakang yaitu "Cicak". Ditambahkan lagi "Domba" pada tail menggunakan insertBelakang sehingga posisi cicak berpindah posisi menjadi data tengah. Hasil saat ini yaitu "Bebek, Ayam, Cicak, Domba". Dilakukan hapus data bagian belakang sehingga domba hilang dan cicak menjadi tail. Lalu ditambahkan data pada posisi kedua menggunakan kode `insertTengah("Sapi", 2);`. Lalu, data pada posisi kedua dihapus menggunakan `hapusTengah(2);`. Return menjadi tanda bahwa program telah selesai dan berhasil. Hasil akhir datanya adalah **Ayam, Sapi, Cicak**. Berikut outputnya.

#### Output Guided 3:
![Modul 6  Guided 3 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/55db1b3d-d1bf-47fe-a06d-bd29351ad125)

## Unguided 
Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan _input_ dari _user_.

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa. 
 
```C++
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// PROGRAM LINKED LIST NON CIRCULAR MAHASISWA DAN NIM DENGAN INPUT OLEH USER

// deklarasi struct untuk mahasiswa
struct Mahasiswa {
    string nama;
    long long nim;
    Mahasiswa* next;
};

// deklarasi head dan tail menggunakan pointer
Mahasiswa* head = NULL;
Mahasiswa* tail = NULL;
Mahasiswa* baru; 
Mahasiswa* help;
Mahasiswa* hapus;

// pengecekan jika list kosong
bool isEmpty() {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}

// membuat node baru
void newNode (string nama, long long nim) {
    baru = new Mahasiswa;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
}

// menghitung list
int countList() {
    help = head;
    int jumlah = 0;

    while (help != NULL) {
        jumlah++;
        help = help->next;
    }
    return jumlah;
}

// fungsi tambah depan 
void insertHead(string nama, long long nim) {

    // membuat node baru
    newNode(nama, nim);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// fungsi tambah tengah
void insertMiddle(string nama, long long nim, int position) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        newNode(nama, nim);

        // transversing
        int nomor = 1;
        help = head;

        while (nomor < position -1) {
            help = help->next;
            nomor++;
        }
        baru->next = help->next;
        help->next = baru;
    }
}

// fungsi tambah belakang
void insertTail(string nama, long long nim) {

    // membuat node baru
    newNode(nama, nim);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// fungsi ubah data depan list
void modifyHead(string newName, long long newNim) {
    if (!isEmpty()) {
        string nama = head->nama;
        long long nim = head->nim;
        head->nama = newName;
        head->nim = newNim;
        cout << "Data berhasil diubah" << endl;
    } else {
        cout << "Data mahasiswa tidak ditemukan." << endl;
    } 
}

// fungsi ubah data tengah list
void modifyMiddle(int position, string newName, long long newNim) {
    if (!isEmpty()) {
        Mahasiswa *temp = head;
        string nama;
        long long nim;
        
        for (int i = 1; i < position && temp != NULL; i++) {
            nama = temp->nama;
            nim = temp->nim;
            temp = temp->next;
        }
        if (temp != NULL) {
            nama = temp->nama;
            nim = temp->nim;
            temp->nama = newName;
            temp->nim = newNim;
            cout << "Data mahasiswa berhasil diubah." << endl;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// fungsi ubah data belakang list
void modifyTail(string newName, long long newNim) {
    if (!isEmpty()) {
        Mahasiswa *temp = head;

        // Mencapai node terakhir
        while (temp->next != head) {
            temp = temp->next;
        }

        // Mengubah data pada node terakhir
        temp->nama = newName;
        temp->nim = newNim;

        cout << "Data mahasiswa berhasil diubah." << endl;
    } else {
        cout << "Data mahasiswa tidak ditemukan." << endl;
    }
}


// fungsi hapus depan
void deleteHead() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;

            cout << "Data mahasiswa berhasil dihapus." << endl;
        }
    } else {
        cout << "List tersebut kosong!" << endl;
    }
}

// fungsi hapus tengah
void deleteMiddle(int posisi) {
    if (isEmpty() == 0) {

        // transvering
        int nomor = 1;
        help = head;

        while (nomor < posisi - 1) {
            help = help->next;
            nomor++;
        }

        hapus = help->next;
        help->next = hapus->next;
        delete hapus;

        cout << "Data mahasiswa berhasil dihapus." << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// fungsi hapus belakang
void deleteTail() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;
            delete hapus;

            cout << "Data mahasiswa berhasil dihapus." << endl;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// fungsi hapus seluruh isi list
void clearList() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            help = hapus-> next;
            delete hapus;
            hapus = help;
        }

        delete head;
        head = NULL;
    }

    cout << "Proses menghapus selesai. Seluruh isi list berhasil dihapus. Saat ini tidak ada data pada list tersebut." << endl;
}

// menampilkan isi list
void display() {
    if (!isEmpty()) {
        cout << "======================== DATA MAHASISWA ===========================" << endl;
        cout << "|\tPosisi\t|\tNama\t\t|\tNIM\t\t|" << endl;
        cout << "-------------------------------------------------------------------" << endl;

        int position = 1;
        Mahasiswa* current = head;
        do {
            cout << "|\t" << position << "\t|\t " << left << setw(15) << current->nama << "|\t" << setw(15) << current->nim << " |" << endl;
            current = current->next;
            position++; 
        } while (current != head); 
        cout << "-------------------------------------------------------------------" << endl; 
    } else {
        cout << "List tersebut kosong. Tidak ada data yang ditemukan di dalam list. Silakan masukkan data terlebih dahulu." << endl;
    }
}


// main program
int main() {
    int pilihan;
    string nama;
    long long nim;
    string newName;
    long long newNim;
    int position; 
    do {
        cout << "========== PROGRAM MENU LINKED LIST MAHASISWA DAN NIM ==========" << endl;
        cout << "Selamat datang. Silakan pilih menu!" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "1. Tambahkan data baru pada list bagian depan" << endl;
        cout << "2. Tambahkan data baru pada list bagian tengah" << endl;
        cout << "3. Tambahkan data baru pada list bagian belakang" << endl;
        cout << "4. Ubah data pada list bagian depan" << endl;
        cout << "5. Ubah data pada list bagian tengah" << endl;
        cout << "6. Ubah data pada list bagian belakang" << endl;
        cout << "7. Hapus data pada list bagian depan" << endl;
        cout << "8. Hapus data pada list bagian tengah" << endl;
        cout << "9. Hapus data pada list bagian belakang" << endl;
        cout << "10. Hapus seluruh data pada list" << endl;
        cout << "11. Tampilkan isi list" << endl;
        cout << "0. Keluar" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Pilih menu yang Anda inginkan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama mahasiswa : ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa : ";
                cin >> nim;
                cin.ignore();
                insertHead(nama, nim);
                cout << "Data berhasil ditambahkan." << endl;
                cout << "Data baru yang ditambahkan : " << nama << " dengan NIM " << nim << endl;
                break;
            case 2:
                cout << "Masukkan nama mahasiswa : ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa : ";
                cin >> nim;
                cin.ignore();
                cout << "Masukkan posisi : ";
                cin >> position;
                insertMiddle(nama, nim, position);
                cout << "Data berhasil ditambahkan." << endl;
                cout << "Data baru yang ditambahkan : " << nama << " dengan NIM " << nim << endl;
                break;
            case 3:
                cout << "Masukkan nama mahasiswa : ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa : ";
                cin >> nim;
                cin.ignore();
                insertTail(nama, nim);
                cout << "Data berhasil ditambahkan." << endl;
                cout << "Data baru yang ditambahkan : " << nama << " dengan NIM " << nim << endl;
                break;
            case 4:
                cout << "Masukkan nama baru mahasiswa : ";
                cin >> newName;
                cout << "Masukkan NIM baru mahasiswa : ";
                cin >> newNim;
                modifyHead(newName, newNim);
                break;
            case 5:
                cout << "Masukkan posisi mahasiswa yang ingin diubah : ";
                cin >> position;
                cout << "Masukkan nama baru mahasiswa : ";
                cin >> newName;
                cout << "Masukkan NIM baru mahasiswa : ";
                cin >> newNim;
                modifyMiddle(position, newName, newNim);
                break;
            case 6:
                cout << "Masukkan nama baru mahasiswa : ";
                cin >> newName;
                cout << "Masukkan NIM baru mahasiswa : ";
                cin >> newNim;
                modifyTail(newName, newNim);
                break;
            case 7:
                deleteHead();
                break;
            case 8:
                cout << "Masukkan posisi data yang ingin dihapus : ";
                cin >> position;
                deleteMiddle(position);
                break;
            case 9:
                deleteTail();
                break;
            case 10:
                clearList();
                break;
            case 11:
                display();
                break;
            case 0:
                cout << "Program selesai. Terima kasih." << endl;
                cout << "============================================================================" << endl;
                cout << "Code by : Ardelia Rachma Laksita" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih opsi operasi yang sesuai." << endl;
                break;
        } 
        cout << "============================================================================" << endl;
        cout << endl;
    } while (pilihan != 0);

    return 0;
}

```

Kode tersebut digunakan untuk menambah data, mengubah data, menghapus data, dan membersihkan atau menghapus seluruh isi data sehingga list menjadi kosong. Program kodenya adalah program menu dimana user akan diminta memasukkan pilihan yang diinginkan. 

- Apabila user ingin memasukkan (insert) data baru, maka user bisa memilih pilihan 1-3 dimana pilihan 1 akan menambahkan data di depan list (head), pilihan 2 akan menambahkan data di tengah list, dan pilihan 3 akan menambahkan data di belakang list (tail).
- Apabila user ingin mengubah (modify / change) data yang ada dengan data baru, maka user bisa memilih pilihan 4-6 dimana pilihan 4 akan mengubah data di depan list (head), pilihan 5 akan mengubah data di tengah list, dan pilihan 6 akan mengubah data di belakang list (tail).
- Apabila user ingin menghapus (delete) data yang ada pada list, maka user bisa memiliki pilihan 7-10 dimana pilihan 7 akan menghapus data di depan list (head), pilihan 8 akan menghapus data di tengah list, pilihan 9 akan menghapus data di belakang list (tail), dan pilihan 10 akan menghapus seluruh isi data sehingga list menjadi kosong.
- Pada opsi 11, user dapat menampilkan seluruh data yang ada di dalam list saat ini.
- Apabila user ingin keluar dari program menu, maka user dapat memilih opsi 0 yaitu keluar.
 
Pada insert data, modify data, dan delete data yang berkaitan dengan data tengah akan meminta user untuk memasukkan posisi data tengah yang ingin ditambah, diubah, atau dihapus sehingga penerapannya menyesuaikan posisi yang diinput oleh user. 

#### Penjelasan main program:
Program tersebut berbentuk menu sehingga terdapat switch case pada main programnya. Tipe data pilihan adalah integer sehingga user harus menginputkan dalam bentuk numerik (angka). Tipe data nama adalah string karena terdapat lebih dari 1 karakter. Tipe data NIM adalah long long karena data yang diinputkan mencapai 10 digit. Sedangkan int position digunakan untuk menyesuaikan posisi pada insert, modify, dan delete data yang ada di tengah list.

Program di dalam kode `do` yaitu berupa `cout` sebanyak 11 opsi menu yang ingin ditampilkan dan bisa dipilih oleh user. Terdapat pula ` cout << "Pilih menu yang Anda inginkan: ";` dan `cin >> pilihan;` yang digunakan untuk user memasukkan menu yang diinginkan.

Pada switch case, masing-masing casenya menyesuaikan pilihan menu yang telah dibuat di dalam kode `do` sebelumnya. Case 1 akan menjalankan menu 1 yaitu insert data depan. Kemudian case 2 akan menjalankan menu 2 yaitu insert data tengah. Begitu juga case-case lainnya. Pada case 1-3 akan menampilkan **"Data berhasil ditambahkan"** dan **"Data yang berhasil ditambahkan : (Nama) dengan NIM (NIM)** apabila program telah berhasil menambahkan data baru. User hanya bisa memasukkan pilihan mulai dari 0 hingga 11. Apabila user memasukkan selain pilihan-pilihan tersebut, maka program akan mencetak **"Pilihan tidak valid. Silakan pilih opsi operasi yang sesuai."**

#### Penjelasan input oleh user:
Penjelasan input oleh user akan dijelaskan lebih lanjut pada interpretasi output berikut.

#### Output:

**- Tampilan Menu :**

Berikut tampilan output dari program menu. User akan diminta untuk memasukkan opsi pilihan 1 hingga 0 pada "Pilih menu yang anda inginkan: "

![Modul 6  Unguided 1 Output (18)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/c78e9bf2-2e6d-40d3-bd19-20897be74983)

**- Tampilan Operasi Tambah :**

**a) Tambah Depan (insertHead)**

User memilih opsi 1 untuk menambahkan data pada bagian depan list (head). Data yang ditambahkan yaitu ara dengan NIM 2311110051. Saat ini masih terdapat 1 data mahasiswa beserta NIMnya.

![Modul 6  Unguided 1 Output (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/b8b64d3a-a181-4ed5-8476-ad3fb0a68b15)

**b) Tambah Tengah (insertMiddle)**

User memilih opsi 2 untuk menambahkan data di tengah list. Data yang ditambahkan yaitu ajwa dengan NIM 2311110050 pada posisi 2. Saat ini ada 2 data mahasiswa beserta NIMnya.

![Modul 6  Unguided 1 Output (3)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/a292c58c-1cd9-4843-a19f-13950ffb3df5)

User memilih opsi 2 lagi untuk menambahkan data di tengah list. Data yang ditambahkan yaitu aurel dengan NIM 2311110020 pada posisi 3. Saat ini ada 3 data mahasiswa beserta NIMnya.

![Modul 6  Unguided 1 Output (4)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/7fd60ad6-5923-484c-987f-4e45717cddbf)


User memilih opsi 2 lagi untuk menambahkan data di tengah list. Data yang ditambahkan yaitu alin dengan NIM 2311110008 pada posisi 3 sehingga posisi aurel yang sebelumnya ada di posisi 3, sekarang berpindah menjadi posisi 4. Saat ini ada 4 data mahasiswa beserta NIMnya. 

![Modul 6  Unguided 1 Output (5)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/736d9e57-750a-412c-9496-60bd2da2c43b)

**c) Tambah Belakang (insertTail)**

User memilih opsi 3 untuk menambahkan data di belakang list (tail). Data yang ditambahkan yaitu anggun dengan NIM 2311110022. Saat ini ada 5 data mahasiswa beserta NIMnya.

![Modul 6  Unguided 1 Output (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/fa6a2fbc-64af-40d5-af4f-32f6bee02bee)

**Tampilan List Saat ini setelah Operasi Tambah :**

Berikut tampilan 5 data yang telah ditambahkan pada list.

![Modul 6  Unguided 1 Output (6)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/378db0d5-6057-4a94-955d-91fab05ef7b2)

**- Tampilan Operasi Ubah :**

**a) Ubah Depan (modifyHead)**

![Modul 6  Unguided 1 Output (7)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/60cfd54c-5446-4b72-ad68-a3206499055c)

User memilih opsi 4 untuk mengubah data pada bagian depan list (head). Data yang diubah yaitu ara dengan NIM 2311110051 menjadi atha dengan NIM 2311110060. Saat ini datanya masih ada 5, hanya ada perubahan pada posisi 1 (head). Data saat ini yaitu sebagai berikut.

![Modul 6  Unguided 1 Output (8)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/264623aa-28f8-4bb4-8e13-0996d66f2e2d)

**b) Ubah Tengah (modifyMiddle)**

![Modul 6  Unguided 1 Output (9)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/7e13cd3c-af16-477f-ada9-7747deba1f8a)

User memilih opsi 5 untuk mengubah data pada bagian tengah list. Data yang berada di posisi 2. Data yang diubah yaitu ajwa dengan NIM 2311110050 menjadi afy dengan NIM 2311110070. Saat ini datanya masih ada 5, hanya ada perubahan pada posisi 2. Data saat ini yaitu sebagai berikut.

![Modul 6  Unguided 1 Output (10)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/084846a7-a470-41a1-a3ad-0d6f237001f3)

**c) Ubah Belakang (modifyTail)**

![Modul 6  Unguided 1 Output (11)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/74c98dc8-b251-4c6c-8d79-ca9886c141de)

User memilih opsi 6 untuk mengubah data pada bagian belakang list (tail). Data yang diubah yaitu anggun dengan NIM 2311110022 menjadi alya dengan NIM 2311110080. Saat ini datanya masih ada 5, hanya ada perubahan pada posisi 5 (tail). Data saat ini yaitu sebagai berikut.

![Modul 6  Unguided 1 Output (12)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/febdb3eb-84a6-45d0-89c3-c6095ca216b1)

**Tampilan List Saat ini setelah Operasi Hapus :**

Berikut tampilan 5 data pada list saat ini.

![Modul 6  Unguided 1 Output (12)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/febdb3eb-84a6-45d0-89c3-c6095ca216b1)

**- Tampilan Operasi Hapus :**

**a) Hapus Depan (deleteHead)**

User memilih opsi 7 untuk menghapus data pada bagian depan list (head). Data yang dihapus yaitu atha dengan NIM 2311110060. Saat ini ada 4 data mahasiswa beserta NIMnya.

![Modul 6  Unguided 1 Output (13)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/41255d57-1ca0-4717-a4d2-bd8d34fdfad5)

**b) Hapus Belakang (deleteTail)**

User memilih opsi 9 untuk menghapus data pada bagian belakang list (tail). Data yang dihapus yaitu alya dengan NIM 2311110080. Saat ini ada 3 data mahasiswa beserta NIMnya.

![Modul 6  Unguided 1 Output (14)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/127e7d83-8cb7-43e5-ba1f-85226dabf346)

**c) Hapus Tengah (deleteMiddle)**

User memilih opsi 8 untuk menghapus data pada bagian tengah list. Data yang dihapus berada pada posisi 2. Data yang dihapus yaitu alin dengan NIM 2311110008. Saat ini ada 2 data mahasiswa beserta NIMnya.

![Modul 6  Unguided 1 Output (14)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/127e7d83-8cb7-43e5-ba1f-85226dabf346)

d) Hapus Seluruh Data (clearList)

Pada hapus seluruh data, semua data yang ada pada list saat ini akan dihapus atau dibersihkan sehingga list menjadi kosong. Berikut output saat seluruh data telah dihapus.

![Modul 6  Unguided 1 Output (16)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/86fcb4db-c31d-47fe-9743-ca2b0fff9d46)

**- Tampilan Operasi Tampil Data :**

Berikut tampilan 5 data yang telah ditambahkan pada list.

![Modul 6  Unguided 1 Output (6)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/378db0d5-6057-4a94-955d-91fab05ef7b2)

**- Tampilan Menu Keluar dari Program :**

Berikut tampilan output apabila user memasukkan opsi 11 yaitu keluar dari program.

![Modul 6  Unguided 1 Output (17)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/9b554be5-33ec-4ab6-b524-e4877b958027)

#### Full code Screenshot:
![Modul 6  Unguided 1 Full SS](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/15d5d3ed-3fc2-4641-a4a0-97e2d391cf9a)

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![Modul 6  Output Unguided 2 Soal](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/402eb780-82ef-4b11-91d9-20ce8bd3b814)

```C++
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// PROGRAM LINKED LIST NON CIRCULAR MAHASISWA DAN NIM DENGAN INPUT OLEH USER

// deklarasi struct untuk mahasiswa
struct Mahasiswa {
    string nama;
    long long nim;
    Mahasiswa* next;
};

// deklarasi head dan tail menggunakan pointer
Mahasiswa* head = NULL;
Mahasiswa* tail = NULL;
Mahasiswa* baru; 
Mahasiswa* help;
Mahasiswa* hapus;

// pengecekan jika list kosong
bool isEmpty() {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}

// membuat node baru
void newNode (string nama, long long nim) {
    baru = new Mahasiswa;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
}

// menghitung list
int countList() {
    help = head;
    int jumlah = 0;

    while (help != NULL) {
        jumlah++;
        help = help->next;
    }
    return jumlah;
}

// fungsi tambah depan 
void insertHead(string nama, long long nim) {

    // membuat node baru
    newNode(nama, nim);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// fungsi tambah tengah
void insertMiddle(string nama, long long nim, int position) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        newNode(nama, nim);

        // transversing
        int nomor = 1;
        help = head;

        while (nomor < position -1) {
            help = help->next;
            nomor++;
        }
        baru->next = help->next;
        help->next = baru;
    }
}

// fungsi tambah belakang
void insertTail(string nama, long long nim) {

    // membuat node baru
    newNode(nama, nim);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// fungsi ubah data depan list
void modifyHead(string newName, long long newNim) {
    if (!isEmpty()) {
        string nama = head->nama;
        long long nim = head->nim;
        head->nama = newName;
        head->nim = newNim;
        cout << "Data berhasil diubah" << endl;
    } else {
        cout << "Data mahasiswa tidak ditemukan." << endl;
    } 
}

// fungsi ubah data tengah list
void modifyMiddle(int position, string newName, long long newNim) {
    if (!isEmpty()) {
        Mahasiswa *temp = head;
        string nama;
        long long nim;
        
        for (int i = 1; i < position && temp != NULL; i++) {
            nama = temp->nama;
            nim = temp->nim;
            temp = temp->next;
        }
        if (temp != NULL) {
            nama = temp->nama;
            nim = temp->nim;
            temp->nama = newName;
            temp->nim = newNim;
            cout << "Data mahasiswa berhasil diubah." << endl;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// fungsi ubah data belakang list
void modifyTail(string newName, long long newNim) {
    if (!isEmpty()) {
        Mahasiswa *temp = head;

        // Mencapai node terakhir
        while (temp->next != head) {
            temp = temp->next;
        }

        // Mengubah data pada node terakhir
        temp->nama = newName;
        temp->nim = newNim;

        cout << "Data mahasiswa berhasil diubah." << endl;
    } else {
        cout << "Data mahasiswa tidak ditemukan." << endl;
    }
}


// fungsi hapus depan
void deleteHead() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;

            cout << "Data mahasiswa berhasil dihapus." << endl;
        }
    } else {
        cout << "List tersebut kosong!" << endl;
    }
}

// fungsi hapus tengah
void deleteMiddle(int posisi) {
    if (isEmpty() == 0) {

        // transvering
        int nomor = 1;
        help = head;

        while (nomor < posisi - 1) {
            help = help->next;
            nomor++;
        }

        hapus = help->next;
        help->next = hapus->next;
        delete hapus;

        cout << "Data mahasiswa berhasil dihapus." << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// fungsi hapus belakang
void deleteTail() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;
            delete hapus;

            cout << "Data mahasiswa berhasil dihapus." << endl;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// fungsi hapus seluruh isi list
void clearList() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            help = hapus-> next;
            delete hapus;
            hapus = help;
        }

        delete head;
        head = NULL;
    }

    cout << "Proses menghapus selesai. Seluruh isi list berhasil dihapus. Saat ini tidak ada data pada list tersebut." << endl;
}

// menampilkan isi list
void display() {
    if (!isEmpty()) {
        cout << "======================== DATA MAHASISWA ===========================" << endl;
        cout << "|\tPosisi\t|\tNama\t\t|\tNIM\t\t|" << endl;
        cout << "-------------------------------------------------------------------" << endl;

        int position = 1;
        Mahasiswa* current = head;
        do {
            cout << "|\t" << position << "\t|\t " << left << setw(15) << current->nama << "|\t" << setw(15) << current->nim << " |" << endl;
            current = current->next;
            position++; 
        } while (current != head); 
        cout << "-------------------------------------------------------------------" << endl; 
    } else {
        cout << "List tersebut kosong. Tidak ada data yang ditemukan di dalam list. Silakan masukkan data terlebih dahulu." << endl;
    }
}


// main program
int main() {
    int pilihan;
    string nama;
    long long nim;
    string newName;
    long long newNim;
    int position; 
    do {
        cout << "========== PROGRAM MENU LINKED LIST MAHASISWA DAN NIM ==========" << endl;
        cout << "Selamat datang. Silakan pilih menu!" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "1. Tambahkan data baru pada list bagian depan" << endl;
        cout << "2. Tambahkan data baru pada list bagian tengah" << endl;
        cout << "3. Tambahkan data baru pada list bagian belakang" << endl;
        cout << "4. Ubah data pada list bagian depan" << endl;
        cout << "5. Ubah data pada list bagian tengah" << endl;
        cout << "6. Ubah data pada list bagian belakang" << endl;
        cout << "7. Hapus data pada list bagian depan" << endl;
        cout << "8. Hapus data pada list bagian tengah" << endl;
        cout << "9. Hapus data pada list bagian belakang" << endl;
        cout << "10. Hapus seluruh data pada list" << endl;
        cout << "11. Tampilkan isi list" << endl;
        cout << "0. Keluar" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Pilih menu yang Anda inginkan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama mahasiswa : ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa : ";
                cin >> nim;
                cin.ignore();
                insertHead(nama, nim);
                cout << "Data berhasil ditambahkan." << endl;
                cout << "Data baru yang ditambahkan : " << nama << " dengan NIM " << nim << endl;
                break;
            case 2:
                cout << "Masukkan nama mahasiswa : ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa : ";
                cin >> nim;
                cin.ignore();
                cout << "Masukkan posisi : ";
                cin >> position;
                insertMiddle(nama, nim, position);
                cout << "Data berhasil ditambahkan." << endl;
                cout << "Data baru yang ditambahkan : " << nama << " dengan NIM " << nim << endl;
                break;
            case 3:
                cout << "Masukkan nama mahasiswa : ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa : ";
                cin >> nim;
                cin.ignore();
                insertTail(nama, nim);
                cout << "Data berhasil ditambahkan." << endl;
                cout << "Data baru yang ditambahkan : " << nama << " dengan NIM " << nim << endl;
                break;
            case 4:
                cout << "Masukkan nama baru mahasiswa : ";
                cin >> newName;
                cout << "Masukkan NIM baru mahasiswa : ";
                cin >> newNim;
                modifyHead(newName, newNim);
                break;
            case 5:
                cout << "Masukkan posisi mahasiswa yang ingin diubah : ";
                cin >> position;
                cout << "Masukkan nama baru mahasiswa : ";
                cin >> newName;
                cout << "Masukkan NIM baru mahasiswa : ";
                cin >> newNim;
                modifyMiddle(position, newName, newNim);
                break;
            case 6:
                cout << "Masukkan nama baru mahasiswa : ";
                cin >> newName;
                cout << "Masukkan NIM baru mahasiswa : ";
                cin >> newNim;
                modifyTail(newName, newNim);
                break;
            case 7:
                deleteHead();
                break;
            case 8:
                cout << "Masukkan posisi data yang ingin dihapus : ";
                cin >> position;
                deleteMiddle(position);
                break;
            case 9:
                deleteTail();
                break;
            case 10:
                clearList();
                break;
            case 11:
                display();
                break;
            case 0:
                cout << "Program selesai. Terima kasih." << endl;
                cout << "============================================================================" << endl;
                cout << "Code by : Ardelia Rachma Laksita" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih opsi operasi yang sesuai." << endl;
                break;
        } 
        cout << "============================================================================" << endl;
        cout << endl;
    } while (pilihan != 0);

    return 0;
}

```
Penjelasan program sama seperti yang telah dijelaskan pada unguided 1. Pada unguided 2, user akan memasukkan beberapa nama menggunakan insert depan, insert tengah, dan insert belakang.

#### Output dan Interpretasi Sesuai Data yang Ditambahkan:
Data dengan nama Jawad dengan NIM 23300001 diinput menggunakan opsi 1 yaitu insert depan karena datanya ditambahkan pada depan list (head). 

![Cuplikan layar 2024-05-02 000053](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/1463885e-c255-4ed3-838d-fa57a3c27501)

Data dengan nama Ardelia dengan NIM 2311110051 diinput menggunakan opsi 2 yaitu insert tengah pada posisi 2 karena datanya ditambahkan pada tengah list. Data tersebut bisa juga ditambahkan menggunakan insert belakang karena data yang berada di posisi Tail belum diinput sehingga semua data yang diinput menggunakan insert belakang akan otomatis sesuai dengan posisinya. Hal ini juga berlaku pada data-data berikutnya hingga posisi ke 9.

![Cuplikan layar 2024-05-02 000106](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/75e53bc4-0564-4894-b17d-a6ad0ee4d997)

Data dengan nama Farrel dengan NIM 23300003 diinput menggunakan opsi 2 yaitu insert tengah pada posisi 3 karena datanya ditambahkan pada tengah list (sebelum data belakang dimasukkan).

![Cuplikan layar 2024-05-02 000203](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/74fb9637-9293-434b-83d9-f28fbd99f6ae)

Data dengan nama Denis dengan NIM 23300005 diinput menggunakan opsi 2 yaitu insert tengah pada posisi 4 karena datanya ditambahkan pada tengah list (sebelum data belakang dimasukkan).

![Cuplikan layar 2024-05-02 000216](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/57f3f845-d575-4ea7-83c1-f061b13dd616)

Data dengan nama Anis dengan NIM 23300008 diinput menggunakan opsi 2 yaitu insert tengah pada posisi 5 karena datanya ditambahkan pada tengah list (sebelum data belakang dimasukkan).

![Cuplikan layar 2024-05-02 000243](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/865028c2-9e7b-4ce6-9c0a-85926a2a1cd0)

Data dengan nama Bowo dengan NIM 23300015 diinput menggunakan opsi 2 yaitu insert tengah pada posisi 6 karena datanya ditambahkan pada tengah list (sebelum data belakang dimasukkan).

![Cuplikan layar 2024-05-02 000347](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/6bf61578-9e8f-4508-a62f-54873e2d3577)

Data dengan nama Gahar dengan NIM 23300040 diinput menggunakan opsi 2 yaitu insert tengah pada posisi 7 karena datanya ditambahkan pada tengah list (sebelum data belakang dimasukkan).

![Cuplikan layar 2024-05-02 000358](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/288cb771-a4ec-4b14-9dbb-6dd703358ca5)

Data dengan nama Udin dengan NIM 23300048 diinput menggunakan opsi 2 yaitu insert tengah pada posisi 8 karena datanya ditambahkan pada tengah list (sebelum data belakang dimasukkan).

![Cuplikan layar 2024-05-02 000411](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/351c8c94-6b2e-4085-a9cf-3e61dc7b8cdb)

Data dengan nama Ucok dengan NIM 23300050 diinput menggunakan opsi 2 yaitu insert tengah pada posisi 9 karena datanya ditambahkan pada tengah list (sebelum data belakang dimasukkan).

![Cuplikan layar 2024-05-02 000421](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/eacb0081-caa7-41f4-8fc9-e78cfdd71ef1)

Data dengan nama Budi dengan NIM 23300099 diinput menggunakan opsi 3 yaitu insert belakang karena datanya ditambahkan pada belakang list (tail). Opsi insert belakang akan sangat membantu user apabila user tidak mengetahui posisi data saat ini ada berapa karena data yang ditambahkan akan langsung ditambahkan pada data paling akhir (tail).

![Cuplikan layar 2024-05-02 000445](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/2b3d198a-de8c-4515-b48a-746e51def2f9)

Berikut merupakan tampilan seluruh data nama dan NIM mahasiswa pada list yang telah diinput sebelumnya.

![Cuplikan layar 2024-05-02 000456](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/b802c7de-0b25-4e36-9f86-c2be551f5585)

#### Full code Screenshot:
![Cuplikan layar 2024-05-02 000652](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/624b7277-e198-459f-9d61-53d7051333a8)

## Kesimpulan


## Referensi
- [1] Farrier, J., Data Structures and Algorithms with the C++ STL. Edisi Pertama. Birmingham : Packt Publishing Ltd, 2024.
- [2] Mohanty, S. N. dan Tripathy, P. K., Data Structure and Algorithms Using C++. New York City : Wiley Publishing, 2021.
- [3] Yang. F. dan Dong, Y., C++ Programming. Edisi Pertama.  Germany : De Gruyter, 2019.
