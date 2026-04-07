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
int recStack[MAX];

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

// DFS cycle check
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->vertex;

        if (!visited[u]) {
            if (dfs(u))
                return 1;
        }
        else if (recStack[u]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
}

// Check cycle in graph
int hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v); // directed
    }

    if (hasCycle(n))
        printf("YES");
    else
        printf("NO");

    return 0;
}