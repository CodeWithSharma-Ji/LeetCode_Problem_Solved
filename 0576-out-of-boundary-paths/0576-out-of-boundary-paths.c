int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    const int MOD = 1000000007;
    
    if (maxMove == 0) return 0;
    
    // dp[r][c] = number of paths ending out of bounds using current move count
    long long dp[50][50];
    memset(dp, 0, sizeof(dp));
    
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int move = 1; move <= maxMove; move++) {
        long long newDp[50][50];
        memset(newDp, 0, sizeof(newDp));
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                long long total = 0;
                for (int d = 0; d < 4; d++) {
                    int nr = r + directions[d][0];
                    int nc = c + directions[d][1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                        total += 1;
                    } else {
                        total += dp[nr][nc];
                    }
                }
                newDp[r][c] = total % MOD;
            }
        }
        
        memcpy(dp, newDp, sizeof(dp));
    }
    
    return (int)dp[startRow][startColumn];
}