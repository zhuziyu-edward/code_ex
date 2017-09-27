//
//  main.c
//  test
//
//  Created by Edward dawson on 25/09/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    char s[40];
    sprintf(s, "%%%dd\n", 10);
    printf("%s", s);

}
