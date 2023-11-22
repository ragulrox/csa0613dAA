#include <stdio.h>
#include <stdbool.h>

#define N 10

int board[N][N];
void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int row, int col, int n) {
    int i, j;
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}
bool solveNQueens(int col, int n) {
    if (col >= n) {
        printBoard(n);
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1;
            res = solveNQueens(col + 1, n) || res;
            board[i][col] = 0;
        }
    }

    return res;
}

int main() {
    int n;

    printf("Enter the value of n for N-Queens: ");
    scanf("%d", &n);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (!solveNQueens(0, n)) {
        printf("Solution does not exist for n = %d.\n", n);
    }

    return 0;
}