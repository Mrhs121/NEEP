#pragma once

#include <stdio.h>
#define MAXNUM 99999999
#define TURE 1
#define FLASE 0
#define YES 1
#define NO 0

void swap(int * a,int *b){
    int  temp = *a;
    *a = *b;
    *b = temp;
}
int getStrlen(char * str){
    int len = 0;
    int i = 0;
    while(str[i]!='\0')
        len++;
    return len;
}

void printIntArr(int arr[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void printCharArr(char arr[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%c ",arr[i]);
    }
    printf("\n");
}

void printString(char arr[])
{
    char c;
    int i =0;
    while( (c=arr[i++])!='\0' )
        printf("%c",c);
    printf("\n");
}

void printFloatArr(float arr[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%f ",arr[i]);
    }
    printf("\n");
}


