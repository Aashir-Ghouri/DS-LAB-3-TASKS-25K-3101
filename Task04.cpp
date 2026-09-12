#include <iostream>

using namespace std;

void shellSort(int arr[], int n) {
    int totalComparisons = 0;
    int totalShifts = 0;

    cout << "\n--- Shell Sort Execution ---\n";

    for (int gap = n / 2; gap > 0; gap /= 2) {
        int gapComparisons = 0;
        int gapShifts = 0;

        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;

            while (j >= gap) {
                gapComparisons++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    gapShifts++;
                    j -= gap;
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }

        totalComparisons += gapComparisons;
        totalShifts += gapShifts;

        cout << "\nGap: " << gap << "\n";
        cout << "Comparisons for this gap: " << gapComparisons << "\n";
        cout << "Shifts for this gap     : " << gapShifts << "\n";
        cout << "Array after gap " << gap << "       : ";
        for (int k = 0; k < n; ++k) {
            cout << arr[k] << " ";
        }
        cout << "\n";
    }

    cout << "Total Comparisons : " << totalComparisons << "\n";
    cout << "Total Shifts      : " << totalShifts << "\n";
}

int main() {
    int loads[] = {90, 20, 80, 30, 70, 40, 60, 50, 10};
    int n = sizeof(loads) / sizeof(loads[0]);

    cout << "Initial Load Values: ";
    for (int i = 0; i < n; ++i) {
        cout << loads[i] << " ";
    }
    cout << "\n";

    shellSort(loads, n);

    cout << "\nFinal Sorted Array : ";
    for (int i = 0; i < n; ++i) {
        cout << loads[i] << " ";
    }
    cout << "\n";

    return 0;
}
