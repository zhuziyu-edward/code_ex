//
//  main.cpp
//  data-structure
//
//  Created by Edward dawson on 07/09/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "btree.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    BinTree tree;
    Node* pNode = tree.root;
    for (int i = 0; i<10; i++)
    {
        pNode = tree.insert(pNode,i);
    }
    cout << "perorder" << endl;
    tree.perOrder(tree.root);
    cout << "inorder" << endl;
    tree.inOrder(tree.root);
    cout << "postorder" << endl;
    tree.postOrder(tree.root);

    
    return 0;
    
    
}
