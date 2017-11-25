//
//  c_prc.hpp
//  data-structure
//
//  Created by Edward dawson on 21/09/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#ifndef c_prc_hpp
#define c_prc_hpp

#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int gcd(int x, int y);
void hano(int num, int posStart,int posMid, int posEnd);
vector<int> mergeSort(vector<int> &array, int left, int right);
vector<int> merge(vector<int> &array, int left, int middle, int right);
int findMinAbs(vector<int> array);
int lengthOfLongestSubstring(string s);
int knapsack(int* W, int* V, int** F, int k, int b);
void knapSol(int* W, int* V, int** F, int* SOL, int k, int b);
bool searchCli(bool** graph, int * clique, int size, int newVertex);
void findMaxClique(bool** graph, int* clique, int size, int pos, int maxVertex, int* maxclique);
void deleteVertex(bool** graph, int maxVertex);
#endif /* c_prc_hpp */
