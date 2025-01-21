// Implement to evaluate a polynomial expression using brute force method
// Input: Coefficients of the polynomial, degree of the polynomial, value of x
// Output: Value of the polynomial at x
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <stdio.h>

int brute_force_method_evaluate_poly(int poly[], int n, int x) {
  int result = 0;
  for (int i = 0; i <= n; i++) {
    int term = poly[i];
    for (int j = 0; j < n - i; j++) {
      term *= x;
    }
    result += term;
  }
  return result;
}

int main() {
    int n, x;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);
    int poly[n + 1];
    printf("Enter the coefficients of the polynomial (highest degree first): \n");
    for (int i = 0; i <= n; i++) {
        printf("Coefficient for x^%d: ", n - i);
        scanf("%d", &poly[i]);
    }
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Value of the polynomial at x is %d\n", brute_force_method_evaluate_poly(poly, n, x));
    return 0;
}

/*
Algorithm:
1. Initialize result to 0.
2. For each coefficient from the highest degree to the lowest:
   a. Initialize term to the coefficient.
   b. Multiply term by x for the appropriate number of times based on its degree.
   c. Add term to result.
3. Return result.

Pseudocode:
function brute_force_method_evaluate_poly(poly, n, x):
    result = 0
    for i from 0 to n:
        term = poly[i]
        for j from 0 to n - i - 1:
            term = term * x
        result = result + term
    return result

main:
    read n
    poly = array of size n + 1
    for i from 0 to n:
        read poly[i]
    read x
    result = brute_force_method_evaluate_poly(poly, n, x)
    print result
*/
