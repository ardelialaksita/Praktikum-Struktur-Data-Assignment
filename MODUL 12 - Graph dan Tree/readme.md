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

### Guided 1 : Graf (Graph)
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
Kode di atas digunakan untuk untuk menampilkan bobot atau jarak antar kota (simpul) dalam bentuk graf yang mudah dibaca. `string simpul[7]` berisi nama-nama kota (simpul) dalam graf tersebut. `int busur[7][7]` digunakan untuk menyimpan bobot atau jarak antar kota dimana kotanya dilihat melalui `simpul[i]` ke kota `simpul[j]`. `if(busur[baris][kolom] !=0 )` akan menampilkan nama kota yang dituju beserta jaraknya. 0 menandakan bahwa jarak antar kedua kota tidak berkaitan. `void tampilGraph()` digunakan untuk menampilkan graf yang terdiri atas kota beserta bobot (jarak)nya. Pada main program, hanya terdapat `tampilGraph()` yang digunakan untuk memanggil fungsi tampilGraph() sehingga graf kota dan jarak antar kota ditampilkan. `return 0;` artinya program tersebut telah selesai dan berhasil.

#### Output Guided 1:
![output guided 1](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/64f59476-7943-4182-849f-997acd4f2039)

### Guided 2 : Pohon (Tree)
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
    TNode *zero = new TNode(0);
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
Kode di atas digunakan untuk menampilkan suatu pohon (tree) menggunakan traversal yaitu pre-order, in-order, dan post-order. Terdapat node root, subtrees kiri, dan subtrees kanan. Pointer kiri dan kanan disimpan di dalam struct TNode dimana `TNode *left;` merupakan pointer ke kiri, sedangkan `TNode *right` merupakan poiter ke kanan. `TNode(int value)` merupakan constructor yang berisi deklarasi dari data, left, dan right. 

#### Penjelasan Traversal:
- **Pre-Order Traversal** akan melihat node dari root, dilanjutkan ke subtrees kiri (left), dan terakhir ke subtrees kanan (right).
- **In-Order Traversal** akan melihat node dari subtrees kiri (left), dilanjutkan ke root, dan terakhir ke subtrees kanan (right).
- **Post-Order Traversal** akan melihat node dari subtrees kiri (left), dilanjutkan ke subtrees kanan (right), dan terakhir ke root.

#### Penjelasan Main Program:
- `TNode *zero = 0` artinya membuat node root atau parents dengan nilai child nodenya adalah NULL.
- `TNode *one = new TNode(1);`, `TNode *five = new TNode(5);`, `TNode *seven = new TNode(7);`, `TNode *eight = new TNode(8);`, dan `TNode *nine = new TNode(9);` digunakan untuk menambahkan node baru yaitu 1, 5, 7, 8, dan 9. Selanjutnya adalah tahap penyusunan pohon (tree).
- `seven->left = one;` artinya menambahkan 1 sebagai child node pada sisi kiri dari parents node 7.
- `seven->right = nine;` artinya menambahkan 9 sebagai child node pada sisi kanan dari parents node 7.
- `one->left = zero;` artinya menambahkan 0 sebagai child node pada sisi kiri dari parents node 1.
- `one->right = five;` artinya menambahkan 5 sebagai child node pada sisi kanan dari parents node 1.
- `nine->left = eight;` artinya menambahkan 8 sebagai child node pada sisi kiri dari parents node 8. Sedangkan sisi kanannya tidak memiliki nilai (NULL).
- `preOrder(seven);` digunakan untuk memanggil fungsi preOrder dengan nilai node 7 sehingga program menampilkan root, subtrees kiri, dan subtrees kanan dari root node 7. Outputnya adalah 7, 1, 0, 5, 9, 8.
- `inOrder(seven);` digunakan untuk memanggil fungsi inOrder dengan nilai node 7 sehingga program menampilkan subtrees kiri, root, dan subtrees kanan dari root node 7. Outputnya adalah 0, 1, 5, 7, 8, 9.
- `postOrder(seven);` digunakan untuk memanggil fungsi postOrder dengan nilai node 7 sehingga program menampilkan subtrees kiri, subtrees kanan, dan root dari root node 7. Outputnya adalah 0, 5, 1, 8, 9, 7.

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

