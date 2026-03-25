#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue node (for BFS with HD)
struct QNode {
    struct Node* node;
    int hd;
};

// Create node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int l = 2*i + 1, r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // Queue
    struct QNode queue[100];
    int front = 0, rear = -1;

    // Storage for columns (HD range -50 to +50)
    int col[100][100]; 
    int size[100] = {0};

    int offset = 50; // shift negative HD

    // Start BFS
    queue[++rear] = (struct QNode){root, 0};

    while (front <= rear) {
        struct QNode curr = queue[front++];
        struct Node* node = curr.node;
        int hd = curr.hd + offset;

        col[hd][size[hd]++] = node->data;

        if (node->left)
            queue[++rear] = (struct QNode){node->left, curr.hd - 1};

        if (node->right)
            queue[++rear] = (struct QNode){node->right, curr.hd + 1};
    }

    // Print columns
    for (int i = 0; i < 100; i++) {
        if (size[i] > 0) {
            for (int j = 0; j < size[i]; j++) {
                printf("%d ", col[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}