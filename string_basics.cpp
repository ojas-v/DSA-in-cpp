#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // 1. Declaration and Initialization
    string s1 = "hello";
    string s2("world");
    string s3 = s1 + " " + s2; // Concatenation

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3 (concatenated): " << s3 << endl;

    // 2. Length and Access
    cout << "Length of s3: " << s3.length() << endl;
    cout << "First character of s3: " << s3[0] << endl;

    // 3. Comparison
    string a = "apple", b = "banana";
    if (a < b)
        cout << a << " comes before " << b << " lexicographically." << endl;

    // 4. Substring
    string sub = s3.substr(0, 5); // substring from index 0 to 4
    cout << "Substring of s3: " << sub << endl;

    // 5. Reversal
    reverse(s3.begin(), s3.end());
    cout << "Reversed s3: " << s3 << endl;

    // 6. Sorting
    string s4 = "cbade";
    sort(s4.begin(), s4.end());
    cout << "Sorted s4: " << s4 << endl;

    // 7. Find operation
    string str = "this is a string";
    size_t found = str.find("is");
    if (found != string::npos)
        cout << "Found 'is' at index: " << found << endl;

    // --- Terminologies ---
    // Length: number of characters in the string.
    // Substring: a part of the original string.
    // Lexicographical Order: dictionary-like order.
    // Mutable: strings in C++ (std::string) can be changed after creation.
    // Immutability: strings once created can't be modified.
    // Time Complexity:
    //   - Access: O(1)
    //   - Concatenation: O(n)
    //   - Substring: O(k)
    //   - Find: O(n)

    return 0;
}
