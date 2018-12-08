/*************************************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Sep 2018 05:45:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

//队列的下标是从0开始
//栈的top是从-1开始
typedef struct{
    int data[MAXSIZE];
    int front,rear;
}SqQueue;


int main()
{
    // 记住了
    SqQueue * q1 = (SqQueue*)malloc(sizeof(SqQueue)); 
    q1->data[0] = 10;
    q1->data[1] = 100;
    printf("%3d\n",q1->data[0]);
    return 0;
}
