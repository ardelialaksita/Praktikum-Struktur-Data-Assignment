#include <iostream>
using namespace std;

// melakukan sorting menggunakan insertion sort secara ascending (menaik)
void insertion_sort_ascending(char arr[], int length) {

    //deklarasi i, j, dan tmp
    int i, j;
    char tmp;

    // for loop dan while loop untuk inisialisasi pada proses insertion sort secara ascending
    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        } // end of while loop
    } // end of for loop
} // end of void function

// melakukan sorting menggunakan insertion sort secara descending (menurun)
void insertion_sort_descending(char arr[], int length) {

    //deklarasi i, j, dan tmp
    int i, j;
    char tmp;

    // for loop dan while loop untuk inisialisasi pada proses insertion sort secara descending
    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        } // end of while loop
    } // end of for loop
} // end of void function

// mencetak dan menampilkan array
void print_array(char a[], int length) {
    
    for(int i=0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {

    // deklarasi length untuk menyimpan panjang array
    int length;
    
    // user memasukkan panjang array
    cout << "input (n) = ";
    cin >> length;

    // deklarasi array bertipe karakter dengan length yang ditentukan oleh user
    char a[length];

    // user memasukkan beberapa karakter sesuai dengan panjang yang telah diinput
    cout << "Masukkan " << length << " karakter: " << endl;
    
    // for looping untuk mnenampilkan karakter ke-berapa yang akan diisi oleh user
    for (int i = 0; i < length; i++) {
        cout << "Karakter ke-" << i + 1 << ": ";
        cin >> a[i];
    }
    cout << endl;
    
    // menampilkan karakter sebelum sorting
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    // memanggil fungsi untuk mengurutkan karakter secara ascending
    insertion_sort_ascending(a, length);

    // menampilkan karakter setelah diurutkan secara ascending
    cout << "\nUrutan karakter setelah ascending sort: " << endl;
    print_array(a, length);

    // memanggil fungsi untuk mengurutkan karakter secara descending
    insertion_sort_descending(a, length);
    
    // menampilkan karakter setelah diurutkan secara descending
    cout << "\nUrutan karakter setelah descending sort: " << endl;
    print_array(a, length);

}