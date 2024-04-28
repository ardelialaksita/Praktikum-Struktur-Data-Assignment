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
- Pada akhir statement struct harus menggunakan sebuah semikolon (;).

## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

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
Kode di atas digunakan untuk menampilkan struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, dan harga_buku. Struct buku tersebut digunakan untuk membuat suatu struktur data yang mewakili suatu buku. judul_buku, pengarang, penerbit, tebal_halaman, dan harga_buku merupakan field struct tersebut yang digunakan untuk menyimpan data buku tersebut. Program tersebut tidak menggunakan _input user_ karena datanya langsung diisi pada kode program. 

Pada `struct buku { };` berisi kode-kode deklarasi struct buku tersebut yaitu judul buku, pengarang, dan penerbit yang bertipe data string, serta tebal halaman dan harga buku yang bertipe integer. `string judulBuku;`, `string pengarang;`, `string penerbit;`, `int tebalHalaman;`, `int hargaBuku;` merupakan bentuk deklarasinya. 

Pada main program, terdapat variabel favorit yang digunakan untuk menyimpan data tentang suatu buku favorit. Variabel favorit dideklarasikan dengan `buku favorit;`. Setelah dideklarasikan, variabel tersebut diisi dengan data suatu buku menggunakan kode `favorit.(namaField): "...";`. 
- `favorit.judulBuku = "The Alpha Girl's Guide";` artinya judul dari buku tersebut adalah The Alpha Girl's Guide.
- `favorit.pengarang = "Henry Manampiring";` artinya pengarang dari buku tersebut adalah Henry Manampiring.
- `favorit.penerbit = "Gagas Media";` artinya buku tersebut diterbitkan oleh Penerbit Gagas Media.
- `favorit.tebalHalaman = 253;` artinya buku tersebut terdiri atas 253 halaman.
- `favorit.hargaBuku = 79000;` artinya harga buku tersebut adalah Rp79.000,00.

Untuk menampilkan informasi dari data buku yang telah diisi datanya yaitu dengan cara menggunakan cout yang menggunakan data-data pada isi dari favorit seperti berikut.
- `cout << "\tBuku Favorit Saya" << endl;` digunakan untuk menampilkan _head of the information_ atau judul dari informasi tersebut yaitu "Buku Favorit Saya".
- `cout << "\tJudul Buku : " << favorit.judulBuku << endl;` digunakan untuk menampilkan judul buku tersebut yaitu The Alpha Girl's Guide.
- `cout << "\tPengarang : " << favorit.pengarang << endl;` digunakan untuk menampilkan pengarang buku tersebu yaitu Henry Manampiring.
- `cout << "\tPenerbit : " << favorit.penerbit << endl;` digunakan untuk menampilkan penerbit buku tersebut yaitu Gagas Media.
- `cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;` digunakan untuk menampilkan tebal halaman buku tersebut dimana `favorit.tebalHalaman` merupakan variabel yang akan menampilkan tebal halamannya.
- `cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;` digunakan untuk menampilkan harga buku dalam nominal rupiah.
- - `/t` digunakan untuk membuat indentasi atau _space_ kosong pada suatu kode sehingga dapat dibaca dengan lebih terstruktur. 

#### Output Guided 1:


### 2. Buatlah sebuah struktur dengan skema seperti di bawah, isi dengan nilai kemudian jalankan. 

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
Kode tersebut digunakan untuk menampilkan struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. 


## Unguided 

### 1. Modifikasi tugas guided pertama sehingga setiap item yang terdapat pada _struct_ buku berupa array yang berukuran 5. Isi dengan data, kemudian tampilkan.

```C++

```

#### Output:


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
- [1] 
