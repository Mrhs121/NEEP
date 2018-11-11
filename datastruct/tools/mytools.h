#pragma once

#include <stdio.h>
#define MAXNUM 99999999


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

void printFloatArr(float arr[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%f ",arr[i]);
    }
    printf("\n");
}
