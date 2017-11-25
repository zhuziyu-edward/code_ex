//
//  tree.h
//  c_ex
//
//  Created by Edward dawson on 22/09/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#ifndef tree_h
#define tree_h
#include <stdlib.h>
#include <stdio.h>

typedef struct tree tree;
struct tree
{
    int element;
    tree* left;
    tree* right;
    tree* father;
};

void insert(tree*, int);
void init(tree* );
void printTree(tree*, int);
void preOrder(tree*);
void postOrder(tree*);
void middleOrder(tree*);
int depthOfTree(tree*);
void delete(tree*);
#endif /* tree_h */
