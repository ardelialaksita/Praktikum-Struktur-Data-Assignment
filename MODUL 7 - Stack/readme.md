# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Ardelia Rachma Laksita - 2311110051</p>

## Table of Contents
1. [Dasar Teori](#dasar-teori)
2. [Guided](#guided)
3. [Unguided](#unguided)
4. [Kesimpulan](#kesimpulan)
5. [Referensi](#referensi)

## Dasar Teori
Stack adalah struktur data yang mengoperasikan teknik berdasarkan LIFO (Last In First Out) []. 

### Operasi pada Stack :
- push : digunakan untuk menambahkan (push) suatu item ke dalam stack.
- pop : digunakan untuk menghapus (pops) suatu item dari dalam stack.
- peek : digunakan untuk mengembalikan _top item_ dari stack tanpa menghilangkannya.
- isFull : digunakan untuk mengecek apakah stack penuh atau tidak.
- isEmpty : digunakan untuk mengecek apakah stack kosong atau tidak. 

### Implementasi Stack :

Berikut merupakan implementasi pada stack.
![Cuplikan layar 2024-05-06 143446](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/08dd1e3c-4280-46b8-a0a0-6355fb2fb481)

## Guided 

### 1. Data Stack Buku

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty(){
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    }

    else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }

        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top; i > 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya Data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";
    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();
    return 0;
}

```
Kode di atas digunakan untuk menampilkan data stack buku dimana isinya terdapat deretan atau tumpukan judul buku, posisi buku, pengecekan apakah data kosong atau tidak, pengecekan apakah data penuh atau tidak, banyak data pada stack (tumpukan) tersebut, serta jumlah data pada stack (tumpukan) tersebut setelah dihapus.

`string arrayBuku[5];
int maksimal = 5, top = 0;`
Kode tersebut artinya panjang array bukunya adalah 5 yaitu terdapat 5 buku pada array tersebut. Karena int maksimal adalah 5, maka banyak bukunya boleh kurang dari 5, namun tidak boleh lebih dari 5. 

- Apabila stack (tumpukan) sudah penuh, maka kode `bool isFull()` akan membuat program menjalankan `return (top == maksimal);` karena telah mencapai jumlah maksimal buku yang bisa disimpan oleh array yaitu sebanyak 5. Tipe data yang digunakan adalah boolean.
- Apabila stack (tumpukan) masih kosong, maka kode `bool isEmpty()` akan membuat program menjalankan `return (top == 0);` karena jumlahnya masih 0. Tidak ada buku sama sekali yang disimpan oleh array tersebut. Tipe data yang digunakan adalah boolean.
- `void pushArrayBuku(string data)` merupakan fungsi void yang digunakan untuk menambahkan buku pada array. Program akan menampilkan "Data telah penuh" apabila data yang disimpan array sudah penuh. Apabila data masih belum penuh, maka program akan tetap menambahkan buku pada _top_ array menggunakan `arrayBuku[top] = data;` hingga `top++;`. Tipe datanya adalah string.
- `void popArrayBuku()` nerupakan fungsi void yang digunakan untuk menghapus data pada list atau array. Apabila tidak ada data pada array atau `if (isEmpty())`, maka program akan mencetak output "Tidak ada data yang dihapus menggunakan `cout << "Tidak ada data yang dihapus" << endl;`. Apabila terdapat data pada aray atau list tersebut, maka program akan menghapus salah satu datanya menggunakan `arrayBuku[top - 1] = "";` dan `top--;`. Array akan terus berkurang karena menggunakan indeks top--;
- `void peekArrayBuku(int posisi)` merupakan fungsi void yang digunakan untuk melihat isi array buku berdasarkan posisinya. Jika tidak ada data pada array atau `if (isEmpty())`, maka program akan menjalankan `cout << "Tidak ada data yang bisa dilihat" << endl;` dan mencetak output "Tidak ada data yang bisa dilihat". Jika terdapat data pada array tersebut, maka program akan menjalankan perulangan for yaitu `for (int i = 1; i <= posisi; i++)` dan `cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;` untuk mencetak **"Posisi ke (posisi buku) adalah (nama buku)"**.
- `int countStack()` digunakan untuk menghitung banyaknya data pada stack.
- `void changeArrayBuku(int posisi, string data)` digunakan untuk mengubah isi array buku memasukkan posisinya terlebih dahulu. Apabila posisinya melebihi data maksimal yang ada, maka program akan menjalankan `cout << "Posisi melebihi data yang ada" << endl;` dan mencetak **"Posisi melebihi data yang ada"**.
- `void destroyArrayBuku()` digunakan untuk menghapus seluruh isi array sehingga list buku menjadi kosong.
- `void cetakArrayBuku() ` digunakan untuk menampilkan isi list atau array tersebut yang terdiri atas data-data buku. Jika tidak ada buku pada array, maka outputnya adalah **"Tidak ada data yang dicetak"**.

#### Penjelasan Main Program :
![Cuplikan layar 2024-05-06 190621](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/cecaa93a-6c14-482a-817d-0b89ab9ae3a7)

Pada main program, user menggunakan push array sebanyak 5 kali yaitu `pushArrayBuku("Kalkulus");`, `pushArrayBuku("Struktur Data");`, `pushArrayBuku("Matematika Diskrit");`, `pushArrayBuku("Dasar Multimedia");`, dan `pushArrayBuku("Inggris");` sehingga pada array tersebut terdapat 5 data buku yaitu Kalkulus, Struktur Data, Matematika Diskrit, Dasar Multimedia, dan Inggris. Data yang terbaru akan ditambahkan ke posisi depan. Berikut urutan posisi datanya.

- Posisi 1 : Inggris (top)
- Posisi 2 : Dasar Multimedia
- Posisi 3 : Matematika Diskrit
- Posisi 4 : Struktur Data
- Posisi 5 : Kalkulus

Selanjutnya, user mencetak array tersebut dengan cara memanggil fungsi `cetakArrayBuku();`.

![Cuplikan layar 2024-05-06 190637](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/9b4eb5d5-099f-4bca-90f0-a365c1c8508e)

Kode `cout << "Apakah data stack penuh? " << isFull() << endl;` dan `cout << "Apakah data stack kosong? " << isEmpty() << endl;` digunakan untuk mencetak pertanyaan **"Apakah data stack penuh? "** dan **"Apakah data stack kosong? "** pada output. 1 merupakan True yang artinya stack tersebut penuh. Sedangkan 0 merupakan False yang artinya stack tersebut tidak kosong.

![Cuplikan layar 2024-05-06 190708](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/07c7ceec-c8a9-4f39-b052-73a9a48bf237)

`peekArrayBuku(2);` digunakan untuk melihat data pada posisi kedua. Data pada posisi kedua adalah buku dengan judul "Dasar Multimedia".

![Cuplikan layar 2024-05-06 190723](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/010dc67c-4b3d-40fd-aa06-f6c4799f1d60)

`popArrayBuku();` digunakan untuk menghapus data yang berada pada posisi top yaitu Inggris sehingga datanya sekarang tinggal 4. Berikut posisi bukunya.

- Posisi 1 : Dasar Multimedia (top)
- Posisi 2 : Matematika Diskrit
- Posisi 3 : Struktur Data
- Posisi 4 : Kalkulus

![Cuplikan layar 2024-05-06 190731](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/bbaa7076-cb6a-45e6-809e-690642e19d29)
`changeArrayBuku(2, "Bahasa Jerman");` digunakan untuk mengubah data kedua menjadi buku berjudul "Bahasa Jerman". Pada posisi kedua diduduki oleh "Matematika Diskrit" sehingga posisi buku setelah data diubah yaitu sebagai berikut.

- Posisi 1 : Dasar Multimedia (top)
- Posisi 2 : Bahasa Jerman
- Posisi 3 : Struktur Data
- Posisi 4 : Kalkulus

`cetakArrayBuku();` digunakan untuk menampilkan isi data array tersebut

`destroyArrayBuku();` digunakan untuk menghapus seluruh isi array sehingga array atau list tersebut menjadi kosong. 

![Cuplikan layar 2024-05-06 194514](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/15116276-4861-4bf5-a168-a255b820fc86)

`cout << "Jumlah data setelah dihapus: " << top << endl;` dan `cetakArrayBuku();` digunakan untuk mencetak jumlah data setelah dihapus yaitu 0.

#### Output Guided 1:
![Cuplikan layar 2024-05-06 194537](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/14da4c36-5b2e-4c66-ac9e-75e4d5ccb98d)

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// class deret huruf 
class deretHuruf {
    // bagian public dari class deretHuruf
    public:
    deretHuruf() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // menambahkan huruf
    void push(char hurufAwal) {
        node* temp = new node;
        temp->words = hurufAwal;
        temp->next = NULL;

        if (size == 0) {
            head = temp;
            tail = temp;
            head->prev = NULL;
        }
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    // menghapus huruf
    char pop() {
        char words = head->words;
        if (head == tail) {
            delete head;
        }
        else {
            node* temp = head;
            head = head->next;
            head->prev;
            temp->next = NULL;
            delete temp;
        }
        size--;
        return words;
    }
    
    // bagian private dari class deretHuruf berisi struct dari node
    private:
    struct node {
        char words;
        node* next;
        node* prev;
    };

    // deklarasi size, words, dhead, dan tail menggunakan pointer node dalam private class deretHuruf
    int size;
    char words;
    node* head;
    node* tail;
};

// class stack (tumpukan) huruf
class stack {
    // bagian public dari class stack
    public:
    stack() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // menambahkan huruf
    void push (char hurufAwal) {
        node* temp = new node;
        temp->words = hurufAwal;
        temp->next = NULL;

        if (size == 0) {
            head = temp;
            tail = temp;
            tail->prev = NULL;
        }

        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    // menghapus huruf
    char pop() {
        words = tail->words;
        if (head == tail) {
            delete head;  
        }

        else{
            node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
        size--;
        return words;
    }

    // bagian private dari class stack berisi struct
    private:
    struct node{
        char words;
        node* next;
        node *prev;
    };

    // deklarasi size, words, head, dan tail dalam private class stack
    int size;
    char words;
    node* head;
    node* tail;
};


// main program (program utama)
int main() {

    // deklarasi kata, hurufAwal, hurufAkhir, checkAgain, firstWord pada class stack dan lastWord pada class words
    string kata;
    char hurufAwal;
    char hurufAkhir;
    char checkAgain;   
    stack firstWord;
    deretHuruf lastWord;
    
    // deklarasi palindrome
    bool palindrome = true;
    // tampilkan head atau judul dari program 
    cout << "=== PALINDROME WORDS CHECK ===" << endl;

    // user menginput kata
    cout << "Masukkan 1 kata: ";
    cin >> kata;
    cout << endl;

    // perulangan for untuk push firstWord dan lastWord 
    for (int i = 0; i < kata.length(); i++) {
        firstWord.push(tolower(kata[i]));
        lastWord.push(tolower(kata[i]));
    }

    // perulangan for untuk pop dan pengecekan palindrome
    for (int i = 0; i < kata.length(); i++) {
        char hurufAwal = firstWord.pop();
        char hurufAkhir = lastWord.pop();

        if (hurufAwal != hurufAkhir) {
            cout << hurufAwal << " != " << hurufAkhir << endl;
            palindrome = false;
        } else {
            cout << hurufAwal << " = " << hurufAkhir << endl; 
        }
    }

    cout << endl;

    // tampilkan hasil
    if (palindrome) {
        cout << "Kata tersebut merupakan kata palindrome." << endl;
        cout << "Semua huruf pada kata tersebut sama sehingga akan menghasilkan urutan huruf yang sama apabila kata dibalik." << endl;
    } else {
        cout << "Kata tersebut bukan merupakan kata palindrome." << endl;
        cout << "Terdapat urutan huruf yang tidak sama sehingga apabila kata tersebut dibalik maka tidak akan menghasilkan bacaan yang sama." << endl;
    }
    cout << "================================================================================================================================" << endl;
    cout << endl;
    return 0;
}

```

Kode tersebut digunakan untuk mengecek apakah suatu kata palindrome atau tidak. Apabila kata tersebut dibalik, maka akan menghasilkan urutan huruf yang sama seperti kata yang belum dibalik. Terdapat dua class pada program tersebut yaitu class deretHuruf dan class stack. Terdapat push yang digunakan untuk menambahkan data, serta terdapat pula pop yang digunakan untuk menghapus data. Pada bagian private masing-masing class harus terdapat deklarasi variabel. Tolower digunakan untuk mengkonversi semua huruf kapital menjadi kecil. 

#### Output dan Penjelasan:
![Cuplikan layar 2024-05-06 200046](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/59f838f4-bae6-4a5d-9e80-6e47ae89b3b7)

Pada output tersebut, kata yang diinput oleh user adalah **Malam**. Selanjutnya, program melakukan pengecekan palindrom menggunakan `for (int i = 0; i < kata.length(); i++)`, `char hurufAwal = firstWord.pop();`, dan `char hurufAkhir = lastWord.pop();`. Karena saat huruf-huruf yang ada pada kata malam dibalik menghasilkan urutan yang sama, maka malam termasuk kata palindrome. Huruf M pada awalan kata Malam yang awalnya menggunakan kapital telah diubah oleh program menjadi huruf kecil menggunakan tolower sehingga pengecekan palindromenya sudah dalam keadaan huruf kecil semua. 

![Cuplikan layar 2024-05-06 200058](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/4bbfebf9-505a-48cd-b0ed-59538734f74b)
Pada output tersebut, kata yang diinput oleh user adalah **Pagi**. Selanjutnya, program melakukan pengecekan palindrom menggunakan `for (int i = 0; i < kata.length(); i++)`, `char hurufAwal = firstWord.pop();`, dan `char hurufAkhir = lastWord.pop();`. Karena saat huruf-huruf yang ada pada kata pagi dibalik tidak menghasilkan urutan yang sama yaitu igap, maka pagi bukan termasuk kata palindrome. Huruf P pada awalan kata Pagi yang awalnya menggunakan kapital telah diubah oleh program menjadi huruf kecil menggunakan tolower sehingga pengecekan palindromenya sudah dalam keadaan huruf kecil semua. 

#### Penjelasan main program:
- Variabel-variabel yang digunakan dalam program harus dideklarasikan tipe datanya terlebih dahulu. Tipe data variabel kata adalah string karena terdapat lebih dari 1 karakter. Tipe data pada variabel hurufAwal dan hurufAkhir adalah char karena hanya memerlukan 1 karakter. hurufAwal merupakan urutan huruf dengan urutan mulai dari awal hingga akhir yang kemudian akan dipasangkan dengan hurufAkhir yang urutannya dimulai dari akhir menuju ke huruf awal. Huruf pertama diperiksa palindromnya dengan huruf terakhir. Apabila tidak sama, maka akan menghasilkan **hurufAwal != hurufAkhir**. Apabila sama, akan menghasilkan **hurufAwal = hurufAkhir**.
- `bool palindrome = true;` merupakan deklarasi palindrome yaitu tipe data boolean dengan deklarasi true.
- `cout << "=== PALINDROME WORDS CHECK ===" << endl;` digunakan untuk mencetak _head of the program_ atau judul program tersebut.
- `cout << "Masukkan 1 kata: ";` dan `cin >> kata;` digunakan untuk memasukkan kata yang akan diinput oleh user.
- Pada perulangan for yang berisi `firstWord.push(tolower(kata[i]));` dan `lastWord.push(tolower(kata[i]));` digunakan untuk menambahkan huruf awal hingga akhir dengan urutan yang sesuai dan urutan berkebalikan. Huruf yang masih dalam bentuk kapital akan diubah menjadi huruf kecil semua menggunakan tolower.
- Pada perulangan for yang berisi `char hurufAwal = firstWord.pop();` dan `char hurufAkhir = lastWord.pop();` digunakan untuk mengecek apakah suatu kata palindrome atau tidak. Urutan huruf dari awal ke akhir akan diperiksa apakah sama seperti urutan huruf dari akhir ke awal atau tidak.

#### Full code Screenshot:
![Cuplikan layar 2024-05-06 200024](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/ebba2d06-d89a-4221-8a0c-1174b6344d67)


### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat.

```C++
#include <iostream>
#include <windows.h>

using namespace std;

// deklarasi stack yang menyimpan karakter
struct Stack {
    char isi[30];
    int top;
} huruf;

// tambahkan karakter ke dalam stack
void push(char x) {
    if (huruf.top == 30) {
        cout << "Stack sudah penuh";
        return;
    }
    huruf.isi[++huruf.top] = x;
}

// keluarkan huruf dari stack
char pop() {
    if (huruf.top == 0) {
        cout << "Stack sudah kosong";
        return ' ';
    }
    return huruf.isi[huruf.top--];
}

// main program (program utama)
int main() {
    char kalimat[30];
    huruf.top = 0;

    // head of the program (judul program)
    cout << "=== PROGRAM MEMBALIK KALIMAT (REVERSE SENTENCES) ===" << endl;
    
    // user input kalimat (boleh lebih dari 3 kata)
    cout << "Masukkan kalimat: ";
    cin.getline(kalimat, sizeof(kalimat));

    // program menampilkan kalimat asli yang diinput user
    cout << "Kalimat asli: " << kalimat;

    // setiap huruf dimasukkan ke dalam stack dengan memanggil fungsi push
    for (int i = 0; kalimat[i] != '\0'; i++) {
        push(kalimat[i]);
    }

    // program menampilkan kalimat yang telah dibalik
    cout << "\nKalimat setelah dibalik: ";

    // balik kalimat dengan mengeluarkan seluruh huruf dari stack dengan memanggil fungsi pop
    while (huruf.top > 0) {
        cout << pop();
    }
    cout << endl;

    return 0;
}

```
#### Output:


#### Full code Screenshot:



## Kesimpulan


## Referensi
- [1] Nordeen, A., C++ Learn in 24 Hours. Edisi Pertama. Delaware : Guru99, 2022.
- [2] 
