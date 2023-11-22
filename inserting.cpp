#include <stdio.h>
void insertElement(int arr[], int *size, int element, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position to insert.\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

int main() {
    int array[50]; 
    int size, num, pos;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &num);

    printf("Enter the position to insert the number (0 to %d): ", size);
    scanf("%d", &pos);

    insertElement(array, &size, num, pos);

    printf("Array after insertion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}