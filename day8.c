#include <stdio.h>

long long power(long long a, int b) {
	if (b == 0) return 1;
	if (b < 0) return 0; /* not handling fractional results */
	return a * power(a, b - 1);
}

int main(void) {
	long long a;
	int b;
	if (scanf("%lld %d", &a, &b) != 2) return 0;
	printf("%lld\n", power(a, b));
	return 0;
}

