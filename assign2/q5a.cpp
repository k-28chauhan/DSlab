#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4;
    vector<int> arr(n);
    arr[0] = 5; arr[1] = 8; arr[2] = 9; arr[3] = 12;

    cout << "Diagonal Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << arr[i - 1] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
