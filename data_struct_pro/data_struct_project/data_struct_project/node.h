//
//  node.h
//  data_struct_project
//
//  Created by Edward dawson on 05/05/2018.
//  Copyright © 2018 ziyu zhu. All rights reserved.
//

#ifndef node_h
#define node_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXWORDLEN 70

typedef struct node node;
typedef struct word word;

struct word
{
    char s[MAXWORDLEN];
    struct word *next;
};

struct node
{
    char prefix1[MAXWORDLEN];
    char prefix2[MAXWORDLEN];
    struct word *suffix;
    struct  node *lChild, *rChild;
    int height;
    int len1, len2, hash1, hash2;
};

void nodeCpy(node *, node *);
int nodeCmp(node *, node *);
int getH(node *);
int getSuffixLen(node *);
word *getNthSuffix(node *, int);
void nodeHash(node *);
double rrand();
#endif /* node_h */
