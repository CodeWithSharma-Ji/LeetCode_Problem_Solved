int stoneGameVIII(int* stones, int stonesSize) {
    for (int i = 1; i < stonesSize; i++) {
        stones[i] += stones[i - 1];
    }

    int best = stones[stonesSize - 1];

    for (int i = stonesSize - 2; i >= 1; i--) {
        int cur = stones[i] - best;
        if (cur > best) best = cur;
    }

    return best;
}