Kode tersebut digunakan untuk menghitung jarak dari sebuah kota ke kota lainnya. Jarak terkecilnya dilihat melalui bobot yang paling kecil antar kota. Simpul sebagai nama dari sebuah kota. Kemudian, user akan diminta memasukkan nama dan bobot antar kota tersebut karena program ini menggunakan input user. 

#### Penjelasan Kode:
- `struct Graph` menyimpan deklarasi dari simpul, jumlah simpul, dan bobot antar simpul.
- `void tampilkanGraph(const Graph& Ardelia_2311110051)` merupakan fungsi yang akan dipanggil untuk menampilkan seluruh graph beserta bobotnya.
- `cout << Ardelia_2311110051.simpul[i] << "\t";` di dalam perulangan for digunakan untuk menampilkan simpul sesuai jumlah yang telah diinputkan untuk user memasukkan nama dan bobot antar simpulnya.

#### Penjelasan Main Program:
- `Graph Ardelia_2311110051;` artinya variable Ardelia_2311110051 akan memanggil kode-kode program yang ada di dalam Graph.
- `cout << "Silakan masukan jumlah simpul : ";` dan `cin >> Ardelia_2311110051.jumlahSimpul;` meminta user untuk memasukkan jumlah simpul.
- `cout << "Silakan masukan nama simpul" << endl;` dan perulangan `for (int i = 0; i < Ardelia_2311110051.jumlahSimpul; ++i)` meminta user untuk memasukkan nama simpul sebanyak jumlah yang telah diinputkan sebelumnya.
- `cout << "Silakan masukkan bobot antar simpul" << endl;` dan perulangan `for (int i = 0; i < Ardelia_2311110051.jumlahSimpul; ++i)` meminta user memasukkan bobot antar simpul.
- `tampilkanGraph(Ardelia_2311110051);` memanggil fungsi tampilkanGraph untuk menampilkan seluruh simpul beserta bobotnya.
- `return 0;` sebagai kode bahwa program telah selesai dan berhasil.

#### Output dan Penjelasan:
![output unguided 1](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/ddc37b42-06a6-427c-9447-92079bc9e31f)

Pada output di atas, user memasukkan jumlah simpulnya ada 2 sehingga program akan meminta user memasukkan 2 nama simpul. User memasukkan BALI sebagai nama dari simpul 1 dan PALU sebagai nama dari simpul 2. Selanjutnya, program meminta user memasukkan bobot antar simpul sesuai yang ditampilkan program. User memasukkan 0,3,4, dan 0 seperti output di atas. Terakhir, program menampilkan graph yang berisi nama dan bobot antar simpul.

#### Full code Screenshot:
![full ss unguided 1](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/6af4635f-0c60-4ada-b1af-57c587b6bd28)


### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!
**Kode Program**
```C++
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// menyimpan deklarasi dalam struct TNode
struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// melihat node dari root, subtree kiri, dan terakhir ke subtree kanan
void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// melihat node dari subtree kiri, root, dan terakhir ke subtree kanan
void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

// melihat node dari subtree kiri, subtree kanan, dan terakhir ke root
void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

// melakukan pencarian pada suatu node berdasarkan nilai
TNode* search_Ardelia_2311110051(TNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    TNode* leftSearch = search_Ardelia_2311110051(root->left, value);
    if (leftSearch != NULL) return leftSearch;
    return search_Ardelia_2311110051(root->right, value);
}

// menambahkan node
void addNode(TNode* &root, int parentValue, int value, char child) {
    TNode* parent = search_Ardelia_2311110051(root, parentValue);
    if (parent == NULL) {
        cout << "Parent node not found!" << endl;
        return;
    }
    if (child == 'L') {
        if (parent->left == NULL) {
            parent->left = new TNode(value);
        } else {
            cout << "Left child already exists!" << endl;
        }
    } else if (child == 'R') {
        if (parent->right == NULL) {
            parent->right = new TNode(value);
        } else {
            cout << "Right child already exists!" << endl;
        }
    } else {
        cout << "Invalid child type!" << endl;
    }
}

// tampilkan child dari node
void tampilkanChildren(TNode* node) {
    if (node == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    cout << "Children of node " << node->data << ": ";
    if (node->left != NULL) {
        cout << node->left->data << " (Left) ";
    }
    if (node->right != NULL) {
        cout << node->right->data << " (Right) ";
    }
    if (node->left == NULL && node->right == NULL) {
        cout << "None";
    }
    cout << endl;
}

// tampilkan descendants dari node
void tampilkanDescendants(TNode* node) {
    if (node == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    cout << "Descendants of node " << node->data << ": ";
    queue<TNode*> qvalue;
    qvalue.push(node);
    bool first = true;
    while (!qvalue.empty()) {
        TNode* current = qvalue.front();
        qvalue.pop();
        if (!first) {
            cout << current->data << " ";
        }
        if (current->left != NULL) {
            qvalue.push(current->left);
        }
        if (current->right != NULL) {
            qvalue.push(current->right);
        }
        first = false;
    }
    cout << endl;
}

// main program (program utama)
int main() {
    TNode* root = NULL;
    int pilihan, value, parentValue;
    char child;

    // tampilkan opsi yang dapat dipilih pada program menu
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambah node root" << endl;
        cout << "2. Tambah node anak" << endl;
        cout << "3. Pre-order traversal" << endl;
        cout << "4. In-order traversal" << endl;
        cout << "5. Post-order traversal" << endl;
        cout << "6. Tampilkan child dari node" << endl;
        cout << "7. Tampilkan descendant dari node" << endl;
        cout << "8. Keluar" << endl;
        cout << "Opsi mana yang ingin Anda pilih? : ";
        cin >> pilihan;

        // jalankan case sesuai opsi yang dipilih (1-8)
        switch (pilihan) {
            // case 1 menambahkan nilai root
            case 1:
                if (root != NULL) {
                    cout << "Root already exists!" << endl;
                } else {
                    cout << "Masukkan nilai untuk root: ";
                    cin >> value;
                    root = new TNode(value);
                }
                break;
            // case 2 memasukkan nilai anak sesuai dengan node parent
            case 2:
                cout << "Masukkan nilai parent: ";
                cin >> parentValue;
                cout << "Masukkan nilai anak: ";
                cin >> value;
                cout << "L (left) atau R (right): ";
                cin >> child;
                addNode(root, parentValue, value, child);
                break;
            // case 3 menampilkan pre-order traversal
            case 3:
                cout << "Pre-order traversal: ";
                preOrder(root);
                cout << endl;
                break;
            // case 4 menampilkan in-order traversal
            case 4:
                cout << "In-order traversal: ";
                inOrder(root);
                cout << endl;
                break;
            // case 5 menampilkan post-order traversal
            case 5:
                cout << "Post-order traversal: ";
                postOrder(root);
                cout << endl;
                break;
            // case 6 menampilkan node children berdasarkan nilai node yang dimasukkan
            case 6:
                cout << "Masukkan nilai node: ";
                cin >> value;
                tampilkanChildren(search_Ardelia_2311110051(root, value));
                break;
            // case 7 menampilkan node descendants berdasarkan nilai node yang dimasukkan
            case 7:
                cout << "Masukkan nilai node: ";
                cin >> value;
                tampilkanDescendants(search_Ardelia_2311110051(root, value));
                break;
            // case 8 keluar dari prorgam
            case 8:
                return 0;
            // tampilan apabila user memasukkan opsi selain 1 hingga 8
            default:
                cout << "Opsi yang Anda pilih tidak valid! Silakan masukkan opsi lain." << endl;
        }
    }
    cout << endl;
    return 0;
}

```

Kode tersebut merupakan program menu yang digunakan untuk menambahkan node root, parents, dan anak berdasarkan node parents. Kode tersebut juga dapat digunakan untuk menampilkan pre-order, in-order, post-order, node anak da suatu node parents, dan descendants dari suatu node. Node root merupakan node teratas. Selanjutnya, root dapat menjadi node parents apabila ditambah dengan node anak pada left dan right nodenya. Node yang berperan sebagai node anak dari node root tersebut juga dapat menjadi sebuah subtree dengan menambah node anak lagi pada sisi left dan rightnya. Penjelasan lebih detail akan dipaparkan pada output dan penjelasan. 

#### Penjelasan Kode:
- `struct TNode` dan constructor di dalamnya digunakan untuk menyimpan deklarasi-deklarasi.
- `void preOrder(TNode *node)` digunakan untuk melihat node dari root, dilanjutkan ke subtree kiri, dan terakhir ke subtree kanan.
- `void inOrder(TNode *node)` digunakan untuk melihat node dari subtree kiri, dilanjutkan ke root, dan terakhir ke subtree kanan.
- `void postOrder(TNode *node)` digunakan untuk melihat node dari subtree kiri, dilanjutkan ke subtree kanan, dan terakhir ke root.
- `TNode* search(TNode* root, int value)` digunakan untuk mencari suatu node.
- `void addNode(TNode* &root, int parentValue, int value, char child)` digunakan untuk menambah suatu node berdasarkan nilai parentsnya dan letak left atu rightnya.
- `void tampilkanChildren(TNode* node)` digunakan untuk menampilkan child dari suatu node parent.
- `void tampilkanDescendants(TNode* node)` digunakan untuk menampilkan descendants dari suatu node.

