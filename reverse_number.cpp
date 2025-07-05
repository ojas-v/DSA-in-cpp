#include <iostream>
#include <climits>
using namespace std;

class ReverseInteger {
public:
    // Function to reverse the digits of an integer
    int reverse(int x) {
        int n = 0;  // Result accumulator

        while(x != 0){
            int y = x % 10;  // Extract last digit
            x = x / 10;      // Remove last digit from x

            // Check for overflow or underflow before multiplying and adding
            if((n > INT_MAX / 10) || (n == INT_MAX / 10 && y > 7)) return 0;
            if((n < INT_MIN / 10) || (n == INT_MIN / 10 && y < -8)) return 0;

            n = n * 10 + y;  // Append digit to reversed number
        }

        return n;
    }
};

int main() {
    ReverseInteger ri;
    int x;
    cout << "Enter an integer to reverse: ";
    cin >> x;

    int result = ri.reverse(x);
    cout << "Reversed Integer: " << result << endl;

    return 0;
}
