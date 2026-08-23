#include <string.h>
#include <stdbool.h>

bool sumGame(char* num) {
    int n = strlen(num);
    int half = n / 2;
    long sum1 = 0, sum2 = 0;
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < half; i++) {
        if (num[i] == '?') cnt1++;
        else sum1 += num[i] - '0';
    }
    for (int i = half; i < n; i++) {
        if (num[i] == '?') cnt2++;
        else sum2 += num[i] - '0';
    }

    int totalQ = cnt1 + cnt2;

    if (totalQ % 2 == 1) return true;

    long left = 2 * sum1 + 9L * cnt1;
    long right = 2 * sum2 + 9L * cnt2;

    return left != right;
}