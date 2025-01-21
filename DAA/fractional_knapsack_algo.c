// implement the Fractional Knapsack algorithm
// Input: An array of items with weights and values, and the capacity of the knapsack
// Output: Maximum value that can be obtained
// Time Complexity: O(n log n)
// Space Complexity: O(1)

#include <stdio.h>

typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void sort_items(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

float fractional_knapsack(Item items[], int n, int capacity) {
    sort_items(items, n);
    float total_value = 0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            total_value += items[i].value;
            capacity -= items[i].weight;
        } else {
            total_value += items[i].ratio * capacity;
            break;
        }
    }
    return total_value;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item items[n];
    printf("Enter the weights and profit of the items: \n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float) items[i].value / items[i].weight;
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Maximum value that can be obtained: %.2f\n", fractional_knapsack(items, n, capacity));
    return 0;
}

/*
Algorithm:
1. Define a structure for items with weight, value, and ratio.
2. Implement a swap function to swap two items.
3. Implement a sort function to sort items based on their value-to-weight ratio in descending order.
4. Implement the fractional knapsack function:
   a. Sort the items.
   b. Initialize total_value to 0.
   c. Iterate through the sorted items:
      i. If the knapsack can carry the full weight of the current item, add its full value to total_value and decrease the capacity.
      ii. If the knapsack cannot carry the full weight, add the fractional value of the item that can fit into the remaining capacity and break the loop.
   d. Return total_value.
5. In the main function:
   a. Read the number of items and their weights and values.
   b. Calculate the value-to-weight ratio for each item.
   c. Read the capacity of the knapsack.
   d. Call the fractional knapsack function and print the result.

Pseudocode:
Define structure Item:
    weight: int
    value: int
    ratio: float

Function swap(a: Item, b: Item):
    temp = a
    a = b
    b = temp

Function sort_items(items: array of Item, n: int):
    for i from 0 to n-2:
        for j from 0 to n-i-2:
            if items[j].ratio < items[j+1].ratio:
                swap(items[j], items[j+1])

Function fractional_knapsack(items: array of Item, n: int, capacity: int) -> float:
    sort_items(items, n)
    total_value = 0
    for i from 0 to n-1:
        if capacity >= items[i].weight:
            total_value += items[i].value
            capacity -= items[i].weight
        else:
            total_value += items[i].ratio * capacity
            break
    return total_value

Main function:
    Read n
    Declare array items of size n
    for i from 0 to n-1:
        Read items[i].weight and items[i].value
        items[i].ratio = items[i].value / items[i].weight
    Read capacity
    result = fractional_knapsack(items, n, capacity)
    Print result
*/
