#include <iostream>
#include <string>
using namespace std;

// melakukan sorting menggunakan bubble sort secara ascending (menaik)
void bubble_sort(string array[], int length) {
    bool before_sorted = true;
    int j=0;
    string tmp;

    // while loop untuk melakukan iterasi selama proses sorting
    while (before_sorted){
        before_sorted = false;
        j++;
        
        // for loop untuk membandingkan antar elemen dan menukar posisi 
        for (int i = 0; i < length - j; i++) {
            if (array[i] > array[i+1]) {
                tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
                before_sorted = true;
            } // end of if
        } // end of for loop
    } // end of while loop
} // end of bubble_sort

// mencetak dan menampilkan array
void print_array(string nama_warga[], int length) {

    for (int i = 0; i < length; i++) {
        cout << nama_warga[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {

    // mengisi panjang array (tanpa menggunakan input oleh user)
    int length = 10;
    // mengisi nama-nama warga dalam array sesuai panjang (length) yang telah ditentukan sebelumnya
    string nama_warga[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    // menampilkan nama warga sebelum diurutkan
    cout << "Urutan nama warga sebelum sorting: " << endl;
    print_array(nama_warga, length);

    // memanggil fungsi untuk melakukan bubble sort secara ascending
    bubble_sort(nama_warga, length);

    // menampilkan nama warga setelah diurutkan sesuai alfabet (A-Z)
    cout << "\nUrutan nama warga sesuai alfabet (A-Z): " << endl;
    print_array(nama_warga, length);
}