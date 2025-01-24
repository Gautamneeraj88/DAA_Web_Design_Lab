#include <stdio.h>

void bubbleSort (int arr[], int n) {
    int comparison = 0, exchange = 0, iteration = 0;

    //bubble sort logic
    for (int i = 0; i < n-1; i++) {
        int swapped = 0;
        for (int j = 0; j < n -i -1; j++){
            comparison++;
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                exchange++;
                swapped = 1;
            }
        }
        iteration++;
        if (!swapped) break;
    }
}

int main ()
{
    int arr[] = {5, 3, 8, 6, 2, 7, 4, 1, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
