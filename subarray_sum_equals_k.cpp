#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// subarray_sum_k.cpp
// Find number of subarrays whose sum equals k.

// Method 1: Brute Force
int countSubarraysBrute(const vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k) count++;
        }
    }
    return count;
}

// Method 2: Hashing with Prefix Sum
int countSubarraysHash(const vector<int>& arr, int k) {
    unordered_map<int, int> freq; // prefix sum -> count
    int sum = 0;
    int count = 0;
    freq[0] = 1; // one way to have sum 0 before starting

    for (int x : arr) {
        sum += x; // current prefix sum
        int need = sum - k;
        if (freq.count(need)) {
            count += freq[need];
        }
        freq[sum]++; // record this prefix sum
    }

    return count;
}

int main() {
    vector<int> arr = {1, 1, 1};
    int k = 2;

    cout << "Brute Force count: " << countSubarraysBrute(arr, k) << "\n";
    cout << "Hashing count:     " << countSubarraysHash(arr, k) << "\n";

    return 0;

// Terminologies:
// - Subarray: contiguous part of an array.
// - Prefix Sum: sum of elements from start up to current index.
// - Hash Map: dictionary to store key-value pairs for fast lookup.
// - Time Complexity: how runtime scales with n.
// - Space Complexity: extra memory used.

}
