#include <stdio.h>
void printSubset(int subset[], int size) {
    printf("Subset is { ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}
void sumOfSubsetsBacktrack(int s[], int targetSum, int subset[], int subsetSize, int index, int size) {
    if (targetSum == 0) {
        printSubset(subset, subsetSize);
        return;
    }
    if (index == size) {
        return;
    }
    subset[subsetSize] = s[index];
    sumOfSubsetsBacktrack(s, targetSum - s[index], subset, subsetSize + 1, index + 1, size);
    sumOfSubsetsBacktrack(s, targetSum, subset, subsetSize, index + 1, size);
}
int main() {
    int size;
    printf("Enter the size of the set: ");
    scanf("%d", &size);
    int s[size];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &s[i]);
    }
    int targetSum;
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    int subset[size];
    printf("\nInput: Set (s) = {");
    for (int i = 0; i < size; i++) {
        printf(" %d", s[i]);
    }
    printf(" } sum is %d\n", targetSum);
    sumOfSubsetsBacktrack(s, targetSum, subset, 0, 0, size);
    return 0;
}
