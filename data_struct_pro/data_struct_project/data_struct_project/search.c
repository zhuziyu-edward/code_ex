//
//  search.c
//  data_struct_project
//
//  Created by Edward dawson on 30/04/2018.
//  Copyright © 2018 ziyu zhu. All rights reserved.
//

#include "search.h"
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
    return  a > b ? a : b;
}

void makeEmpty(node *t)
{
    if(t == NULL)
        return;
    makeEmpty(t->lChild);
    makeEmpty(t->rChild);
    free(t);
}
    
node* insert(node *x, node *t)
{
    if(t == NULL)
    {
        t = (node*) malloc (sizeof(node));
        nodeCpy(t, x);
    }
    else if(nodeCmp(t, x) > 0)
    {
        t->lChild = insert(x, t->lChild);
        if(getH(t->lChild) - getH(t->rChild) == 2)
        {
            if( nodeCmp(x, t->lChild) < 0)
                t = singleRightRotate(t);
            else
                t = doubleRightRotate(t);
        }
    }
    else if(nodeCmp(t, x) < 0)
    {
        t->rChild = insert(x, t->rChild);
        if(getH(t->rChild) - getH(t->lChild) == 2)
        {
            if(nodeCmp(x, t->rChild) > 0)
                t = singleLeftRotate(t);
            else
                t = doubleLeftRotate(t);
        }
    }
    else
    {
        word *rear = t->suffix;
        while(rear->next != NULL)
            rear = rear->next;
        rear->next = (word*) malloc (sizeof(word));
        rear = rear->next;
        rear->next = NULL;
        strcpy(rear->s, x->suffix->s);
    }
    t->height = max(getH(t->lChild), getH(t->rChild)) + 1;
    return t;
}

node* singleLeftRotate(node* t)
{
    node* u = t->rChild;
    t->rChild = u->lChild;
    u->lChild = t;
    t->height = max(getH(t->lChild), getH(t->rChild)) + 1;
    u->height = max(getH(u->rChild), getH(t)) + 1;
    return u;
}
    
node* singleRightRotate(node* t)
{
    node *u = t->lChild;
    t->lChild = u->rChild;
    u->rChild = t;
    t->height = max(getH(t->lChild), getH(t->rChild)) + 1;
    u->height = max(getH(u->lChild), t->height) + 1;
    return u;
}
    
node* doubleLeftRotate(node* t)
{
    t->rChild = singleRightRotate(t->rChild);
    return singleLeftRotate(t);
}
    
node* doubleRightRotate(node* t)
{
    t->lChild = singleLeftRotate(t->lChild);
    return singleRightRotate(t);
}

node *find(node *x, node *t)
{
    if(t == NULL)
        return NULL;
    int v = nodeCmp(x, t);
    if(v > 0)
        return find(x, t->rChild);
    else if(v < 0)
        return find(x, t->lChild);
    else
        return t;
}

void preOrder(node *x)
{
    if(x != NULL)
    {
        printf("%s %s %s\n", x->prefix1, x->prefix2, x->suffix->s);
        preOrder(x->lChild);
        preOrder(x->rChild);
    }
}

