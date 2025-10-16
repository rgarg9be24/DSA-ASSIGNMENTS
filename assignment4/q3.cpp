#include <iostream>
using namespace std;

void interleave(int arr[], int n) {
    if (n % 2 != 0) {
        cout << "Number of elements should be even!" << endl;
        return;
    }

    int half = n / 2;
    int result[n];
    int idx = 0;

  
    for (int i = 0; i < half; i++) {
        result[idx++] = arr[i];         
        result[idx++] = arr[i + half];  
    }

    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

int main() {
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    interleave(arr, n);

    cout << "Interleaved output: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}