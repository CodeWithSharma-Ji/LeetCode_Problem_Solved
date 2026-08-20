/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct HashNode {
    int key;
    int value;
    struct HashNode* next;
};

#define TABLE_SIZE 20011

int hashFunc(int key) {
    unsigned int ukey = (unsigned int)key;
    return ukey % TABLE_SIZE;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct HashNode* table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) table[i] = NULL;

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int idx = hashFunc(complement);

        struct HashNode* node = table[idx];
        while (node != NULL) {
            if (node->key == complement) {
                result[0] = node->value;
                result[1] = i;
                return result;
            }
            node = node->next;
        }

        // insert nums[i] into table
        int insertIdx = hashFunc(nums[i]);
        struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
        newNode->key = nums[i];
        newNode->value = i;
        newNode->next = table[insertIdx];
        table[insertIdx] = newNode;
    }

    *returnSize = 0;
    return NULL;
}