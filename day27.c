#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create list
struct Node* createList(int n) {
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
    return head;
}

// Find length
int getLength(struct Node* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection by value comparison
void findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;
    struct Node *ptr1 = head1, *ptr2 = head2;

    if(len1 > len2) {
        diff = len1 - len2;
        for(int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        diff = len2 - len1;
        for(int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1->data == ptr2->data) {
            printf("%d", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    findIntersection(list1, list2);

    return 0;
}