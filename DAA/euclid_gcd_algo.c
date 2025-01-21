//implementing Euclid's algorithm to find the GCD of two numbers
//Time Complexity: O(log(min(a, b)))

#include <stdio.h>

int gcd(int a, int b) {
  int reminder;
  while (b != 0) {
    reminder = a % b;
    a = b;
    b = reminder;
  }
return a;
}
int main() {
    int a, b;
    printf("Enter the divisior (a): ");
    scanf("%d", &a);
    printf("Enter the dividend (b): ");
    scanf("%d", &b);
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
}

/*
Algorithm to find the GCD of two numbers a and b:

1. Start
2. Input a and b
3. While b is not equal to 0, repeat steps 4-6
4. Compute the remainder of a divided by b
5. Assign the value of b to a
6. Assign the value of the remainder to b
7. When b becomes 0, the value of a is the GCD
8. Output the GCD
9. End

Pseudocode:

function gcd(a, b)
    while b ≠ 0 do
        remainder ← a mod b
        a ← b
        b ← remainder
    return a

main
    input a, b
    print "GCD of", a, "and", b, "is", gcd(a, b)
*/
