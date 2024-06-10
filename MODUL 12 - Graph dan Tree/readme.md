# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Dasar Teori](#dasar-teori)
2. [Guided](#guided)
3. [Unguided](#unguided)
4. [Kesimpulan](#kesimpulan)
5. [Referensi](#referensi)

## Dasar Teori


### Implementasi Hash Table:


## Guided 

### Guided 1
**Kode Program**
```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0,7,8,0,0,0,0},
    {0,0,5,0,0,15,0},
    {0,6,0,0,5,0,0},
    {0,5,0,0,2,4,0},
    {23,0,0,10,0,0,8},
    {0,0,0,0,7,0,3},
    {0,0,0,0,9,4,0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if(busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}

```
Kode di atas digunakan untuk untuk 

#### Penjelasan Main Program:
- 

#### Output Guided 1:
![output guided 1](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/64f59476-7943-4182-849f-997acd4f2039)

### Guided 2 
**Kode Program**
```C++
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor(untuk membuat objek, otomatis dijalankan)
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main() {
    TNode *zero = new TNode(0);\
    // 0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    // 7
    // /\
    // 1 NULL

    seven->right = nine;
    // 7
    // /\
    // 1 9

    one->left = zero;
    // 7
    // /\
    // 1 9
    // /\
    // 0 NULL

    one->right = five;
    // 7 
    // /\
    // 1 9
    // /\

    nine->left = eight;
    // 7
    // /\
    // 1 9
    // /\  /\
    // 0 5 8 NULL

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;

    
    return 0;
}

```
Kode di atas digunakan untuk 

#### Output Guided 2:
![output guided 2](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/fecb802c-b270-4e15-b4f2-bf6767cabd51)


## Unguided 
*Cantumkan NIM pada salah satu variabel di dalam program.
Contoh : int nama_22102003;

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
![soal unguided 1](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/76570b22-3c2b-47f5-bc50-0e0e7b40f065)

**Kode Program**
```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// menyimpan deklarasi dalam struct
struct Graph {
    vector<string> simpul;
    vector<vector<int>> bobotAntarSimpul;
    int jumlahSimpul;
};

// fungsi void untuk menampilkan graph
void tampilkanGraph(const Graph& Ardelia_2311110051) {
    cout << "Simpul\t";

    // perulangan for untuk menampilkan 'Simpul' sesuai jumlah simpul yang diinput user
    for (int i = 0; i < Ardelia_2311110051.jumlahSimpul; ++i) {
        cout << Ardelia_2311110051.simpul[i] << "\t";
    }
    cout << endl;

    // perulangan for untuk menampilkan dan memasukkan bobot antar simpul sesuai jumlah simpul
    for (int i = 0; i < Ardelia_2311110051.jumlahSimpul; ++i) {
        cout << Ardelia_2311110051.simpul[i] << "\t";
        for (int j = 0; j < Ardelia_2311110051.jumlahSimpul; ++j) {
            cout << Ardelia_2311110051.bobotAntarSimpul[i][j] << "\t";
        }
        cout << endl;
    }
}

// main program (program utama)
int main() {
    // variable Ardelia_2311110051 akan memanggil kode program di dalam Graph
    Graph Ardelia_2311110051;

    // user memasukkan jumlah simpul
    cout << "Silakan masukan jumlah simpul : ";
    cin >> Ardelia_2311110051.jumlahSimpul;

    // user memasukkan nama simpul
    Ardelia_2311110051.simpul.resize(Ardelia_2311110051.jumlahSimpul);
    cout << "Silakan masukan nama simpul" << endl;
    for (int i = 0; i < Ardelia_2311110051.jumlahSimpul; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> Ardelia_2311110051.simpul[i];
    }

    // user memasukkan bobot antar simpul
    Ardelia_2311110051.bobotAntarSimpul.resize(Ardelia_2311110051.jumlahSimpul, vector<int>(Ardelia_2311110051.jumlahSimpul, 0));
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < Ardelia_2311110051.jumlahSimpul; ++i) {
        for (int j = 0; j < Ardelia_2311110051.jumlahSimpul; ++j) {
            // menampilkan kota satu ke kota lain untuk disesuaikan bobotnya
            cout << Ardelia_2311110051.simpul[i] << " --> " << Ardelia_2311110051.simpul[j] << " = ";
            cin >> Ardelia_2311110051.bobotAntarSimpul[i][j];
        }
    }

    // panggil fungsi tampilkanGraph untuk menampilkan seluruh simpul beserta bobotnya
    tampilkanGraph(Ardelia_2311110051);

    cout << endl;

    // return sebagai kode bahwa program telah selesai dan berhasil
    return 0;
}

```

Kode tersebut digunakan untuk 

#### Penjelasan Kode:
-

#### Penjelasan Main Program:
-

#### Output dan Penjelasan:


#### Full code Screenshot:


### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!
**Kode Program**
```C++

```

Kode tersebut digunakan untuk 

#### Penjelasan Kode:
-

#### Penjelasan Main Program:
-

#### Output dan Penjelasan:


#### Full code Screenshot:



## Kesimpulan
Kesimpulan yang dapat diambil dari praktikum modul Graph dan Tree adalah 

## Referensi
- [1] 
