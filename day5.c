#include <stdio.h>

int main() {
    int p, q;
    int i = 0, j = 0;

    scanf("%d", &p);
    int log1[p];
    for (int k = 0; k < p; k++) {
        scanf("%d", &log1[k]);
    }

    scanf("%d", &q);
    int log2[q];
    for (int k = 0; k < q; k++) {
        scanf("%d", &log2[k]);
    }

    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }

    return 0;
}
