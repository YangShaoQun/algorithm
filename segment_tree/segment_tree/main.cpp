//
//  main.cpp
//  segment_tree
//
//  Created by YANGSHAOQUN on 16/3/19.
//  Copyright © 2016年 YANGSHAOQUN. All rights reserved.
//

#include <iostream>
#include "SegmentTree.hpp"
#include "TrieTree.hpp"

int main(int argc, const char * argv[])
{
    int count = 7;
    int val[count];
    for (int i=0; i<count; ++i) {
        val[i] = 20;
    }
    SegmentTree stree(val, count);
    printf("%d, %d, %d, %d\n", stree.Query(2, 4), stree.Query(2, 5), stree.Query(5, 6), stree.Query(0, 2));
    stree.Update(2, 5, -1);
    printf("%d, %d, %d, %d\n", stree.Query(2, 4), stree.Query(2, 5), stree.Query(5, 6), stree.Query(0, 2));
    
    int station_count = 8;
    const char* stations[] = {
        "fuzhou",
        "fuzhounan",
        "fuqing",
        "putian",
        "quanzhou",
        "jinjiang",
        "xiamenbei",
        "xiamen"
    };
    TrieTree ttree;
    for (int i=0; i<station_count; ++i) {
        ttree.InsertWord(stations[i], i);
    }
    const char* qs[4] = {
        "pution",
        "jinjiang",
        "fuqin",
        "xiamen"
    };
    for (int i=0; i<4; ++i) {
        int value;
        bool s = ttree.SearchWord(qs[i], value);
        printf("%s %d\n", s ? "true" : "false", value);
    }
    
    return 0;
}
