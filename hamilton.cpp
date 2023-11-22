#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Number of vertices in the graph
int vertices;

// Graph represented as an adjacency matrix
int graph[MAX][MAX];

// Array to store the solution (Hamiltonian circuit)
int path[MAX];

// Function to check if a vertex can be added to the Hamiltonian circuit
bool isSafe(int v, int pos, int path[]) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive function to find Hamiltonian circuit
bool hamiltonianCircuitUtil(int path[], int pos) {
    if (pos == vertices) {
        // Check if the last vertex is connected to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < vertices; v++) {
        if (isSafe(v, pos, path)) {
            path[pos] = v;

            if (hamiltonianCircuitUtil(path, pos + 1) == true)
                return true;

            path[pos] = -1; // Backtrack
        }
    }

    return false;
}

// Function to find and print Hamiltonian circuit
void findHamiltonianCircuit() {
    int path[MAX];

    // Initialize path array
    for (int i = 0; i < vertices; i++)
        path[i] = -1;

    // Start from the first vertex (0)
    path[0] = 0;

    if (hamiltonianCircuitUtil(path, 1) == false) {
        printf("Hamiltonian Circuit does not exist.\n");
        return;
    }

    printf("Hamiltonian Circuit:\n");
    for (int i = 0; i < vertices; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    findHamiltonianCircuit();

    return 0;
}