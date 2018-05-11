//
//  node.c
//  data_struct_project
//
//  Created by Edward dawson on 05/05/2018.
//  Copyright © 2018 ziyu zhu. All rights reserved.
//

#include "node.h"

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

void nodeHash(node *x)
{
    int hash1 = 0, hash2 = 0, i;
    x->len1 = (int)strlen(x->prefix1);
    x->len2 = (int)strlen(x->prefix2);
    for(i = 0; i < x->len1; i ++)
        hash1 += x->prefix1[i] * 3;
    for(i = 0; i < x->len2; i += 2)
        hash2 += x->prefix2[i] * 3;
    x->hash1 = hash1;
    x->hash2 = hash2;
}

void nodeCpy(node *x, node *y)
{
    strcpy(x->prefix1, y->prefix1);
    strcpy(x->prefix2, y->prefix2);
    x->lChild = y->lChild;
    x->rChild = y->rChild;
    x->height = y->height;
    x->hash1 = y->hash1;
    x->hash2 = y->hash2;
    x->len1 = y->len1;
    x->len2 = y->len2;
    
    if(y->suffix == NULL)
        x->suffix = NULL;
    else
    {
        x->suffix = (word*) malloc(sizeof(word));
        strcpy(x->suffix->s, y->suffix->s);
        x->suffix->next = NULL;
        word *rearX = x->suffix, *rearY = y->suffix->next;
        while(rearY != NULL)
        {
            rearX->next = (word*) malloc(sizeof(word));
            rearX = rearX->next;
            strcpy(rearX->s, rearY->s);
            rearX->next = NULL;
            rearY = rearY->next;
        }
        
    }
    
}

int  nodeCmp(node *x, node *y)
{
    if(x->len1 > y->len1)
        return 1;
    else if(x->len1 < y->len1)
        return -1;
    else
    {
        if(x->hash1 >  y->hash1)
            return 1;
        else if(x->hash1 < y->hash1)
            return -1;
        else
        {
            if(x->len2 > y->len2)
                return 1;
            else if(x->len2 < y->len2)
                return -1;
            else
            {
                if(x->hash2 > y->hash2)
                    return 1;
                else if(x->hash2 < y->hash2)
                    return -1;
                else
                    return 0;
            }
        }
    }
}

int getH(node *x)
{
    return x != NULL ? x->height : 0;
}

int getSuffixLen(node *x)
{
    if(x == NULL)
        return 0;
    word *rear = x->suffix;
    int ans = 0;
    while(rear != NULL)
    {
        ans++;
        rear = rear->next;
    }
    return ans;
}

word *getNthSuffix(node *x, int n)
{
    if(x == NULL)
        return NULL;
    word *rear = x->suffix;
    while(--n)
        rear = rear->next;
    return rear;
}
