#include <string.h>
#include <stdlib.h>

#define LIMBS 40
#define BASE 1000000000U

typedef struct {
    unsigned int limb[LIMBS]; 
} BigInt;

static void bigAddInPlace(BigInt* a, const BigInt* b) {
    unsigned long long carry = 0;
    for (int i = 0; i < LIMBS; i++) {
        unsigned long long sum = (unsigned long long)a->limb[i] + b->limb[i] + carry;
        a->limb[i] = (unsigned int)(sum % BASE);
        carry = sum / BASE;
    }
 }

int numDistinct(char* s, char* t) {
    int n = strlen(s);
    int m = strlen(t);
    if (m > n) return 0;

    BigInt* dp = (BigInt*)calloc(m + 1, sizeof(BigInt));
    dp[0].limb[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 1; j--) {
            if (s[i] == t[j - 1]) {
                bigAddInPlace(&dp[j], &dp[j - 1]);
            }
        }
    }

  long long ans = (long long)dp[m].limb[0] + (long long)dp[m].limb[1] * BASE;

    free(dp);
    return (int)ans;
}