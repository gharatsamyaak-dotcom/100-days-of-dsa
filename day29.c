#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct Node* rotateRight(struct Node* head, int n, int k) {
    if(head == NULL || k == 0)
        return head;

    k = k % n;

    struct Node* temp = head;

    // find last node
    while(temp->next != NULL)
        temp = temp->next;

    // make circular
    temp->next = head;

    int steps = n - k;
    struct Node* newTail = head;

    for(int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;

    // break circle
    newTail->next = NULL;

    return newHead;
}

int main() {
    int n, k, val;

    scanf("%d", &n);

    struct Node *head = NULL, *temp, *last = NULL;

    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        temp = createNode(val);

        if(head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, n, k);

    printList(head);

    return 0;
}