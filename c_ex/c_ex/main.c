//
//  main.c
//  c_ex
//
//  Created by Edward dawson on 22/09/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#include <stdio.h>
#include "algorithm.h"
#include "tree.h"
#include <time.h>
#ifndef macro1
#define macro1 38
#endif


int main(int argc, const char * argv[])
{
    srand((int)time(0));
    tree* root = (tree* ) malloc (sizeof(tree));
    init(root);
    root->element = (int)(rand() % 100);
    for(int i = 0; i<10; i++)
        insert(root, (int)(rand() % 100));
    printTree(root, 0);
    preOrder(root);
    printf("\n");
    middleOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    return 0;
}

