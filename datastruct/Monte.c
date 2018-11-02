/*************************************************************************
	> File Name: Monte.c
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Sep 2018 06:30:41 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TIMES 1000000

struct T{
    int key, value;
};

int main(int argc,char ** args)
{
    /*
    if(argc<2){
        printf("please give param islog\n");
        return -1;
    }
    */
    int i;
    struct T a[12];
    for(i=0;i<12;i++){
        a[i].key = i+1;
        a[i].value = 0;
    }
    srand((unsigned)time(0));
    // Monte模拟算法
    for(i=0;i<TIMES;i++){
        int v = (rand()%6+1) + (rand()%6+1);
        a[v-1].value++;
    }
    for(i=0;i<12;i++){
        printf("%2d:%.2f (origin:%d)\n",a[i].key,(double)a[i].value/TIMES,a[i].value);
    }
    return 0;
}
