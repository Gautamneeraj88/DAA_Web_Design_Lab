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

/*
Algorithm: Selection Sort

1. Start with the first element as the minimum.
2. Compare this minimum with the second element.
3. If the second element is smaller than the minimum, assign the second element as the new minimum.
4. Continue this process for all elements in the array.
5. After finding the minimum element in the array, swap it with the first element.
6. Move to the next element and repeat the process until the entire array is sorted.

Pseudocode:

function selection_sort(arr, n):
    exchanges = 0
    comparisons = 0
    outer_iterations = 0
    inner_iterations = 0

    for i from 0 to n-1:
        outer_iterations = outer_iterations + 1
        min_idx = i
        for j from i+1 to n:
            inner_iterations = inner_iterations + 1
            comparisons = comparisons + 1
            if arr[j] < arr[min_idx]:
                min_idx = j
        if min_idx != i:
            swap arr[min_idx] and arr[i]
            exchanges = exchanges + 1

    print "Sorted array: ", arr
    print "Number of exchange operations: ", exchanges
    print "Number of comparison operations: ", comparisons
    print "Number of iterations of the outer loop: ", outer_iterations
    print "Number of iterations of the inner loop: ", inner_iterations
*/
