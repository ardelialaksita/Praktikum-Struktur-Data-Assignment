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
![Modul 5  Guided 1 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/6354dcb2-ac68-46c9-8678-fad849bc978b)

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
Kode tersebut digunakan untuk menampilkan hewan dan kategorinya menggunakan struct yang memiliki _field_ yang berbeda-beda. Terdapat 3 struct pada program tersebut yaitu `struct hewan`, `struct hewanDarat`, dan `struct hewanLaut`. 

**1) `struct hewan`**
  
Field pada `struct hewan` yaitu namaHewan, jenisKelamin, caraBerkembangbiak, alatPernapasan, tempatHidup, dan termasuk karnivora atau tidak. Tipe data namaHewan, jenisKelamin, caraBerkembangbiak, alatPernapasan, dan tempatHidup adalah string karena terdapat lebih dari 1 karakter. Sedangkan karnivora menggunakan `bool Karnivora;` dimana tipe datanya adalah boolean karena kategori tersebut memiliki output true or false yang digunakan untuk menentukan apakah hewan tersebut termasuk karnivora atau tidak. 

**2) `struct hewanDarat`**

Field pada `struct hewan` yaitu jumlahKaki, menyusui, dan suara. Tipe data variabel jumlahKaki adalah integer karena jumlah kaki yang dimasukkan berbentuk numerik (angka). Variabel menyusui memiliki tipe data bool karena kategori tersebut memiliki output true atau false yang digunakan untuk menentukan apakah hewan tersebut menyusui atau tidak. Variabel suara memiliki tipe data string karena terdapat lebih dari 1 karakter. 

**3) `struct hewanLaut`**

Field pada `struct hewanLaut` yaitu bentukSirip dan bentukPertahananDiri. Kedua variabel tesebut memiliki tipe data string karena data yang dimasukkan memiliki lebih dari 1 karakter. 

#### Main Program:
Pada main program, isi data pada struct. Pertama-tama, tentukan terlebih dahulu struct yang ingin digunakan dan nama hewannya. Penulisan kodenya yaitu `nama_struct nama_hewan;`. Selanjutnya, isi data dengan cara menuliskan kembali nama hewan dan _field_ struct yang digunakan dengan kode `nama_hewan.field`. Setelah itu, tampilkan seluruh data yang telah dimasukkan dengan menggunakan cout. Terakhir, kode return digunakan sebagai tanda bahwa program telah selesai dan berhasil. 

`hewanDarat kelinci;`

Jenis hewan yang akan dimasukkan datanya pada struct hewanDarat adalah kelinci. Isi datanya yaitu jumlahKaki, menyusui, dan suara. Ketik nama hewan terlebih dahulu sebelum menuliskan fieldnya. Data yang dimasukkan pada jumlahKaki kelinci adalah 4 yaitu pada kode `kelinci.jumlahKaki = 4;`. Untuk menampilkan data apakah kelinci menyusui atau tidak yaitu dengan kode `kelinci.menyusui = true;` yang artinya kelinci menyusui. Citcit merupakan data yang dimasukkan pada suara kelinci yaitu `kelinci.suara = "Citcit";`.

`hewanLaut ikan;`

Jenis hewan yang akan dimasukkan datanya pada struct hewanLaut adalah ikan. Isi datanya yaitu bentukSirip dan bentukPertahananDiri. `ikan.bentukSirip = "Sirip ekor";` digunakan untuk memasukkan data bentuk sirip ikan yaitu sirip ekor. Sedangkan `ikan.bentukPertahananDiri = "Sisik";` digunakan untuk memasukkan bentuk pertahanan diri ikan yaitu menggunakan sisik mereka.

`hewan serigala;`

Jenis hewan yang akan dimasukkan datanya pada struct hewan adalah serigala. Isi datanya memiliki cukup banyak kategori, antara lain namaHewan, jenisKelamin, caraBerkembangbiak, alatPernapasan, tempatHidup, dan termasuk karnivora atau tidak. `serigala.namaHewan = "Serigala";` untuk memasukkan data namaHewan yaitu serigala. `serigala.jenisKelamin = "Jantan";` untuk memasukkan data jenisKelamin serigala yaitu jantan. `serigala.caraBerkembangbiak = "Melahirkan";` untuk memasukkan data cara serigala berkembang biak yaitu dengan cara melahirkan. `serigala.alatPernafasan = "Paru-paru";` untuk memasukkan data alat pernapasan serigala yaitu paru-paru. `serigala.tempatHidup = "Hutan terbuka";` untuk memasukkan data tempat hidup serigala yaitu di hutan terbuka. `serigala.Karnivora = true;` untuk menampilkan data apakah serigala merupakan karnivora atau tidak. True artinya serigala merupakan karnivora. 

