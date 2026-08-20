/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
    int* arr1 = (int*)malloc(numsSize * sizeof(int));
    int* arr2 = (int*)malloc(numsSize * sizeof(int));
    int size1 = 0, size2 = 0;

    arr1[size1++] = nums[0];
    arr2[size2++] = nums[1];

    for (int i = 2; i < numsSize; i++) {
        if (arr1[size1 - 1] > arr2[size2 - 1]) {
            arr1[size1++] = nums[i];
        } else {
            arr2[size2++] = nums[i];
        }
    }

    int* result = (int*)malloc(numsSize * sizeof(int));
    int idx = 0;

    for (int i = 0; i < size1; i++) result[idx++] = arr1[i];
    for (int i = 0; i < size2; i++) result[idx++] = arr2[i];

    free(arr1);
    free(arr2);

    *returnSize = numsSize;
    return result;
}