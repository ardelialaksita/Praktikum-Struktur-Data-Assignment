#include <iostream>
using namespace std;

// Ardelia Rachma Laksita (2311110051) S1SD-04 A

// PROGRAM SINGLE LINKED LIST

Struct Node() {
    int head;
    int awal;
    int akhir;
    int bantu;
    int temp;
    int node;
};

void addNodeHead() {
    Node* newNode = baru;
    if(head == awal) {
        data->head = awal;
        head->baru = baru;
        temp = baru;
    }

    temp->tail = baru;
}

void addNodeTail() {
    Node* newNode = baru;
    if(head == awal) {
        data->head = awal;
        head->baru = baru;
        temp = baru;
    }

    head->tail = akhir;
    akhir->tail = baru;
}

void addNodeTengah(int middle, int posisi) {
    for (i = 0; i < 0; i++) {
        if(data[i] == posisi) {
            return;
        }
    }
    Node* newNode = baru;
    head->bantu = head;
    bantu->temp = bantu;
    temp->baru = baru;
    temp = baru;
}

void deleteNodeHead() {
    Node* data = hapus;
    head->hapus = head;
    delete head;
}

void deleteNodeTail() {
    Node* data = hapus;
    head->bantu = bantu;
    bantu->temp = middle;
    delete middle;
}

void deleteNodeTengah(int middle) {
    Node* data = hapus;
    tail->hapus = tail;
    delete tail;
}

void cetakLinkedList() {
    for (i = 0; i < n; i++) {
        cout << "List: " << data << endl;
}

int main() {
    do {
        cout << "===== Program Menu =====" << endl;
        cout << "1. Tambahkan nilai pada node awal (head)" << endl;
        cout << "2. Tambahkan nilai pada node akhir (tail)" << endl;
        cout << "3. Tambahkan nilai pada node tengah (middle)" << endl;
        cout << "4. Hapus node awal" << endl;
        cout << "5. Hapus node akhir" << endl;
        cout << "6. Hapus node tengah" << endl;
        cout << "7. Tampilkan seluruh isi list" << endl;
        cout << "8. Keluar" << endl;
        cout << "Opsi mana yang ingin Ands pilih?: " << endl;
    }

    switch (pilihan) {
        // menambah node head
        case 1: 
            addNodeHead();
            break;
        // menambah node tail
        case 2:
            addNodeTail();
            break;
        // menambah node tengah
        case 3:
            addNodeMiddle();
            break;
        // menghapus node head
        case 4:
            deleteNodeHead();
            break;
        // menghapus node tail
        case 5:
            deleteNodeTail();
            break;
        // menhapus node tengah
        case 6:
            deleteNodeTengah();
            break;
        // tampilkan isi list
        case 7:
            tampilkanList();
        // keluar dari program
        case 8;
            return;
        // jika user memasukkan opsi bukan angka 1 hingga 8    
        default:
            cout << "Opsi yang Anda pilih tidak ada dalam menu. Silaakan masukkan angka lain yang terdapat pada menu."

    }
    cout << endl;
    return 0;
}
