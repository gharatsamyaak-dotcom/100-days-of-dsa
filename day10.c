#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int left, right, len, flag = 1;

    scanf("%s", s);

    len = strlen(s);
    left = 0;
    right = len - 1;

    while(left < right) {
        if(s[left] != s[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }

    if(flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}
