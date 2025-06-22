#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// reverse_words.cpp

// Function to reverse words in a string
string reverseWords(string sentence) {
    vector<string> parts; // store words
    string temp;
    stringstream ss(sentence);

    while (ss >> temp) {
        parts.push_back(temp);
    }

    string finalLine = "";
    for (int i = parts.size() - 1; i >= 0; i--) {
        finalLine += parts[i];
        if (i != 0) finalLine += " ";
    }
    return finalLine;
}

// Function to show output with label
void printLine(string tag, string text) {
    cout << tag << text << "\n";
}

int main() {
    string msg = "hello world test";
    printLine("Original: ", msg);

    string changed = reverseWords(msg);
    printLine("Reversed: ", changed);

    return 0;

// Terminologies:
// - Word: group of characters between spaces.
// - Stringstream: helps break a string into words.
// - Reverse: flip the order of things.
// - Time: O(n), Space: O(n)
}
