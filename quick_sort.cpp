#include <iostream>
#include <vector>
using namespace std;

// quick_sort.cpp
// Sort an array using the Quick Sort algorithm (Divide and Conquer)

// Important Terms:
// - Pivot: reference element used for splitting
// - Partition: rearranging elements around pivot

// Partition function to place pivot in correct position
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1; // return pivot index
}

// Quick sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // find pivot position
        quickSort(arr, low, pivotIndex - 1);        // sort left part
        quickSort(arr, pivotIndex + 1, high);       // sort right part
    }
}

// Print the array
void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> numbers = {29, 10, 14, 37, 13};
    cout << "Original array:\n";
    printArray(numbers);

    quickSort(numbers, 0, numbers.size() - 1);

    cout << "Sorted array using Quick Sort:\n";
    printArray(numbers);

    return 0;
}
