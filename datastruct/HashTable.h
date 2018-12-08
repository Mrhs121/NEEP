#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 1000
typedef struct KEYVALUE{
    char * key;
    char * value;
    struct KEYVALUE * next;
}KeyValue;

typedef struct HASHTABLE{
    KeyValue ** kv;
    int size;
    int isInit;
    int length;
    int index;
    
    int postions[1000];
}HashTable;

void removeKV(char * key);
void put(char * key,char * value);
void putVal2(char * key,char * value,int hashcode);
char* _get(char * key);
static int hash(char * key,int base);
static void init();
void foreach();
static void extendCapcity();
static KeyValue * findKey(char * key,int hashcode);
