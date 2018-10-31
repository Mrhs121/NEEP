/*
    839-17年真题答案
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../datastruct/myStrcut.h"
#define satisfy 1
#define notsatisfy 0
#define NOT_VISITED 0
#define VISITED 1




int myScanf(const char * format, ...){
    va_list ap;
    va_start(ap,format);
    char c = '';
    int i=0;
    char f;

}


// 第四大题，自定义myprintf
void myprintf(const char * format , ...)
{
    va_list argList; // 定义一个 va_list 指针来访问参数表
    va_start(argList, format); // 初始化 argList，让它指向第一个变参,即为format字符串
    char c=' ';
    int i=0;
    int next_data;
    char f;

    while(c!='\0') {
        while ((c = format[i]) != '%' && (c = format[i]) != '\0'){
            printf("%c", c);
            i++;
        }
        f = format[++i];
        switch(f){
            case 's':
                i++;
                printf("%s",va_arg(argList, char*));
                break;

            case 'd':
                i++;
                printf("%d",va_arg(argList, int));
                break;
            case 'f':
                i++;
                printf("%f",va_arg(argList, double));
                break;
            case 'c':
                i++;
                printf("%c",va_arg(argList, char));
                break;
            case 'o':
                // 处理八进制
                i++;
                printf("%o",va_arg(argList, int));
                break;
            case 'x':
                // 处理十六进制
                i++;
                printf("%x",va_arg(argList, int));
                break;
        }
       // printf("%c",format[i++]);
    }
}

// 从x的第p位开始的n位数求反，其他位不变
// 即 1->0 0->1
// 思路： 11111111
// ~0<<n 先将全为1的屏蔽码后最右边的n位变成0 11111111000
// 然后再取反，将最后面的n位变成1  000000000111
// 然后再将后面的n位移动（左移）到与目标数字相应的位数上 00000001110000
// 最后用x与屏蔽码异或 （如果不同结果是1，相同为0）（0^0=0,1^0=1,即其他位没有变化）
unsigned invert(unsigned x,int p,int n){
    return x^ (~(~0<<n) << (p+1-n));
}// kr原题 p40

//第三大题 将十进制转为十六进制输出
// 采取递归的方法
void DtoH(int x){
    if(x==0)
        return;
    int Divisor = x/16;
    int mod = x%16;
    DtoH(Divisor);    
    if(mod>=10)// 如果余数大于10则转换为A-F输出
        printf("%c",'A'+(mod-10));
    else 
        printf("%d",mod);
} // 完美解决方案

// 9 判断一颗二叉树是否满足大顶堆的条件
int isSatisfyHeap(BTree * tree) {
    if(tree==NULL)
        return notsatisfy;
	BTree * stack[100];
	int top = -1;
	stack[++top] = tree;
	BTree * p;
	while (top != -1)
	{
		p = stack[top--];
		// 左右孩子均不能大于根结点
		if (p->lchild != NULL)
		{
			if (p->data < p->lchild->data)
			{
                printf("notsatisfy :lchild:%d > root:%d\n",p->lchild->data,p->data);
				return notsatisfy;
			}
			stack[++top] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			if (p->data < p->rchild->data)
			{
                printf("not satisfy rchild:%d > root:%d\n",p->rchild->data,p->data);
				return notsatisfy;
			}
			stack[++top] = p->lchild;
		}
	}
	return satisfy;
}

void printPath(int path[],int size){
    int i=0;
    for(i=0;i<=size;i++){
        printf("--->%d",path[i]);
    }
    printf("\n");
}

int visited[1000];

// 可用于解2017最后一题即为找简单路径，没有回路
// uv:指定的两点 path用于存放路径的数组 d迭代的路径深度 k指定的长度
void FindPath(ALGraph * algraph,int u,int v,int path[],int d,int k){
    int w;
    ArcNode * p;
    d++;
    path[d] = u;
    visited[u] = VISITED;
    if(u==v){
        if(d==k){
            printPath(path,d);
        }
        visited[v] = NOT_VISITED;
        return;
    }
    p = algraph->vertices[u].first;
    while(p!=NULL){
        w = p->adjvex;
        if(visited[w] == NOT_VISITED){
            FindPath(algraph,w,v,path,d,k);
        }
        p = p->next;
    }
    visited[u] = NOT_VISITED;
}




int main()
{

    
    int a = 175;
    int b=8,c=16;
    //printf("%d\n",invert(a,4,3));
    DtoH(a);
    printf("\n");
    myprintf("str = %s int :%d char:%c float:%f %d->八进制:%o %d->十六进制:%x finish\n","huangsheng",1,'c',2.0f,b,b,c,c);
    //printf("%c\n",'a'+1+'0');
    BTree * T = (BTree*)malloc(sizeof(BTree));
    int data[] = {5,2,4,-1,-1,3,-1,-1,-1,3,-1,-1};
    T = createTree(T, data);
    PreOrderBiTree(T);
    printf("\n");
    printf("isSatisfyHeap = %s\n",isSatisfyHeap(T)==satisfy?"satisfy":"notsatisfy");
    return 1;
}
