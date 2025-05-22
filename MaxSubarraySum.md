# DSA-in-cpp

#include<iostream>
#include <climits>
using namespace std;

// Printing all the subarrays
for(int st = 0; st < n; st++){
  for(int end = st; end < n; end++){
    for(int i = st; i<=end; i++){
      cout<<arr[i];
    }
    cout<<" ";
  }
  cout<<endl;
}

// Function for brute force approach to find max subarray sum
void subarrayMaxSumBrute(int arr[], int n){
  int maxSum = INT_MIN;
  for(int st =0; st<n; st++){
    int currSum = 0;
    for(int end = st; end < n; end++){
        currSum += arr[end];
        maxSum = max(currSum, maxSum); 
    }
  }
  cout << "Maximum Subarray Sum = "<< maxSum << endl;
}

// Function for optimal approach for problem (Kadane's algorithm)
int kadanesAlgo(int arr[], int n){
    int max_so_far = INT_MIN;
    int currentMax = 0;
    for(int i =0; i<n; i++){
        currentMax = max( arr[i], currentMax + arr[i]);
        max_so_far = max(max_so_far, currentMax);
    }
    return max_so_far;
}

// Main Function
int main()
{
    // Example case: 
    int arr[7] = {3, -4, 5, 4, -1, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int n = 7;
    subarrayMaxSumBrute(arr, n);
    cout <<  "Maximum Subarray Sum: " << kadanesAlgo(arr, n) << endl;
    return 0;
}

    
