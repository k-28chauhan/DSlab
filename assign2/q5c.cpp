#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4;
    int size = n * (n + 1) / 2;
    vector<int> arr(size);

    vector<int> values = {5, 3, 6, 4, 7, 8, 2, 9, 1, 11};
    for (int i = 0; i < size; i++) arr[i] = values[i];

    cout << "Lower Triangular Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) cout << arr[i * (i - 1) / 2 + j - 1] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
