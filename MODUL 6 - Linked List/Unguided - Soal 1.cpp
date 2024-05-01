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
void modifyHead(string newName, long long newNim) {
    if (!isEmpty()) {
        string nama = head->nama;
        long long nim = head->nim;
        head->nama = newName;
        head->nim = newNim;
        cout << "Data berhasil diubah" << endl;
    } else {
        cout << "Data mahasiswa tidak ditemukan." << endl;
    } 
}

// fungsi ubah data tengah list
void modifyMiddle(int position, string newName, long long newNim) {
    if (!isEmpty()) {
        Mahasiswa *temp = head;
        string nama;
        long long nim;
        
        for (int i = 1; i < position && temp != NULL; i++) {
            nama = temp->nama;
            nim = temp->nim;
            temp = temp->next;
        }
        if (temp != NULL) {
            nama = temp->nama;
            nim = temp->nim;
            temp->nama = newName;
            temp->nim = newNim;
            cout << "Data mahasiswa berhasil diubah." << endl;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// fungsi ubah data belakang list
void modifyTail(string newName, long long newNim) {
    if (!isEmpty()) {
        Mahasiswa *temp = head;

        // Mencapai node terakhir
        while (temp->next != head) {
            temp = temp->next;
        }

        // Mengubah data pada node terakhir
        temp->nama = newName;
        temp->nim = newNim;

        cout << "Data mahasiswa berhasil diubah." << endl;
    } else {
        cout << "Data mahasiswa tidak ditemukan." << endl;
    }
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

            cout << "Data mahasiswa berhasil dihapus." << endl;
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

        cout << "Data mahasiswa berhasil dihapus." << endl;
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

            cout << "Data mahasiswa berhasil dihapus." << endl;
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
    if (!isEmpty()) {
        cout << "======================== DATA MAHASISWA ===========================" << endl;
        cout << "|\tPosisi\t|\tNama\t\t|\tNIM\t\t|" << endl;
        cout << "-------------------------------------------------------------------" << endl;

        int position = 1;
        Mahasiswa* current = head;
        do {
            cout << "|\t" << position << "\t|\t " << left << setw(15) << current->nama << "|\t" << setw(15) << current->nim << " |" << endl;
            current = current->next;
            position++; 
        } while (current != head); 
        cout << "-------------------------------------------------------------------" << endl; 
    } else {
        cout << "List tersebut kosong. Tidak ada data yang ditemukan di dalam list. Silakan masukkan data terlebih dahulu." << endl;
    }
}


// main program
int main() {
    int pilihan;
    string nama;
    long long nim;
    string newName;
    long long newNim;
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
                cout << "Masukkan nama baru mahasiswa : ";
                cin >> newName;
                cout << "Masukkan NIM baru mahasiswa : ";
                cin >> newNim;
                modifyHead(newName, newNim);
                break;
            case 5:
                cout << "Masukkan posisi mahasiswa yang ingin diubah : ";
                cin >> position;
                cout << "Masukkan nama baru mahasiswa : ";
                cin >> newName;
                cout << "Masukkan NIM baru mahasiswa : ";
                cin >> newNim;
                modifyMiddle(position, newName, newNim);
                break;
            case 6:
                cout << "Masukkan nama baru mahasiswa : ";
                cin >> newName;
                cout << "Masukkan NIM baru mahasiswa : ";
                cin >> newNim;
                modifyTail(newName, newNim);
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
                cout << "============================================================================" << endl;
                cout << "Code by : Ardelia Rachma Laksita" << endl;
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
