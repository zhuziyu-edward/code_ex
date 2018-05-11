#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE (2000001)
#define MAXWORD (8000000)
#define DEFAULT_CAPACITY (10)
#define IN_FILE "article.txt"
#define OUT_FILE "markov.txt"

typedef struct node node;
typedef long long ll;

struct node
{
    char *s1;
    char *s2;
    int len1;
    int len2;
    int size;
    int capacity;
    int *suffix;
};

char initStr[MAXWORD];
char notEmpty[MAXSIZE];
node hashTable[MAXSIZE];
double seed = 997;
int startIndex;
ll sCur = 0, sSize, sStart;

double rrand()
{
    double lambda = 3125.0;
    double m = 34359738337.0;
    double r;
    seed = fmod(lambda*seed, m);
    r = seed / m;
    return r;
}

int hash(char *s1, char *s2)
{
    int hash = 0;
    int i = 0;
    for(; s1[i] != '\0'; i++)
        hash =  (hash << 5) - hash + s1[i];
    for(i = 0; s2[i] != '\0'; i++)
        hash =  (hash << 5) - hash + s2[i];
    return (hash & 0x7fffffff) % MAXSIZE;
}

char *readWord(int *len)
{
    char tmp;
    while(sCur < sSize)
    {
        tmp = initStr[sCur];
        if(tmp != ' ' && tmp != '\r' && tmp != '\n')
        {
            sStart = sCur;
            break;
        }
        sCur++;
    }
    if(sCur >= sSize)
        return NULL;
    while(sCur < sSize)
    {
        tmp = initStr[sCur];
        if(tmp == ' ' || tmp == '\n' || tmp == '\r')
        {
            initStr[sCur] = '\0';
            break;
        }
        sCur++;
    }
    *len = sCur - sStart;
    sCur++;
    return initStr + sStart;
}

void pushSuffixToNode(int index, int suffixIndex)
{
    if(hashTable[index].size == hashTable[index].capacity)
    {
        int newCap = 2 * hashTable[index].capacity;
        int *newSuffix = (int*) malloc (sizeof(int) * newCap);
        memcpy(newSuffix, hashTable[index].suffix, sizeof(int) * hashTable[index].size);
        free(hashTable[index].suffix);
        hashTable[index].suffix = newSuffix;
        hashTable[index].capacity = newCap;
    }
    hashTable[index].suffix[hashTable[index].size++] = suffixIndex;
}

int getIndex(char *first, int len1, char *second, int len2)
{
    int index = hash(first, second);
    while(notEmpty[index] == 1)
    {
        if(strcmp(hashTable[index].s1, first) == 0 && strcmp(hashTable[index].s2, second) == 0)
            return index;
        index++;
    }
    notEmpty[index] = 1;
    hashTable[index].s1 = first;
    hashTable[index].len1 = len1;
    hashTable[index].s2 = second;
    hashTable[index].len2 = len2;
    hashTable[index].capacity = DEFAULT_CAPACITY;
    hashTable[index].size = 0;
    hashTable[index].suffix = (int*) malloc (sizeof(int) * DEFAULT_CAPACITY);
    return index;
}

int pushNodeToTable(int curIndex, char *curWord, int len)
{
    char *nextS1 = hashTable[curIndex].s2;
    int nextIndex = getIndex(nextS1, hashTable[curIndex].len2, curWord, len);
    pushSuffixToNode(curIndex, nextIndex);
    return nextIndex;
}

void initTable(FILE *inFile)
{
    char *first, *second;
    sSize = fread(initStr, sizeof(char), MAXWORD, inFile);
    int len1, len2;
    first = readWord(&len1);
    second = readWord(&len2);
    startIndex = getIndex(first, len1, second, len2);
}

void buildHashTable(FILE *inFile)
{
    initTable(inFile);
    int curIndex = startIndex, len;
    char *curWord;
    while((curWord = readWord(&len)) != NULL)
    {
        curIndex = pushNodeToTable(curIndex, curWord, len);
    }
    pushSuffixToNode(curIndex, -100);
}

void printTable(int maxWord, FILE *outFile)
{
    int curIndex = startIndex;
    int n;
    fwrite(hashTable[curIndex].s1, sizeof(char), hashTable[curIndex].len1, outFile);
    fputc(' ', outFile);
    fwrite(hashTable[curIndex].s2, sizeof(char), hashTable[curIndex].len2, outFile);
    fputc(' ', outFile);
    while(maxWord--)
    {
        if(hashTable[curIndex].size == 1)
            n = 0;
        else
            n = (int)(rrand() * hashTable[curIndex].size);
        curIndex = hashTable[curIndex].suffix[n];
        if(curIndex >= 0)
        {
            fwrite(hashTable[curIndex].s2, sizeof(char), hashTable[curIndex].len2, outFile);
            fputc(' ', outFile);
        }
        else
            break;
    }
}

int main(int argc, const char * argv[]) {
    FILE *inFile = fopen(IN_FILE, "r"), *outFile = fopen(OUT_FILE, "w");
    int maxWord;
    scanf("%d", &maxWord);
    
    buildHashTable(inFile);
    printTable(maxWord - 2, outFile);
    
    fclose(inFile);
    fclose(outFile);
    return 0;
}
