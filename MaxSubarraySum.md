# DSA-in-cpp

#include<iostream>
#include<climits>
using namespace std;

// Function to print all subarrays
void printAllSubarrays(int arr[], int n) {
    cout << "All subarrays:" << endl;
    for (int st = 0; st < n; st++) {
        for (int end = st; end < n; end++) {
            for (int i = st; i <= end; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
}

// Brute force approach to find maximum subarray sum
void subarrayMaxSumBrute(int arr[], int n) {
    int maxSum = INT_MIN;
    for (int st = 0; st < n; st++) {
        int currSum = 0;
        for (int end = st; end < n; end++) {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }
    cout << "Maximum Subarray Sum (Brute Force): " << maxSum << endl;
}

// Kadane's algorithm for maximum subarray sum
int kadanesAlgo(int arr[], int n) {
    int max_so_far = INT_MIN;
    int currentMax = 0;
    for (int i = 0; i < n; i++) {
        currentMax = max(arr[i], currentMax + arr[i]);
        max_so_far = max(max_so_far, currentMax);
    }
    return max_so_far;
}

// Main function
int main() {
    int arr[] = {3, -4, 5, 4, -1, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printAllSubarrays(arr, n);
    subarrayMaxSumBrute(arr, n);
    cout << "Maximum Subarray Sum (Kadane's Algorithm): " << kadanesAlgo(arr, n) << endl;
    return 0;
}


    
