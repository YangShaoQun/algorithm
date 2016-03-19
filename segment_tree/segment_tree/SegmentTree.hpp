//
//  SegmentTree.hpp
//  segment_tree
//
//  Created by YANGSHAOQUN on 16/3/19.
//  Copyright © 2016年 YANGSHAOQUN. All rights reserved.
//

#ifndef SegmentTree_hpp
#define SegmentTree_hpp

#include <iostream>

class SegmentTree {
    
    typedef struct _TreeNode {
        int value;
    }TreeNode;
    
    TreeNode* _segment_tree;
    
    int _count;
    
    void CreateTree(int val[], int count);
    void InsertTreeNode(int start, int end, int val[], int root);
    void UpdateTree(int iter_start, int iter_end, int add_val, int root, int q_start, int q_end);
    int QueryTree(int iter_start, int iter_end, int root, int q_start, int q_end);
    
public:
    SegmentTree(int val[], int count);
    ~SegmentTree();
    
    void Update(int start, int end, int add_val);
    int Query(int start, int end);
};

#endif /* SegmentTree_hpp */
