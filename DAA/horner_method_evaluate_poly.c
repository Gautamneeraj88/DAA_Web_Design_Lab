// Implement Horner's method to evaluate a polynomial expression
// Input: Coefficients of the polynomial, degree of the polynomial, value of x
// Output: Value of the polynomial at x
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <stdio.h>

int horner_method_evaluate_poly(int poly[], int n, int x) {
  int result = poly[0];
  for (int i = 1; i <= n; i++) {
    result = result * x + poly[i];
  }
  return result;
}

int main () {
    int n, x;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);
    int poly[n];
    printf("Enter the coefficients of the polynomial (highest degree first): \n");
    for (int i = 0; i <= n; i++) {
        printf("Coefficient for x^%d: ", n - i);
        scanf("%d", &poly[i]);
    }
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Value of the polynomial at x is %d\n", horner_method_evaluate_poly(poly, n, x));
}
/*
Algorithm: Horner's Method

Horner's method is used to evaluate a polynomial at a given value of x efficiently.
It reduces the number of multiplications and additions required.

Pseudocode:
1. Initialize result as the first coefficient of the polynomial.
2. For each coefficient from the second to the last:
   a. Multiply the current result by x.
   b. Add the next coefficient to the result.
3. The final result is the value of the polynomial at x.

Example:
For a polynomial 6x^6 + 5x^5 + 4x^4 - 3x^3 + 2x^2 + 8x - 7 and x = 3:
1. Start with the first coefficient: result = 6
2. Multiply result by x and add the next coefficient: result = 6*3 + 5 = 23
3. Repeat for all coefficients: result = 23*3 + 4 = 73, result = 73*3 - 3 = 216, result = 216*3 + 2 = 650, result = 650*3 + 8 = 1958, result = 1958*3 - 7 = 5867
4. The final result is 5867.
*/
