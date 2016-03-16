//
//  main.cpp
//  quicksort
//
//  Created by YANGSHAOQUN on 16/3/16.
//  Copyright © 2016年 YANGSHAOQUN. All rights reserved.
//

#include <iostream>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int head, int tail)
{
    int sentry = tail-1;
    for (int i=head; i<sentry; ) {
        if (arr[i]>arr[sentry]) {
            swap(&arr[i], &arr[sentry-1]);
            swap(arr+sentry-1, arr+sentry);
            --sentry;
        }else {
            ++i;
        }
    }
    return sentry;
}

void quicksort(int arr[], int head, int tail)
{
    if (tail-head < 2) {
        return;
    }
    int sentry = partition(arr, head, tail);
    quicksort(arr, head, sentry);
    quicksort(arr, sentry+1, tail);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[10] = {3, 7, 8, 5, 2, 6, 1, 9, 5, 4};
    quicksort(arr, 0, 10);
    for (int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
