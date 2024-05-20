# <h1 align="center">Laporan Praktikum Modul Priority Queue and Heaps</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Dasar Teori](#dasar-teori)
2. [Guided](#guided)
3. [Unguided](#unguided)
4. [Kesimpulan](#kesimpulan)
5. [Referensi](#referensi)

## Dasar Teori


### Fungsi atau Kegunaan Queue:
- 

### Karakteristik Queue:



## Guided 

### 1. Program Priority Queue and Heaps
**Kode Program**
```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (1 <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = 1;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }    
    std::cout << "\n";

    std::cout << "Node with maximum priority: " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    remove(3);
    std::cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```
Kode di atas digunakan untuk mendapatkan parent node, left child node, right child node, melakukan operasi shift up dan shift down, memasukkan atau menambahkan elemen baru, mengekstrak elemen maksimum, mengubah prioritas elemen, mendapatkan elemen maksimum, serta menghapus elemen dari heap.

Berikut fungsi-fungsi yang terdapat pada program tersebut:
- - `int H[50];` dan `int heapSize = -1;` merupakan deklarasi ukuran maksimal queue tersebut dan heapSizenya.
- `int parent(int i)` digunakan untuk mendapatkan parent node.
- `int leftChild(int i)` digunakan untuk mendapatkan leftChild node dari indeks i.
- `int rightChild(int i)` digunakan untuk mendapatkan rightChild node dari indeks i.
- `void shiftUp(int i)` digunakan untuk melakukan operasi shift up pada elemen dengan indeks i. Elemen akan digerakkan ke atas heap hingga priority terpenuhi.
- `void shiftDown(int i)` digunakan untuk melakukan operasi shift down pada elemen dengan indeks i. Elemen akan digerakkan ke bawah heap hingga priority terpenuhi.
- `void insert(int p)` digunakan untuk menambahkan atau memasukkan elemen baru pada heap.
- `int extractMax()` digunakan untuk mengekstrak elemen maksimum sehingga keluar dari heap saat ini.
- `void changePriority(int i, int p) ` digunakan untuk melakukan perubahan elemen sesuai indeks yang diinginkan dan diinputkan oleh user.
- `int getMax() ` digunakan untuk mendapatkan elemen maksimum pada heap.
- `void remove(int i)` digunakan untuk menghapus suatu elemen sesuai dengan indeks yang diinputkan oleh user.
- `void addHeap(int size)` digunakan untuk menambahkan elemen-elemen pada heap sesuai dengan size yang telah diinputkan oleh user. Banyak elemen yang dimasukkan yaitu sesuai dengan ukurannya.

#### Penjelasan Main Program :
- `insert(45);`, `insert(20);`, `insert(14);`, `insert(12);`, `insert(31);`, `insert(7);`, `insert(11);`, `insert(13);`, dan `insert(7);` digunakan untuk menambahkan elemen ke dalam heap sehingga saat ini ada 9 elemen di dalam heap yaitu 45, 20, 14, 12, 31, 7, 11, 13, dan 7.
- `std::cout << "Priority Queue: ";` dan `for (int i = 0; i <= heapSize; ++i)` digunakan untuk menampilkan Priority Queue saat ini.
- **"Node with maximum priority: "** digunakan untuk menampilkan node yang memiliki nilai maximum priority, artinya nilainya paling besar. Kemudian, cara untuk menampilkannya adalah dengan memanggil fungsi `extractMax()`. Selanjutnya node yang memiliki nilai maximum akan diekstrak sehingga dihapus dari heap.
- `cout << "Priority queue after extracting maximum: "` dan perulangan for `for (int i = 0; i <= heapSize; ++i)` pada line setelah kode cout tersebut digunakan untuk menampilkan Priority queue setelah node maksimumnya diesktrak sehingga pada heap saat ini memiliki nilai maksimum yang baru.
- `changePriority(2, 49);` artinya indeks 2 pada heap saat ini akan diubah menjadi 49.
- `std::cout << "Priority queue after priority change: ";` dan perulangan `for (int i = 0; i <= heapSize; ++i)` digunakan untuk menampilkan Priority Queue setelah ada elemen yang diubah.
- `remove(3);` artinya program akan menghapus elemen pada indeks ke 3 heap saat ini.
- `std::cout << "Priority queue after removing the element: ";` dan perulangan `for (int i = 0; i <= heapSize; ++i)` digunakan untuk menampilkan Priority Queue setelah elemen pada indeks 3 dihapus.
- `cout << "\n"` digunakan untuk mencetak space sebanyak 1 line sebelum atau sesudah suatu tampilan output. 

#### Output Guided 1:
![Cuplikan layar 2024-05-20 075357](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/92f6f066-2d92-459c-89bd-eaf3d7c20d60)


## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.
**Kode Program**
```C++
#include <iostream>
#include <algorithm>
using namespace std;

// deklarasi ukuran maksimal H dan deklarasi heapSize
int H[50];
int heapSize = -1;

// fungsi void untuk dapatkan parent node
int parent(int i) {
    return (i - 1) / 2;
}

// fungsi void untuk dapatkan leftChiled node dari indeks i
int leftChild(int i) {
    return ((2 * i) + 1);
}

// fungsi void untuk dapatkan rightChild node dari indeks i
int rightChild(int i) {
    return ((2 * i) + 2);
}

// fungsi void untuk lakukan operasi shift up pada elemen dengan indeks i (elemen digerakkan ke atas heap)
void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

// fungsi void untuk lakukan operasi shift down pada elemen dengan indeks i (elemen digerakkan ke bawah heap)
void shiftDown(int i) {
    // deklarasi maxIndex
    int maxIndex = i;
    int l = leftChild(i);
    // jika leftChild (l) lebih kecil dari heapSize dan H[l] > H[maxindex]
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    // jika rightChild (r) lebih kecil dari heapSize dan H[r] > H[maxindex]
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    // jika indeks tidak sama dengan maxIndex
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

// fungsi void untuk tambahkan elemen baru 
void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

// fungsi void untuk ekstrak (keluarkan) elemen maksimal dimana nilainya paling besar
int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

// fungsi void untuk ubah priority elemen
void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

// mendapatkan elemen maksimum dari heap
int getMax() {
    return H[0];
}

// fungsi void untuk hapus elemen dari heap
void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

// fungsi void untuk atur ukuran elemen dan isi elemen di dalam heap oleh input user
void addHeap(int size) {
    for (int i = 0; i < size; i++) {
        int element;
        cout << "Enter element " << (i + 1) << ": ";
        cin >> element;
        insert(element);
    }
}

// main program (program utama)
int main() {
    // deklarasi a
    int a;
    // user input ukuran elemen (banyak elemen yang diinginkan)
    cout << "Enter the size of elements: ";
    cin >> a;
    // memanggil fungsi addHeap
    addHeap(a);

    // tampilkan priority queue dari elemen yang telah diinput user
    cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // tampilkan node yang memiliki maximum priority dengan memanggil fungsi extractMax
    cout << "Node with maximum priority: " << extractMax() << "\n";

    // tampilkan priority queue setelah ekstrak elemen maximum"
    cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // deklarasi index dan newPriority
    int indeks, newPriority;
    // user input index elemen yang ingin diubah
    cout << "Enter the Index of the priority you want to change: ";
    cin >> indeks;
    // user input new priority untuk menggantikan elemen pada index yang telah diinput
    cout << "Enter the new priority: ";
    cin >> newPriority;
    // memanggil fungsi changePriority untuk ubah elemen
    changePriority(indeks, newPriority);

    // tampilkan Priority queue setelah elemen diperbarui
    cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // deklarasi removeElement
    int removeElement;
    // user input indeks dari elemen yang ingin dihapus
    cout << "Enter the Indeks of the element you want to remove: ";
    cin >> removeElement;
    // panggil fungsi remove untuk hapus elemen
    remove(removeElement);

    // tampilkan Priority Queue setelah elemen dihapus
    cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    return 0;
}

```

Kode tersebut digunakan untuk mendapatkan parent node, left child node, right child node, melakukan operasi shift up dan shift down, memasukkan atau menambahkan elemen baru, mengekstrak elemen maksimum, mengubah prioritas elemen, mendapatkan elemen maksimum, serta menghapus elemen dari heap menggunakan input user. Program tersebut hampir sama seperti Guided 1. Yang membedakan adalah program ini menggunakan input user karena heapnya telah dikonstruksi secara manual berdasarkan user. Pada Guided 1, semua elemen dan indeks yang ingin ditambah (insert), diubah (change), dihapus (remove), dan lain-lain langsung dimasukkan dalam program sehingga user tidak melakukan input pada output. Sedangkan pada unguided 1, user perlu memasukkan size elemen, elemen-elemen, dan input-inut lain sesuai dengan operasi yang diminta. 

#### Penjelasan Kode:
Berikut kode-kode dan fungsi yang terdapat pada program tersebut (sama seperti guided 1):
- `int H[50];` dan `int heapSize = -1;` merupakan deklarasi ukuran maksimal queue tersebut dan heapSizenya.
- `int parent(int i)` digunakan untuk mendapatkan parent node.
- `int leftChild(int i)` digunakan untuk mendapatkan leftChild node dari indeks i.
- `int rightChild(int i)` digunakan untuk mendapatkan rightChild node dari indeks i.
- `void shiftUp(int i)` digunakan untuk melakukan operasi shift up pada elemen dengan indeks i. Elemen akan digerakkan ke atas heap hingga priority terpenuhi.
- `void shiftDown(int i)` digunakan untuk melakukan operasi shift down pada elemen dengan indeks i. Elemen akan digerakkan ke bawah heap hingga priority terpenuhi.
- `void insert(int p)` digunakan untuk menambahkan atau memasukkan elemen baru pada heap.
- `int extractMax()` digunakan untuk mengekstrak elemen maksimum sehingga keluar dari heap saat ini.
- `void changePriority(int i, int p) ` digunakan untuk melakukan perubahan elemen sesuai indeks yang diinginkan dan diinputkan oleh user.
- `int getMax() ` digunakan untuk mendapatkan elemen maksimum pada heap.
- `void remove(int i)` digunakan untuk menghapus suatu elemen sesuai dengan indeks yang diinputkan oleh user.
- `void addHeap(int size)` digunakan untuk menambahkan elemen-elemen pada heap sesuai dengan size yang telah diinputkan oleh user. Banyak elemen yang dimasukkan yaitu sesuai dengan ukurannya.

#### Penjelasan Main Program:
- `int a;` merupakan deklarasi dari a yang akan digunakan untuk menginput ukuran elemen (banyak elemen) yang diinginkan.
- `cout << "Enter the size of elements: ";` dan `cin >> a;` akan meminta user untuk memasukkan ukuran (size) elemen.
- `addHeap(a);` adalah fungsi yang dipanggil untuk menambahkan elemen sesuai dengan banyak ukuran yang telah diinput.
- **"Node with maximum priority: "** digunakan untuk menampilkan node yang memiliki nilai maximum priority, artinya nilainya paling besar. Kemudian, cara untuk menampilkannya adalah dengan memanggil fungsi `extractMax()`. Selanjutnya node yang memiliki nilai maximum akan diekstrak sehingga dihapus dari heap.
- `cout << "Priority queue after extracting maximum: "` dan perulangan for `for (int i = 0; i <= heapSize; ++i)` pada line setelah kode cout tersebut digunakan untuk menampilkan Priority queue setelah node maksimumnya diesktrak sehingga pada heap saat ini memiliki nilai maksimum yang baru.
- `int indeks, newPriority;` merupakan deklarasi index dan newPriority dimana variabel tersebut dibutuhkan untuk menjalankan program perubahan priority (changePriority).
- `cout << "Enter the Index of the priority you want to change: ";` dan `cin >> indeks` akan meminta user untuk memasukkan indeks dari elemen yang ingin diubah.
- `cout << "Enter the new priority: ";` dan `cin >> newPriority;` akan meminta user untuk memasukkan elemen baru sesuai pada indeks yang telah diinput sebelumnya.
- `changePriority(indeks, newPriority);` adalah fungsi yang dipanggil untuk melakukan changePriority atau perubahan elemen.
- `cout << "Priority queue after priority change: ";` dan `for (int i = 0; i <= heapSize; ++i)` digunakan untuk menampilkan Priority queue setelah ada elemen yang diubah sebelumnya.
- `int removeElement;` merupakan deklarasi removeElement yang akan digunakan untuk program menghapus elemen.
- `cout << "Enter the Indeks of the element you want to remove: ";` dan `cin >> removeElement;` digunakan untuk menghapus elemen sesuai dengan indeks yang diinput oleh user. Indeks dimulai dari 0. Elemen maksimalnya berada pada indeks **Size Element - 1**. Misalnya, ada 10 elemen pada suatu heap, maka indeksnya adalah 0 hingga 9.
- `cout << "Priority queue after removing the element: ";` dan`for (int i = 0; i <= heapSize; ++i)` digunakan untuk menampilkan elemen saat ini setelah ada elemen yang dihapus.
- `cout << "\n"` digunakan untuk mencetak space sebanyak 1 line sebelum atau sesudah suatu tampilan output. 

#### Output:
![Cuplikan layar 2024-05-20 085503](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/ac6672b0-a919-45d8-aa1f-79c6ab7d2c82)

**Penjelasan Output :**

![Cuplikan layar 2024-05-20 120411](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/595fe6bc-45fa-4412-8d40-d52a17ca9091)

Pada output tersebut, user melakukan input dengan ukuran elemen (banyak elemen) adalah 10 menggunakan **"Enter the size of element: "**. Selanjutnya, program akan melakukan iterasi sebanyak elemen yang telah diinputkan. Program akan meminta user memasukkan elemen sebanyak 10 pada bagian **"Enter element ...: "** (elemen 1 hingga 10). Kemudian, program akan menampilkan seluruh elemen yang telah diinput dengan tampilan **"Priority Queue: "**. User memasukkan elemen-elemen berikut.
- Enter element 1 : 10
- Enter element 2 : 9
- Enter element 3 : 8
- Enter element 4 : 7
- Enter element 5 : 6
- Enter element 6 : 5
- Enter element 7 : 4
- Enter element 8 : 3
- Enter element 9 : 2
- Enter element 10 : 1

![Cuplikan layar 2024-05-20 120610](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/186ac088-ff58-4e01-b860-afe135ee05c2)

Node with maximum prioritynya adalah 10. Selanjutnya, 10 diesktrak sehingga tidak ada lagi di dalam heap.

![Cuplikan layar 2024-05-20 120620](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/8e83b065-3121-4b31-846f-5b6b3d3f0232)

Pada output tersebut, elemen yang ingin diubah menggunakan changePriority adalah indeks ke-2 yaitu 8 menjadi 11 sehingga menghasilkan tampilan di atas.

![Cuplikan layar 2024-05-20 120633](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/925e50ad-6ee5-413c-a03a-307e959c3368)

Pada output tersebut, elemen yang dihapus berada pada index ke-1 yaitu 7. 7 dihapus dari heap tersebut.

#### Full code Screenshot:
![Cuplikan layar 2024-05-20 085437](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/02323af2-db95-4618-b354-23d80a274aea)


## Kesimpulan
Kesimpulan yang dapat diambil dari praktikum modul Priority Queue and Heap adalah ...

## Referensi
- 
