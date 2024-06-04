#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// struktur data untuk setiap node
struct Node {
    long long NIM;
    int nilai;
    Node* next;
    Node(long long NIM, int nilai) : NIM(NIM), nilai(nilai), next(nullptr) {}
};

// class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // insertion
    void insert(long long NIM, int nilai) {
        int index = hash_func(NIM);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->NIM == NIM) {
                current->nilai = nilai;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(NIM, nilai);
        node->next = table[index];
        table[index] = node;
    }

    // searching berdasarkan NIM
    int get(long long NIM) {
        int index = hash_func(NIM);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->NIM == NIM) {
                return current->nilai;
            }
            current = current->next;
        }
        return -1; // Tidak ditemukan
    }

    // menghapus berdasarkan NIM
    void remove(long long NIM) {
        int index = hash_func(NIM);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->NIM == NIM) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // searching berdasarkan nilai
    void getNilai(int min, int max) {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                if (current->nilai >= min && current->nilai <= max) {
                    cout << "NIM: " << current->NIM << ", Nilai: " << current->nilai << endl;
                }
                current = current->next;
            }
        }
    }

    // traversal untuk menampilkan hash table
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << "NIM: " << current->NIM << ", Nilai: " << current->nilai << endl;
                current = current->next;
            }
        }
    }
};

void optionMenu() {
    cout << "================ PROGRAM DATA MAHASISWA ==================" << endl;
    cout << "1. Tambah data mahasiswa" << endl;
    cout << "2. Hapus data mahasiswa" << endl;
    cout << "3. Cari data mahasiswa berdasarkan NIM" << endl;
    cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80-90)" << endl;
    cout << "5. Tampilkan semua data mahasiswa" << endl;
    cout << "6. Keluar" << endl;
    cout << "Opsi mana yang ingin Anda pilih? : ";
}

// program utama (main program)
int main() {
    HashTable ht;
    int option, NIM, nilai;

    while (true) {
        optionMenu();
        cin >> option;
        switch (option) {
            // insert data mahasiswa berisi NIM dan nilai
            case 1:
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                ht.insert(NIM, nilai);
                break;
            // hapus data mahasiswa
            case 2:
                cout << "Masukkan NIM yang ingin dihapus: ";
                cin >> NIM;
                ht.remove(NIM);
                break;
            // cari data mahasiswa berdasarkan NIM
            case 3:
                cout << "Masukkan NIM yang ingin dicari: ";
                cin >> NIM;
                nilai = ht.get(NIM);
                if (nilai != -1) {
                    cout << "Nilai Mahasiswa dengan NIM " << NIM << " adalah " << nilai << endl;
                } else {
                    cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
                }
                break;
            // cari data mahasiswa berdasarkan nilai
            case 4:
                cout << "Mahasiswa dengan nilai antara 80 dan 90:" << endl;
                ht.getNilai(80, 90);
                break;
            // tampilkan seluruh data mahasiswa
            case 5:
                cout << "Data seluruh mahasiswa:" << endl;
                ht.traverse();
                break;
            // return
            case 6:
                return 0;
            // apabila user input pilihan selain 1-6
            default:
                cout << "Pilihan yang Anda masukkan tidak valid." << endl;
        }
        cout << endl;
    }
}
