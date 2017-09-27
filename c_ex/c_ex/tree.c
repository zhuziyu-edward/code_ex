//
//  tree.c
//  c_ex
//
//  Created by Edward dawson on 22/09/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#include "tree.h"
void init(tree* node)
{
    node->element = 0;
    node->left = NULL;
    node->right = NULL;
    node->father = NULL;
     
}

void insert(tree* root,int num)
{
    
    int stop = 0;
    do{
        if(num <= root->element)
        {
            if(root->left == NULL)
            {
                root->left = (tree*) malloc (sizeof(tree));
                init(root->left);
                root->left->element = num;
                root->left->father =  root;
                stop = 1;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if(root->right == NULL)
            {
                root->right = (tree*) malloc (sizeof(tree));
                init(root->right);
                root->right->element = num;
                root->right->father =  root;
                stop =1 ;
            }
            else
            {
                root = root->right;
            }

        }
        
        
    }while(stop == 0);
}

void preOrder(tree* root)
{
    if(root == NULL)
        return;
    else
    {
        printf("%d\n", root->element);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void middleOrder(tree* root)
{
    if(root == NULL)
        return;
    else
    {
        middleOrder(root->left);
        printf("%d\n", root->element);
        middleOrder(root->right);
    }
}

void postOrder(tree* root)
{
    if(root == NULL)
        return;
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n", root->element);

    }
}

void printTree(tree* root, int indent)
{
    char s[10];
    sprintf(s, "%%%dd\n", indent);
    if(root->right != NULL)
        printTree(root->right, indent+4);
    printf(s, root->element);
    if(root->left != NULL)
        printTree(root->left, indent+4);
}

int depthOfTree(tree* root)
{
    int depth = 0;
    if(root != NULL)
    {
        int leftDepth = depthOfTree(root->left);
        int rightDepth = depthOfTree(root->right);
        depth = leftDepth >= rightDepth ? leftDepth + 1: rightDepth + 1;
    }
    return depth;
}

void delete(tree* root)
{
    int isLeft = 0;
    if(root->father->left == root)
        isLeft = 1;
    if(root->left == NULL)
    {
        if(root->right == NULL)
        {
            if(isLeft == 1)
                root->father->left = NULL;
            else
                root->father->right = NULL;

            free(root);
        }
        else
        {
            if(isLeft == 1)
                root->father->left = root->right;
            else
                root->father->right = root->right;
        }
    }
    else
    {
        if(root->right == NULL)
        {
            if(isLeft == 1)
                root->father->left = root->left;
            else
                root->father->right = root->left;
            free(root);
        }
    }
    
}
