#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// class deret huruf 
class deretHuruf {
    // bagian public dari class deretHuruf
    public:
    deretHuruf() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // menambahkan huruf
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

    // menghapus huruf
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
    
    // bagian private dari class deretHuruf berisi struct dari node
    private:
    struct node {
        char words;
        node* next;
        node* prev;
    };

    // deklarasi size, words, dhead, dan tail menggunakan pointer node dalam private class deretHuruf
    int size;
    char words;
    node* head;
    node* tail;
};

// class stack (tumpukan) huruf
class stack {
    // bagian public dari class stack
    public:
    stack() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // menambahkan huruf
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

    // menghapus huruf
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

    // bagian private dari class stack berisi struct
    private:
    struct node{
        char words;
        node* next;
        node *prev;
    };

    // deklarasi size, words, head, dan tail dalam private class stack
    int size;
    char words;
    node* head;
    node* tail;
};


// main program (program utama)
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

    // user menginput kata
    cout << "Masukkan 1 kata: ";
    cin >> kata;
    cout << endl;

    // perulangan for untuk push firstWord dan lastWord 
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
        cout << "Semua huruf pada kata tersebut sama sehingga akan menghasilkan urutan huruf yang sama apabila kata dibalik." << endl;
    } else {
        cout << "Kata tersebut bukan merupakan kata palindrome." << endl;
        cout << "Terdapat urutan huruf yang tidak sama sehingga apabila kata tersebut dibalik maka tidak akan menghasilkan bacaan yang sama." << endl;
    }
    cout << "================================================================================================================================" << endl;
    cout << endl;
    return 0;
}
