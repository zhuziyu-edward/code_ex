//
//  c_prc.cpp
//  data-structure
//
//  Created by Edward dawson on 21/09/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#include "c_prc.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

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

vector<int> merge(vector<int> &array, int left, int middle, int right)
{
    int posL = left;
    int posR = middle + 1;
    int length = right - left + 1;
    vector<int> tempArray(length);
    for(int i = 0; i < length; i++)
    {
        if(posL <= middle && posR <= right)
        {
            if(array.at(posL) >= array.at(posR))
                tempArray.at(i) = array.at(posR++);
            else
                tempArray.at(i) = array.at(posL++);
        }
        else
        {
            if(posL > middle)
                tempArray.at(i) = array.at(posR++);
            else
                tempArray.at(i) = array.at(posL++);
        }
     }
    for(int i = 0; i < length; i++)
        array.at(left + i) = tempArray.at(i);
    return array;
}

vector<int> mergeSort(vector<int> &array, int left, int right)
{
    if(right > left)
    {
        int middle = (left + right) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
    return array;
}

int findMinAbs(vector<int> array)
{
    int minAbs;
    mergeSort(array, 0, (int)array.size() - 1);
    minAbs = array.at(1) - array.at(0);
    for(vector<int>::iterator it = array.begin()+1; it != array.end(); it++)
        minAbs = (*it - *(it - 1) < minAbs) ? *it - *(it - 1) : minAbs;
   return minAbs;
}

int lengthOfLongestSubstring(string s)
{
    int i = 0,j = 0;
    int length = (int)s.length();
    bool exist[256] = {false};
    int maxLength = 0;
    while(j<length)
    {
        if(exist[s[j]])
        {
            maxLength = max(maxLength, j - i);
            while(s[i] != s[j])
            {
                exist[s[i]] = false;
                i++;
            }
            j++;
            i++;
        }
        else
        {
            exist[s[j]] = true;
            j++;
        }
    }
    maxLength = max(maxLength, length - i);
    return 0;
}

int knapsack(int* W, int* V, int** F, int k, int b)
{
    if(F[k-1][b-1] >= 0)
        return F[k-1][b-1];
    if(k == 1){
        F[k-1][b-1] = (b / W[k-1])* V[k-1];
        return F[k-1][b-1];
    }
    if(b - W[k-1] >= 0){
        F[k-1][b-1] = max(knapsack(W, V, F, k, b-W[k-1]) + V[k-1], knapsack(W, V, F, k-1, b));
        return F[k-1][b-1];
    }
    else{
        F[k-1][b-1] = knapsack(W, V, F, k-1, b);
        return F[k-1][b-1];
    }
}

void knapSol(int* W, int* V, int** F, int* SOL, int k, int b)
{
    if(k == 1){
        SOL[k-1] += b / W[k-1];
        return;
    }
    if(b - W[k-1] >= 0){
        if(F[k-2][b-1] < F[k-1][b-W[k-1]-1] + V[k-1]){
            SOL[k-1]++;
            knapSol(W, V, F, SOL, k, b-W[k-1]);
        }
        else{
            knapSol(W, V, F, SOL, k-1, b);
        }
    }
    else{
        knapSol(W, V, F, SOL, k-1, b);
    }
    return;
}

bool searchCli(bool** graph, int * clique, int size, int newVertex)
{
    for(int i = 0; i < size; i++)
    {
        if(graph[clique[i]][newVertex] == false)
            return false;
    }
    return true;
}


void findMaxClique(bool** graph, int* clique, int size, int pos, int maxVertex, int* maxclique)
{
    if(searchCli(graph, clique, size, pos+1))
    {
        if((pos+1) == maxVertex){
               if((size+1) > *maxclique)
               {*maxclique = size+1; cout << *maxclique << endl;return ;}
               else{
                   return;}
                                }
           else{
               clique[size] = pos + 1;
               findMaxClique(graph, clique, size+1, pos+1, maxVertex, maxclique);
               }
    }
    if(*maxclique == (maxVertex+1))
        return;
    else
    {
        if((pos+1) == maxVertex){
            if(size > *maxclique)
            {*maxclique = size;cout << *maxclique << endl;return ;}
            else{
                return;}}
        else
            findMaxClique(graph, clique, size, pos+1, maxVertex,maxclique);
    }
    return;
}

void deleteVertex(bool** graph, int maxVertex)
{
    bool conti = 1;
    while(conti)
    {
        conti = false;
        for(int i = 0; i <=maxVertex; i++)
        {
            int nodeNum = 0;
            for(int j = 0; j <= maxVertex ; j++)
            {if(graph[i][j] == true)
                nodeNum++;}
            
            if(nodeNum > 0 && nodeNum < 29)
            {
                for(int j = 0; j<= maxVertex; j++){
                graph[i][j] = false;
                graph[j][i] = false;
                    }
                conti = true;
                cout << "cut" << endl;
            }
        }
    }
}

int findKSmallest(int *array, int low, int high, int k)
{
    int index = partition(array, low, high);
    if(index - low + 1 > k)
        return findKSmallest(array, low, index - 1, k);
    else if(index - low + 1 ==k)
        return array[index];
    else
        return findKSmallest(array, index + 1, high, k - index + low - 1);
}

int merge(int *array,int low, int mid, int high)
{
    int *temp = new int[high - low + 1];
    int inv = 0, left = low, right = mid + 1, current = 0;
    while(left <= mid && right <= high){
        if(array[left] > array[right]){
            inv += mid - left + 1;
            temp[current++] = array[right++];
        }
        else{
            temp[current++] = array[left++];
        }
    }
    while(left <= mid) temp[current++] = array[left++];
    while(right <= high) temp[current++] = array[right++];
    for(int i = 0; i < current; i++)
        array[low + i] = temp[i];
    delete[] temp;
    return inv;
}

int findInverse(int *array, int low, int high)
{
    int inv = 0;
    if(low < high){
        int mid = (low + high) / 2;
        inv += findInverse(array, low, mid);
        inv += findInverse(array, mid+1, high);
        inv += merge(array, low, mid, high);
    }
    return inv;
}

