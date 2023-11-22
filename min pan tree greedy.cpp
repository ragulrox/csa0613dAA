#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find the parent of a vertex in a subset
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare edges based on their weights
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to perform Kruskal's algorithm to find the Minimum Spanning Tree
void kruskalMST(struct Edge* edges, int V, int E) {
    struct Edge result[V - 1]; // To store the result MST
    int e = 0; // Index variable for the result array
    int i = 0; // Index variable for the sorted edges array

    qsort(edges, E, sizeof(edges[0]), compareEdges); // Sort edges in non-decreasing order

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Create V subsets with single elements
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Keep adding edges until V-1 edges are added or all edges are considered
    while (e < V - 1 && i < E) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // Add the edge to the result if it doesn't create a cycle
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the result MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d  Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets);
}

int main() {
    int V, E; // V is the number of vertices, and E is the number of edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    // Input each edge with its source, destination, and weight
    printf("Enter the edges (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskalMST(edges, V, E);

    free(edges);

    return 0;
} 9