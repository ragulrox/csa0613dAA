#include <stdio.h>

// Function to calculate the sum of digits of a number
int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to find the maximum value of nums[i] + nums[j]
int maxSumWithEqualDigitSums(int nums[], int size) {
    const int maxDigitSum = 200; // Maximum possible digit sum (as per problem constraints)
    int digitSumIndex[maxDigitSum * 2 + 1]; // Storing indices of same digit sum numbers
    for (int i = 0; i < maxDigitSum * 2 + 1; i++) {
        digitSumIndex[i] = -1; // Initializing indices with -1 (no occurrence initially)
    }

    int maxSum = 0;
    for (int i = 0; i < size; i++) {
        int sum = digitSum(nums[i]);
        if (digitSumIndex[sum] != -1) {
            int index = digitSumIndex[sum];
            maxSum = (nums[index] + nums[i] > maxSum) ? (nums[index] + nums[i]) : maxSum;
        }
        digitSumIndex[sum] = (digitSumIndex[sum] == -1) ? i : digitSumIndex[sum];
    }

    return maxSum;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int nums[size];

    printf("Enter %d elements into the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    int maxSum = maxSumWithEqualDigitSums(nums, size);
    printf("Maximum value of nums[i] + nums[j]: %d\n", maxSum);

    return 0;
}