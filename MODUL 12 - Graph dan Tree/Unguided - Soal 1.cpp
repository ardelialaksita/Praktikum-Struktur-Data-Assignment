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
