#include <iostream>
#include <vector>
using namespace std;

// merge_sort.cpp
// Sort an array using the Merge Sort algorithm (Divide and Conquer)

// Important Terms:
// - Divide and Conquer: break the problem, solve smaller parts, combine results
// - Merge: combine two sorted arrays into one sorted array

// Merge two sorted parts of the array
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left;     // start of left part
    int j = mid + 1;  // start of right part

    // Compare and merge
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from left part
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from right part
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Put sorted elements back into original array
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

// Recursive merge sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return; // base case

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);      // sort left half
    mergeSort(arr, mid + 1, right); // sort right half
    merge(arr, left, mid, right);   // merge sorted halves
}

// Print the array
void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> numbers = {38, 27, 43, 3, 9, 82, 10};
    cout << "Original array:\n";
    printArray(numbers);

    mergeSort(numbers, 0, numbers.size() - 1);

    cout << "Sorted array:\n";
    printArray(numbers);

    return 0;
}
