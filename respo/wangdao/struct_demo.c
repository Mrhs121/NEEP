/*************************************************************************
	> File Name: struct_demo.c
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Sep 2018 07:33:29 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
struct stu1{
    int clazz;
    char name[20];
};

int main()
{
    struct stu1 a;
    struct stu1 * p ;///(struct stu *)malloc(sizeof(struct stu *)) ;
    // 为结构体指针分配空间
    p = (struct stu1 *)malloc(sizeof(struct stu1));
    p->clazz = 2;
    printf("%d\n",p->clazz);

    return 0;
}
