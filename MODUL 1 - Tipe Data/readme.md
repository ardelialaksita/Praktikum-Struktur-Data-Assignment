# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Ardelia Rachma Laksita</p>

## Dasar Teori

Tipe data merupakan klasifikasi jenis-jenis data yang berfungsi untuk menentukan data serta variabel yang dapat digunakan dalam suatu sistem dan operasi-operasi tertentu. Tipe data adalah semua himpunan yang ada pada semua data tanpa terkecuali[1]. Adanya klasifikasi data juga dapat membantu operasi komputer mengenali nilai data beserta instruksinya. Tipe data dibagi menjadi 3, antara lain :

#### 1. Tipe Data Primitif:
   Tipe data primitif merupakan tipe data yang dapat menyimpan satu nilai dan telah ditentukan oleh sistem. Tipe data primitif adalah tipe yang sederhana sehingga kesulitan menjangkau data kompleks yang tingkat kerumitannya tinggi. Beberapa macam tipe data primitif :
a) Boolean (bool) : digunakan untuk menyimpan nilai logika dan hanya memiliki 2 nilai yaitu true dan false.
b) Integer (int) : digunakan untuk angka tanpa pecahan baik positif maupun negatif. Contoh : 10,11,12.
c) Float (float) : digunakan untuk angka pecahan. Contoh : 10.1, 11.5, 12.4.
d) Character (char) : digunakan untuk satu karakter. Contoh : 'a','A'.
e) String (string) : digunakan untuk menyimpan nilai lebih dari 1 karakter. Contoh : 'Apel', 'Strawberry'.
   
#### 2. Tipe Data Abstrak :
   Tipe data abstrak merupakan tipe data yang memiliki sistematik serupa dan didefinisikan melalui operasi matematis tertentu. Deklarasi Abstract Data Type (ADT) terdapat pada beberapa bahasa pemrograman dan bentuk deklarasinya mengikat daftar identifikasi terhadap suatu tipe dengan operasi terkait[2].  Fitur yang dapat digunakan dalam tipe data abstrak antara lain : struct (akses defaultnya bersifat public) dan class (akses defaultnya bersifat private).

#### 3. Tipe Data Koleksi : 
   Tipe data koleksi merupakan tipe data yang berfungsi mengelompokkan, mengelola, dan mengakses beberapa objek dan nilai secara bersamaan. Tipe data koleksi antara lain : array (untuk menyimpan elemen-elemen dengan tipe data yang sama), vector(untuk menyimpan data dalam bentuk elemen-elemen yang alokasi memorinya dilakukan secara otomatis dan bersebelahan), dan map (untuk menyimpan elemen-elemen dengan tipe data yang sama namun bisa digunakan pula untuk tipe data selain integer pada indeksnya).

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream> 
using namespace std;

