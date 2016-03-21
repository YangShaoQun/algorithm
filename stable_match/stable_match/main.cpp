//
//  main.cpp
//  stable_match
//
//  Created by YANGSHAOQUN on 16/3/21.
//  Copyright © 2016年 YANGSHAOQUN. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#define PARTNER_COUNT 10
#define NO_PARTNER -1

typedef struct _Partner {
    int ID;
    int next;
    int current;
    int prefer[PARTNER_COUNT];
    
    _Partner() {
        next = 0;
        current = NO_PARTNER;
    }
    
    void Initialize(int id, int* prefer_list) {
        ID = id;
        for(int i=0; i<PARTNER_COUNT; ++i) {
            prefer[i] = prefer_list[i];
        }
    }
}Partner;

const char* boy_name[PARTNER_COUNT] = {
    "jack",
    "daniel",
    "mike",
    "david",
    "james",
    "peter",
    "polo",
    "mason",
    "kobe",
    "tracy"
};

const char* girl_name[PARTNER_COUNT] = {
    "kate",
    "janifer",
    "avil",
    "nancy",
    "gina",
    "eva",
    "angel",
    "anqula",
    "madonala",
    "sansa"
};

bool is_better_match(int* prefer, int origin, int current)
{
    for (int i=0; i<PARTNER_COUNT; ++i) {
        if (origin == prefer[i]) {
            return false;
        }
        if (current == prefer[i]) {
            return true;
        }
    }
    printf("something wrong!!!\n");
    return false;
}

void stable_match(Partner* boys, Partner* girls)
{
    int no_match = PARTNER_COUNT;
    int index = 0;
    while (no_match > 0) {
        Partner* boy = &boys[index];
        int add_idx = 1;
        if (boy->current == NO_PARTNER) {
            Partner* girl = &girls[boy->prefer[boy->next]];
            if (girl->current == NO_PARTNER) {
                girl->current = boy->ID;
                boy->current = girl->ID;
                ++ boy->next;
                -- no_match;
            }else if (is_better_match(girl->prefer, girl->current, boy->ID)) {
                boys[girl->current].current = NO_PARTNER;
                girl->current = boy->ID;
                boy->current = girl->ID;
                ++ boy->next;
            }else {
                ++ boy->next;
                add_idx = 0;
            }
        }
        index = (index + add_idx) % PARTNER_COUNT;
    }
}

void print_match(Partner* boys)
{
    for (int i=0; i<PARTNER_COUNT; ++i) {
        Partner* boy = &boys[i];
        printf("%s <==> %s\n", boy_name[boy->ID], girl_name[boy->current]);
    }
}

void generate_random_list(int* list)
{
    int num[PARTNER_COUNT] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    int count = PARTNER_COUNT;
    while (count > 0) {
        int idx = rand()%count;
        list[PARTNER_COUNT-count] = num[idx];
        if (idx != count-1) {
            num[idx] = num[count-1];
        }
        -- count;
    }
}

void generate_data(Partner* boys, Partner* girls)
{
    for (int i=0; i<PARTNER_COUNT; ++i) {
        int list[PARTNER_COUNT];
        generate_random_list(list);
        boys[i].Initialize(i, list);
        generate_random_list(list);
        girls[i].Initialize(i, list);
    }
}

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
    
    Partner boys[PARTNER_COUNT];
    Partner girls[PARTNER_COUNT];
    generate_data(boys, girls);
    stable_match(boys, girls);
    print_match(boys);
    
    return 0;
}





