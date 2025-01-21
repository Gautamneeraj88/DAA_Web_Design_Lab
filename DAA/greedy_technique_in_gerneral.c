// Implement greedy technique in general

#include <stdio.h>

int greedy_algorithm(int items[], int n) {
    int i, max_value = 0;

    for (i = 0; i < n; i++) {
        if (items[i] > max_value) {
            max_value = items[i];
        }
    }

    return max_value;
}

int main() {
    int items[] = {1, 2, 3, 4, 5};
    int n = sizeof(items) / sizeof(items[0]);
    int result = greedy_algorithm(items, n);

    printf("The maximum value is: %d\n", result);

    return 0;
}

/*
Greedy Technique:
The greedy technique is an algorithmic approach that builds up a solution piece by piece, always choosing the next piece that offers the most immediate benefit. The idea is to make a locally optimal choice at each step with the hope that these local choices will lead to a globally optimal solution.

General Implementation:
1. Initialize an empty solution set.
2. While the solution set is not complete:
   a. Select the best candidate from the remaining candidates.
   b. Check if the candidate can be added to the solution set without violating the problem constraints.
   c. If yes, add the candidate to the solution set.
3. Return the solution set.

Example: Fractional Knapsack Problem

#include <stdio.h>

struct Item {
    int value;
    int weight;
};

void fractional_knapsack(struct Item items[], int n, int capacity) {
    int i, j;
    float total_value = 0.0;
    float current_weight = 0.0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            float ratio1 = (float)items[j].value / items[j].weight;
            float ratio2 = (float)items[j + 1].value / items[j + 1].weight;
            if (ratio1 < ratio2) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            int remaining_weight = capacity - current_weight;
            total_value += items[i].value * ((float)remaining_weight / items[i].weight);
            break;
        }
    }

    printf("Total value in the knapsack: %.2f\n", total_value);
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    fractional_knapsack(items, n, capacity);

    return 0;
}
*/
