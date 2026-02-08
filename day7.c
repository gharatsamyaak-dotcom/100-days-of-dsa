#include <stdio.h>

long long fib(int n) {
	if (n <= 1) return n;
	return fib(n - 1) + fib(n - 2);
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) return 0;
	if (n < 0) return 0;
	printf("%lld\n", fib(n));
	return 0;
}

