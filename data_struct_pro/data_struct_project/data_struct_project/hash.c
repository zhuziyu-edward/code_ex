//
//  hash.c
//  data_struct_project
//
//  Created by Edward dawson on 05/05/2018.
//  Copyright © 2018 ziyu zhu. All rights reserved.
//

#include "hash.h"


double seed = 997;

double rrand()
{
    double lambda = 3125.0;
    double m = 34359738337.0;
    double r;
    seed = fmod(lambda*seed, m); //要包含头文件#include <math.h>
    r = seed / m;
    return r;
}

void init()
{
    ll i;
    for(i = 0; i < MAXSIZE; i++)
    {
        hashTable[i].empty = true;
        hashTable[i].len   = 0;
    }
}

ll hash(char *s1, char *s2)
{
    ll hash = 0;
    int i = 0;
    for(; s1[i] != '\0'; i++)
        hash = 31 * hash + s1[i];
    for(i = 0; s2[i] != '\0'; i++)
        hash = 31 * hash + s2[i];
    return (hash & 0x7fffffff) % MAXSIZE;
}

void push(char *s1, char *s2, char *s3)
{
    ll hashValue = hash(s1, s2);
    while((strcmp(s1, hashTable[hashValue].s1) != 0 || strcmp(s2, hashTable[hashValue].s2) != 0)  && hashTable[hashValue].empty == false)
        hashValue = (hashValue + 1) % MAXSIZE;
    node *p = hashTable + hashValue;
    if(p->empty)
    {
        p->empty = false;
        p->len = 1;
        strcpy(p->s1, s1);
        strcpy(p->s2, s2);
        strcpy(p->head.s, s3);
        p->head.next = NULL;
    }
    else
    {
        p->len = p->len + 1;
        suffix *t = &p->head;
        while(t->next != NULL)
            t = t->next;
        t->next = (suffix *) malloc (sizeof(suffix));
        t = t->next;
        t->next = NULL;
        strcpy(t->s, s3);
    }
}

ll search(char *s1, char *s2)
{
    ll hashValue = hash(s1, s2);
    while((strcmp(s1, hashTable[hashValue].s1) != 0 || strcmp(s2, hashTable[hashValue].s2) != 0))
        hashValue = (hashValue + 1) % MAXSIZE;
    return hashValue;
}

suffix* getNthSuffix(suffix *x, int n)
{
    while(--n)
        x = x->next;
    return x;
}
