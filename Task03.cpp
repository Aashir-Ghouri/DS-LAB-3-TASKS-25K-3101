#include <iostream>

using namespace std;

void combSort(int arr[], int size) {
    int gap = size;
    bool swapped = true;
    int iteration = 1;

    cout << "\n--- Comb Sort Process ---\n";
    while (gap > 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) {
            gap = 1;
        }

        swapped = false;
        
        for (int i = 0; i < size - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }

        cout << "Iteration " << iteration++ << " | Gap: " << gap << " | Array: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int quantities[] = {10, 20, 30, 40, 5, 50, 60, 70};
    int size = sizeof(quantities) / sizeof(quantities[0]);

    cout << "Initial Quantities\n";
    for (int i = 0; i < size; ++i) {
        cout << quantities[i] << " ";
    }
    cout << "\n";

    combSort(quantities, size);
    cout << "\n";

    cout << "Sorted Quantities\n";
    for (int i = 0; i < size; ++i) {
        cout << quantities[i] << " ";
    }

    return 0;
}
