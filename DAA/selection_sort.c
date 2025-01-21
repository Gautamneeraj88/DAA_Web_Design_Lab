// Implement the selection sort algorithm in C.
// Input: An array of n elements
// Output: Sorted array in ascending order
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// print numbers of exchange operation performed
// print numbers of comparison operation performed
// print number of times the inner and outer loop will iterate

#include <stdio.h>

void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;
    int exchanges = 0, comparisons = 0, outer_iterations = 0, inner_iterations = 0;

    for (i = 0; i < n - 1; i++) {
        outer_iterations++;
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            inner_iterations++;
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            exchanges++;
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of exchange operations: %d\n", exchanges);
    printf("Number of comparison operations: %d\n", comparisons);
    printf("Number of iterations of the outer loop: %d\n", outer_iterations);
    printf("Number of iterations of the inner loop: %d\n", inner_iterations);
}

int main() {
    int arr[] = {55, 25, 15, 40, 60, 35, 17, 65, 75, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, n);

    return 0;
}
