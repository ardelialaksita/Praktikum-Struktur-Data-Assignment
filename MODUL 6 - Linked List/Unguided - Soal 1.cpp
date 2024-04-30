#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// PROGRAM LINKED LIST NON CIRCULAR MAHASISWA DAN NIM DENGAN INPUT OLEH USER

// deklarasi struct untuk mahasiswa
struct Mahasiswa {
    string nama;
    long long nim;
    Mahasiswa* next;
};

// deklarasi head dan tail menggunakan pointer
Mahasiswa* head = NULL;
Mahasiswa* tail = NULL;
Mahasiswa* baru; 
Mahasiswa* help;
Mahasiswa* hapus;

// pengecekan jika list kosong
bool isEmpty() {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}

// membuat node baru
void newNode (string nama, long long nim) {
    baru = new Mahasiswa;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
}

// menghitung list
int countList() {
    help = head;
    int jumlah = 0;

    while (help != NULL) {
        jumlah++;
        help = help->next;
    }
    return jumlah;
}

// fungsi tambah depan 
void insertHead(string nama, long long nim) {

    // membuat node baru
    newNode(nama, nim);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// fungsi tambah tengah
void insertMiddle(string nama, long long nim, int position) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        newNode(nama, nim);

        // transversing
        int nomor = 1;
        help = head;

        while (nomor < position -1) {
            help = help->next;
            nomor++;
        }
        baru->next = help->next;
        help->next = baru;
    }
}

// fungsi tambah belakang
void insertTail(string nama, long long nim) {

    // membuat node baru
    newNode(nama, nim);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// fungsi ubah data depan list
void modifyHead() {
    if (isEmpty()) {
        cout << "List masih kosong." << endl;
        return; 
    }

    long long searchNIM;
    Mahasiswa* current = head;
    Mahasiswa* prev = NULL;

    while (current != NULL) {
        if (current->nim != searchNIM) {
            cout << "Masukkan nama baru mahasiswa : ";
            string newNama;
            getline(cin, newNama);
            cout << "Masukkan NIM baru mahasiswa : ";
            long long newNIM;
            cin >> newNIM;
            cin.ignore();

            current->nama = newNama;
            current->nim = newNIM;

            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Mahasiswa tidak ditemukan." << endl;
}

// fungsi ubah data tengah list
void modifyMiddle(int position) {
    if (isEmpty()) {
        cout << "List masih kosong." << endl;
        return;
    }

    cout << "Masukkan posisi data yang ingin diubah: ";
    string newNama;
    long long newNIM;

    getline(cin, newNama);
    cin >> newNIM;
    cin.ignore();

    Mahasiswa* current = head;
    int count = 1;

    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        cout << "Posisi tidak valid." << endl;
        return;
    }
    cout << "Masukkan nama baru mahasiswa : ";
    cin >> current->nama;
    cout << "Masukkan NIM baru mahasiswa : ";
    cin >> current->nim;
}

// fungsi ubah data belakang list
void modifyTail() {
    if (isEmpty()) {
        cout << "List masih kosong." << endl;
        return; 
    }

    long long searchNIM;
    Mahasiswa* current = head;
    Mahasiswa* prev = NULL;

    while (current != NULL) {
        if (current->nim == searchNIM) {
            if (current->next == NULL) {
                cout << "Masukkan nama baru mahasiswa : ";
                string newNama;
                getline(cin, newNama);
                cout << "Masukkan NIM baru mahasiswa : ";
                long long newNIM;
                cin >> newNIM;
                cin.ignore();

                current->nama = newNama;
                current->nim = newNIM;
            
                cout << "Data mahasiswa berhasil diubah." << endl;
                return;
            }
        }
        prev = current;
        current = current->next;
    }
    cout << "Mahasiswa tidak ditemukan." << endl;
}

// fungsi hapus depan
void deleteHead() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List tersebut kosong!" << endl;
    }
}