#### Output Guided 2:
![Modul 5  Guided 2 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/267bcfff-2231-4bf4-a324-320923cfaf81)

## Unguided 

### 1. Modifikasi tugas guided pertama sehingga setiap item yang terdapat pada _struct_ buku berupa array yang berukuran 5. Isi dengan data, kemudian tampilkan.

```C++
#include <iostream>
using namespace std;

// mendefinisikan struktur buku dengan panjang array sebanyak 5 pada masing-masing kategori
struct buku {
    string judulBuku[5]; // deklarasi tipe data judulBuku dan banyak datanya
    string pengarang[5]; // deklarasi tipe data pengarang dan banyak datanya
    string penerbit[5]; // deklarasi tipe data penerbit dan banyak datanya
    int tebalHalaman[5]; // deklarasi tipe data tebalHalaman dan banyak datanya
    int hargaBuku[5]; // deklarasi tipe data hargaBuku dan banyak datanya
};

int main() {
    // deklarasi variabel favorit dengan tipe buku
    buku favorit;

    // mengisi data ke dalam variabel favorit
    // data buku pertama
    favorit.judulBuku[0] = "Overthinking is My Hobby";
    favorit.pengarang[0] = "Alvi Syahrin";
    favorit.penerbit[0] = "Kawah Media";
    favorit.tebalHalaman[0] = 268;
    favorit.hargaBuku[0] = 99000;

    //data buku kedua
    favorit.judulBuku[1] = "Insecurity is My Middle Name";
    favorit.pengarang[1] = "Alvi Syahrin";
    favorit.penerbit[1] = "Kawah Media";
    favorit.tebalHalaman[1] = 264;
    favorit.hargaBuku[1] = 99000;

    // data buku ketiga
    favorit.judulBuku[2] = "Autumn in Paris";
    favorit.pengarang[2] = "Ilana Tan";
    favorit.penerbit[2] = "Gramedia Pustaka Utama";
    favorit.tebalHalaman[2] = 260;
    favorit.hargaBuku[2] = 79000;

    // data buku keempat
    favorit.judulBuku[3] = "The Star and I";
    favorit.pengarang[3] = "Ilana Tan";
    favorit.penerbit[3] = "Gramedia Pustaka Utama";
    favorit.tebalHalaman[3] = 344;
    favorit.hargaBuku[3] = 99000;

    // data buku kelima
    favorit.judulBuku[4] = "Teluk Alaska";
    favorit.pengarang[4] = "Eka Aryani";
    favorit.penerbit[4] = "Bumi Semesta Media";
    favorit.tebalHalaman[4] = 408;
    favorit.hargaBuku[4] = 99000;

    // menampilkan seluruh informasi buku favorit
    cout << "============ DAFTAR BUKU FAVORIT SAYA ============" << endl;
    // perulangan for untuk menampilkan data masing-masing buku
    for (int i=0; i < 5; i++) {
        cout << "\n \tBuku ke-" << i+1 << endl;
        cout << "\tJudul Buku    : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang     : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit      : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman : " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku    : Rp " << favorit.hargaBuku[i] << endl;
    }
    // return sebagai kode bahwa program telah selesai dan berhasil
    return 0;
}

```

#### Output:
![Modul 5  Unguided 1 Output (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/14b4dbe3-8dc7-4ca2-a457-c9f0d828d6cc)
![Modul 5  Unguided 1 Output (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/837fccf9-3914-4f2f-bcc6-01b751ccf0a8)

Kode tersebut digunakan untuk 

#### Penjelasan main program:
 

#### Penjelasan input oleh user:


#### Full code Screenshot:
![Modul 5  Unguided 1 Full SS (1)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/ebfc75c5-d0b4-4712-8d4b-793187798e47)
![Modul 5  Unguided 1 Full SS (2)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/2f875429-a487-47b6-9893-58645292b72e)
![Modul 5  Unguided 1 Full SS (3)](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/9d684310-313e-4590-9f7f-0efb1271b7fd)

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
