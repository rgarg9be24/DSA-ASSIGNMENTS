#include <iostream>
using namespace std;

int arr[100], n = 0;

void createArray() {
    cout << "Enter size: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray() {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement() {
    int pos, val;
    cout << "Enter position and value: ";
    cin >> pos >> val;
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void deleteElement() {
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void linearSearch() {
    int searchVal, found = 0;
    cout << "Enter value to search: ";
    cin >> searchVal;
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchVal) {
            cout << "Found at position " << i << endl;
            found = 1;
        }
    }
    if (!found) cout << "Not found\n";
}


int main() {
    int choice;
    while (true) {
        cout << "\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: return 0;
        }
    }
}
