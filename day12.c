#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[100][100];
    int i, j;
    int symmetric = 1;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // First condition: must be square
    if(m != n) {
        symmetric = 0;
    } else {
        // Check symmetry condition
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(matrix[i][j] != matrix[j][i]) {
                    symmetric = 0;
                    break;
                }
            }
            if(symmetric == 0)
                break;
        }
    }

    if(symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
