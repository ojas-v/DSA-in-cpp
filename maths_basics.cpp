#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// math_basics.cpp
// Basic math operations using simple functions in C++.

// 1. Prime number check
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 2. Sieve of Eratosthenes
vector<bool> getPrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

// 3. GCD using Euclid's algorithm
int getGCD(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 4. Count digits in a number
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

// 5. Reverse a number
int reverseNumber(int num) {
    int rev = 0;
    while (num != 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

// 6. Armstrong number check
bool isArmstrong(int num) {
    int digits = countDigits(num);
    int sum = 0;
    int original = num;
    while (num != 0) {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }
    return sum == original;
}

// 7. Modular addition
int modAdd(int a, int b, int mod) {
    return (a % mod + b % mod) % mod;
}

// 7. Modular multiplication
int modMultiply(int a, int b, int mod) {
    return ((long long)(a % mod) * (b % mod)) % mod;
}

// 8. Fast exponentiation (x^power % mod)
int fastPower(int x, int power, int mod) {
    long long result = 1;
    long long base = x % mod;
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power /= 2;
    }
    return (int)result;
}

int main() {
    int n = 29;
    cout << n << " is prime? " << (isPrime(n) ? "yes" : "no") << "\n";

    int limit = 50;
    auto primeList = getPrimes(limit);
    cout << "Primes up to " << limit << ": ";
    for (int i = 2; i <= limit; i++) {
        if (primeList[i]) cout << i << " ";
    }
    cout << "\n";

    int a = 36, b = 60;
    cout << "GCD of " << a << " and " << b << " = " << getGCD(a, b) << "\n";

    int number = 12345;
    cout << "Digits in " << number << " = " << countDigits(number) << "\n";
    cout << "Reverse of " << number << " = " << reverseNumber(number) << "\n";

    int arm = 153;
    cout << arm << " is Armstrong? " << (isArmstrong(arm) ? "yes" : "no") << "\n";

    int mod = 1000000007;
    cout << "(2 + 3) mod " << mod << " = " << modAdd(2, 3, mod) << "\n";
    cout << "(2 * 3) mod " << mod << " = " << modMultiply(2, 3, mod) << "\n";
    cout << "2^10 mod " << mod << " = " << fastPower(2, 10, mod) << "\n";

    return 0;
}
