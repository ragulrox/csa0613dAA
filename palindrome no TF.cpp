#include <stdio.h>

// Function to check if a number is a palindrome
int isPalindrome(int x) {
    int original = x;
    int reversed = 0;

    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return original == reversed;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}