# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Ardelia Rachma Laksita</p>

## Dasar Teori

Tipe data merupakan klasifikasi jenis-jenis data yang berfungsi untuk menentukan data serta variabel yang dapat digunakan dalam suatu sistem dan operasi-operasi tertentu. Tipe data adalah semua himpunan yang ada pada semua data tanpa terkecuali[1]. Adanya klasifikasi data juga dapat membantu operasi komputer mengenali nilai data beserta instruksinya. Tipe data dibagi menjadi 3, antara lain :

#### 1. Tipe Data Primitif:
   Tipe data primitif merupakan tipe data yang dapat menyimpan satu nilai dan telah ditentukan oleh sistem. Tipe data primitif adalah tipe yang sederhana sehingga kesulitan menjangkau data kompleks yang tingkat kerumitannya tinggi. Tipe data sederhana merupakan tipe data fundamental dalam C++ karena menjadi blok pembangun untuk tipe data terstruktur[2].
Beberapa macam tipe data primitif :
- a) Boolean (bool) : digunakan untuk menyimpan nilai logika dan hanya memiliki 2 nilai yaitu true dan false.
- b) Integer (int) : digunakan untuk angka tanpa pecahan baik positif maupun negatif. Contoh : 10,11,12.
- c) Float (float) : digunakan untuk angka pecahan. Contoh : 10.1, 11.5, 12.4.
- d) Character (char) : digunakan untuk satu karakter. Contoh : 'a','A'.
- e) String (string) : digunakan untuk menyimpan nilai lebih dari 1 karakter. Contoh : 'Apel', 'Strawberry'.
   
#### 2. Tipe Data Abstrak :
   Tipe data abstrak merupakan tipe data yang memiliki sistematik serupa dan didefinisikan melalui operasi matematis tertentu. Deklarasi Abstract Data Type (ADT) terdapat pada beberapa bahasa pemrograman dan bentuk deklarasinya mengikat daftar identifikasi terhadap suatu tipe dengan operasi terkait. Ide dasar dari ADT adalah bahwa implementasi himpunan operasi ditulis satu kali dalam program dan bagian dari program yang perlu melakukan suatu operasi diselesaikan oleh ADT dengan menjalankan operasi yang diperlukan. Fitur yang dapat digunakan dalam tipe data abstrak antara lain : struct (akses defaultnya bersifat public) dan class (akses defaultnya bersifat private).

#### 3. Tipe Data Koleksi : 
   Tipe data koleksi merupakan tipe data yang berfungsi mengelompokkan, mengelola, dan mengakses beberapa objek dan nilai secara bersamaan. Tipe data koleksi antara lain : array (untuk menyimpan elemen-elemen dengan tipe data yang sama), vector (untuk menyimpan data dalam bentuk elemen-elemen yang alokasi memorinya dilakukan secara otomatis dan bersebelahan), dan map (untuk menyimpan elemen-elemen dengan tipe data yang sama namun bisa digunakan pula untuk tipe data selain integer pada indeksnya).

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream> 
using namespace std;

