#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) return 0;
	if (n <= 0) return 0;

	int *a = malloc(sizeof(int) * n);
	if (!a) return 0;

	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	int write = 1; /* index where next unique goes */
	for (int i = 1; i < n; ++i) {
		if (a[i] != a[write - 1]) {
			a[write++] = a[i];
		}
	}

	/* print unique elements */
	if (write > 0) {
		printf("%d", a[0]);
		for (int i = 1; i < write; ++i) printf(" %d", a[i]);
	}
	printf("\n");

	free(a);
	return 0;
}

