/*************************************************************************
	> File Name: ThreadNode.c
	> Author:黄大神 
	> Mail: 
	> Created Time: Fri 14 Sep 2018 08:41:57 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode , *ThreadTree;

void test1(ThreadTree tree){
    printf("tree %d\n",sizeof(tree));
}

void test2(ThreadTree * tree){
    printf("* tree %d\n",sizeof(tree));
}

int main()
{
    int a =10;
    int *p = &a;
    printf("p size :%d\n",sizeof(p));
    printf("node size :%d\n",sizeof(ThreadNode));
    ThreadTree tree = (ThreadTree)malloc(sizeof(ThreadNode));
    test2(&tree);
    test1(tree);
    return 0;
}