//Main program
int main() {
    char op;
    float num1, num2;
    //It allows user to enter operator i.e, +, -, *, /    
    cout << "Masukkan operator (+, -, *, /): ";
    cin >> op;
    //It allow user to enter the operands
    cout << "Masukkan angka pertama: ";
    cin >> num1;
    cout << "Masukkan angka kedua: ";
    cin >> num2;
    //Switch statement begins

    switch (op) 
    {
        //If user enter +
        case '+':
            cout << "Hasil Penjumlahan: " << num1 + num2;
            break;
        //If user enter -
        case '-':
            cout << "Hasil Pengurangan: " << num1 - num2;
            break;
        //If user enter *
        case '*':
            cout << "Hasil Perkalian: " << num1 * num2;
            break;
        //If user enter /
        case '/':
            if (num2 != 0)
                cout << "Hasil Pembagian: " << num1 / num2;
            else
                cout << "Error! Nol tidak boleh digunakan sebagai pembagi.";
            break;
        //If the operator is other than +,-,*, or /,
        //error message will display
        default:
            cout << "Error! Operator is not correct";
        //Switch statement ends
    } 
    return 0;
}
```
Kode di atas digunakan untuk melakukan operasi penjumlahan(+), pengurangan(-), perkalian(*), dan pembagian(/) terhadap 2 bilangan. 
**cout << "Masukkan operator" dan cin >> op** digunakan untuk memasukkan operasi yang ingin digunakan.
**cout << "Masukkan angka pertama" dan cin >> num1** digunakan untuk memasukkan angka pertama yang ingin dioperasikan.
**cout << "Masukkan angka kedua" dan cin >> num2** digunakan untuk memasukkan angka kedua yang ingin dioperasikan.
Untuk melakukan operasi kedua bilangan, maka tentukan masing-masing case terlebih dahulu. 
Jika operator yang dimasukkan tidak benar, maka akan menghasilkan output **"Error! Operator is not correct."**.
Jika suatu bilangan memiliki 0 sebagai pembaginya, maka akan menghasilkan output **"Error! Nol tidak boleh sebagai pembagi."**
#### Contoh penggunaan program :
- Masukkan operasi : +  
- Masukkan bilangan pertama : 11  
- Masukkan bilangan kedua : 13  
- Hasil penjumlahan : 24  
#### Output Guided 1:
![Modul 1  Guided 1](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/38799ae5-1b50-4acf-8d8a-f4620f755a52)

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>

// Struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{

    // Menggunakan struct
    struct Mahasiswa mhs1, mhs2;

    // Mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // Mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);

    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    
    return 0;
    
}
```
Kode di atas digunakan untuk menngisi identitas mahasiswa berupa nama, alamat, dan umur menggunakan struct. 
- **// Struct** digunakan untuk menentukan jenis data struct yang digunakan. Pada program tersebut menggunakan char.
- **// Mengisi nilai ke struct** digunakan untuk mengisi apa saja yang akan diinput dalam identitas mahasiswa. Pengetikan kodenya dimulai dari mhs1 kemudian diikuti dengan identitas yang ingin diinput, misalnya **mhs1.address** untuk menggunakan struct dalam alamat mahasiswa. 
- **// Mencetak isi struct** dilakukan dengan cara **printf("Nama: %s\n", mhs1.name)** dan seterusnya. Kode **\n** digunakan untuk membuat 'enter' pada line berikutnya. Kode **\n** dapat diganti dengan **endl;**.
- **return 0** digunakan untuk mengakhiri program tersebut.
#### Output Guided 2:
![Modul 1  Guided 2](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/1d210f89-7eaf-44b2-b24c-f960850f9af4)

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;
int main()
{
    // deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
    return 0;
}
```
Kode tersebut digunakan untuk deklarasi, inisialisasi, dan mencetak suatu array. Array tersebut berisi 5 nilai yang terdiri atas 4 indeks. Untuk mendeklarasikan dan inisialisasi array dilakukan dengan **int nilai[5]** dimana 5 dalam kode tersebut artinya array terdiri atas 5 nilai. Selanjutnya, isi masing-masing indeks menggunakan nilai[0] untuk indeks ke 0 hingga nilai [4] untuk indeks ke 5. Untuk mencetak array dan mengetahui nilai masing-masing array menggunakan **cout << "Isi array .... :" << nilai[0] << endl;**. Pengetikan masing-masing cout harus sesuai dengan indeks yang diinput dalam [] sehingga tidak ada kesalahan dalam pencetakan isi array.
#### Output Guided 3:
![Modul 1  Guided 3](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/778c700f-c6ea-4bb9-8066-bd3e7c5e7897)


## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

//Fungsi untuk mengecek apakah suatu bilangan adalah bilangan ganjil (odd number)
bool isOdd(int num) {
    return num % 2 != 0;
}

//Fungsi untuk mengecek apakah suatu bilangan adalah bilangan genap (even number)
bool isEven(int num){
    return num % 2 == 0;
}

int main() {
    int num;
    cout << "Masukkan bilangan: ";
    cin >> num;

    if (isOdd(num)) {
        cout << num << " adalah bilangan ganjil" << endl;
    }
    else if (isEven(num)) {
        cout << num << " adalah bilangan genap" << endl;
    }
    else {
        cout << num << " adalah bilangan 0 (bukan bilangan ganjil dan genap)" << endl;
    }
        
    return 0; 
        
}
```

#### Output:
![Modul 1  Unguided 1 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/3cd54b3b-a355-492c-8f74-ef1e6fd30254)

