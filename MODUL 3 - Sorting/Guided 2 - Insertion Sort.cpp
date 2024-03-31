#include <iostream>
using namespace std;

// fungsi untuk melakukan sorting menggunakan insertion sort secara descending (menurun)
void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        } // end of while loop
    } // end of for loop
}

// mencetak dan menampilkan isi array
void print_array(char a[], int length) {
    
    for(int i=0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {

    // menentukan panjang array (banyak data yang dimasukkan)
    int length = 6;
    // memasukkan karakter sesuai panjang yang ditentukan
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    // menampilkan urutan karakter sebelum diurutkan
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    // memanggil fungsi untuk melakukan insertion sort
    insertion_sort(a, length);

    // menampilkan urutan karakter setelah diurutkan 
    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}