#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> A = {
        {4, 4, 4},
        {0, 0, 1},
        {0, 3, 2},
        {2, 2, 3},
        {3, 1, 4}
    };

    vector<vector<int>> B = {
        {4, 4, 4},
        {0, 1, 5},
        {1, 2, 6},
        {2, 3, 7},
        {3, 0, 8}
    };

    // (a) Transpose of A
    vector<vector<int>> transpose;
    int rows = A[0][1];
    int cols = A[0][0];
    int count = A[0][2];
    transpose.push_back({rows, cols, count});

    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= count; i++) {
            if (A[i][1] == col) {
                transpose.push_back({A[i][1], A[i][0], A[i][2]});
            }
        }
    }

    cout << "Transpose of Matrix A:\n";
    for (auto &row : transpose) {
        cout << row[0] << " " << row[1] << " " << row[2] << endl;
    }

    // (b) Addition of A and B
    vector<vector<int>> sum;
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Matrices cannot be added." << endl;
    } else {
        int i = 1, j = 1;
        sum.push_back({A[0][0], A[0][1], 0});
        while (i <= A[0][2] && j <= B[0][2]) {
            if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
                sum.push_back(A[i]);
                i++;
            } else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
                sum.push_back(B[j]);
                j++;
            } else {
                sum.push_back({A[i][0], A[i][1], A[i][2] + B[j][2]});
                i++; j++;
            }
        }
        while (i <= A[0][2]) sum.push_back(A[i++]);
        while (j <= B[0][2]) sum.push_back(B[j++]);
        sum[0][2] = sum.size() - 1;

        cout << "\nSum of A and B:\n";
        for (auto &row : sum) {
            cout << row[0] << " " << row[1] << " " << row[2] << endl;
        }
    }

    // (c) Multiplication of A and B
    if (A[0][1] != B[0][0]) {
        cout << "\nMultiplication not possible" << endl;
    } else {
        vector<vector<int>> result;
        result.push_back({A[0][0], B[0][1], 0});

        for (int i = 1; i <= A[0][2]; i++) {
            for (int j = 1; j <= B[0][2]; j++) {
                if (A[i][1] == B[j][0]) {
                    int row = A[i][0];
                    int col = B[j][1];
                    int val = A[i][2] * B[j][2];
                    bool found = false;
                    for (int k = 1; k < result.size(); k++) {
                        if (result[k][0] == row && result[k][1] == col) {
                            result[k][2] += val;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        result.push_back({row, col, val});
                    }
                }
            }
        }

        result[0][2] = result.size() - 1;
        cout << "\nMultiplication of A and B:\n";
        for (auto &row : result) {
            cout << row[0] << " " << row[1] << " " << row[2] << endl;
        }
    }

    return 0;
}
