#include <bits/stdc++.h>
using namespace std;

/*
 * sorting_algorithms.cpp
 *
 * Usage:
 *   1. Compile:
 *        g++ -std=c++11 sorting_algorithms.cpp -o sorting_algos
 *   2. Run:
 *        ./sorting_algos
 *   3. Modify the `arr` in main() or add tests as needed.
 *
 * Time Complexities:
 *   Bubble:     O(n^2)
 *   Selection:  O(n^2)
 *   Insertion:  O(n^2)
 *   Merge:      O(n log n)
 *   Quick:      O(n^2) worst, O(n log n) average
 *   Counting:   O(n + k) where k = max(arr)
 *
 * Space Complexity:
 *   Bubble/Selection/Insertion: O(1)
 *   Merge:     O(n)
 *   Quick:     O(log n) recursion
 *   Counting:  O(k)
 */

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}

void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void merge(vector<int>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSortRec(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortRec(a, l, m);
    mergeSortRec(a, m + 1, r);
    merge(a, l, m, r);
}

void mergeSort(vector<int>& a) {
    mergeSortRec(a, 0, a.size() - 1);
}

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSortRec(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSortRec(a, low, pi - 1);
        quickSortRec(a, pi + 1, high);
    }
}

void quickSort(vector<int>& a) {
    quickSortRec(a, 0, a.size() - 1);
}

void countingSort(vector<int>& a) {
    if (a.empty()) return;
    int maxv = *max_element(a.begin(), a.end());
    int minv = *min_element(a.begin(), a.end());
    int range = maxv - minv + 1;
    vector<int> count(range);
    for (int x : a) count[x - minv]++;
    for (int i = 1; i < range; i++) count[i] += count[i - 1];
    vector<int> output(a.size());
    for (int i = a.size() - 1; i >= 0; i--) {
        output[count[a[i] - minv] - 1] = a[i];
        count[a[i] - minv]--;
    }
    a = output;
}

// Utility to print array
void printArr(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << '\n';
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    cout << "Original:      "; printArr(arr);

    auto v = arr;
    bubbleSort(v);      cout << "Bubble Sort:   "; printArr(v);

    v = arr;
    selectionSort(v);   cout << "Selection Sort:"; printArr(v);

    v = arr;
    insertionSort(v);   cout << "Insertion Sort:"; printArr(v);

    v = arr;
    mergeSort(v);       cout << "Merge Sort:    "; printArr(v);

    v = arr;
    quickSort(v);       cout << "Quick Sort:    "; printArr(v);

    v = arr;
    countingSort(v);    cout << "Counting Sort: "; printArr(v);

    return 0;
}
