#include <string.h>

int min(int a, int b, int c) {
    int min_val = a;
    if (b < min_val) min_val = b;
    if (c < min_val) min_val = c;
    return min_val;
}

int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    
    // Arrays fixos baseados no constraint máximo (500)
    int prev[501], curr[501];
    
    for (int j = 0; j <= n; j++) {
        prev[j] = j;
    }
    
    for (int i = 1; i <= m; i++) {
        curr[0] = i;
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                curr[j] = prev[j - 1];
            } else {
                curr[j] = min(prev[j], curr[j - 1], prev[j - 1]) + 1;
            }
        }
        for (int j = 0; j <= n; j++) {
            prev[j] = curr[j];
        }
    }
    
    return prev[n];
}