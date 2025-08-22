#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string result = "";
    for (char c : str) {
        if (!isVowel(c)) {
            result += c;
        }
    }

    cout << "String without vowels: " << result << endl;
    return 0;
}
