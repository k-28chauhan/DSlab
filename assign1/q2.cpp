#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result[n], k = 0;

    for (int i = 0; i < n; i++) {
        bool exists = false;
        for (int j = 0; j < k; j++) {
            if (arr[i] == result[j]) {
                exists = true;
                break;
            }
        }
        if (!exists) result[k++] = arr[i];
    }

    cout << "Unique array: ";
    for (int i = 0; i < k; i++) cout << result[i] << " ";

    return 0;
}
