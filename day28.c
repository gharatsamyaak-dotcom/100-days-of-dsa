#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create Circular Linked List
struct Node* createCircularList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    if(temp != NULL) {
        temp->next = head;  // Make it circular
    }

    return head;
}

// Traverse Circular Linked List
void printCircularList(struct Node* head) {
    if(head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
}

int main() {
    int n;

    scanf("%d", &n);
    struct Node* head = createCircularList(n);

    printCircularList(head);

    return 0;
}