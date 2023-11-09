#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* res = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i<numsSize-1; i++){
        for (int j = i+1; j<numsSize; j++){
            if (nums[i] + nums[j] == target){
                res[0] = i;
                res[1] = j;
                return res;
            }   
        }
    }
    return res;
}

int main(int argc, char** argv){
    if (argc < 4){
        printf("Usage : ./1 <Array of int> <Size of the array> <Target Number> <pointer of returnSize>\n");
        return EXIT_FAILURE;
    }
    int* returnSize = malloc(sizeof(int));
    int* res = twoSum((int*)argv[1], atoi(argv[2]), atoi(argv[3]), returnSize);
    printf("[%d, %d]\n", res[0], res[1]);
    free(returnSize);
    free(res);
    return EXIT_SUCCESS;
}