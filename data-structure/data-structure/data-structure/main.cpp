//
//  main.cpp
//  data-structure
//
//  Created by Edward dawson on 07/09/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int maxDivision(int number)
{
    if(number < 4)
        return 0;
    else{
        if(number % 2 == 0){
            for(int i = number / 4; i >= 0; i--){
                if((number - i*4) % 6 == 0)
                    return i + (number - i*4) / 6;
            }
            return 0;
        }
        else{
            if(number < 9)
                return 0;
            else{
                number -= 9;
                for(int i = number / 4; i >= 0; i--){
                    if((number - i*4) % 6 == 0)
                        return i + (number - i*4) / 6 + 1;
                }
                return 0;
            }
        }
    }
}
int main()
{
    int number;
    while(cin >> number){
        int maxD = maxDivision(number);
        if(maxD == 0)
            cout << -1 << endl;
        else
            cout << maxD << endl;
    }
}
