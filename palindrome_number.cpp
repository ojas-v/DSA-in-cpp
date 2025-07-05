#include <iostream>
using namespace std;

class PalindromeNumber {
public:
    // Function to check if a number is a palindrome
    bool isPalindrome(int x) {
        // Negative numbers or numbers ending in 0 (but not 0 itself) can't be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversed = 0;

        // Reverse half of the number
        while (x > reversed) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        // If number has even digits: x == reversed
        // If number has odd digits: x == reversed / 10
        return (x == reversed || x == reversed / 10);
    }
};

int main() {
    PalindromeNumber checker;

    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (checker.isPalindrome(num)) {
        cout << num << " is a palindrome number." << endl;
    } else {
        cout << num << " is not a palindrome number." << endl;
    }

    return 0;
}
