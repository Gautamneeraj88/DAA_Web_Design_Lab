// Implement the left and right binary exponentiation method in C.
// Input: Base, exponent, and modulus
// Output: Result of base raised to the power of exponent modulo modulus
// Time Complexity: O(log(exponent))
// Space Complexity: O(1)

#include <stdio.h>

// Function for left-to-right binary exponentiation with modulus
unsigned long long left_to_right_binary_exponentiation(unsigned long long base, unsigned long long exponent, unsigned long long mod) {
    unsigned long long result = 1;

    // Convert exponent to binary and process left-to-right
    for (int i = 63; i >= 0; i--) {
        result = (result * result) % mod; // Square the result mod
        if ((exponent >> i) & 1) {
            result = (result * base) % mod; // Multiply by base if the current bit is 1
        }
    }

    return result;
}

// Function for right-to-left binary exponentiation with modulus
unsigned long long right_to_left_binary_exponentiation(unsigned long long base, unsigned long long exponent, unsigned long long mod) {
    unsigned long long result = 1;
    unsigned long long current_base = base % mod;

    while (exponent > 0) {
        if (exponent % 2 == 1) { // If the least significant bit is 1
            result = (result * current_base) % mod;
        }
        current_base = (current_base * current_base) % mod; // Square the base mod
        exponent /= 2; // Shift right (integer division by 2)
    }

    return result;
}

int main() {
    unsigned long long base, exponent, mod;

    // User interaction
    printf("Enter the base: ");
    scanf("%llu", &base);

    printf("Enter the exponent: ");
    scanf("%llu", &exponent);

    printf("Enter the modulus: ");
    scanf("%llu", &mod);

    // Calculate using left-to-right binary exponentiation
    unsigned long long ltr_result = left_to_right_binary_exponentiation(base, exponent, mod);
    printf("Result using left-to-right binary exponentiation: %llu\n", ltr_result);

    // Calculate using right-to-left binary exponentiation
    unsigned long long rtl_result = right_to_left_binary_exponentiation(base, exponent, mod);
    printf("Result using right-to-left binary exponentiation: %llu\n", rtl_result);

    return 0;
}
