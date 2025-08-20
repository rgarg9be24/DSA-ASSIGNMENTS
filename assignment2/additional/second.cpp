#include <iostream>
using namespace std;

// Function to input the matrix
void inputMatrix(int matrix[20][20], int R, int C) {
    cout << "Enter elements:\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Function to display the matrix
void printMatrix(int matrix[20][20], int R, int C) {
    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to print matrix in spiral order
void printSpiral(int matrix[20][20], int R, int C) {
    int min_row = 0, max_row = R - 1, min_col = 0, max_col = C - 1;
    int te = 0; // total elements printed

    cout << "\nSpiral Order:\n";
    while (te < R * C) {
        for (int j = min_col; j <= max_col; j++) {
            cout << matrix[min_row][j] << " ";
            te++;
        }
        min_row++;
        if (te >= R * C) break;

        for (int i = min_row; i <= max_row; i++) {
            cout << matrix[i][max_col] << " ";
            te++;
        }
        max_col--;
        if (te >= R * C) break;

        for (int j = max_col; j >= min_col; j--) {
            cout << matrix[max_row][j] << " ";
            te++;
        }
        max_row--;
        if (te >= R * C) break;

        for (int i = max_row; i >= min_row; i--) {
            cout << matrix[i][min_col] << " ";
            te++;
        }
        min_col++;
        if (te >= R * C) break;
    }
}

int main() {
    int R, C;
    int matrix[20][20]; 
    cout << "Enter number of rows: ";
    cin >> R;
    cout << "Enter number of columns: ";
    cin >> C;

    inputMatrix(matrix, R, C);
    printMatrix(matrix, R, C);
    printSpiral(matrix, R, C);

    return 0;
}
