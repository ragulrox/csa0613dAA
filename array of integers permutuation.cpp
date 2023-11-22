#include <stdio.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate all permutations of an array
void generatePermutations(int arr[], int size, int index) {
    if (index == size - 1) {
        printArray(arr, size);
        return;
    }

    for (int i = index; i < size; i++) {
        // Swap current element with the element at index
        swap(&arr[i], &arr[index]);

        // Recursively generate permutations for the remaining elements
        generatePermutations(arr, size, index + 1);

        // Backtrack to restore the original array
        swap(&arr[i], &arr[index]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Permutations of the array:\n");
    generatePermutations(arr, n, 0);

    return 0;
}