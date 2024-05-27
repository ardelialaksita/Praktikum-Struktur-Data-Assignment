#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n -1);
}

int main() {
    cout << "Rekursif langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}