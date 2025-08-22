#include <iostream>
using namespace std;

int arr[100];
int n = 0;

int main() {
    int choice;
    do {
        cout << "\n——MENU——-\n";
        cout << "1.CREATE\n";
        cout << "2.DISPLAY\n";
        cout << "3.INSERT\n";
        cout << "4.DELETE\n";
        cout << "5.LINEAR SEARCH\n";
        cout << "6.EXIT\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter elements:\n";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                break;
            }
            case 2: {
                cout << "Array: ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 3: {
                int pos, val;
                cout << "Enter position to insert (0-based): ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> val;
                for (int i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = val;
                n++;
                break;
            }
            case 4: {
                int pos;
                cout << "Enter position to delete (0-based): ";
                cin >> pos;
                for (int i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                break;
            }
            case 5: {
                int val;
                cout << "Enter value to search: ";
                cin >> val;
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == val) {
                        cout << "Found at index: " << i << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Not found." << endl;
                break;
            }
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 6);

    return 0;
}
