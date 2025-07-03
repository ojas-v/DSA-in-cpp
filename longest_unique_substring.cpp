/*
  longest_unique_substring.cpp
 
  Key Terminologies:
    • Sliding Window: Technique where a window [start, end] moves over the string.
    • Hash Map (unordered_map): Stores last index at which each character appeared.
    • start Index: Beginning of the current window without duplicates.
    • Window Length: end - start + 1, size of current valid substring.
 
  Usage:
    1. Compile: g++ longest_unique_substring.cpp -o longest_unique_substring
    2. Run:     ./longest_unique_substring
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Class that finds the longest substring without repeating characters
class LongestUniqueSubstr {
public:
    // Returns length of longest substring without duplicates
    int lengthOfLongestSubstring(const string& s) {
        unordered_map<char, int> lastIndex;
        int maxLen = 0;
        int start = 0; // start index of current window

        for (int end = 0; end < (int)s.length(); end++) {
            char c = s[end];
            // If character is seen and inside current window, move start
            if (lastIndex.count(c) && lastIndex[c] >= start) {
                start = lastIndex[c] + 1;
            }
            lastIndex[c] = end; // update last seen index
            // Update maximum length
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};

int main() {
    LongestUniqueSubstr solver;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    int result = solver.lengthOfLongestSubstring(input);
    cout << "Length of longest substring without repeating characters: "
         << result << endl;

    return 0;
}
