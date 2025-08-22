#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character in uppercase: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;  // ASCII conversion: 'A' (65) → 'a' (97)
    }

    cout << "Lowercase character: " << ch << endl;

    return 0;
}
