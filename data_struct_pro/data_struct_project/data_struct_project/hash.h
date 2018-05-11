//
//  hash.h
//  data_struct_project
//
//  Created by Edward dawson on 05/05/2018.
//  Copyright © 2018 ziyu zhu. All rights reserved.
//

#ifndef hash_h
#define hash_h

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 6000977
typedef struct node node;
typedef struct suffix suffix;
typedef long long int ll;

struct suffix
{
    char s[100];
    struct suffix *next;
};

struct node
{
    bool empty;
    char s1[100];
    char s2[100];
    int len;
    struct suffix head;
};

ll hash(char *, char *);
void push(char *, char *, char *);
ll search(char *, char *);
void init();
suffix* getNthSuffix(suffix *, int);
double rrand();
#endif /* hash_h */
