#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> s1;  
    string ds = "DataStructure";  

    cout << "Original string: " << ds << endl;

    // Push characters onto stack
    for (int i = 0; i < ds.length(); i++) {
        s1.push(ds[i]);
    }

    // Pop characters to reverse
    string dsr = "";
    while (!s1.empty()) {
        dsr += s1.top();  // take top element
        s1.pop();         // remove top element
    }

    cout << "Reversed string: " << dsr << endl;

    return 0;
}