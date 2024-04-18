#include <iostream>
#include <string>
using namespace std;

// deklarasi kalimat, vokal, konsonan, dan huruf
string kalimat;
int vokal = 0;
int konsonan = 0;
char huruf;

// program melakukan pencarian menggunakan binary search
bool binarysearch()
{
    // searching
    int awal, akhir, tengah;
    awal = 0;
    akhir = kalimat.size() - 1;
    while (awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        // jika indeks tengah pada kalimat sama dengan huruf, maka akan mengembalikan nilai true
        if (kalimat[tengah] == huruf)
        {
            return true;
        }
        // jika indeks tengah pada kalimat lebih kecil dari huruf, maka akan menjalankan awal = tengah + 1
        else if (kalimat[tengah] < huruf)
        {
            awal = tengah + 1;
        }
        // jika indeks tengah pada kalimat tidak lebih kecil dari huruf, maka akan menjalankan akhir = tengah - 1
        else
        {
            akhir = tengah - 1;
        }
    }
    return false;
}

// melakukan pencarian dan penghitungan jumlah huruf vokal dan huruf konsonan
void search_vokalkonsonan()
{
    for (int i = 0; i < kalimat.length(); i++)
    {
        // pencarian dan penghitungan jumlah huruf vokal
        char huruf = tolower(kalimat[i]);
        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o')
        {
            vokal++;
        }
        // pencarian dan penghitungan jumlah huruf konsonan
        else if (huruf == 'b' || huruf == 'c' || huruf == 'd' || huruf == 'f' || huruf == 'g' || huruf == 'h' || huruf == 'j' || huruf == 'k' || huruf == 'l' || huruf == 'm' || huruf == 'n' || huruf == 'p' || huruf == 'q' || huruf == 'r' || huruf == 's' || huruf == 't' || huruf == 'v' || huruf == 'w' || huruf == 'x' || huruf == 'y' || huruf == 'z')
        {
            konsonan++;
        }
    }
}

// main program
int main()
{
    // mencetak header pada program
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "===== Program Mencari Sebuah Huruf pada Suatu Kalimat Menggunakan Binary Search =====" << endl;
    // user memasukkan kalimat tanpa menggunakan huruf kapital
    cout << "Masukkan kalimat (tanpa kapital): ";
    getline(cin, kalimat);

    // user memasukkan huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin Anda cari : ";
    cin >> huruf;

    // melakukan pencarian menggunakan binary search
    bool ketemu = binarysearch();
    // memanggil fungsi untuk melakukan pencarian dan penghitungan jumlah huruf vokal dan konsonan
    search_vokalkonsonan();

    // tampilkan data setelah dilakukan pencarian
    // menampilkan output jika huruf yang dicari ditemukan pada kalimat yang diinput
    if (ketemu)
    {
        cout << "Huruf '" << huruf << "' ditemukan dalam kalimat." << endl;
        cout << "Jumlah huruf vokal dalam kalimat: " << vokal << endl;
        cout << "Jumlah huruf konsonan dalam kalimat: " << konsonan << endl;
    }
    // menampilkan output jika huruf yang dicari tidak ditemukan pada kalimat yang diinput
    else
    {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
        cout << "Jumlah huruf vokal dalam kalimat: " << vokal << endl;
        cout << "Jumlah huruf konsonan dalam kalimat: " << konsonan << endl;
    }
    
    // mencetak footer pada program
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << endl;
    return 0;
}