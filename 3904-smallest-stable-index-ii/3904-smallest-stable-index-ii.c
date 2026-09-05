#include <stdlib.h>

int firstStableIndex(int* nums, int numsSize, int k) {
    int *suffixMin = (int *)malloc(numsSize * sizeof(int));
    if (!suffixMin) return -1;

    suffixMin[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        suffixMin[i] = (nums[i] < suffixMin[i + 1]) ? nums[i] : suffixMin[i + 1];
    }

    int prefixMax = nums[0];
    int result = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > prefixMax) prefixMax = nums[i];
        if (prefixMax - suffixMin[i] <= k) {
            result = i;
            break;
        }
    }

    free(suffixMin);
    return result;
}