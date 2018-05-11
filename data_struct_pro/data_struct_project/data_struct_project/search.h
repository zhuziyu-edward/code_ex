//
//  search.h
//  data_struct_project
//
//  Created by Edward dawson on 30/04/2018.
//  Copyright © 2018 ziyu zhu. All rights reserved.
//

#ifndef search_h
#define search_h
#include "node.h"

void makeEmpty(node *);
int max(int, int);
node* insert(node *x, node *);
node* singleLeftRotate(node* );
node* singleRightRotate(node* );
node* doubleLeftRotate(node* );
node *doubleRightRotate(node *);
void preOrder(node *);
node *find(node *, node *);

#endif /* search_h */
