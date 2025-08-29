#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4;
    int size = n * (n + 1) / 2;
    vector<int> arr(size);

    vector<int> values = {5, 8, 7, 2, 6, 4, 1, 9, 3, 10};
    for (int i = 0; i < size; i++) arr[i] = values[i];

    cout << "Upper Triangular Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j)
                cout << arr[(i - 1) * n - (i - 2) * (i - 1) / 2 + (j - i)] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
