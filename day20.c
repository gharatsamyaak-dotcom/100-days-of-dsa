#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix_sum = 0;
    int count = 0;

    // Frequency array (adjust size if needed)
    // Assuming sum range is within -10000 to 10000
    int freq[20001] = {0};

    // To handle sum = 0 at beginning
    freq[10000] = 1;

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(freq[prefix_sum + 10000] > 0) {
            count += freq[prefix_sum + 10000];
        }

        freq[prefix_sum + 10000]++;
    }

    printf("%d", count);

    return 0;
}