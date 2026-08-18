int largestInteger(int* nums, int numsSize, int k) {
    int best = -1;

    for (int v = 0; v <= 50; v++) {
        int windowCount = 0;

        for (int start = 0; start + k <= numsSize; start++) {
            int found = 0;
            for (int i = start; i < start + k; i++) {
                if (nums[i] == v) {
                    found = 1;
                    break;
                }
            }
            if (found) windowCount++;
        }

        if (windowCount == 1 && v > best) {
            best = v;
        }
    }

    return best;
}