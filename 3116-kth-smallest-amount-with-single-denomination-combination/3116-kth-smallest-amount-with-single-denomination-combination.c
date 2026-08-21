#include <limits.h>

long long gcdll(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long safeLcm(long long a, long long b) {
    long long g = gcdll(a, b);
    long long part = a / g;
    if (part > LLONG_MAX / b) {
        return LLONG_MAX / 2; 
    }
    return part * b;
}

long long findKthSmallest(int* coins, int coinsSize, int k) {
    int n = coinsSize;
    int total = 1 << n;

    long long* lcmArr = (long long*)malloc(total * sizeof(long long));
    lcmArr[0] = 0;

    for (int mask = 1; mask < total; mask++) {
        int lowBit = mask & (-mask);
        int idx = __builtin_ctz(lowBit);
        int rest = mask ^ lowBit;
        if (rest == 0) {
            lcmArr[mask] = (long long)coins[idx];
        } else {
            lcmArr[mask] = safeLcm(lcmArr[rest], (long long)coins[idx]);
        }
    }

    int minCoin = coins[0];
    for (int i = 1; i < n; i++) {
        if (coins[i] < minCoin) minCoin = coins[i];
    }

    long long lo = 1;
    long long hi = (long long)minCoin * (long long)k;

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        long long count = 0;

        for (int mask = 1; mask < total; mask++) {
            long long l = lcmArr[mask];
            long long term = mid / l;
            int bits = __builtin_popcount(mask);
            if (bits % 2 == 1) {
                count += term;
            } else {
                count -= term;
            }
        }

        if (count >= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    free(lcmArr);
    return lo;
}