// fungsi hapus tengah
void deleteMiddle(int posisi) {
    if (isEmpty() == 0) {

        // transvering
        int nomor = 1;
        help = head;

        while (nomor < posisi - 1) {
            help = help->next;
            nomor++;
        }

        hapus = help->next;
        help->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// fungsi hapus belakang
void deleteTail() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// fungsi hapus seluruh isi list
void clearList() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            help = hapus-> next;
            delete hapus;
            hapus = help;
        }

        delete head;
        head = NULL;
    }

    cout << "Proses menghapus selesai. Seluruh isi list berhasil dihapus. Saat ini tidak ada data pada list tersebut." << endl;
}

// menampilkan isi list
void display() {
    if (isEmpty() == 0) {
        cout << "======= DATA MAHASISWA =======" << endl;
        cout << "NAMA\t\tNIM" << endl;
        cout << "------------------------------" << endl;

        Mahasiswa* current = head;
        do {
            cout << setw(15) << left << current->nama << "\t" << current->nim << endl;
            current = current->next;
        } while (current != head);
    } else {
        cout << "List tersebut kosong. Tidak ada data yang ditemukan di dalam list. Silakan masukkan data terlebih dahulu." << endl;
    }
}


// main program
int main() {
    int pilihan;
    string nama;
    long long nim;
    int position; 
    do {
        cout << "========== PROGRAM MENU LINKED LIST MAHASISWA DAN NIM ==========" << endl;
        cout << "Selamat datang. Silakan pilih menu!" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "1. Tambahkan data baru pada list bagian depan" << endl;
        cout << "2. Tambahkan data baru pada list bagian tengah" << endl;
        cout << "3. Tambahkan data baru pada list bagian belakang" << endl;
        cout << "4. Ubah data pada list bagian depan" << endl;
        cout << "5. Ubah data pada list bagian tengah" << endl;
        cout << "6. Ubah data pada list bagian belakang" << endl;
        cout << "7. Hapus data pada list bagian depan" << endl;
        cout << "8. Hapus data pada list bagian tengah" << endl;
        cout << "9. Hapus data pada list bagian belakang" << endl;
        cout << "10. Hapus seluruh data pada list" << endl;
        cout << "11. Tampilkan isi list" << endl;
        cout << "0. Keluar" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Pilih menu yang Anda inginkan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama mahasiswa : ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa : ";
                cin >> nim;
                cin.ignore();
                insertHead(nama, nim);
                cout << "Data berhasil ditambahkan." << endl;
                cout << "Data baru yang ditambahkan : " << nama << " dengan NIM " << nim << endl;
                break;
            case 2:
                cout << "Masukkan nama mahasiswa : ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa : ";
                cin >> nim;
                cin.ignore();
                cout << "Masukkan posisi : ";
                cin >> position;
                insertMiddle(nama, nim, position);
                cout << "Data berhasil ditambahkan." << endl;
                cout << "Data baru yang ditambahkan : " << nama << " dengan NIM " << nim << endl;
                break;
            case 3:
                cout << "Masukkan nama mahasiswa : ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa : ";
                cin >> nim;
                cin.ignore();
                insertTail(nama, nim);
                cout << "Data berhasil ditambahkan." << endl;
                cout << "Data baru yang ditambahkan : " << nama << " dengan NIM " << nim << endl;
                break;
            case 4:
                modifyHead();
                break;
            case 5:
                cout << "Masukkan posisi data yang ingin diubah: ";
                cin >> position;
                modifyMiddle(position);
                break;
            case 6:
                modifyTail();
                break;
            case 7:
                deleteHead();
                break;
            case 8:
                cout << "Masukkan posisi data yang ingin dihapus : ";
                cin >> position;
                deleteMiddle(position);
                break;
            case 9:
                deleteTail();
                break;
            case 10:
                clearList();
                break;
            case 11:
                display();
                break;
            case 0:
                cout << "Program selesai. Terima kasih." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih opsi operasi yang sesuai." << endl;
                break;
        } 
        cout << "============================================================================" << endl;
        cout << endl;
    } while (pilihan != 0);

    return 0;
}
