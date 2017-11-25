//
//  huffman_tree.hpp
//  data-structure
//
//  Created by Edward dawson on 29/10/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#ifndef huffman_tree_hpp
#define huffman_tree_hpp
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    char value;
    int freq = 0;
    bool ischar = 1;
    node* left = NULL;
    node* right = NULL;
};

struct cmp
{
    bool operator () (node a, node b)
    {
        if(b.freq < a.freq )
            return true;
        else if(a.freq == b.freq)
        {
            if(b.value > a.value)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};

struct nodeDec{
    short bit;
    char value;
    bool operator <(nodeDec const &a)const
    {
        if(bit < a.bit)
            return  true;
        if(bit == a.bit && value < a.value)
            return true;
        return false;
    }
};

class huffman
{
    int freq[256] = {0};
public:
    priority_queue<node, vector<node>, cmp> priQue;
    map<char,char> value;
    map<char,short> bits;
    map<nodeDec,char> mapDec;
    void count(string infile);
    void getHuff();
    void traverse(node* root, char val, short bitNum);
    void writefile(string inDir, string outDir);
    void decode(string inDir, string outDir);
};
#endif /* huffman_tree_hpp */
