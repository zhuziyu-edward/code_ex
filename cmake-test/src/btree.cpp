//
//  btree.cpp
//  data-structure
//
//  Created by Edward dawson on 10/09/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#include "btree.hpp"
#include <iostream>

Node* BinTree::insert(Node* root,int value)
{
    if (root->lNode == NULL)
    {
        root->lNode = new Node;
        root->lNode->num = value;
        if (root->rNode == NULL)
            return root;
        else
            return root->lNode;
    }
    else if (root->rNode == NULL)
    {
        root->rNode = new Node;
        root->rNode->num = value;
        return root->rNode;
    }
    else
    {
        std::cout << "wrong" << std::endl;
        return NULL;
    }
    
}

void BinTree::perOrder(Node* root)
{
    if (root != NULL)
    {
        std::cout << root->num << std::endl;
        perOrder(root->lNode);
        perOrder(root->rNode);
    }
}

void BinTree::inOrder(Node* root)
{
    if (root != NULL)
    {
        inOrder(root->lNode);
        std::cout << root->num << std::endl;
        inOrder(root->rNode);
    }
}

void BinTree::postOrder(Node* root)
{
    if (root != NULL)
    {
        postOrder(root->lNode);
        postOrder(root->rNode);
        std::cout << root->num << std::endl;

    }
}
