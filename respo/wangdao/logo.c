/*************************************************************************
	> File Name: logo.c
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Sep 2018 01:39:05 PM CST
 ************************************************************************/

#include<stdio.h>

#include <math.h>
void Fractal(int n,int level)
{
    if(level==1)
    {
        int p=pow(3,n);
        printf("FD 1/%d\n",p);
        printf("LD 60\n");
        printf("FD 1/%d\n",p);
        printf("LD 240\n");
        printf("FD 1/%d\n",p);
        printf("LD 60\n");
        printf("FD 1/%d\n",p);
    }
    else
    {
        Fractal(n,level-1);
        printf("LD 60\n");
        Fractal(n,level-1);
        printf("LD 240\n");
        Fractal(n,level-1);
        printf("LD 60\n");
        Fractal(n,level-1);
    }
}
void output(int n)
{
    Fractal(n,n);
}

int main()
{
    int n = 5;
    output(5);
    return 0;
}




