#include <stdio.h>
#include "./HashTable.h"
int main()
{
    put("name","huangsheng");
    put("age","22");
    put("email","1237467330@qq.com");
    put("hs","黄大神");
    foreach();
    removeKV("name");
    //putVal2("aaaaaa","kjashdfhjkld",127863);
    foreach();
    put("name","huangdashen");
    foreach();
    //printf("%d\n",hash("aaaa",100));
    return 0;

}