int main() {
    char op;
    float num1, num2;
    
    cout << "Masukkan operator (+, -, *, /): ";
    cin >> op;
    
    cout << "Masukkan angka pertama: ";
    cin >> num1;
    cout << "Masukkan angka kedua: ";
    cin >> num2;

    switch (op) {
        case '+':
            cout << "Hasil Penjumlahan: " << num1 + num2;
            break;
        case '-':
            cout << "Hasil Pengurangan: " << num1 - num2;
            break;
        case '*':
            cout << "Hasil Perkalian: " << num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                cout << "Hasil Pembagian: " << num1 / num2;
            else
                cout << "Error! Nol tidak boleh sebagai pembagi.";
            break;
        default:
            cout << "Error! Operator is not correct";
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
##### Contoh penggunaan program :
Masukkan operasi : +
Masukkan bilangan pertama : 11
Masukkan bilangan kedua : 13
Hasil penjumlahan : 24
#### Output Guided 1:
![240302_00h00m06s_screenshot](https://github.com/ardelialaksita/photo/blob/4587d9cd4a853ca248386f98fffc24ccf99f9fad/%5BModul%201%5D%20Guided%201.png)


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
**// Struct** digunakan untuk menentukan jenis data struct yang digunakan. Pada program tersebut menggunakan char.
**// Mengisi nilai ke struct** digunakan untuk mengisi apa saja yang akan diinput dalam identitas mahasiswa. Pengetikan kodenya dimulai dari mhs1 kemudian diikuti dengan identitas yang ingin diinput, misalnya **mhs1.address** untuk menggunakan struct dalam alamat mahasiswa. 
**// Mencetak isi struct** dilakukan dengan cara **printf("Nama: %s\n", mhs1.name)** dan seterusnya. Kode **\n** digunakan untuk membuat 'enter' pada line berikutnya. Kode **\n** dapat diganti dengan **endl;**.
**return 0** digunakan untuk mengakhiri program tersebut.
#### Output Guided 2:
![240302_00h00m06s_screenshot](https://github.com/ardelialaksita/photo/blob/4587d9cd4a853ca248386f98fffc24ccf99f9fad/%5BModul%201%5D%20Guided%202.png)

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
![240302_00h00m06s_screenshot](https://github.com/ardelialaksita/photo/blob/4587d9cd4a853ca248386f98fffc24ccf99f9fad/%5BModul%201%5D%20Guided%203.png)

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
![240302_00h00m06s_screenshot][(https://github.com/ardelialaksita/photo/blob/e4310b9e24bfbc039d23be0af0d5f3d47be707c0/%5BModul%201%5D%20Unguided%201%20Output.png)]

Kode di atas digunakan untuk menentukan bilangan. Program tersebut berisi tentang fungsi untuk menentukan apakah suatu bilangan termasuk bilangan ganjil, bilangan genap, atau bilangan 0 (bukan ganjil dan bukan genap). Terdapat 2 fungsi yaitu fungsi untuk mengecek apakah suatu bilangan termasuk bilangan ganjil dan fungsi untuk mengecek apakah apakah suatu bilangan termasuk bilangan genap. Tipe data primitif yang digunakan dalam program tersebut yaitu integer atau int dimana cara menentukan suatu bilangan ganjil atau genap dilakukan dengan cara membagi bilangan tersebut dengan 2. 
**num % 2 != 0** artinya jika bilangan tersebut dibagi 2 tidak sama dengan 0, maka bilangan tersebut adalah bilangan ganjil. Kemudian, program akan menjalankan **cout << num << " adalah bilangan ganjil" << endl;** dan akan menghasilkan output **"(bilangan) adalah bilangan ganjil"**.
**num % 2 == 0** artinya jika bilangan tersebut dibagi 2 sama dengan 0, maka bilangan tersebut adalah bilangan genap. Kemudian, program akan menjalankan **cout << num << " adalah bilangan genap" << endl;** dan akan menghasilkan output **"(bilangan) adalah bilangan genap"**.
**else** artinya jika bilangan yang diinput adalah 0 dimana bilangan 0 bukan merupakan bilangan ganjil dan bukan bilangan genap. 

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/ardelialaksita/photo/blob/e4310b9e24bfbc039d23be0af0d5f3d47be707c0/%5BModul%201%5D%20Unguided%201%20Full%20SS.png)

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya.

```C++
//CONTOH PROGRAM STRUCT
#include <iostream>
#include <string>
using namespace std;

//Struct
struct Fruit {
    string name;
    string colour;
    string taste;
};

int main() 
{
    struct Fruit fruit1, fruit2;
    fruit1.name = "Durian";
    fruit1.colour = "Kuning";
    fruit1.taste = "Manis";
    fruit2.name = "Lemon";
    fruit2.colour = "Kuning";
    fruit2.taste = "Asam";

    cout << "===== BUAH 1 =====" << endl;
    cout << "Nama Buah : " << fruit1.name << endl;
    cout << "Warna Buah : " << fruit1.colour << endl;
    cout << "Rasa Buah: " << fruit1.taste << endl;
    cout << "===== BUAH 2 =====" << endl;
    cout << "Nama Buah : " << fruit2.name << endl;
    cout << "Warna Buah : " << fruit2.colour << endl;
    cout << "Rasa Buah: " << fruit2.taste << endl;
    return 0;
}
```

```C++
//CONTOH PROGRAM CLASS
#include <iostream>
#include <string>
using namespace std;

//Class
class FruitClass {
    private:
    string name;
    string colour;
    string taste;

    public:
    string getname() {return name};
    string getcolour() {return colour};
    string gettaste() {return taste};

};

int main() 
{
    class FruitClass fruit1, fruit2;
    fruit1.getname = "Durian";
    fruit1.getcolour = "Kuning";
    fruit1.gettaste = "Manis";
    fruit2.getname = "Lemon";
    fruit2.getcolour = "Kuning";
    fruit2.gettaste = "Asam";

    cout << "===== BUAH 1 =====" << endl;
    cout << "Nama Buah : " << fruit1.getname << endl;
    cout << "Warna Buah : " << fruit1.getcolour << endl;
    cout << "Rasa Buah: " << fruit1.gettaste << endl;
    cout << "===== BUAH 2 =====" << endl;
    cout << "Nama Buah : " << fruit2.getname << endl;
    cout << "Warna Buah : " << fruit2.getcolour << endl;
    cout << "Rasa Buah: " << fruit2.gettaste << endl;
    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/ardelialaksita/photo/blob/614339283baac424ce078a4bedd25818e47573b0/%5BModul%201%5D%20Unguided%202%20Output.png)

Kode di atas digunakan untuk mencetak nama, warna, dan rasa suatu buah. Struct memiliki akses default secara public, sedangkan class memiliki akses default private sehingga tidak semua variabel dapat dieksekusi apabila ada kode rivate yang digunakan. 

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/ardelialaksita/photo/blob/614339283baac424ce078a4bedd25818e47573b0/%5BModul%201%5D%20Unguided%202%20Full%20SS.png)

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
![240302_00h00m06s_screenshot](https://github.com/ardelialaksita/photo/blob/4587d9cd4a853ca248386f98fffc24ccf99f9fad/%5BModul%201%5D%20Unguided%203%20Output.png)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/ardelialaksita/photo/blob/4587d9cd4a853ca248386f98fffc24ccf99f9fad/%5BModul%201%5D%20Unguided%203%20Full%20SS.png)


## Kesimpulan
Tipe data merupakan klasifikasi atau pengelompokan jenis-jenis data. Variabel merupakan kontainer yang dapat digunakan untuk menyimpan suatu nilai pada sebuah program dengan tipe data tertentu[3]. Untuk menentukan tipe data yang digunakan dalam variabel dapat dilihat melalui klasifikasi tipe-tipe data. Tipe data ada 3: tipe data primitif yaitu sudah ditentukan oleh sistem, tipe data abstrak yaitu dibentuk oleh programer sendiri, dan tipe data koleksi yaitu digunakan untuk mengelompokkan nilai dan objek secara bersamaan. Korelasi antara tipe data tersebut yaitu tipe data abstrak sering digunakan untuk mengimplementasikan tipe data koleksi sehingga memungkinkan pengguna untuk berinteraksi dengan strultur data tanpa perlu mengetahui detail implementasinya. 

## Referensi
[1] Litalia (2023, September 30). Pengertian Tipe Data Beserta Fungsi dan Jenis-Jenis Tipe Data [online]. Available: https://www.jurnalponsel.com/pengertian-tipe-data/.
[2] Mitchell, John C.; Plotkin, Gordon. "Abstract Types Have Existential Type" ACM Transactions on Programming Languages and Systems. 10 (3). 1988.
[3] Tim Dosen Common Laboratory. "Modul Praktikum Pemrograman Berorientasi Obyek". 2009.
