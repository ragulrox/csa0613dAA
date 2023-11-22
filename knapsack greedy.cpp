#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Function to compare items based on value-to-weight ratio in descending order
int compareItems(const void* a, const void* b) {
    double ratioA = ((double)((struct Item*)a)->value) / ((struct Item*)a)->weight;
    double ratioB = ((double)((struct Item*)b)->value) / ((struct Item*)b)->weight;
    return (ratioB - ratioA) > 0 ? 1 : -1;
}

// Function to perform Knapsack using a greedy approach
void knapsackGreedy(struct Item items[], int n, int capacity) {
    // Sort items based on value-to-weight ratio in descending order
    qsort(items, n, sizeof(struct Item), compareItems);

    int currentWeight = 0;  // Current weight in the knapsack
    double totalValue = 0;  // Total value obtained

    // Iterate through sorted items
    for (int i = 0; i < n; i++) {
        // If adding the current item doesn't exceed the capacity, add it
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Selected: Value: %d, Weight: %d\n", items[i].value, items[i].weight);
        }
    }

    printf("Total Value in Knapsack: %.2lf\n", totalValue);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item* items = (struct Item*)malloc(n * sizeof(struct Item));

    // Input items and their values and weights
    printf("Enter the values and weights of items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    knapsackGreedy(items, n, capacity);

    free(items);

    return 0;
}