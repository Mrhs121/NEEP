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
}HashTable;

void put(char * key,char * value);
char* get(char * key);
int hash(char * key);
void cover(char * key,char * value);
void init();
