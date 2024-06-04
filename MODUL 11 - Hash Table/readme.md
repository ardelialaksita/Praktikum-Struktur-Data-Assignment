# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Dasar Teori](#dasar-teori)
2. [Guided](#guided)
3. [Unguided](#unguided)
4. [Kesimpulan](#kesimpulan)
5. [Referensi](#referensi)

## Dasar Teori


### Tujuan Hash Table:


### Kelebihan dan Kekurangan Hash Table:


### Implementasi Hash Table:



## Guided 

### Guided 1
**Kode Program**
```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) { // apabila current tidak kosong
                cout << current->key << ": " << current->value << endl;
                current = current->next; // perbarui nilai value
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    
    // Deletion
    ht.remove(4);
    
    // Traversal
    ht.traverse();
    
    return 0;
}

```
Kode di atas digunakan untuk untuk menyisipkan, mencari, menghapus, dan menampilkan elemen-elemen dalam tabel hash. Terdapat beberapa fungsi sebagai bentuk implementasinya, antara lain sebagai berikut.

- `int hash_func(int key)` merupakan fungsi hash sederhana yang digunakan untuk menghitung indeks untuk kunci yang diberikan dengan cara mengambil sisa bagi kunci tersebut dengan ukuran maksimum tabel hash (MAX_SIZE).
- `struct Node` merupakan struct merepresentasikan setiap elemen dalam tabel hash. Setiap node menyimpan key, value, dan pointer next yang menunjuk ke node berikutnya. Hash table membutuhkan parameter key untuk operasi kuncinya.
- `class HashTable` merupakan class yang menjadi bentuk implementasi dari hash table sederhana. Private classnya menyimpan deklaras `Node** table;`. Public classnya berisi perulangan for `for (int i = 0; i < MAX_SIZE; i++) ` yang akan menginisialisasi tabel dengan ukuran MAX_SIZE dan membersihkan memori yang digunakan oleh tabel hash dengan menghapus setiap node yang ada.
- `void insert(int key, int value)` digunakan untuk menambahkan elemen baru ke dalam hash table. ` if (current->key == key)` artinya jika saat ini sudah ada key, maka nilai akan diperbarui. `current = current->next;` artinya, apabila belum ada elemen key, maka node baru akan ditambahkan di awal list sesuai indeksnya.
- `int get(int key)` digunakan untuk mendapatkan suatu nilai berdasarkan key. Apabila node saat ini sama dengan key, maka akan menjalankan `return current->value;` yaitu mengembalikan nilai. Sedangkan apabila key belum didapatkan, maka akan menjalankan `return -1`.
- `void remove(int key)` digunakan untuk menghapus elemen berdasarkan key.
- `void traverse()` digunakan untuk mencetak semua elemen dalam hash table.

#### Penjelasan Main Program:
- `ht.insert(1, 10);`, `ht.insert(2, 20);`, dan `ht.insert(3, 30);` akan menambahkan elemen ke dalam hash table. Key pertama adalah 10, key kedua adalah 20, dan key ketiga adalah 30. `cout << "Get key 1: " << ht.get(1) << endl;` dan `cout << "Get key 4: " << ht.get(4) << endl;` akan mencetak key yang ingin didapatkan atau dicari menggunakan get. Get key 1 adalah 10 karena key 1 adalah 10. Sedangkan Get key 4 adalah -1 karena tidak ada key 4 sehingga menjalankan return -1.
- `ht.remove(4);` digunakan untuk menghapus key 4 sehingga -1 dihapus dan hanya ada key 1 hingga 3.
- `ht.traverse();` digunakan untuk menampilkan isi hash table.
- `return 0;` artinya program telah sukses dan berhasil.

#### Output Guided 1:


### Guided 2 
**Kode Program**
```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}

```
Kode di atas digunakan untuk merepresentasikan setiap node pada hash table dimana terdapat nama dan nomor telepon karyawan. 

#### Penjelasan Main Program:


## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :

a.	Setiap mahasiswa memiliki NIM dan nilai.

b.	Program memiliki tampilan pilihan menu berisi poin C.

c.	Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

**Kode Program**
```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// struktur data untuk setiap node
struct Node {
    long long NIM;
    int nilai;
    Node* next;
    Node(long long NIM, int nilai) : NIM(NIM), nilai(nilai), next(NULL) {}
};

// class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // insertion
    void insert(long long NIM, int nilai) {
        int index = hash_func(NIM);
        Node* current = table[index];
        while (current != NULL) {
            if (current->NIM == NIM) {
                current->nilai = nilai;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(NIM, nilai);
        node->next = table[index];
        table[index] = node;
    }

    // searching berdasarkan NIM
    int get(long long NIM) {
        int index = hash_func(NIM);
        Node* current = table[index];
        while (current != NULL) {
            if (current->NIM == NIM) {
                return current->nilai;
            }
            current = current->next;
        }
        return -1; // Tidak ditemukan
    }

    // menghapus berdasarkan NIM
    void remove(long long NIM) {
        int index = hash_func(NIM);
        Node* current = table[index];
        Node* prev = NULL;
        while (current != NULL) {
            if (current->NIM == NIM) {
                if (prev == NULL) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // searching berdasarkan nilai
    void getNilai(int min, int max) {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != NULL) {
                if (current->nilai >= min && current->nilai <= max) {
                    cout << "NIM: " << current->NIM << ", Nilai: " << current->nilai << endl;
                }
                current = current->next;
            }
        }
    }

    // traversal untuk menampilkan hash table
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != NULL) {
                cout << "NIM: " << current->NIM << ", Nilai: " << current->nilai << endl;
                current = current->next;
            }
        }
    }
};

void optionMenu() {
    cout << "================ PROGRAM DATA MAHASISWA ==================" << endl;
    cout << "1. Tambah data mahasiswa" << endl;
    cout << "2. Hapus data mahasiswa" << endl;
    cout << "3. Cari data mahasiswa berdasarkan NIM" << endl;
    cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80-90)" << endl;
    cout << "5. Tampilkan semua data mahasiswa" << endl;
    cout << "6. Keluar" << endl;
    cout << "Opsi mana yang ingin Anda pilih? : ";
}

// program utama (main program)
int main() {
    HashTable ht;
    int option, NIM, nilai;

    while (true) {
        optionMenu();
        cin >> option;
        switch (option) {
            // insert data mahasiswa berisi NIM dan nilai
            case 1:
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                ht.insert(NIM, nilai);
                break;
            // hapus data mahasiswa
            case 2:
                cout << "Masukkan NIM yang ingin dihapus: ";
                cin >> NIM;
                ht.remove(NIM);
                break;
            // cari data mahasiswa berdasarkan NIM
            case 3:
                cout << "Masukkan NIM yang ingin dicari: ";
                cin >> NIM;
                nilai = ht.get(NIM);
                if (nilai != -1) {
                    cout << "Nilai Mahasiswa dengan NIM " << NIM << " adalah " << nilai << endl;
                } else {
                    cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
                }
                break;
            // cari data mahasiswa berdasarkan nilai
            case 4:
                cout << "Mahasiswa dengan nilai antara 80 dan 90:" << endl;
                ht.getNilai(80, 90);
                break;
            // tampilkan seluruh data mahasiswa
            case 5:
                cout << "Data seluruh mahasiswa:" << endl;
                ht.traverse();
                break;
            // return
            case 6:
                return 0;
            // apabila user input pilihan selain 1-6
            default:
                cout << "Pilihan yang Anda masukkan tidak valid." << endl;
        }
        cout << endl;
    }
}

```

Kode tersebut digunakan untuk menambahkan, menghapus, dan mencari data NIM dan nilai mahasiswa berdasarkan NIM dan rentang nilainya. Terdaoat program menu dengan 6 case. 

#### Penjelasan Kode:
- `int hash_func(int key)` merupakan fungsi hash sederhana yang digunakan untuk menghitung indeks untuk kunci yang diberikan dengan cara mengambil sisa bagi kunci tersebut dengan ukuran maksimum tabel hash (MAX_SIZE).
- `struct Node` merupakan struct merepresentasikan setiap elemen dalam tabel hash. Setiap node menyimpan NIM, nilai, dan pointer next yang menunjuk ke node berikutnya. Hash table membutuhkan parameter key untuk operasi kuncinya.
- `class HashTable` merupakan class yang menjadi bentuk implementasi dari hash table sederhana. Private classnya menyimpan deklaras `Node** table;`. Public classnya berisi perulangan for `for (int i = 0; i < MAX_SIZE; i++) ` yang akan menginisialisasi tabel dengan ukuran MAX_SIZE dan membersihkan memori yang digunakan oleh tabel hash dengan menghapus setiap node yang ada.
- `void insert(long long NIM, int nilai)` digunakan untuk menambahkan elemen baru ke dalam hash table. ` if (current->NIM == NIM)` artinya jika saat ini sudah ada NIMnya (bukan NULL), maka nilai akan diperbarui. `current = current->next;` artinya, apabila belum ada NIM, maka node baru akan ditambahkan di awal list sesuai indeksnya. Hal yang sama juga berlaku pada `current->nilai = nilai;`
- `int get(long long NIM)` digunakan untuk mendapatkan suatu nilai berdasarkan NIM. Apabila node saat ini sama dengan NIM, maka akan menjalankan `return current->nilai;` yaitu mengembalikan nilai. Sedangkan apabila NIM belum didapatkan, maka akan menjalankan `return -1`.
- `void remove(long long NIM)` digunakan untuk menghapus data berdasarkan NIM yang dimasukkan.
- `void getNilai(int min, int max)` digunakan untuk mendapatkan atau mencari data berdasarkan nilai dengan rentang 80-90.
- `void traverse()` digunakan untuk mencetak semua elemen dalam hash table.
- `void optionMenu()` berisi program menu yang akan ditampilkan untuk dipilih oleh user. Terdapat 5 menu yang dapat dilakukan oleh user beserta 1 opsi keluar apabila user ingin keluar dari program.

#### Penjelasan Main Program:
- `HashTable ht;` dan `int option, NIM, nilai;` merupakan deklarasi.
- `optionMenu()` digunakan untuk memanggil prorgam menu dan meminta user memasukkan option menggunakan `cin >> option;`.
- Pada `switch (option)` terdapat beberapa case. Case 1 akan menambahkan data mahasiswa berisi NIM dan nilai. Case 2 akan menghapus data mahasiswa meggunakan NIM yang dimasukkan. Case 3 akan melakukan pencarian (searching) data mahasiswa berdasarkan NIM. Case 4 akan melakukan pencarian (searching) data mahasiswa berdasarkan rentang nilai (80-90). Case 5 akan menampilkan seluruh data menggunakan traverse. Case 6 merupakan menu keluar dari program (selesai). Apabila pilihan yang dimasukkan selain 1, 2, 3, 4, 5, 6, maka akan menampilkan "Pilihan yang Anda masukkan tidak valid".

#### Output:


**Penjelasan Output:**


#### Full code Screenshot:



## Kesimpulan
Kesimpulan yang dapat diambil dari praktikum modul Hash Table adalah 

## Referensi
- [1] 
