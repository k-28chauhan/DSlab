#include <iostream>
#include <stack>
using namespace std;

int main() {
    int arr[] = {1, 3, 2, 4, 2, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int out[n];
    stack<int> s;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop all smaller or equal elements
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        // If stack becomes empty → no greater element
        if (s.empty()) {
            out[i] = -1;
        } else {
            out[i] = s.top();
        }
        // Push current element
        s.push(arr[i]);
    }

    // Print result
    for (int i = 0; i < n; i++) {
        cout << out[i] << " ";
    }
    return 0;
}