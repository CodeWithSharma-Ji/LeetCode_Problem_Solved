bool stoneGameIX(int* stones, int stonesSize) {
    int cnt[3] = {0, 0, 0};
    for (int i = 0; i < stonesSize; i++) {
        cnt[stones[i] % 3]++;
    }

    if (cnt[0] % 2 == 0) {
        return cnt[1] > 0 && cnt[2] > 0;
    } else {
        int diff = cnt[1] - cnt[2];
        return diff > 2 || diff < -2;
    }
}