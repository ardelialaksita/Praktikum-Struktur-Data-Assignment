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

```

#### Output:
- Tampilan Menu :
- Tampilan Operasi Tambah :
- Tampilan Operasi Hapus :
- Tampilan Operasi Ubah :
- Tampilan Operasi Tampil Data :

Kode tersebut digunakan untuk 

#### Penjelasan main program:
 

#### Penjelasan input oleh user:


#### Full code Screenshot:


### 2. Apa yang terjadi jika deklarasi variabel _struct_ yang dibuat pada tugas guided I berjenis _Array_. Bagaimana cara mengisi data dan menampilkannya?
```C++

```

#### Output:


Kode tersebut digunakan untuk 

#### Penjelasan main program:


#### Penjelasan input oleh user:


#### Full code Screenshot:



## Kesimpulan


## Referensi
- [1] Farrier, J., Data Structures and Algorithms with the C++ STL. Edisi Pertama. Birmingham : Packt Publishing Ltd, 2024.
- [2] Mohanty, S. N. dan Tripathy, P. K., Data Structure and Algorithms Using C++. New York City : Wiley Publishing, 2021.
<<<<<<< HEAD
- [3] Yang. F. dan Dong, Y., C++ Programming. Edisi Pertama.  Germany : De Gruyter, 2019.
=======
- [3] Yang. F. dan Dong, Y., C++ Programming. Edisi Pertama.  Germany : De Gruyter, 2019.
>>>>>>> 7b6ff7b21a8aa31d6fb652efbb61d2b5b6fe5fa7
