//
//  main.cpp
//  kmp
//
//  Created by YANGSHAOQUN on 16/3/18.
//  Copyright © 2016年 YANGSHAOQUN. All rights reserved.
//

#include <iostream>
#include <vector>

int max_partial_match(const char* str, int length)
{
    char pre[length-1];
    char back[length-1];
    int max_match = 0;
    for (int i=0, j=length-1; i<length-1; i++, j--) {
        pre[i] = str[i];
        back[j] = str[j];
        bool match = true;
        for (int k=0; k<=i; k++) {
            if (pre[k]!=back[length-1-i+k]) {
                match = false;
                break;
            }
        }
        if (match && max_match<i+1) {
            max_match = i+1;
        }
    }
    return max_match;
}

void partial_match_table(const char* str, int* pmt, int length)
{
    pmt[0] = 0;
    for (int i=1; i<length; i++) {
        pmt[i] = max_partial_match(str, i+1);
    }
}

void kmp_search(const char* text, const char* search, std::vector<std::pair<int, int>>& match_list)
{
    int text_length = (int)strlen(text);
    int search_length = (int)strlen(search);
    int pmt[search_length];
    
    partial_match_table(search, pmt, search_length);
    
    int text_idx = 0, search_idx = 0;
    while (text_idx<text_length) {
        if (search_idx == search_length) {
            std::pair<int, int> match;
            match.first = text_idx - search_length;
            match.second = text_idx - 1;
            match_list.push_back(match);
            
            ++ text_idx;
            search_idx = 0;
        }
        if (text[text_idx] == search[search_idx]) {
            ++ text_idx;
            ++ search_idx;
        }else {
            if (search_idx == 0) {
                ++ text_idx;
            }else {
                search_idx = pmt[search_idx-1];
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    const char* str = std::string("ABCDABD").c_str();
    const char* text = std::string("BBC ABCDAB ABCDABCDABDE ABCDABDDABCDABCDABDCAB").c_str();
    
    std::vector<std::pair<int, int>> match_list;
    kmp_search(text, str, match_list);
    
    for (int i=0; i<match_list.size(); i++) {
        printf("(%d, %d)\n", match_list[i].first, match_list[i].second);
    }
    
    return 0;
}
