//
//  SegmentTree.cpp
//  segment_tree
//
//  Created by YANGSHAOQUN on 16/3/19.
//  Copyright © 2016年 YANGSHAOQUN. All rights reserved.
//

#include "SegmentTree.hpp"
#define INFINITE 0xFFFF

SegmentTree::SegmentTree(int val[], int count)
{
    _count = count;
    _segment_tree = new TreeNode[3*count];
    CreateTree(val, count);
}

SegmentTree::~SegmentTree()
{
    delete _segment_tree;
}

void SegmentTree::CreateTree(int val[], int count)
{
    InsertTreeNode(0, count, val, 0);
}

void SegmentTree::InsertTreeNode(int start, int end, int val[], int root)
{
    if (start == end) {
        _segment_tree[root].value = val[start];
        return;
    }
    int mid = (start + end) / 2;
    InsertTreeNode(start, mid, val, 2*root+1);
    InsertTreeNode(mid+1, end, val, 2*root+2);
    _segment_tree[root].value = std::min(_segment_tree[2*root+1].value, _segment_tree[2*root+2].value);
}

void SegmentTree::UpdateTree(int iter_start, int iter_end, int add_val, int root, int q_start, int q_end)
{
    if (q_start > iter_end || q_end < iter_start) {
        return;
    }
    if (iter_start == iter_end) {
        if (iter_start >= q_start && iter_start < q_end) {
            _segment_tree[root].value += add_val;
        }
        return;
    }
    int mid = (iter_start + iter_end) / 2;
    UpdateTree(iter_start, mid, add_val, 2*root+1, q_start, q_end);
    UpdateTree(mid+1, iter_end, add_val, 2*root+2, q_start, q_end);
    _segment_tree[root].value = std::min(_segment_tree[2*root+1].value, _segment_tree[2*root+2].value);
}

int SegmentTree::QueryTree(int iter_start, int iter_end, int root, int q_start, int q_end)
{
    if (q_start > iter_end || q_end < iter_start) {
        return INFINITE;
    }
    if (iter_start >= q_start && iter_end <= q_end) {
        return _segment_tree[root].value;
    }
    int mid = (iter_start + iter_end) / 2;
    return std::min(QueryTree(iter_start, mid, 2*root+1, q_start, q_end), QueryTree(mid+1, iter_end, 2*root+2, q_start, q_end));
}

void SegmentTree::Update(int start, int end, int add_val)
{
    UpdateTree(0, _count, add_val, 0, start, end);
}

int SegmentTree::Query(int start, int end)
{
    return QueryTree(0, _count, 0, start, end);
}