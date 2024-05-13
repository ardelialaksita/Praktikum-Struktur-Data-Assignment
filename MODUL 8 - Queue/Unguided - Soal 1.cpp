#include <iostream>
using namespace std;

// struct Node
struct Node {
    // deklarasi data
    string data;
    Node *next;
};

// class Queue
class Queue {
// bagian public dari class Queue
public :
    Queue() {
        // deklarasi size, data front, dan data back
        size = 0;
        front = NULL;
        back = NULL;
    }

    // mengecek apakah data antrian penuh atau tidak
    bool isFull() {
        return false;
    }

    // mengecek apakah antrian kosong atau tidak
    bool isEmpty() {
        return size == 0;
    }

    // tambahkan data ke dalam antrian
    void enqueueAntrian(string data) {
        Node* baru = new Node();
        baru->data = data;
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

    // lihat data antrian teller
    void viewQueue() {
        cout << "Data antrian teller: " << endl;
        Node* current = front;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << "." << current->data << endl;
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
    // deklarasi queueTeller dengan menggunakan fungsi di dalam class queue
    Queue queueTeller;
    // tambahkan data ke antrian
    queueTeller.enqueueAntrian("Andi");
    queueTeller.enqueueAntrian("Maya");
    // lihat data di dalam antrian saat ini
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;
    // hapus data dalam antrian (otomatis hapus data front)
    queueTeller.dequeueAntrian();
    // lihat data di dalam antrian saat ini
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;
    // kosongkan atau bersihkan seluruh data antrian 
    queueTeller.clearQueue();
    // lihat data di dalam antrian saat ini
    queueTeller.viewQueue();
    // tampilkan jumlah atau banyak data dalam antrian saat ini
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    cout << endl;

    return 0;
}
