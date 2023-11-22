#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int key;
    int freq;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given key and frequency
struct Node* createNode(int key, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to construct an optimal binary search tree
struct Node* constructOptimalBST(int keys[], int freq[], int start, int end) {
    if (start > end)
        return NULL;

    // Find the root of the optimal BST
    int minCostIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (freq[i] < freq[minCostIndex])
            minCostIndex = i;
    }

    // Create the root node
    struct Node* root = createNode(keys[minCostIndex], freq[minCostIndex]);

    // Recursively construct left and right subtrees
    root->left = constructOptimalBST(keys, freq, start, minCostIndex - 1);
    root->right = constructOptimalBST(keys, freq, minCostIndex + 1, end);

    return root;
}

// Function to calculate the cost of a binary search tree
int calculateCost(struct Node* root, int depth) {
    if (root == NULL)
        return 0;

    // The cost is the product of depth and frequency, plus costs of left and right subtrees
    return root->freq * depth + calculateCost(root->left, depth + 1) + calculateCost(root->right, depth + 1);
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n];
    int freq[n];

    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the corresponding frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    struct Node* root = constructOptimalBST(keys, freq, 0, n - 1);
    int totalCost = calculateCost(root, 1);

    printf("\nBinary Search Tree (In-order traversal):\n");
    
    printf("\nTotal Cost of Binary Search Tree: %d\n", totalCost);

    return 0;
}