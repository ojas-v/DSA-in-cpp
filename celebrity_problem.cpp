/*
Terminologies:
- Celebrity: A person who is known by everyone but knows no one in return.
- knows(a, b): A simulated function that returns true if person 'a' knows person 'b'.
- Candidate: A potential celebrity, selected by eliminating those who know someone.
- Verification: Process to check if the candidate satisfies the celebrity conditions.
*/

#include<iostream>
#include<vector>
using namespace std;

// Global matrix to represent who knows whom (1 if a knows b, 0 otherwise)
vector<vector<int>> arr;

// Simulated 'knows' function to check if person 'a' knows person 'b'
bool knows(int a, int b) {
    return arr[a][b] == 1;
}

// Function to find the celebrity among 'n' people
int findCelebrity(int n){
    int cand = 0; // Assume 0 is the celebrity candidate

    // Step 1: Identify potential candidate
    for(int i = 1; i < n; i++){
        if(knows(cand, i)){
            // If candidate knows i, candidate can't be celebrity; update candidate
            cand = i;
        }
    }

    // Step 2: Verify if candidate is actually a celebrity
    for(int i = 0; i < n; ++i){
        if(i != cand && (knows(cand, i) || !knows(i, cand))){
            // If candidate knows someone OR someone doesn't know candidate => not a celebrity
            return -1;
        }
    }

    return cand; // Valid celebrity found
}

// Main Function to test the logic
int main(){
    // 3 people: only person 1 is a celebrity (everyone knows 1, 1 knows no one)
    arr = { {0, 1, 0},
            {0, 0, 0},
            {0, 1, 0} };

    int ans = findCelebrity(arr.size());

    if(ans == -1){
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity is: " << ans << endl;
    }

    return 0;
}

