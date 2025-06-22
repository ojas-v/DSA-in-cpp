#include <iostream>
#include <string>
using namespace std;

// remove_occurrences.cpp
// Simple examples to remove all occurrences from a string:
// Case 1: Remove a specific character
// Case 2: Remove a given substring

// Remove all instances of character c from string s
string removeChar(const string& s, char c) {
    string result;
    for (char x : s) {
        if (x != c) {
            result.push_back(x);
        }
    }
    return result;
}

// Remove all non-overlapping occurrences of substring sub from string s
string removeSub(const string& s, const string& sub) {
    string result;
    int n = s.length();
    int m = sub.length();
    for (int i = 0; i < n; ) {
        // check if sub matches at position i
        if (i + m <= n && s.substr(i, m) == sub) {
            i += m;  // skip this substring
        } else {
            result.push_back(s[i]);
            i++;
        }
    }
    return result;
}

void show(const string& label, const string& s) {
    cout << label << s << "\n";
}

int main() {
    string s1 = "banana";
    show("Original:   ", s1);
    string r1 = removeChar(s1, 'a');
    show("Remove 'a': ", r1);

    string s2 = "hello_world_hello";
    show("Original:       ", s2);
    string r2 = removeSub(s2, "hello");
    show("Remove 'hello': ", r2);

    // Terminologies:
    // - Occurrence: each time a character or substring appears.
    // - Substring: a contiguous sequence of characters.
    // - s.length(): length of string s.
    // - s.substr(i, m): substring of length m starting at index i.
    // Time Complexity:
    // removeChar: O(n), removeSub: O(n * m) in worst case.
    // Space Complexity: O(n) for result strings.

    return 0;
}
