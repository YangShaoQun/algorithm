//
//  main.cpp
//  01backpack
//
//  Created by YANGSHAOQUN on 16/3/17.
//  Copyright © 2016年 YANGSHAOQUN. All rights reserved.
//

#include <iostream>

int max(int a, int b)
{
    return a > b ? a : b;
}

int maxBackpack_DP(int v[], int p[], int count, int bpv)
{
    int maxPrice[count+1][bpv+1];
    for (int i=0; i<=count; i++) {
        for (int j=0; j<=bpv; j++) {
            maxPrice[i][j] = i==0 ? 0 : maxPrice[i-1][j];
            if (i>0 && j>v[i-1]) {
                maxPrice[i][j] = max(maxPrice[i][j], maxPrice[i-1][j-v[i-1]]+p[i-1]);
            }
        }
    }
    return maxPrice[count][bpv];
}

float greedyPrice1(int v, int p)
{
    return (float)p/v;
}

float greedyPrice2(int v, int p)
{
    return p;
}

int maxBackpack_Greedy(int v[], int p[], int count, int bpv, float (*func)(int, int))
{
    int visit[10] = {0};
    int leftVolume = bpv;
    bool done = false;
    int totalPrice = 0;
    while (!done) {
        float maxPrice = 0;
        done = true;
        int idx = 0;
        for (int i=0; i<10; i++) {
            if (visit[i] == 0 && leftVolume>=v[i] && maxPrice<(*func)(v[i], p[i])) {
                idx = i;
                maxPrice = p[i];
            }
        }
        done = (maxPrice==0);
        leftVolume -= v[idx];
        visit[idx] = 1;
        totalPrice += maxPrice;
    }
    return totalPrice;
}

int main(int argc, const char * argv[])
{
    int volume[10] = {10, 5, 7, 10, 30, 22, 14, 8, 20, 15};
    int price[10] = {20, 8, 20, 10, 15, 30, 24, 20, 25, 20};
    int backpackVolume = 70;
    
    printf("max=%d/%d/%d\n", maxBackpack_DP(volume, price, 10, backpackVolume)
           , maxBackpack_Greedy(volume, price, 10, backpackVolume, greedyPrice1)
           , maxBackpack_Greedy(volume, price, 10, backpackVolume, greedyPrice2));
    
    return 0;
}
