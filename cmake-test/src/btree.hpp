//
//  btree.hpp
//  data-structure
//
//  Created by Edward dawson on 10/09/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#ifndef btree_hpp
#define btree_hpp

#include <stdio.h>

struct Node
{
    int num = 10;
    Node* lNode = NULL;
    Node* rNode = NULL;
};

typedef struct Node Node;

class BinTree
{
public:
    Node* root = new Node;
    Node* insert(Node* root,int value);
    void perOrder(Node* root);
    void inOrder(Node* root);
    void postOrder(Node* root);

};

#endif /* btree_hpp */
