#include <iostream>
using namespace std;

int main() {
    int m, n, o;
    cout << "Enter m, n, o: ";
    cin >> m >> n >> o;

    int a[m][n], b[n][o], resultant[m][o];

    cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < o; j++)
            cin >> b[i][j];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < o; j++) {
            resultant[i][j] = 0;
            for (int k = 0; k < n; k++)
                resultant[i][j] += a[i][k] * b[k][j];
        }
    }

    cout << "Multiplication is:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < o; j++)
            cout << resultant[i][j] << " ";
        cout << endl;
    }

    return 0;
}
