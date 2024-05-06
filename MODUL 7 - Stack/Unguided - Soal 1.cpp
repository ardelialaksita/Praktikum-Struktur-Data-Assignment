#include <iostream>
#include <string>
#include <cctype>
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

    // deklarasi variabel kata untuk menyimpan kata yang diinput oleh user
    string kata;

    // deklarasi hurufAwal, hurufAkhir, checkAgain, firstWord pada class stack dan lastWord pada class words
    char hurufAwal;
    char hurufAkhir;
    char checkAgain;   
    stack firstWord;
    deretHuruf lastWord;
    
    // deklarasi palindrome
    bool palindrome = true;
    // tampilkan head atau judul dari program 
    cout << "=== PALINDROME WORDS CHECK ===" << endl;

    // user menginput kata
    cout << "Masukkan 1 kata: ";
    cin >> kata;
    cout << endl;

    // perulangan for untuk push firstWord dan lastWord
    for (int i = 0; i < kata.length(); i++) {
        firstWord.push(kata[i]);
        lastWord.push(kata[i]);
    }

    // ubah semua huruf menjadi huruf kecil semua menggunakan tolower
    for (int i = 0; i < kata.length(); i++) {
        firstWord.push(tolower(kata[i]));
        lastWord.push(tolower(kata[i]));
    }

    // perulangan for untuk pop dan pengecekan palindrome
    for (int i = 0; i < kata.length(); i++) {
        char hurufAwal = firstWord.pop();
        char hurufAkhir = lastWord.pop();

        if (hurufAwal != hurufAkhir) {
            cout << hurufAwal << " != " << hurufAkhir << endl;
            palindrome = false;
        } else {
            cout << hurufAwal << " = " << hurufAkhir << endl; 
        }
    }

    cout << endl;

    // tampilkan hasil
    if (palindrome) {
        cout << "Kata tersebut merupakan kata palindrome." << endl;
        cout << "Semua huruf pada kata tersebut akan menghasilkan urutan huruf yang sama apabila kata dibalik." << endl;
    } else {
        cout << "Kata tersebut bukan merupakan kata palindrome." << endl;
        cout << "Terdapat urutan huruf yang tidak sama apabila kata tersebut dibalik." << endl;
    }
    cout << "=================================================================================================" << endl;
    cout << endl;
    return 0;
}
