#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindromeString(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

// Function to check if a number is a palindrome
int isPalindromeNumber(int num) {
    int originalNum = num;
    int reversedNum = 0;
    
    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return originalNum == reversedNum;
}

int main() {
    char str[100];
    int num;

    // Case 1: Check if a given string is a palindrome
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindromeString(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    // Case 2: Check if a given number is a palindrome
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPalindromeNumber(num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }

    return 0;
}