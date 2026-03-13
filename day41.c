#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue
void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue
int dequeue() {
    if (front == NULL) return -1;

    struct Node* temp = front;
    int val = temp->data;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

int main() {
    int n;
    scanf("%d", &n);

    char op[10];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'e' && op[1] == 'n') { // enqueue
            scanf("%d", &x);
            enqueue(x);
        }
        else if (op[0] == 'd') { // dequeue
            printf("%d\n", dequeue());
        }
    }

    return 0;
}