//
//  huffman_tree.cpp
//  data-structure
//
//  Created by Edward dawson on 29/10/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#include "huffman_tree.hpp"
void huffman::count(string inName)
{
    ifstream infile;
    infile.open(inName);
    char temp;
    while(infile.get(temp))
    {
        freq[temp]++;
    }
    infile.close();
    return;
}

void huffman::getHuff()
{
    node temp;
    node* temp1;
    node* temp2;
    int num = 0;
    for(int i = 0; i < 256; i++)
    {
        if(freq[i])
        {
            temp.value = i;
            temp.freq = freq[i];
            temp.ischar = 1;
            priQue.push(temp);
            num++;
        }
    }
    while(num > 1)
    {
        node newNode;
        temp1 = new node;
        temp1->value = priQue.top().value;temp1->freq = priQue.top().freq;temp1->ischar = priQue.top().ischar;temp1->left = priQue.top().left;temp1->right = priQue.top().right;
        priQue.pop();
        temp2 = new node;
        temp2->value = priQue.top().value;temp2->freq = priQue.top().freq;temp2->ischar = priQue.top().ischar;temp2->left = priQue.top().left;temp2->right = priQue.top().right;
        priQue.pop();
        newNode.ischar = 0;
        newNode.left = temp1; newNode.right = temp2; newNode.freq = temp1->freq + temp2->freq; newNode.value = 88;
        priQue.push(newNode);
        num--;
    }
    temp = priQue.top();
    traverse(&temp, 0, 0);
}

void huffman::traverse(node* root, char val, short bitNum)
{
    if(root->left == NULL && root->right == NULL)
    {
        value[root->value] = val;
        bits[root->value] = bitNum;
        nodeDec nodeTemp = {bitNum,val};
        mapDec[nodeTemp] = root->value;
        cout << "char:" << root->value << "  bits:" << bitNum << "  value:" << (int)val << endl;
    }
    else
    {
        traverse(root->left, val<<1, bitNum+1);
        traverse(root->right, (val<<1) + 1, bitNum+1);
    }
}

void huffman::writefile(string inDir, string outDir)
{
    char tempfile[20];
    short end = 0,currentLen = 0;
    short leftbit = 8;
    char writetemp = 0;
    long long int totalbits = 0;
    ifstream infile;
    ofstream outfile;
    infile.open(inDir);
    outfile.open(outDir,ios::binary);
    while(infile.get(tempfile[end]))
    {
        currentLen += bits[tempfile[end]];
        if(currentLen < leftbit)
        {end++;continue;}
        else
        {
            for(int i = 0;i < end; i++)   //write first, will not exceed
            {
                writetemp += (value[tempfile[i]] << (leftbit - bits[tempfile[i]]));
                leftbit -= bits[tempfile[i]];
            }
            if(leftbit == bits[tempfile[end]])
            {
                writetemp += value[tempfile[end]];
                outfile << writetemp;
                leftbit = 8;
                writetemp = 0;
            }
            else
            {
                writetemp += value[tempfile[end]] >> (bits[tempfile[end]] - leftbit);
                outfile << writetemp;
                writetemp = value[tempfile[end]] << (leftbit + 8 - bits[tempfile[end]]);
                leftbit = 8 - bits[tempfile[end]] + leftbit;
            }
            end = 0;currentLen = 0;
            totalbits += 8;
        }
    }
    if(currentLen > 0)
    {
        for(int i = 0;i < end; i++)   //write first, will not exceed
        {
            writetemp += (value[tempfile[i]] << (leftbit - bits[tempfile[i]]));
            leftbit -= bits[tempfile[i]];
        }
        outfile << writetemp;
        totalbits += 8 - leftbit;
    }
    outfile << (char)127 << totalbits;
    cout << "Encode:totalbits:" << totalbits << endl;
    outfile.close();
    infile.close();
}

void huffman::decode(string inDir, string outDir)
{
    long long int totalbits;
    ifstream infile(inDir, ios::binary);
    ofstream outfile(outDir, ios::binary);
    char num;
    infile.seekg(-1,ios::end);
    infile >> num;
    while(num != (char)127)
    {
        infile.seekg(-2,ios::cur);
        infile >> num;
    };
    infile >> totalbits;
    cout << "Decode:totalbits" << totalbits << endl;
    infile.seekg(0,ios::beg);
    char tempChar, tempVal, moveleft;
    nodeDec tempNode = {0,0};
    for(int i = 0;i < totalbits / 8; i++)
    {
        infile >> tempChar;
        for(int j = 0; j < 8; j++)
        {
            moveleft = tempChar << j;
            if( (moveleft & (char)-128) == (char)-128)
                tempVal = 1;
            else
                tempVal = 0;
            tempNode.value = (tempNode.value << 1) + tempVal; tempNode.bit++;
            if(mapDec[tempNode])
            {
                outfile << mapDec[tempNode];
                cout << mapDec[tempNode] << endl;
                tempNode = {0,0};
            }
        }
    }
    if(totalbits % 8 == 0){
        outfile.close(); infile.close();return;}
    else
    {
        int leftB = totalbits % 8;
        infile >> tempChar;
        for(int j = 0; j < leftB; j++)
        {
            moveleft = tempChar << j;
            if( (moveleft & (char)-128) == (char)-128)
                tempVal = 1;
            else
                tempVal = 0;
            tempNode.value = (tempNode.value << 1) + tempVal; tempNode.bit++;
            if(mapDec[tempNode])
            {
                outfile << mapDec[tempNode];
                cout << mapDec[tempNode] << endl;
                tempNode = {0,0};
            }
        }
    }
    outfile.close();
    infile.close();
}
