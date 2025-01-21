// implement the bubble sort algorithm
// Input: An array of n elements
// Output: Sorted array in ascending order
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// print numbers of exchange operation performed
// print numbers of comparison operation performed
// print number of times the inner and outer loop will iterate

#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    int exchanges = 0, comparisons = 0, outer_iterations = 0, inner_iterations = 0;

    for (i = 0; i < n - 1; i++) {
        outer_iterations++;
        for (j = 0; j < n - i - 1; j++) {
            inner_iterations++;
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                exchanges++;
            }
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
    bubble_sort(arr, n);
    return 0;
}

/*
Algorithm: Bubble Sort

1. Start
2. Initialize exchanges, comparisons, outer_iterations, and inner_iterations to 0
3. For i from 0 to n-1:
    a. Increment outer_iterations
    b. For j from 0 to n-i-1:
        i. Increment inner_iterations
        ii. Increment comparisons
        iii. If arr[j] > arr[j+1]:
            1. Swap arr[j] and arr[j+1]
            2. Increment exchanges
4. Print the sorted array
5. Print exchanges, comparisons, outer_iterations, and inner_iterations
6. End

Pseudocode:

procedure bubble_sort(arr, n)
    exchanges ← 0
    comparisons ← 0
    outer_iterations ← 0
    inner_iterations ← 0

    for i ← 0 to n-1 do
        outer_iterations ← outer_iterations + 1
        for j ← 0 to n-i-1 do
            inner_iterations ← inner_iterations + 1
            comparisons ← comparisons + 1
            if arr[j] > arr[j+1] then
                swap(arr[j], arr[j+1])
                exchanges ← exchanges + 1

    print("Sorted array: ", arr)
    print("Number of exchange operations: ", exchanges)
    print("Number of comparison operations: ", comparisons)
    print("Number of iterations of the outer loop: ", outer_iterations)
    print("Number of iterations of the inner loop: ", inner_iterations)
end procedure
*/
