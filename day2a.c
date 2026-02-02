#include <stdio.h>

int main() {
    int n, pos;
    int arr[100];   // assuming maximum size

    // Input
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos);

    // Check for valid position
    if (pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    // Shift elements to the left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Output updated array
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
