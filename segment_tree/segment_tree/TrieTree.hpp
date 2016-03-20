//
//  TrieTree.hpp
//  segment_tree
//
//  Created by YANGSHAOQUN on 16/3/20.
//  Copyright © 2016年 YANGSHAOQUN. All rights reserved.
//

#ifndef TrieTree_hpp
#define TrieTree_hpp

#include <iostream>

#define CHARACTER_NUMBER 26
#define NONSENSE_VALUE 0x80000000

class TrieTree {
    
    typedef struct _TreeNode {
        int value;
        _TreeNode* next[CHARACTER_NUMBER];
        
        _TreeNode() {
            value = NONSENSE_VALUE;
            for(int i=0; i<CHARACTER_NUMBER; i++) {
                next[i] = NULL;
            }
        }
        
        ~_TreeNode() {
            for(int i=0; i<CHARACTER_NUMBER; i++) {
                if(next[i] != NULL) {
                    delete next[i];
                }
            }
        }
    }TreeNode;
    
    TreeNode* _trie_tree[CHARACTER_NUMBER];
    
public:
    TrieTree();
    ~TrieTree();
    
    void InsertWord(const char* word, int value);
    bool SearchWord(const char*word, int &value);
};

#endif /* TrieTree_hpp */
