#include <stdio.h>

void selectionSort (int arr[], int n)
{
    int comparison = 0, exchange = 0, iteration = 0;

    // Selection sort logic
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j<n; j++) {
            comparison++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        iteration++;
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            exchange++;
        }
    }

    printf("Number of comparisons: %d\n", comparison);
    printf("Number of exchanges: %d\n", exchange);
    printf("Number of iterations: %d\n", iteration);
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
        int n = sizeof(arr)/sizeof(arr[0]);

        printf("Original array: \n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        selectionSort(arr, n);

        printf("Sorted array: \n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
}
