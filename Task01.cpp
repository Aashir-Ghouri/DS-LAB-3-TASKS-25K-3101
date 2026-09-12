#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size) {
    int totalComparisons = 0;
    int totalSwaps = 0;
    int totalPasses = 0;

    // Standard unoptimized loop: always runs size - 1 passes
    for (int i = 0; i < size - 1; ++i) {
        totalPasses++;

        for (int j = 0; j < size - i - 1; ++j) {
            totalComparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                totalSwaps++;
            }
        }
    }

    cout << "\n--- Statistics ---\n";
    cout << "Total Passes: " << totalPasses << "\n";
    cout << "Total Comparisons: " << totalComparisons << "\n";
    cout << "Total Swaps: " << totalSwaps << "\n";
}

int main() {
    int prices[] = {45, 12, 78, 34, 23, 90};
    int size = sizeof(prices) / sizeof(prices[0]);

    cout << "Initial Array\n";
    for (int i = 0; i < size; ++i) {
        cout << prices[i] << " ";
    }
    
    cout << "\n";

    bubbleSort(prices, size);

    cout << "\n";

    cout << "Sorted Array\n";
    for (int i = 0; i < size; ++i) {
        cout << prices[i] << " ";
    }
    

    return 0;
}
