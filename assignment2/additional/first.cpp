#include <iostream>
using namespace std;

#define MAX 20

void findSaddlePoint(int A[MAX][MAX], int m, int n) {
    int found = 0;  

    for (int i = 0; i < m; i++) {
        int rowMin = A[i][0];
        int colIndex = 0;

        // Find minimum element in row i
        for (int j = 1; j < n; j++) {
            if (A[i][j] < rowMin) {
                rowMin = A[i][j];
                colIndex = j;
            }
        }

        // Check if this rowMin is largest in its column
        int isSaddle = 1;  
        for (int k = 0; k < m; k++) {
            if (A[k][colIndex] > rowMin) {
                isSaddle = 0;
                break;
            }
        }

        if (isSaddle == 1) {
            cout << "Saddle Point = " << rowMin 
                 << " at position (" << i << "," << colIndex << ")" << endl;
            found = 1;
        }
    }

    if (found == 0) {
        cout << "No Saddle Point in the matrix." << endl;
    }
}

int main() {
    int A[MAX][MAX], m, n;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    findSaddlePoint(A, m, n);

    return 0;
}
