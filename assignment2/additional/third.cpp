#include <iostream>
using namespace std;

int main() {
    int A;
    cout << "enter size of square matrix : ";
    cin >> A;

    int matrix[A][A];
    int num = 1;
    int min_row = 0, max_row = A - 1;
    int min_col = 0, max_col = A - 1;

    while (num <= A * A) {
        for (int j = min_col; j <= max_col; j++) {
            matrix[min_row][j] = num++;
        }
        min_row++;

        for (int i = min_row; i <= max_row; i++) {
            matrix[i][max_col] = num++;
        }
        max_col--;

        for (int j = max_col; j >= min_col; j--) {
            matrix[max_row][j] = num++;
        }
        max_row--;

        for (int i = max_row; i >= min_row; i--) {
            matrix[i][min_col] = num++;
        }
        min_col++;
    }

    cout << "\nspiral matrix :\n";
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
