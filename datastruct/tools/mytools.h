#pragma once
#ifndef H_MYTOOLS
#define H_MYTOOLS

#include <stdio.h>
#include "../myStrcut.h"
//#define MAXNUM 99999999
#define TURE 1
#define FLASE 0
#define YES 1
#define NO 0
#define DATATPYE int
#define FORMAT "%c\n"

void printList(LNode * list);
void testDatatype(DATATPYE a);

void swap(int * a,int *b);
int getStrlen(char * str);

void printIntArr(int arr[],int n);

void printCharArr(char arr[],int n);

void printString(char arr[]);

void printFloatArr(float arr[],int n);

// 十进制转为二进制输出
void B2I(int x);
#endif

