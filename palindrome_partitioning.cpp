#include <iostream>
#include <vector>
#include <string>
using namespace std;

// palindrome_partitioning.cpp
// Split a string into all possible combinations of palindromic substrings (Leetcode 131)

// Important Terms:
// - Palindrome: a string that reads the same backward
// - Partition: divide a string into non-overlapping substrings
// - Backtracking: try a split, go deeper, backtrack if needed
// - Base Case: when we reach the end of the string

// Function to check if a substring is a palindrome
bool isPalindrome(string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) return false;
        start++;
        end--;
    }
    return true;
}

// Helper function to find all palindromic partitions
void findParts(int index, string& s, vector<string>& temp, vector<vector<string>>& result) {
    if (index == s.length()) {
        result.push_back(temp);
        return;
    }

    for (int i = index; i < s.length(); i++) {
        if (isPalindrome(s, index, i)) {
            temp.push_back(s.substr(index, i - index + 1)); // choose
            findParts(i + 1, s, temp, result);               // explore
            temp.pop_back();                                // backtrack
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> temp;
    findParts(0, s, temp, result);
    return result;
}

// Print the partitions
void printPartitions(vector<vector<string>>& parts) {
    for (int i = 0; i < parts.size(); i++) {
        cout << "[";
        for (int j = 0; j < parts[i].size(); j++) {
            cout << '"' << parts[i][j] << '"';
            if (j != parts[i].size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
}

int main() {
    string input = "aab";
    vector<vector<string>> result = partition(input);
    cout << "Palindrome partitions of '" << input << "':\n";
    printPartitions(result);
    return 0;
}
