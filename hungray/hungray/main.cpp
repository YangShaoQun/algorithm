//
//  main.cpp
//  hungray
//
//  Created by YANGSHAOQUN on 16/3/22.
//  Copyright © 2016年 YANGSHAOQUN. All rights reserved.
//

#include <iostream>
#define PARTNER_COUNT 4

const char* boy_name[PARTNER_COUNT] = {
    "jack",
    "mike",
    "james",
    "peter",
};

const char* girl_name[PARTNER_COUNT] = {
    "nancy",
    "eva",
    "sansa",
    "kate"
};

const bool flirtation[PARTNER_COUNT][PARTNER_COUNT] = {
    true, true, false, false,
    false, true, true, false,
    true, true, false, false,
    false, false, true, false
};

int girl_matched[PARTNER_COUNT];
bool visited[PARTNER_COUNT];

bool find_match(int v)
{
    for (int i=0; i<PARTNER_COUNT; ++i) {
        if (flirtation[v][i] && !visited[i]) {
            visited[i] = true;
            if (girl_matched[i] == -1 || find_match(girl_matched[i])) {
                girl_matched[i] = v;
                return true;
            }
        }
    }
    return false;
}

int hungray()
{
    memset(girl_matched, -1, sizeof(girl_matched));
    int match_number = 0;
    for (int i=0; i<PARTNER_COUNT; ++i) {
        memset(visited, false, sizeof(visited));
        if (find_match(i)) {
            ++ match_number;
        }
    }
    return match_number;
}

void print_match()
{
    printf("there are %d couples:\n", hungray());
    for (int i=0; i<PARTNER_COUNT; ++i) {
        if (girl_matched[i] != -1) {
            printf("%s <==> %s\n", boy_name[girl_matched[i]], girl_name[i]);
        }
    }
}

int main(int argc, const char * argv[])
{
    print_match();
    
    return 0;
}