#### Penjelasan Main Program:
Pada main program terdapat deklarasi `TNode* root = NULL;`, `int pilihan, value, parentValue;` dan `char child;`. Program juga mencetak pilihan-pilihan program menu. Selanjutnya, program akan meminta user memasukkan 1 opsi sesuai pilihan yang diinginkan. Berikut penjelasan case-casenya:
- `case 1:` artinya apabila user memasukkan 1, program akan meminta user untuk menambahkan nilai pada root node.
- `case 2:` artinya apabila user memasukkan 2, program akan meminta user untuk menambahkan nilai child node dari suatu nilai parents yang ditentukan oleh user juga.
- `case 3:` artinya apabila user memasukkan 3, program akan mengunjungi dan menampilkan node secara pre-order dimana dimulai dari node root, dilanjutkan ke subtrees kiri, dan terakhir ke subtrees kanan.
- `case 4:` artinya apabila user memasukkan 4, program akan mengunjungi dan menampilkan node secara in-order dimana dimulai dari node subtrees kiri, dilanjutkan ke root, dan terakhir ke subtrees kanan.
- `case 5:` artinya apabila user memasukkan 5, program akan mengunjungi dan menampilkan node secara post-order dimana dimulai dari node subtrees kiri, dilanjutkan ke subtrees kanan, dan terakhir ke root.
- `case 6:` artinya apabila user memasukkan 6, program akan menampilkan child node beserta letak left dan rightnya dari parents node yang diinputkan oleh user.
- `case 7:` artinya apabila user memasukkan 7, program akan menampilkan descendants node dari parents node yang diinputkan oleh user.
- `case 8:` artinya apabila user memasukkan 8, program akan berhenti karena 8 merupakan opsi untuk keluar dari program menu tersebut.
- `default` artinya apabila user memasukkan nilai selain 1 hingga 8, maka program akan mencetak "Opsi yang Anda pilih tidak valid! Silakan masukkan opsi lain." karena opsi pilihannya hanya 1 hingga 8.

#### Output dan Penjelasan:

#### Output 1:
![1](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/386cd822-851e-4f75-a974-f9ff17623823)

Pada output tersebut, user memasukkan opsi 1 dan menambahkan nilai pada node root yaitu 10. Dengan demikian, terdapat 1 node di dalam pohon tersebut yaitu 10.

#### Output 2:
![2](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/b4813498-8b0f-48f4-940b-9fe9fe19dabd)

Pada output tersebut, user memasukkan opsi 2. User memasukkan 10 sebagai parents nodenya. Selanjutnya, 5 ditambahkan pada sisi kiri (left / L) dari parents node tersebut. Saat ini, terdapat 2 node. Sisi kanan (right / R) parents node 10 masih kosong (NULL).

#### Output 3:
![3](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/cfd4727e-72bc-446c-ac8b-f5f2f2051f59)

Pada output tersebut, user memasukkan opsi 2. User memasukkan 10 sebagai parents nodenya. Selanjutnya, 15 ditambahkan pada sisi kanan (right / R) dari parents node tersebut. Saat ini, terdapat 3 node. Sisi kanan (right / R) parents node 10 yang awalnya kosong (NULL), saat ini sudah terisi.

#### Output 4:
![4](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/cabadbe0-0dd4-4363-a463-661034143ff8)

Pada output tersebut, user memasukkan opsi 2. User memasukkan 5 sebagai parents nodenya. Saat ini, 5 tidak hanya sebagai child node, melainkan juga parents node karena user menambahkan child node. Selanjutnya, 2 ditambahkan pada sisi kiri (left / L) dari parents node tersebut. Saat ini, terdapat 4 node. Sisi kanan (right / R) parents node 5 masih kosong (NULL).

#### Output 5:
![5](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/72f0d7ea-7665-474b-bd12-301b8385ff65)

