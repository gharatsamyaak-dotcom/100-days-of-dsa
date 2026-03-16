#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int *queue = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;

    for(int i = 0; i < m; i++) {
        front = (front + 1) % n;
        rear = (rear + 1) % n;
    }

    int count = 0;
    int i = front;

    while(count < n) {
        printf("%d ", queue[i]);
        i = (i + 1) % n;
        count++;
    }

    free(queue);
    return 0;
}