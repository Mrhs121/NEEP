#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 1000
typedef struct KEYVALUE{
    char * key;
    char * value;
}KeyValue;

typedef struct HASHTABLE{
    KeyValue * kv;
    int size;
    int isInit;
    int length;
    int index;
    int postions[1000];
}HashTable;

void put(char * key,char * value);
char* get(char * key);
int hash(char * key);
void cover(char * key,char * value);
void init();
void foreach();
