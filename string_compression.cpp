#include <iostream>
#include <string>
using namespace std;

// string_compression.cpp

// Function to compress a string using RLE
string compressString(const string& s) {
    string result;
    int n = s.length();
    int i = 0;

    while (i < n) {
        char c = s[i];          // current char
        int count = 0;          // run length
        
        // count repeats
        while (i < n && s[i] == c) {
            count++;
            i++;
        }
        
        // append char and count
        result += c;
        result += to_string(count);
    }
    return result;
}

// Function to print a label and value
void printLine(const string& label, const string& text) {
    cout << label << text << "\n";
}

int main() {
    string input = "aaabbccccdd";
    printLine("Original:   ", input);

    string comp = compressString(input);
    printLine("Compressed: ", comp);

    // Example compression ratio
    double ratio = (double)input.length() / comp.length();
    cout << "Compression Ratio: " << ratio << "\n";

    return 0;

// Terminologies:
// - Run: a sequence of the same character repeated.
// - Run-Length Encoding (RLE): compression by collapsing runs into (char,count).
// - Compression Ratio: original_length / compressed_length.
// - Time Complexity: O(n) where n = length of input.
// - Space Complexity: O(n) for output string (in worst case).
}
