#include <iostream>
#include <stack>
using namespace std;

int main() {
    int arr[5] = {4, 5, 2, 10, 8};
    int output[5];
    stack<int> s;

    for (int i = 0; i < 5; i++) {
        // Remove all elements greater or equal to arr[i]
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            output[i] = -1;
        } else {
            output[i] = s.top();
        }

        // Push current element into stack
        s.push(arr[i]);
    }

    for (int i = 0; i < 5; i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}