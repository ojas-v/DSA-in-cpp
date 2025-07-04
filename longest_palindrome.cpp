/*
  longest_palindrome.cpp

  Key Terminologies:
    • Palindrome: A string that reads the same forwards and backwards.
    • Expand Around Center: Technique to grow a palindrome by expanding pointers from the middle.
    • Odd-length Palindrome: Center is a single character.
    • Even-length Palindrome: Center is between two characters.
 
  Usage:
    1. Compile: g++ longest_palindrome.cpp -o longest_palindrome
    2. Run:     ./longest_palindrome
 */

#include <iostream>
#include <string>
using namespace std;

// Class that finds the longest palindromic substring
class PalindromeFinder {
public:
    // Returns the longest palindromic substring in s
    string findLongestPalindrome(const string& s) {
        int start = 0, maxLen = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            // Odd-length palindromes (single center)
            expandAroundCenter(s, i, i, start, maxLen);
            // Even-length palindromes (two-character center)
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }

private:
    // Expands pointers left and right while characters match
    void expandAroundCenter(const string& s, int left, int right,
                            int& start, int& maxLen) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // right - left - 1 is the length of palindrome
        int len = right - left - 1;
        if (len > maxLen) {
            start = left + 1;
            maxLen = len;
        }
    }
};

int main() {
    PalindromeFinder finder;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    string longest = finder.findLongestPalindrome(input);
    cout << "Longest Palindromic Substring: " << longest << endl;

    return 0;
}
