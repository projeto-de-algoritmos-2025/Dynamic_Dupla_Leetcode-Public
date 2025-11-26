int largestRectangleArea(int* heights, int size) {
    int* stack = (int*)malloc(size * sizeof(int));
    int top = -1;
    int maxArea = 0;
    int i = 0;
    
    while (i < size) {
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            stack[++top] = i++;
        } else {
            int h = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = h * width;
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }
    
    while (top != -1) {
        int h = heights[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        int area = h * width;
        if (area > maxArea) {
            maxArea = area;
        }
    }
    
    free(stack);
    return maxArea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return 0;
    }
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int maxArea = 0;
    
    int* heights = (int*)calloc(cols, sizeof(int));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        
        int area = largestRectangleArea(heights, cols);
        if (area > maxArea) {
            maxArea = area;
        }
    }
    
    free(heights);
    return maxArea;
}