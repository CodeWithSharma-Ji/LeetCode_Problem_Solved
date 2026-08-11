#include <stdio.h>
#include <stdlib.h>

int stoneGameVII(int* stones, int stonesSize) {
    int prefix[stonesSize + 1];
    prefix[0] = 0;
    for (int i = 0; i < stonesSize; i++)
        prefix[i + 1] = prefix[i] + stones[i];

    int dp[stonesSize][stonesSize];
    for (int i = 0; i < stonesSize; i++)
        for (int j = 0; j < stonesSize; j++)
            dp[i][j] = 0;

    for (int len = 2; len <= stonesSize; len++) {
        for (int i = 0; i + len <= stonesSize; i++) {
            int j = i + len - 1;
            int removeLeft = prefix[j + 1] - prefix[i + 1] - dp[i + 1][j];
            int removeRight = prefix[j] - prefix[i] - dp[i][j - 1];
            dp[i][j] = (removeLeft > removeRight) ? removeLeft : removeRight;
        }
    }

    return dp[0][stonesSize - 1];
}
