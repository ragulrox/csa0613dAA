#include <stdio.h>

#define MAX 10

// Function to print subsets
void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Function to generate all subsets
void generateSubsets(int arr[], int n) {
    for (int i = 0; i < (1 << n); i++) {
        int subset[MAX];
        int subsetSize = 0;

        // Check each bit of the counter
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset[subsetSize++] = arr[j];
            }
        }

        // Print the subset
        printSubset(subset, subsetSize);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Array size exceeds the limit.\n");
        return 1;
    }

    int arr[MAX];
    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("All possible subsets:\n");
    generateSubsets(arr, n);

    return 0;
}