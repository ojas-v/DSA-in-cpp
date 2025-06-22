#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// palindrome_check.cpp
// Simple program to check if a string is a palindrome.

// Method 1: reverse and compare
bool isPalindromeByReverse(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

// Method 2: two-pointer technique
bool isPalindromeTwoPointer(string s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    // Example input
    string s = "madam";
    cout << "Input: " << s << "\n";

    // Method 1
    bool res1 = isPalindromeByReverse(s);
    cout << "Method 1 (reverse+compare): ";
    cout << (res1 ? "Palindrome" : "Not palindrome") << "\n";

    // Method 2
    bool res2 = isPalindromeTwoPointer(s);
    cout << "Method 2 (two-pointer):    ";
    cout << (res2 ? "Palindrome" : "Not palindrome") << "\n";

    // Terminologies:
    // Palindrome: sequence that is same forwards and backwards.
    // reverse(): STL function to reverse a range.
    // two-pointer: using two indices to scan from both ends.
    // string::length(): returns number of characters.

    // Time Complexity:
    // Method 1: O(n) for reverse + O(n) for compare => O(n)
    // Method 2: O(n) single pass => O(n)
    // Space Complexity:
    // Method 1: O(n) extra for reversed string.
    // Method 2: O(1).

    return 0;
}
