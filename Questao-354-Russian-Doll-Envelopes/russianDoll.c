#include <stdio.h>
#include <stdlib.h>

int compareEnvelopes(const void* a, const void* b) {
    int* envA = *(int**)a;
    int* envB = *(int**)b;

    if (envA[0] != envB[0]) return envA[0] - envB[0];
    return envB[1] - envA[1];
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    if (envelopesSize == 0) return 0;

    qsort(envelopes, envelopesSize, sizeof(int*), compareEnvelopes);

    int* heights = malloc(envelopesSize * sizeof(int));
    for (int i = 0; i < envelopesSize; i++) {
        heights[i] = envelopes[i][1];
    }

    int* lis = malloc(envelopesSize * sizeof(int));
    int length = 0;

    for (int i = 0; i < envelopesSize; i++) {
        int h = heights[i];
        int left = 0, right = length;

        while (left < right) {
            int mid = (left + right) / 2;
            if (lis[mid] < h) left = mid + 1;
            else right = mid;
        }

        lis[left] = h;
        if (left == length) length++;
    }

    free(heights);
    free(lis);
    return length;
}
