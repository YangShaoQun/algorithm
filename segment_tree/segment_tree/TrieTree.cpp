//
//  TrieTree.cpp
//  segment_tree
//
//  Created by YANGSHAOQUN on 16/3/20.
//  Copyright © 2016年 YANGSHAOQUN. All rights reserved.
//

#include "TrieTree.hpp"

TrieTree::TrieTree()
{
    for (int i=0; i<CHARACTER_NUMBER; ++i) {
        _trie_tree[i] = NULL;
    }
}

TrieTree::~TrieTree()
{
    for (int i=0; i<CHARACTER_NUMBER; ++i) {
        if (_trie_tree[i] != NULL) {
            delete _trie_tree[i];
        }
    }
}

void TrieTree::InsertWord(const char *word, int value)
{
    int length = (int)strlen(word);
    TreeNode** root = _trie_tree;
    for (int i=0; ; ++i) {
        int idx = word[i] - 'a';
        if (root[idx] == NULL) {
            TreeNode * node = new TreeNode();
            root[idx] = node;
        }else {
            if (i == length-1 && root[idx]->value != NONSENSE_VALUE) {
                printf("WARN: This word has exist, will replace its value");
            }
        }
        if (i == length-1) {
            root[idx]->value = value;
            break;
        }
        root = root[idx]->next;
    }
}

bool TrieTree::SearchWord(const char *word, int &value)
{
    value = NONSENSE_VALUE;
    int length = (int)strlen(word);
    TreeNode** root = _trie_tree;
    for (int i=0; ; ++i) {
        int idx = word[i] - 'a';
        if (root[idx] == NULL) {
            break;
        }
        if (i == length-1) {
            if (root[idx]->value == NONSENSE_VALUE) {
                break;
            }else {
                value = root[idx]->value;
                return true;
            }
        }
        root = root[idx]->next;
    }
    return false;
}



