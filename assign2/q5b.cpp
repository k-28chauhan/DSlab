#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4;
    vector<int> arr(3 * n - 2);


    arr[0] = 3; arr[1] = 4; arr[2] = 1;
    arr[n - 1] = 5; arr[n] = 6; arr[n + 1] = 9; arr[n + 2] = 8;

    arr[2 * n - 1] = 8; arr[2 * n] = 7; arr[2 * n + 1] = 2;

    cout << "Tri-diagonal Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - j == 1) cout << arr[i - 2] << " ";
            else if (i - j == 0) cout << arr[n - 1 + i - 1] << " ";
            else if (i - j == -1) cout << arr[2 * n - 1 + i - 1] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
