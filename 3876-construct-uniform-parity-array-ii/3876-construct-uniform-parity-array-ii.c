#include <stdlib.h>
#include <stdbool.h>

static int cmp(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

static bool checkParity(int *nums1, int n, int T) {
    bool hasOdd = false, hasEven = false;
    for (int i = 0; i < n; i++) {
        int px = nums1[i] & 1;
        if (px != T) {
            int needed = px ^ T;           
            
            if (needed == 1) {
                if (!hasOdd) return false;
            } else {
                if (!hasEven) return false;
            }
        }
        if (px) hasOdd = true; else hasEven = true;
    }
    return true;
}

bool uniformArray(int *nums1, int nums1Size) {
    qsort(nums1, nums1Size, sizeof(int), cmp);
    return checkParity(nums1, nums1Size, 0) || checkParity(nums1, nums1Size, 1);
}