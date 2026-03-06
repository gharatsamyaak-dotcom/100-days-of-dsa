#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char* expr) {
    struct Node* stack = NULL;
    int i = 0;

    while (expr[i] != '\0') {

        // Skip spaces
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        // If operand
        if (isdigit(expr[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }

            push(&stack, num);
        }
        else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);

            switch (expr[i]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
            }
            i++;
        }
    }

    return pop(&stack);
}

// Main function
int main() {
    char expr[100];

    printf("Enter postfix expression: ");
    fgets(expr, sizeof(expr), stdin);

    int result = evaluatePostfix(expr);

    printf("Result = %d\n", result);

    return 0;
}