#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize == 0) return 0;
    int indexMax = pricesSize-1;
    int bestDiff = 0;
    for(int i = pricesSize-2; i>=0; i--){

        if (prices[i]>prices[indexMax]) indexMax = i;
        int currDiff = prices[indexMax] - prices[i];
        if (currDiff > bestDiff) bestDiff = currDiff;
    }
    return bestDiff;
}