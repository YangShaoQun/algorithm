//
//  main.cpp
//  quicksort
//
//  Created by YANGSHAOQUN on 16/3/16.
//  Copyright © 2016年 YANGSHAOQUN. All rights reserved.
//

#include <iostream>

template <typename T>
void swap(T* a, T* b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template <typename T>
int partition(T arr[], int head, int tail)
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

template <typename T>
void quicksort(T arr[], int head, int tail)
{
    if (tail-head < 2) {
        return;
    }
    int sentry = partition(arr, head, tail);
    quicksort(arr, head, sentry);
    quicksort(arr, sentry+1, tail);
}

void test1()
{
    int arr[10] = {3, 7, 8, 5, 2, 6, 1, 9, 5, 4};
    quicksort(arr, 0, 10);
    for (int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void test2()
{
    float arr[10] = {3, 7, 8, 5, 2.3, 6, 1, 9, 5, 4};
    quicksort(arr, 0, 10);
    for (int i=0; i<10; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void test3()
{
    char arr[10] = {'c', 'g', 'h', 'e', 'b', 'f', 'a', 'i', 'e', 'd'};
    quicksort(arr, 0, 10);
    for (int i=0; i<10; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void test4()
{
    std::string arr[10] = {"cabin", "git", "hair", "exam", "ball", "fvck", "act", "island", "execute", "dead"};
    quicksort(arr, 0, 10);
    for (int i=0; i<10; i++) {
        printf("%s ", arr[i].c_str());
    }
    printf("\n");
}

int main(int argc, const char * argv[])
{
    test1();
    test2();
    test3();
    test4();
    
    return 0;
}
