/*************************************************************************
	> File Name: c_test.c
	> Author:黄大神 
	> Mail: 
	> Created Time: Thu 13 Sep 2018 08:31:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void change(int a)
{
    a = 100;
}

void change22(int *a){
    *a = 100;
}

int main()
{
    int a[] = {1,2,3,4};
    printf("%d\n",a[2]);
    change(a[2]);
    printf("%d\n",a[2]);
    change22(&a[2]);
    printf("%d\n",a[2]);
    return 0;
}

