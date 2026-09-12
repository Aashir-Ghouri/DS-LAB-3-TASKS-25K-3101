#include <iostream>

using namespace std;

void modifiedBubbleSort(int arr[], int size) {
    int comparisons = 0;
    int swaps = 0;
    int totalPasses = 0;
    bool swapped;

    for (int i = 0; i < size - 1; ++i) {
        swapped = false;
        totalPasses++;

        for (int j = 0; j < size - i - 1; ++j) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    cout << "\n--- Modified Bubble Sort Results ---\n";
    cout << "Total Passes: " << totalPasses << "\n";
    cout << "Total Comparisons: " << comparisons << "\n";
    cout << "Total Swaps: " << swaps << "\n";
}

int main() {
    int attendance[] = {55, 61, 67, 72, 78, 81, 80, 85};
    int size = sizeof(attendance) / sizeof(attendance[0]);

    cout << "Initial Array\n";
    for (int i = 0; i < size; ++i) {
        cout << attendance[i] << " ";
    }
    cout << "\n";

    modifiedBubbleSort(attendance, size);
    cout << "\n";

    cout << "Sorted Array\n";
    for (int i = 0; i < size; ++i) {
        cout << attendance[i] << " ";
    }

    return 0;
}
