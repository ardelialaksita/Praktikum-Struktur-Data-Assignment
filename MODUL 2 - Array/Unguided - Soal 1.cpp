#include <iostream>
using namespace std;

int main ()
{
    // user memasukkan panjang array
    int a;
    cout << "Masukkan panjang array: ";
    cin >> a;

    // deklarasi array
    int array[a];

    // user memasukkan value array sesuai panjang array yang telah diinput sebelumnya
    cout << "Masukkan value array: " << endl;
    for (int i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }

    // menampilkan data array
    cout << "Data Array: ";
    for (int i = 0; i < a; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";

    // menampilkan nomor genap pada elemen array menggunakan modulo % 2 menghasilkan angka 0 (habis)
    cout << "Nomor Genap: ";*
    for (int i = 0; i < a; i++)
    {
        if (array[i] % 2 == 0)
        {
            cout << array[i] << " ";
        }
    }
    cout << "\n";

    // menampilkan nomor ganjil pada array menggunakan modulo % 2 menghasilkan angka bukan 0 (tidak habis)
    cout << "Nomor Ganjil: ";
    for (int i = 0; i < a; i++)
    {
        if (array[i] % 2 != 0)
        {
            cout << array[i] << " ";
        }
    }
    cout << "\n";

    return 0;
}