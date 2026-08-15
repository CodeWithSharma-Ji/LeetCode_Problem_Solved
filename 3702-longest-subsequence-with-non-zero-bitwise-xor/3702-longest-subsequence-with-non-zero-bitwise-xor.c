int longestSubsequence(int* nums, int numsSize) {
    int totalXor = 0;
    int hasNonZero = 0;

    for (int i = 0; i < numsSize; i++) {
        totalXor ^= nums[i];
        if (nums[i] != 0) {
            hasNonZero = 1;
        }
    }

    if (totalXor != 0) {
        return numsSize;
    } else if (hasNonZero) {
        return numsSize - 1;
    } else {
        return 0;
    }
}