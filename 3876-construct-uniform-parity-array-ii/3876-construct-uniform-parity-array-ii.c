#include <stdbool.h>

bool uniformArray(int* nums1, int nums1Size) {
    int min = nums1[0];

    for (int i = 1; i < nums1Size; i++) {
        if (nums1[i] < min) {
            min = nums1[i];
        }
    }

    if (min % 2 == 1) {
        return true;
    }

    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] % 2 == 1) {
            return false;
        }
    }

    return true;
}