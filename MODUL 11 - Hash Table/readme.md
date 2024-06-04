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

### 1. 
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
- `struct Node` merupakan struct merepresentasikan setiap elemen dalam tabel hash. Setiap node menyimpan key, value, dan pointer next yang menunjuk ke node berikutnya. Hash tablemembutuhkan parameter key untuk operasi kuncinya.
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


### 2. 
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
Kode di atas digunakan untuk 

#### Penjelasan Main Program:


## Unguided 

### 1. 
**Kode Program**
```C++

```

Kode tersebut digunakan untuk 

#### Penjelasan Main Program:


#### Output:


**Penjelasan Output:**


#### Full code Screenshot:



## Kesimpulan
Kesimpulan yang dapat diambil dari praktikum modul Hash Table adalah 

## Referensi
- [1] 
