#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter the number of students (5 to 15): ";
    cin >> n;
    while (n < 5 || n > 15) {
        cout << "Invalid input! Number of students must be between 5 and 15. Try again: ";
        cin >> n;
    }

    int marks[15];
    
    cout << "Enter marks for " << n << " students (0 to 100):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Student " << (i + 1) << " mark: ";
        cin >> marks[i];
        while (marks[i] < 0 || marks[i] > 100) {
            cout << "Invalid mark! Must be between 0 and 100. Enter again for Student " << (i + 1) << ": ";
            cin >> marks[i];
        }
    }

    int totalComparisons = 0;
    int totalShifts = 0;

    for (int i = 1; i < n; ++i) {
        int key = marks[i];
        int j = i - 1;

        while (j >= 0) {
            totalComparisons++;
            if (marks[j] < key) {
                marks[j + 1] = marks[j];
                totalShifts++;
                j--;
            } else {
                break;
            }
        }
        marks[j + 1] = key;
    }

    double sum = 0;
    bool hasHighAchiever = false;

    for (int i = 0; i < n; ++i) {
        sum += marks[i];
        if (marks[i] >= 90) {
            hasHighAchiever = true;
        }
    }

    int highest = marks[0];
    int lowest = marks[n - 1];
    double average = sum / n;

    cout << "SORTING STATS\n";
    cout << "Total Comparisons : " << totalComparisons << "\n";
    cout << "Total Shifts      : " << totalShifts << "\n";

    cout << "PERFORMANCE REPORT\n";
    cout << "Sorted Marks (Descending) : ";
    for (int i = 0; i < n; ++i) {
        cout << marks[i] << " ";
    }
    cout << "\n";

    cout << "Highest Marks             : " << highest << "\n";
    cout << "Lowest Marks              : " << lowest << "\n";
    cout << "Average Marks             : " << average << "\n";

    if (hasHighAchiever) {
        cout << "High Achiever Status      : High Achiever(s) Present\n";
    } else {
        cout << "High Achiever Status      : No High Achiever\n";
    }
    cout << "\n";

    return 0;
}
