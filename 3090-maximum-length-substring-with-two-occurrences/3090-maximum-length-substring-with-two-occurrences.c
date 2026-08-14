int maximumLengthSubstring(char* s) {
    int count[26] = {0};
    int left = 0, maxLen = 0;
    int n = strlen(s);

    for (int right = 0; right < n; right++) {
        int c = s[right] - 'a';
        count[c]++;

        // Shrink window from the left while this character exceeds 2 occurrences
        while (count[c] > 2) {
            count[s[left] - 'a']--;
            left++;
        }

        int windowLen = right - left + 1;
        if (windowLen > maxLen) {
            maxLen = windowLen;
        }
    }

    return maxLen;
}