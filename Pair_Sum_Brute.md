#include<iostream>
using namespace std;

// Boolean function to check for target element
bool pairSumBrute(int arr[], int n, int target){
    for(int i= 0; i<n; i++){
        for(int j= i+1; j<n; j++){
            if(arr[i] + arr[j] == target){
                return true;
            }
        }
    }
    return false;
}

// MAIN Function
int main()
{
    // Declaration of variables 
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    
    // Asking user for target element 
    cout << "Enter your target sum: " << endl;
    cin >> target;

    // Calling the function
    bool result = pairSumBrute(arr, n, target);

    // Printing result of the basis of value returned
    if(result){
        cout << "Target exist" << endl;
    }
    else{
        cout << "Target doesn't exists" << endl;
    }
   return 0;
}
