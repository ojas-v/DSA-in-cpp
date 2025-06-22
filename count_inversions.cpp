#include <iostream>
#include <vector>
using namespace std;

// count_inversions.cpp
// Count the number of inversions in an array using both brute force and merge sort

// BRUTE FORCE APPROACH 
int countInversionsBruteForce(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

// OPTIMAL MERGE SORT APPROACH
// Merge two sorted parts and count inversions
int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    int invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            invCount += (mid - i + 1); // Count all remaining elements in left part
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }

    return invCount;
}

// Recursive merge sort to count inversions
int countInversionsMergeSort(vector<int>& arr, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        count += countInversionsMergeSort(arr, left, mid);
        count += countInversionsMergeSort(arr, mid + 1, right);
        count += mergeAndCount(arr, left, mid, right);
    }
    return count;
}

int main() {
    vector<int> numbers = {2, 4, 1, 3, 5};

    cout << "Original array:\n";
    for (int num : numbers) cout << num << " ";
    cout << "\n";

    // Brute force inversion count
    vector<int> numsBrute = numbers;
    int bruteAns = countInversionsBruteForce(numsBrute);
    cout << "Brute force inversions: " << bruteAns << "\n";

    // Merge sort inversion count
    vector<int> numsMerge = numbers;
    int mergeAns = countInversionsMergeSort(numsMerge, 0, numsMerge.size() - 1);
    cout << "Merge sort inversions: " << mergeAns << "\n";

    cout << "Sorted array after merge sort:\n";
    for (int num : numsMerge) cout << num << " ";
    cout << "\n";

    return 0;
}
