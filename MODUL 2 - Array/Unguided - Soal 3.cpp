#include <iostream>
using namespace std;

int main()
{
    // deklarasi maksimum, minimum, rata-rata, total, dan lokasi
    int maks, min, total = 0, a, i = 0, lokasiMaks, lokasiMin;
    double mean;

    // user memasukkan panjang array
    cout << "Masukkan panjang array : ";
    cin >> a;

    // deklarasi array
    int arr[a];

    // user memasukkan value array dan menampilkan value tersebut berada pada array ke berapa
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> arr[i];

        // menambahkan elemen pada total
        total += arr[i];
    }

    // mencari nilai maksimum pada array
    maks = arr[0];
    lokasiMaks = 0;
    for (i = 0; i < a; i++)
    {
        if (arr[i] > maks)
        {
            maks = arr[i];
            lokasiMaks = i;
        }
    }

    // mencari nilai minimum pada array
    min = arr[0];
    lokasiMin = 0;
    for (i = 0; i < a; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            lokasiMin = i;
        }
    }

    // menghitung nilai rata-rata
    mean = static_cast<double>(total) / a;
    cout << endl;

    // program menu
    int pilihan;
    do
    {
        cout << "\n=========== Menu =============" << endl;
        cout << "1. Nilai maksimum pada array" << endl;
        cout << "2. Nilai minimum pada array" << endl;
        cout << "3. Nilai rata-rata pada array" << endl;
        cout << "4. Selesai." << endl;
        cout << "==============================" << endl;
        cout << "Apa yang ingin Anda cari? : ";
        cin >> pilihan;

        // switch statement begins
        switch (pilihan) {
            // if user enter 1, programs will run case 1
            case 1:
                cout << "Nilai maksimum adalah " << maks << " berada pada Array ke-" << lokasiMaks << endl;
                break;
            // if user enter 2, programs will run case 2
            case 2:
                cout << "Nilai minimum adalah " << min << " berada pada Array ke-" << lokasiMin << endl;
                break;
            // if user enter 3, programs will run case 3
            case 3:
                cout << "Nilai rata-rata adalah " << mean << endl;
                break;
            // if user enter 4, programs will run case 4
            case 4:
                cout << "Program pencarian selesai. Terima kasih!" << endl;
                break;
            // if user input the menu other than 1, 2, 3, 4
            // error message will display cause the menu isn't valid
            default:
                cout << "Error! Pilihan tidak valid. Silakan pilih menu lainnya." << endl;
                break;
            // switch statement ends
        }
    } while (pilihan != 4);

    cout << endl;
    cout << "Code by : Ardelia Rachma Laksita" << endl;
    
    return 0;
}