#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* array = calloc(nums1Size + nums2Size, sizeof(int));
    int i = 0, j = 0, k = 0;
    double res = 0;
    while (i < nums1Size && j < nums2Size){
        if (nums1[i] < nums2[j]){
            array[k] = nums1[i];
            i++;
        }else{
            array[k] = nums2[j];
            j++;
        }
        k++;
    }
    while (i < nums1Size){
        array[k] = nums1[i];
        i++;
        k++;
    }
    while (j < nums2Size){
        array[k] = nums2[j];
        j++;
        k++;
    }
    if ((nums1Size + nums2Size) % 2 == 0){
        res = (array[(nums1Size + nums2Size) / 2] + array[(nums1Size + nums2Size) / 2 - 1]) / 2.0;
    }else{
        res = array[(nums1Size + nums2Size) / 2];
    }
    free(array);
    return res;   
}
