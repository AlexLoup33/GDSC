#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int search(int* nums, int numSize, int target){
    int left = 0;
    int right = numSize - 1;
    while (left <= right){
        int mid = (left + right) / 2;
        if (nums[mid] == target){
            return mid;
        }
        if (nums[mid] < nums[right]){
            if (nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }else{
            if (nums[left] <= target && target < nums[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
    }
    return -1;
}