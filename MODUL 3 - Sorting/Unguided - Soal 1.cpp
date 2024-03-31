#include <iostream>
using namespace std;

// selection sort secara descending menggunakan fungsi void 
void selection_sort(double array[], int n) {

    // deklarasi posisiMaks dan temp
    int posisiMaks; 
    double temp;

    // perulangan for untuk menjalankan proses sorting secara descending (terbesar ke terkecil)
    for (int i=0; i < n-1; i++) {
        posisiMaks = i;
        for (int j=i+1; j < n; j++) {
            // array[j] lebih besar daripada array[post_maks] karena sorting dilakukan secara descending (menurun)
            if (array[j] > array[posisiMaks]) {
                posisiMaks = j;
            } // end of if
        } // end of for loop

        if (posisiMaks != i) {
                temp = array[i];
                array[i] = array[posisiMaks];
                array[posisiMaks] = temp;
        } // end of if
    } // end of for loop
}

// mencetak dan menampilkan array
void print_array(double a[], int length) {

    for (int i=0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {
    
    // menentukan panjang array (banyak data yang dimasukkan)
    int length = 5;
    // memasukkan data array
    double a[length] = {3.8, 2.9, 3.3, 4.0, 2.4};  

    // menampilkan data Indeks Prestasi Semester Mahasiswa sebelum diurutkan 
    cout << "Indeks Prestasi Semester (IPS) Mahasiswa sebelum sorting: " << endl;
    print_array(a, length);

    // memanggil fungsi untuk menjalankan selection sort
    selection_sort(a, length);

    // menampilkan data Indeks Prestasi Semester Mahasiswa setelah diurutkan secara descending (dari terbesar ke terkecil)
    cout << "\nIndeks Prestasi Semester (IPS) Mahasiswa setelah sorting dari terbesar ke terkecil: " << endl;
    print_array(a, length);

}