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
    int count = 8;
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
    
    int val[count];
    for (int i=0; i<count; ++i) {
        val[i] = 200;
    }
    
    TrieTree ttree;
    for (int i=0; i<count; ++i) {
        ttree.InsertWord(stations[i], i);
    }
    
    SegmentTree stree(val, count);
    
    const char* qs[] = {
        "putian",
        "jinjiang",
        "fuqing",
        "xiamen",
        "fuzhou",
        "putian"
    };
    int index1;
    int index2;
    ttree.SearchWord(qs[0], index1);
    ttree.SearchWord(qs[1], index2);
    printf("%s->%s: %d\n", qs[0], qs[1], stree.Query(index1, index2));
    stree.Update(index1, index2, -30);
    ttree.SearchWord(qs[2], index1);
    ttree.SearchWord(qs[3], index2);
    printf("%s->%s: %d\n", qs[2], qs[3], stree.Query(index1, index2));
    ttree.SearchWord(qs[4], index1);
    ttree.SearchWord(qs[5], index2);
    printf("%s->%s: %d\n", qs[4], qs[5], stree.Query(index1, index2));
    
    return 0;
}
