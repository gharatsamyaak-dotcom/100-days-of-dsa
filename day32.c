#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

void display() {
    for(int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if(i != 0)
            printf(" ");
    }
}

int main() {
    int n, m, val;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        pop();
    }

    display();

    return 0;
}