#include <iostream>
using namespace std;

// mendefinisikan struktur buku dengan panjang array sebanyak 5 pada masing-masing kategori
struct buku {
    string judulBuku[5]; // deklarasi tipe data judulBuku dan banyak datanya
    string pengarang[5]; // deklarasi tipe data pengarang dan banyak datanya
    string penerbit[5]; // deklarasi tipe data penerbit dan banyak datanya
    int tebalHalaman[5]; // deklarasi tipe data tebal Halaman dan banyak datanya
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
