#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Stack
int stack[MAX];
int top = -1;

// Create node
struct Node* newNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = v;
    temp->next = NULL;
    return temp;
}

// Add edge (directed)
void addEdge(int u, int v) {
    struct Node* node = newNode(v);
    node->next = adj[u];
    adj[u] = node;
}

// DFS
void DFS(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }

    // Push after visiting all neighbors
    stack[++top] = v;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Run DFS for all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    // Print topo order (reverse stack)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}