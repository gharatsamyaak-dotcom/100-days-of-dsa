#include <stdio.h>

#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// Pop from stack
int pop() {
    return stack[top--];
}

int main() {
    int n;
    scanf("%d", &n);

    // Input queue
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue → stack
    for (int i = 0; i < n; i++) {
        push(dequeue());
    }

    // Step 2: Move stack → queue
    front = 0;
    rear = -1;

    for (int i = 0; i < n; i++) {
        enqueue(pop());
    }

    // Output reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}