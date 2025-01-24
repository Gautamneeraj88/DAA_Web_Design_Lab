#include <stdio.h>

typedef struct {
int weight;
int profit;
double ratio;
} Item;

//bubble sort
void sortItems(Item items[], int n) {
    for (int i = 0; i<n-1; i++) {
        for (int j = 0; j<n-i-1; j++) {
            if (items[j].ratio < items[j+1].ratio) {
                Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}

double fractionalKnapsack(Item items[], int n, int capacity) {
    //sort items based on ratio
    sortItems(items, n);

    double totalProfit = 0.0;
    int currentWeight = 0;

    //logic for fractional knapsack
    for (int i = 0; i<n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
        } else {
            int remainingCap = capacity - currentWeight;
            totalProfit += items[i].profit * ((double) remainingCap / items[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main()
{
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxProfit = fractionalKnapsack(items, n, capacity);
    printf("Maximum profit: %.2f\n", maxProfit);

    return 0;
}
