#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void tryToFill(int** image, int nbRows, int* nbColumns, int row, int col, int** returnImage, int color, int colorToFill){
    if (row < 0 || col < 0) return ;
    else if (row >= nbRows || col >= nbColumns[row]) return ;
    // => (row, col) is inside image 
    if (returnImage[row][col] != -1) return ;
    else if (image[row][col] != colorToFill) return ;
    // => Fill and flood the target pixel
    returnImage[row][col] = color;
    tryToFill(image, nbRows, nbColumns, row+1, col, returnImage, color, colorToFill);
    tryToFill(image, nbRows, nbColumns, row-1, col, returnImage, color, colorToFill);
    tryToFill(image, nbRows, nbColumns, row, col+1, returnImage, color, colorToFill);
    tryToFill(image, nbRows, nbColumns, row, col-1, returnImage, color, colorToFill);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    int** returnArray = malloc(imageSize*sizeof(int*));
    for (int i = 0; i < imageSize; i++){
        returnArray[i] = malloc(imageColSize[i] * sizeof(int));
        returnColumnSizes[0][i] = imageColSize[i];
        for (int j = 0; j < imageColSize[i]; j++) {
            returnArray[i][j] = -1;
        }
    }
    int colorToFill = image[sr][sc];
    tryToFill(image, imageSize, imageColSize, sr, sc, returnArray, color, colorToFill);
    for (int i = 0; i < imageSize; i++){
        for (int j = 0; j < imageColSize[i]; j++) {
            if (returnArray[i][j] == -1) returnArray[i][j] = image[i][j];
        }
    }
    return returnArray;
}