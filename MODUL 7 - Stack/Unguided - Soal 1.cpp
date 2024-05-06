#include <iostream>
#include <string>
using namespace std;

class deretHuruf {
    public:
    deretHuruf() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push(char hurufAwal) {
        node* temp = new node;
        temp->words = hurufAwal;
        temp->next = NULL;

        if (size == 0) {
            head = temp;
            tail = temp;
            head->prev = NULL;
        }
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    char pop() {
        char words = head->words;
        if (head == tail) {
            delete head;
        }
        else {
            node* temp = head;
            head = head->next;
            head->prev;
            temp->next = NULL;
            delete temp;
        }
        size--;
        return words;
    }
    
    private:
    struct node {
        char words;
        node* next;
        node* prev;
    };

    int size;
    char words;
    node* head;
    node* tail;
};

class stack {
    public:
    stack() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push (char hurufAwal) {
        node* temp = new node;
        temp->words = hurufAwal;
        temp->next = NULL;

        if (size == 0) {
            head = temp;
            tail = temp;
            tail->prev = NULL;
        }

        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    char pop() {
        words = tail->words;
        if (head == tail) {
            delete head;  
        }

        else{
            node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
        size--;
        return words;
    }

    private:
    struct node{
        char words;
        node* next;
        node *prev;
    };

    int size;
    char words;
    node* head;
    node* tail;
};


int main() {

    // deklarasi kata, hurufAwal, hurufAkhir, checkAgain, firstWord pada class stack dan lastWord pada class words
    string kata;
    char hurufAwal;
    char hurufAkhir;
    char checkAgain;   
    stack firstWord;
    deretHuruf lastWord;
    
    // deklarasi palindrome
    bool palindrome = true;
    // tampilkan head atau judul dari program 
    cout << "=== PALINDROME WORDS CHECK ===" << endl;

    do {
        // user dapat input kata untuk dicheck apakah palindrome atau tidak
        cout << "Masukkan kata : ";
        cin >> kata;
        cout << endl;

        // perulangan for untuk menjalankan program push untuk menambahkan firstWord hingga lastWord
        for (int i = 0; i < kata.length(); i++) {
            firstWord.push(kata[i]);
            lastWord.push(kata[i]);
        }

        // mengubah huruf yang dimasukkan menjadi huruf kecil semua menggunakan tolower
        for (int i = 0; i < kata.length(); i++) {
            firstWord.push(tolower(kata[i])); 
            lastWord.push(tolower(kata[i]));
        }

        // perulangan for untuk menjalankan program pop untuk pengecekan firstWord dan lastWord
        for (int i = 0; i < kata.length(); i++) {
            hurufAwal = firstWord.pop();
            hurufAkhir = lastWord.pop();

            // if apabila huruf awal tidak sama dengan huruf akhir 
            if (hurufAwal != hurufAkhir) {
                cout << hurufAwal << " != " << hurufAkhir << endl;
                palindrome = false;
            }
            // else apabila huruf awal sama dengan huruf akhir
            else{
                cout << hurufAwal << " = " << hurufAkhir << endl; 
            }
        }

        // menampilkan hasil apakah kata yang diinput palindrome atau tidak
        // tampilan kata yang termasuk palindrom
        if (palindrome) {
            cout << "Kata tersebut merupakan kata palindrome." << endl;
        }
        // tampilan kata yang tidak termasuk palindrome
        else {
            cout << "Kata tersebut bukan merupakan kata palindrome." << endl;
        }
        cout << endl;
    }
    return 0;
}
