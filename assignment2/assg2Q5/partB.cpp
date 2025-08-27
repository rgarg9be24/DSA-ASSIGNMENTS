#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix (n x n): ";
    cin >> n;

    int mainDiag[n], upper[n-1], lower[n-1];

    cout << "Enter main diagonal elements (" << n << " elements):\n";
    for (int i = 0; i < n; i++) {
        cin >> mainDiag[i];
    }

    cout << "Enter upper diagonal elements (" << n-1 << " elements):\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> upper[i];
    }

    cout << "Enter lower diagonal elements (" << n-1 << " elements):\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> lower[i];
    }

    cout << "\nFull matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << mainDiag[i] << " ";
            else if (j == i + 1) cout << upper[i] << " ";
            else if (i == j + 1) cout << lower[j] << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
    }

    return 0;
}