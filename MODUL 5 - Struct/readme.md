# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Ardelia Rachma Laksita</p>

## Table of Contents
1. [Dasar Teori](#dasar-teori)
2. [Guided](#guided)
3. [Unguided](#unguided)
4. [Kesimpulan](#kesimpulan)
5. [Referensi](#referensi)

## Dasar Teori
Struct atau struktur data adalah salah satu tipe data di C++ yang memungkinkan kita untuk menggabungkan beberapa tipe data yang berbeda menjadi satu kesatuan logis [2]. Isinya dapat berupa variabel dan fungsi sebagai anggota atau elemennya. Struct dapat digunakan untuk merepresentasikan data yang memiliki banyak elemen dan objek yang kompleks. Apabila ingin menambahkan struct ke dalam struct lain yang bertipe sama, operator relasional tidak bisa digunakan pada variabel struct [7]. Contohnya `if (mahasiswa == mahasiswaBaru)` adalah tindakan ilegal. 

Beberapa anggota dalam struct memungkinkan digunakan secara bersamaan. Struct termasuk data komposit dan lebih dikenali di C++ [4]. Dalam mengakses suatu _field_, notasi seperti berikut digunakan : **_Variabel_struct.namefield_** [3]. Pengikatan struct (struct _bindings_) memungkinkan pembongkaran elemen dari tuples, pairs, atau objects ke dalam variabel dengan nama terpisah sehingga dapat dibaca dengan mudah [1]. Sintaks ini menyederhanakan akses beberapa elemen yang dikembalikan dari suatu fungsi atau menguraikan struktur data yang kompleks [1]. Struct juga dapat meningkatkan kejelasan dari kode. 

Sebuah semikolon (yang berada setelah kurung kurawal kanan) sangat penting untuk mengakhiri statement struct [5]. Semikolon di akhir definisi struct merupakan bagian dari sintaks [8]. Pelabelan struct sama seperti tipe-tipe data C++ yang lain. Deklarasi suatu struct adalah definisi suatu tipe baru [6].

### Penerapan atau Penggunaan Struct :
- Struct memungkinkan anggota digunakan secara bersamaan.
- Anggota atau elemen struct dapat didefinisikan dengan tipe yang berbeda.
- Tipe struct yang telah didefinisikan dapat digunakan untuk mendeklarasikan variabel.
- Pada akhir statement struct harus menggunakan sebuah semikolon. 

## Guided 

### 1. 

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}

```
Kode di atas digunakan untuk 

#### Output Guided 1:


### 2. 

```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora; // Menggunakan boolean (true or false)
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}

```
Kode tersebut digunakan untuk 


## Unguided 

### 1. 
```C++

```

#### Output:


Kode tersebut digunakan untuk 

#### Penjelasan main program:
 

#### Penjelasan input oleh user:


#### Full code Screenshot:


### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!
```C++

```

#### Output:


Kode tersebut digunakan untuk 

#### Penjelasan main program:


#### Penjelasan input oleh user:


#### Full code Screenshot:


### 3. 
```C++

```

#### Output:


Kode tersebut digunakan untuk 

#### Penjelasan Main Program:


#### Penjelasan Output:


#### Full code Screenshot:



## Kesimpulan
 

## Referensi
- [1] 
