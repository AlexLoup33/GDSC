#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
int firstBadVersion(int n) {
    int answer = -1;
    int i=1, j=n; 
    while(i<=j){
        int mid=i+(j-i)/2;
        if(isBadVersion(mid)){
            answer=mid;
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
    return answer;
}