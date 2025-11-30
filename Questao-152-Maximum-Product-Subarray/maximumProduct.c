int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int maxSoFar = nums[0];
    int minSoFar = nums[0];
    int result = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int x = nums[i];

        if (x < 0) {
            int tmp = maxSoFar;
            maxSoFar = minSoFar;
            minSoFar = tmp;
        }

        if (x > maxSoFar * x) {
            maxSoFar = x;
        } else {
            maxSoFar = maxSoFar * x;
        }
        if (x < minSoFar * x) {
            minSoFar = x;
        } else {
            minSoFar = minSoFar * x;
        }

        if (maxSoFar > result) {
            result = maxSoFar;
        }
    }

    return result;
}