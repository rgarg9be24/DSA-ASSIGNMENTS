#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    int arr[100][100];
    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];

    // Sum of each row
    cout << "Row sums:\n";
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++)
            sum += arr[i][j];
        cout << "Row " << i + 1 << ": " << sum << endl;
    }

    // Sum of each column
    cout << "Column sums:\n";
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++)
            sum += arr[i][j];
        cout << "Column " << j + 1 << ": " << sum << endl;
    }

    return 0;
}
