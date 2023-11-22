
#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int space = 1; space <= n - i; space++) {
            printf("  ");
        }

        // Print numbers
        for (int j = 1; j <= i; j++) {
            printf("%2d", j);

            // Print a space after the number except for the last number in the row
            if (j < i) {
                printf(" ");
            }
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}