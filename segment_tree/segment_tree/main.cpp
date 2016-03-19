//
//  main.cpp
//  segment_tree
//
//  Created by YANGSHAOQUN on 16/3/19.
//  Copyright © 2016年 YANGSHAOQUN. All rights reserved.
//

#include <iostream>
#include "SegmentTree.hpp"

int main(int argc, const char * argv[])
{
    int count = 7;
    int val[7] = {20, 20, 20, 20, 20, 20, 20};
    
    SegmentTree stree(val, count);
    printf("%d, %d, %d, %d\n", stree.Query(2, 4), stree.Query(2, 5), stree.Query(5, 6), stree.Query(0, 2));
    stree.Update(2, 5, -1);
    printf("%d, %d, %d, %d\n", stree.Query(2, 4), stree.Query(2, 5), stree.Query(5, 6), stree.Query(0, 2));
    
    return 0;
}
