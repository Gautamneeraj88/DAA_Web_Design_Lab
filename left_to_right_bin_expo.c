#include <stdio.h>

long long binaryExponentiationLTR(long long a, long long b) {
    long long result = 1;

    while (b > 0) {
        // If the current bit is 1, multiply the result by the base
        if (b & 1) {
            result *= a;
        }
        a *= a;    // Square the base
        b >>= 1;   // Shift bits of b to the right (b = b / 2)
    }

    return result;
}

int main() {
    long long a, b;
    printf("Enter the base (a) and exponent (b): ");
    scanf("%lld %lld", &a, &b);

    long long result = binaryExponentiationLTR(a, b);
    printf("Result of %lld^%lld = %lld\n", a, b, result);

    return 0;
}
