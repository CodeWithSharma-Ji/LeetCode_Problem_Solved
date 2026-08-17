int stoneGameV(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;
    long long prefix[501];
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }

    static int dp[501][501];
    for (int i = 0; i < n; i++) dp[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            int best = 0;
            for (int k = i; k < j; k++) {
                long long left  = prefix[k + 1] - prefix[i];
                long long right = prefix[j + 1] - prefix[k + 1];
                int cand;
                if (left < right) {
                    cand = (int)left + dp[i][k];
                } else if (left > right) {
                    cand = (int)right + dp[k + 1][j];
                } else {
                    int m = dp[i][k] > dp[k + 1][j] ? dp[i][k] : dp[k + 1][j];
                    cand = (int)left + m;
                }
                if (cand > best) best = cand;
            }
            dp[i][j] = best;
        }
    }

    return dp[0][n - 1];
}