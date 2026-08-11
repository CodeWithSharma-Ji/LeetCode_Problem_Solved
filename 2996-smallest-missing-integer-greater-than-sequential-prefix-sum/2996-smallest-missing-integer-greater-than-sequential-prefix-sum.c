int missingInteger(int* nums, int numsSize) {
    int sum = nums[0];
    int i = 1;

    // Find the longest sequential prefix and calculate its sum
    while (i < numsSize && nums[i] == nums[i - 1] + 1) {
        sum += nums[i];
        i++;
    }

    // Find the smallest missing integer >= sum
    int x = sum;
    int found;
    while (1) {
        found = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == x) {
                found = 1;
                break;
            }
        }
        if (!found) return x;
        x++;
    }
}
