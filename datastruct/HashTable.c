#include <stdio.h>
#include <string.h>
#include "./HashTable.h"

static HashTable hashTable;

int hash(char * key){
    int hashcode = 0;
    char c;
    int i = 0;
    while( (c=key[i++])!='\0'){
        hashcode += c;
    }
    return hashcode % 10007 % 1000;
}


void init(){
    hashTable.kv = (KeyValue*)malloc(sizeof(KeyValue)*1000);
    hashTable.isInit = 1;
}
void cover(char * key,char * value){
        int hashcode = hash(key);
        KeyValue kv;
        kv.key = (char *)malloc(sizeof(char)*strlen(key)+1);
        kv.value = (char *)malloc(sizeof(char)*strlen(value)+1);
        strcpy(kv.key,key);
        strcpy(kv.value,value);
        hashTable.kv[hashcode] = kv;
}

void put(char * key,char * value){
    if(get(key)==NULL){
        cover(key,value);
    } else if(0==strcmp(key,hashTable.kv[hash(key)].key)){
        printf("覆盖旧数据\n");
        cover(key,value);
    } else {
        printf("冲突\n");
    }
}

char * get(char * key){
    return hashTable.kv[hash(key)].value;
}

int main()
{
    init();
    printf("%d ,%d\n",hashTable.isInit,hash("huangsheng"));
    put("name","huangsheng");
    printf("name = %s\n",get("name"));
    put("name","liaili");
    printf("name = %s\n",get("name"));
    if(get("age")==NULL){
        printf("null\n");
        put("age","22");
    } 
    return 0;
}

