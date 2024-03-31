#include <iostream>
using namespace std;

// fungsi untuk melakukan sorting menggunakan bubble sort secara ascending (menaik)
void bubble_sort(double arr[], int length) {
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++) {
            if (arr[i] > arr[i+1]) {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                not_sorted = true;
            } // end of if
        } // end of for loop
    } // end of while loop
} // end of bubble_sort

// mencetak dan menampilkan isi array
void print_array(double a[], int length) {

    for (int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {

    // menentukan panjang array (banyak data yang dimasukkan)
    int length = 5;
    // memasukkan bilangan sesuai panjang yang ditentukan
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};

    // menampilkan urutan bilangan sebelum diurutkan
    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    // memanggil fungsi untuk menjalankan bubble sort
    bubble_sort(a, length);

    // menampilkan urutan bilangan setelah diurutkan
    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}