Kode di atas digunakan untuk menentukan bilangan. Program tersebut berisi tentang fungsi untuk menentukan apakah suatu bilangan termasuk bilangan ganjil, bilangan genap, atau bilangan 0 (bukan ganjil dan bukan genap). Terdapat 2 fungsi yaitu fungsi untuk mengecek apakah suatu bilangan termasuk bilangan ganjil dan fungsi untuk mengecek apakah apakah suatu bilangan termasuk bilangan genap. Tipe data primitif yang digunakan dalam program tersebut yaitu integer atau int dimana cara menentukan suatu bilangan ganjil atau genap dilakukan dengan cara membagi bilangan tersebut dengan 2. 
- **num % 2 != 0** artinya jika bilangan tersebut dibagi 2 tidak sama dengan 0, maka bilangan tersebut adalah bilangan ganjil. Kemudian, program akan menjalankan **cout << num << " adalah bilangan ganjil" << endl;** dan akan menghasilkan output **"(bilangan) adalah bilangan ganjil"**. **num % 2 == 0** artinya jika bilangan tersebut dibagi 2 sama dengan 0, maka bilangan tersebut adalah bilangan genap. Kemudian, program akan menjalankan **cout << num << " adalah bilangan genap" << endl;** dan akan menghasilkan output **"(bilangan) adalah bilangan genap"**. **else** artinya jika bilangan yang diinput adalah 0 dimana bilangan 0 bukan merupakan bilangan ganjil dan bukan bilangan genap. 

#### Kesimpulan tipe data primitif :
Tipe data primitif dapat berupa int (integer), bool (boolean), float (float), string (string), dan char (character). Masing-masing tipenya dapat digunakan pada operasi sesuai yang dibutuhkan. Pada program di atas, tipe data yang digunakan adalah int. Operasi yang digunakan adalah modulo (%) karena mengembalikan sisa pembagian dari 2 bilangan. Jika sisa pembagian 2 bilangan tersebut adalah 0, maka bilangan tersebut adalah bilangan genap. Sebaliknya, jika sisa pembagian 2 bilangan tersebut bukan 0, maka bilangan tersebut adalah bilangan ganjil. 

#### Full code Screenshot:
![Modul 1  Unguided 1 Full SS](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/cb85080c-6bda-4fce-8696-93bc08dc7345)

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya.

#### Struct :
Fungsi struct yaitu dapat menggabungkan sekumpulan variabel dan memberi nama pada variabel-variabel tersebut. Nama yang digunakan sama seperti tipe variabelnya, misalnya : int atau string. Struct dapat mendeklarasikan variabel baru dan mengakses semua kolom. Struct akan mengelola data yang akan diakses secara langsung. Struct memiliki akses default yang terbuka (secara public). Struct hanya dapat memiliki properti. Struct mendefinisikan tipe data dan menginstruksikan kepada C++ untuk mengelompokkan koleksi tipe data dasar sebagai kesatuan tipe data sehingga dapat mendefinisikan variabel dan array variabel.Kata kunci struct mengindikasikan bahwa suatu kode mendefinisikan suatu struktur[3]. Deklarasi suatu struktur adalah pendefinisian suatu tipe baru[3].


#### Class :
Class berfungsi untuk mendeskripsikan suatu objek melalui data dan fungsi yang dimiliki. Class memiliki akses default private sehingga tidak semua variabel dapat dieksekusi apabila ada objek yang private. Jika objek anggota dari class tersebut ingin dipublikasikan, maka harus menggunakan **public :** . Class memiliki properti dan metode. Class akan mengelola data yang akan diakses melalui metode (method).

#### Contoh Program :
```C++
#include <iostream>
#include <string>
using namespace std;

// Struct
struct Fruit
{
    string name;
    string colour;
    string taste;
};

// Class (akses default private)
class FruitClass
{
    string name;
    string colour;
    string taste;
};

// Class (akses default public)
class FruitClass1
{
public:
    string name;
    string colour;
    string taste;
};

int main()
{
    // mengisi nilai ke class 
    Fruit frt; 
    FruitClass1 frt1;

    // mengisi nilai class menggunakan nama, warna, dan rasa buah apel
    frt.name = "Apple";
    frt.colour = "Red";
    frt.taste = "Sweet";

    // mengisi nilai class menggunakan nama, warna, dan rasa buah lemon
    frt1.name = "Lemon";
    frt1.colour = "Yellow";
    frt1.taste = "Sour";

    // mencetak isi class pada frt1 (buah apel)
    cout << "===== BUAH 1 =====" << endl;
    cout << "Nama Buah : " << frt.name << endl;
    cout << "Warna Buah : " << frt.colour << endl;
    cout << "Rasa Buah: " << frt.taste << endl;

    // mencetak isi class pada frt2 (buah lemon)
    cout << "\n===== BUAH 2 =====" << endl;
    cout << "Nama Buah : " << frt1.name << endl;
    cout << "Warna Buah : " << frt1.colour << endl;
    cout << "Rasa Buah: " << frt1.taste << endl;

    return 0;
}
```

#### Output:
![Modul 1  Unguided 2 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/65579231-a656-4598-8f97-6a272c5ea9af)

