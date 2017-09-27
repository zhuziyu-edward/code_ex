//
//  c_prc.cpp
//  data-structure
//
//  Created by Edward dawson on 21/09/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#include "c_prc.hpp"
#include <stdio.h>
int main()
{
    hano(20, 1, 2, 3);
    return 0;
}

int gcd(int x, int y)
{
    int rem;
    while(y > 0)
    {
        rem = x % y;
        x = y;
        y= rem;
    }
    return x;
}

void hano(int num, int posStart,int posMid, int posEnd)
{
    if(num == 1)
        printf("move form %d to %d\n", posStart, posEnd);
    else
    {
        hano(num-1, posStart, posEnd, posMid);
        printf("move form %d to %d\n", posStart, posEnd);
        hano(num-1, posMid, posStart, posEnd);
    }
}