Pada output tersebut, user memasukkan opsi 2. User memasukkan 5 sebagai parents nodenya. Saat ini, 5 tidak hanya sebagai child node, melainkan juga parents node karena user menambahkan child node. Selanjutnya, 7 ditambahkan pada sisi kanan (right / R) dari parents node tersebut. Saat ini, terdapat 5 node. Sisi kanan (right / R) parents node 5 yang awalnya kosong (NULL), saat ini sudah terisi.

#### Output 6:
![6](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/60878579-4ea0-4500-9739-7687bc0abf5b)

Pada output tersebut, user memasukkan opsi 2. User memasukkan 15 sebagai parents nodenya. Saat ini, 15 tidak hanya sebagai child node, melainkan juga parents node karena user menambahkan child node. Selanjutnya, 11 ditambahkan pada sisi kiri (left / L) dari parents node tersebut. Saat ini, terdapat 6 node. Sisi kanan (right / R) parents node 15 masih kosong (NULL).

#### Output 7:
![7](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/2d314e71-21f2-4801-9702-0027b8bbccb8)

Pada output tersebut, user memasukkan opsi 2. User memasukkan 15 sebagai parents nodenya. Saat ini, 15 tidak hanya sebagai child node, melainkan juga parents node karena user menambahkan child node. Selanjutnya, 13 ditambahkan pada sisi kanan (right / R) dari parents node tersebut. Saat ini, terdapat 7 node. Sisi kanan (right / R) parents node 15 yang awalnya kosong (NULL), saat ini sudah terisi.

#### Output 8:
![8](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/19391374-9ade-42ca-84ca-86cd21097bdd)

Pada output tersebut, user memasukkan opsi 3 sehingga program menampilkan isi pohon secara pre-order traversal yaitu dari node root, subtrees kiri, dan terakhir subtrees kanan. Outputnya adalah 10, 5, 2, 7, 15, 11, 13.

#### Output 9:
![9](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/75373bfd-dc0a-4f7e-9135-7c9c99f8d877)

Pada output tersebut, user memasukkan opsi 4 sehingga program menampilkan isi pohon secara in-order traversal yaitu dari node subtrees kiri, root, dan terakhir subtrees kanan. Outputnya adalah 2, 5, 7, 10, 11, 15, 13.

#### Output 10:
![10](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/c25df1b3-d3dd-4be3-9c65-df9e05807913)

Pada output tersebut, user memasukkan opsi 5 sehingga program menampilkan isi pohon secara post-order traversal yaitu dari node root, subtrees kiri, dan terakhir subtrees kanan. Outputnya adalah 10, 5, 2, 7, 15, 11, 13.

#### Output 11:
![11](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/f5f4046c-1d1b-4197-b55b-fc91364f424e)

Pada output tersebut, user memasukkan opsi 6 dan memasukkan nilai node 5 sehingga program menampilkan child node dari 5 yaitu 2 pada left dan 7 pada right.

#### Output 12:
![12](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/9c0aa2e9-c93c-41d8-922d-88243db52304)

Pada output tersebut, user memasukkan opsi 6 dan memasukkan nilai node 15 sehingga program menampilkan child node dari 5 yaitu 11 pada left dan 13 pada right.

#### Output 13:
![13](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/706b7961-c8dd-4157-9ed7-5d3d95431dce)

Jika dilihat dari output 11 dan 12, node yang ditampilkan terletak pada akhir subtrees sehingga tidak ada child node lagi di dalamnya. Sedangkan pada output 13, user memasukkan 10 sebagai parents nodenya dan program menampilkan 5 pada left dan 15 pada right sebagai child nodenya. Dengan demikian, dapat disimpulkan bahwa child node yang ditampilkan hanya dilihat dari parents node yang diinputkan, bukan seluruh child node di dalam child node berikutnya.

![14](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/a969a6b4-6dff-433a-bf85-04594e5ededb)

Pada output tersebut, user memasukkan opsi 7 dan nilai node yang dimasukkan adalah sehingga didapatkan descendants of node 5 adalah 2 dan 7.

![15](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/e0010063-7ce0-445a-85cc-f3347ffb8570)

Pada output tersebut, user memasukkan opsi 8 sehingga keluar dari program.

#### Full code Screenshot:
![full ss unguided 2](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/1c26b641-8cd4-4f1a-a12d-fd5d47e8f4b9)


## Kesimpulan
Kesimpulan yang dapat diambil dari praktikum modul Graph dan Tree adalah 

## Referensi
- [1] 