Kode di atas digunakan untuk mencetak nama, warna, dan rasa suatu buah. Struct tidak memiliki objek private. **frt1.name = "Lemon"** merupakan salah satu isi struct dimana jika dieksekusi menggunakan **cout << "Nama Buah : " << fruit1.name << endl;** akan menghasilkan output **Nama Buah : Lemon**. 

#### Full code Screenshot:
![Modul 1  Unguided 2 Full SS](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/b100da37-a2d0-441e-bebf-f831af3ca37c)

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

```C++
#include <iostream>
#include <map>
using namespace std;

int main() {
    // Membuat map dengan integer key
    map<int, string> animals = {{1, "Kucing"}, {2, "Unicorn"}, {3, "Dinosaurus"}};

    // Menambahkan elemen baru
    animals.insert(make_pair(4, "Paus"));

    // Mengakses elemen-elemen map
    cout << animals[1] << endl;
    cout << animals[2] << endl;
    cout << animals[3] << endl;
    cout << animals[4] << endl;

    // Menghapus elemen dari map
    animals.erase(2);

    // Membersihkan map
    animals.clear();

    return 0;
}
```
#### Output:
![Modul 1  Unguided 3 Output](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/9c4cc71f-8ade-42a7-acc7-1d85d6313327)

Kode di atas digunakan untuk mengisi animals pada masing-masing indeks menggunakan fungsi map. **animals[1]** berisi Kucing, **animals[2]** berisi Unicorn, dan **animals[3]** berisi Dinosaurus. Untuk menambahkan elemen baru pada map tersebut dapat menggunakan **animals.insert(make_pair(4, "Paus"));**. Kemudian, Paus akan ditambahkan pada **animals[4]**. Untuk menghapus elemen dari map dapat menggunakan **animals.erase(2)** dimana kode ini akan menghapus Unicorn. Sedangkan untuk membersihkan map dapat menggunakan **animals.clear()**.

#### Perbedaan array dan map :
- **Array** merupakan sekumpulan data dengan tipe yang sama dan disimpan dalam satu variabel saja. Array menyimpan data yang memiliki urutan dan dapat diakses menggunakan indeks. Indeks dalam array digunakan untuk mengakses data.
- **Map** merupakan sekumpulan key-value yang disimpan dalam satu variabel. Map menyimpan data yang memiliki hubungan key-value dan dapat diakses menggunakan key. Key dalam map digunakan untuk mengakses data. 
- Dengan demikian, array menggunakan indeks untuk mengakses data, sedangkan map menggunakan key. Array dapat menyimpan data dengan tipe yang sama, sedangkan map dapat menyimpan key dan value dengan tipe yang berbeda. 

#### Full code Screenshot:
![Modul 1  Unguided 3 Full SS](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/bb1a51b0-91cd-400a-a360-3b5b350d26f0)

## Kesimpulan
Tipe data merupakan klasifikasi atau pengelompokan jenis-jenis data. Variabel merupakan kontainer yang dapat digunakan untuk menyimpan suatu nilai pada sebuah program dengan tipe data tertentu. Nilai yang ditugaskan ke variabel dapat berubah selama eksekusi program[4]. Untuk menentukan tipe data yang digunakan dalam variabel dapat dilihat melalui klasifikasi tipe-tipe data. Tipe data ada 3: tipe data primitif yaitu sudah ditentukan oleh sistem, tipe data abstrak yaitu dibentuk oleh programer sendiri, dan tipe data koleksi yaitu digunakan untuk mengelompokkan nilai dan objek secara bersamaan. Korelasi antara tipe data tersebut yaitu tipe data abstrak sering digunakan untuk mengimplementasikan tipe data koleksi sehingga memungkinkan pengguna untuk berinteraksi dengan struktur data tanpa perlu mengetahui detail implementasinya. 

## Referensi
- [1] Litalia. (2023, September 30). _Pengertian Tipe Data Beserta Fungsi dan Jenis-Jenis Tipe Data_ [online]. Available: https://www.jurnalponsel.com/pengertian-tipe-data/.
- [2] Satrio, E. dan Pakpahan, S., Pemrograman C++ untuk Pembelajar Mandiri. Jakarta : Penerbit CAHAYA INFORMATIKA, 2019. 
- [3] Siahaan, V. dan Sianipar, R.H., Buku Pintar Pemrograman C++. Sumatra Utara : Balige Publishing, 2020. 
- [4] Siahaan, V. dan Sianipar, R.H., THREE COOKBOOKS IN ONE: Visual C++, Visual Basic, Visual C#. Sumatra Utara : Balige Publishing, 2020.
- [4] Siahaan, V. dan Sianipar, R.H., THREE COOKBOOKS IN ONE: Visual C++, Visual Basic, Visual C#. Sumatra Utara : Balige Publishing, 2020.