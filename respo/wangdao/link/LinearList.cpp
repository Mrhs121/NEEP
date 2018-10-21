/*************************************************************************
	> File Name: LinearList.cpp
	> Author: huangsheng 
	> Mail: 
	> Created Time: Sat 01 Sep 2018 10:08:14 PM CST
 ************************************************************************/
/*
 *
 *
 *
 * 线性表的集合
 *
 *
 */


#include<iostream>
using namespace std;
#include <stdio.h>


int M_Search(int a[],int b[],int n)
{
    int s1=0,d1=n-1,m1,s2=0,d2=n-1,m2;
    while(s1!=d1 || s2!=d2){
        m1 = (s1+d1)/2;
        m2 = (s2+d2)/2;
        if(a[m1] == b[m2]){
            return a[m1];
        }

    }
    return -1;
}
int main()
{
   // cout<<"线性表集合"<<endl;
    
    
    return 0;
}
