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
        hashTable.postions[hashTable.index] = hashcode;
        if(get(key)==NULL){
            hashTable.index++;
        }
        KeyValue kv;
        kv.key = (char *)malloc(sizeof(char)*strlen(key)+1);
        kv.value = (char *)malloc(sizeof(char)*strlen(value)+1);
        strcpy(kv.key,key);
        strcpy(kv.value,value);
        hashTable.kv[hashcode] = kv;
}

void put(char * key,char * value){
    if(hashTable.isInit == 0){
        init();
    }
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
    if(hashTable.isInit == 0){
        init();
    }
    return hashTable.kv[hash(key)].value;
}

void foreach(){
    int i = 0;
    for(i=0;i<hashTable.index;i++){
        printf("key:%s value:%s\n",hashTable.kv[hashTable.postions[i]].key,
                                   hashTable.kv[hashTable.postions[i]].value);
    }
}
int main()
{
    init();
    printf("%d ,%d\n",hashTable.isInit,hash("huangsheng"));
    put("name","huangsheng");
    put("jhasdjkfhjlkdsahfjlkhdsakjfh","huangsheng");
    put("age","12");
    put("email","1367467330@qq.com");
    foreach();
    put("name","李爱莉");
    foreach();
    return 0;
}

