#include <iostream>
#include <string>
using namespace std;

// struct Node
struct Node {
    // deklarasi Nama dan Nim
    string Nama;
    string Nim;
    Node *next;
};

// class Queue
class Queue {
// bagian public dari class Queue
public:
    Queue() {
        // deklarasi size, data front dan data back
        size = 0;
        front = NULL;
        back = NULL;
    }

    // mengecek apakah antrian penuh atau tidak
    bool isFull() {
        return false;
    }

    // mengecek apakah antrian kosong atau tidak
    bool isEmpty() {
    return size == 0;
    }

    // tambahkan data ke dalam antrian 
    void enqueueAntrian(string Nama, string Nim) {
        Node* baru = new Node();
        baru->Nama = Nama;
        baru->Nim = Nim;
        baru->next = NULL;

        // apabila antrian kosong, maka front dan back dimulai dari node baru
        if (isEmpty()) {
            front = baru;
            back = baru;
        // apabila antrian tidak kosong, maka dimulai dari node sebelumnya (back)
        } else {
            back->next = baru;
            back = baru;
        }

        size++;
    }

    // hapus data dalam antrian (otomatis menghapus front)
    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian Kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    // lihat jumlah data dalam antrian 
    int countQueue() {
        return size;
    }

    // hapus seluruh data dalam antrian (kosongkan antrian)
    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    // lihat data antrian teller dengan atribut nama dan NIM mahasiswa
    void viewQueue() {
        cout << "Data antrian teller: " << endl;
        Node* current = front;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". Nama: " << current->Nama << " (Nim: " << current->Nim << ")" << endl;
            current = current->next;
        }
    }

    ~Queue() {
        clearQueue();
    }

// bagian private dari class Queue
private:
    // deklarasi data front, back, dan size
    Node* front;
    Node* back;
    int size;
};

// main program (program utama)
int main() {
    // deklarasi class Queue serta tipe data Nama dan Nim
    Queue queueTeller;
    string Nama, Nim;

    // user input nama dan NIM mahasiswa pertama
    cout << "Masukkan Nama mahasiswa: ";
    cin >> Nama;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> Nim;
    // panggil fungsi untuk menambahkan data ke dalam antrian
    queueTeller.enqueueAntrian(Nama, Nim);

    // user input nama dan NIM mahasiswa kedua
    cout << "Masukkan Nama mahasiswa: ";
    cin >> Nama;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> Nim;
    // panggil fungsi untuk menambahkan data ke dalam antrian
    queueTeller.enqueueAntrian(Nama, Nim);

    // lihat data di dalam antrian saat ini
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;

    // hapus antrian (data yang dihapus adalah front)
    queueTeller.dequeueAntrian();
    // lihat data di dalam antrian saat ini (setelah data front sebelumnya dihapus)
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini 
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;

    // bersihkan atau hapus seluruh antrian sehingga antrian kosong
    queueTeller.clearQueue();
    // lihat data di dalam antrian saat ini (setelah semua antrian dihapus)
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;

    return 0;
}
