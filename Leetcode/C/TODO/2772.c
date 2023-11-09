#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checkArray(int* nums, int numsSize, int k){
    int* array = calloc(k, sizeof(int));
    bool res = false;
    //Choose any subarray of size k from the array and decease all its elements by 1. Return true if you can make all the array elements equal to 0, or false otherwise. A subarray is a contiguous part of an array.
    for (int i = 0; i < numsSize; i++){
        array[nums[i] % k]++;
    }
    for (int i = 0; i < k; i++){
        if (array[i] % 2 != 0){
            res = true;
            break;
        }
    }
    free(array);
    return res;   
}