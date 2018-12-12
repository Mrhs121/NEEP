/*
    839-17年真题答案
*/
#include "./myhead.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "../datastruct/myStrcut.h"
#define satisfy 1
#define notsatisfy 0
#define NOT_VISITED 0
#define VISITED 1




// int myScanf(const char * format, ...){
//     va_list ap;
//     va_start(ap,format);
//     char c = '';
//     int i=0;
//     char f;

// }
// 第五大题 对矩阵进行排序（现根据面积，）
typedef struct Matrix
{
    double left_bottom_x,left_bottom_y;
    double right_top_x,right_top_y;
    double s;
}matrix;

// double calS(matrix m){
//     return (m.right_top_x-m.left_bottom_x) * (m.right_top_y-m.left_bottom_y);
// }
double calS(double a,double b,double c,double d){
    return (c-a) * (d-b);
}

double calDistant(double x,double y){
    return x*x + y*y;
}

int compareMatrix(const void * a,const void * b){
    matrix * m1 = (matrix*)a;
    matrix * m2 = (matrix*)b;
    printf("comparing %0.4lf <-> %0.4lf\n",m1->s,m2->s);
    if(m1->s == m2->s){
        if(calDistant(m1->left_bottom_x,m1->left_bottom_y) == calDistant(m2->left_bottom_x,m2->left_bottom_y)){
            if(m1->left_bottom_x == m2->left_bottom_x){
                return (m1->left_bottom_y - m2->left_bottom_y)>0?1:-1;
            } else {
                printf("same %lf %lf\n",m1->left_bottom_x ,m2->left_bottom_x );
                return (m1->left_bottom_x - m2->left_bottom_x)>0?1:-1;
            }
        } else {
            return (calDistant(m1->left_bottom_x,m1->left_bottom_y) - calDistant(m2->left_bottom_x,m2->left_bottom_y))>0?1:-1;
        }
    } else {
        return (m1->s - m2->s)>0?1:-1;
    }
}
// 按照矩阵的面积排序
void SortMatrix(char * filename){
    if(filename == NULL){
        printf("usge : [filename]\n");
        return;
    }
    int N = 10;
    FILE * in = fopen(filename,"r");
    FILE * out = fopen("./matrix.out","w");
    matrix matrixs[40];
    double left_bottom_x,left_bottom_y;
    double right_top_x,right_top_y;
    int i=0,j=0;
    while(i<N && fscanf(in,"%lf %lf %lf %lf\n",&left_bottom_x,&left_bottom_y,&right_top_x,&right_top_y)!=EOF){
         matrixs[i].left_bottom_x = left_bottom_x;
         matrixs[i].left_bottom_y = left_bottom_y;
         matrixs[i].right_top_x = right_top_x;
         matrixs[i].right_top_y = right_top_y;
         matrixs[i].s = calS(left_bottom_x,left_bottom_y,right_top_x,right_top_y);
        // printf("(%0.2lf,%0.2lf) (%0.2lf,%0.2lf) S = %0.4lf\n",left_bottom_x,left_bottom_y
        //                           ,right_top_x,right_top_y,calS(left_bottom_x,left_bottom_y
        //                           ,right_top_x,right_top_y));
        i++;
    }

    qsort(matrixs,i,sizeof(matrix),compareMatrix);
    for(j=0;j<i;j++){
        fprintf(out, "%0.4lf %lf %lf %lf %lf\n",
                                        matrixs[j].s,
                                        matrixs[j].left_bottom_x,
                                        matrixs[j].left_bottom_y,
                                        matrixs[j].right_top_x,
                                        matrixs[j].right_top_y );
    }
    printf("\n");

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
            // case 'c':
            //     i++;
            //     printf("%c",va_arg(argList, char));
            //     break;
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
    va_end(argList);
}

// 从x的第p位开始的n位数求反，其他位不变
// 即 1->0 0->1
// 思路： 11111111
// ~0<<n 先将全为1的屏蔽码后最右边的n位变成0 11111111000
// 然后再取反，将最后面的n位变成1  000000000111
// 然后再将后面的n位移动（左移）到与目标数字相应的位数上 00000001110000
// 最后用x与屏蔽码异或 （如果不同结果是1，相同为0）（0^0=0,1^0=1,即其他位没有变化）
char * invert(unsigned x,int p,int n){
    unsigned result =  (x^ (~(~0<<n) << (p+1-n)));
    printf("result = %d\n",result );
    char  * str = (char*)malloc(sizeof(char)*32);
    sprintf(str,"%d",result);
    return str;
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


// 十进制转为二进制输出
static void B2I(int x){
    if(x==0)
        return;
    int Divisor = x/2;
    int mod = x%2;
    B2I(Divisor);
    printf("%d",mod);
}

typedef struct Qu {
    BTree * data[100];
    // int LeverCount[50];
    int front, rear;
}Qu;

int isComplete(BTree * tree){
    //int result = 0;
    Qu _queue;
    _queue.front = -1;
    _queue.rear = -1;
    _queue.data[++_queue.rear] = tree;
    BTree * node;
    while(_queue.front < _queue.rear){
        node = _queue.data[++_queue.front];
        if(node){
            _queue.data[++_queue.rear] = node->lchild;
            _queue.data[++_queue.rear] = node->rchild;
        } else {
            while(_queue.front < _queue.rear){
                node = _queue.data[++_queue.front];
                if(node)
                    return 0;
            }
        }
    }
    return 1;
}
// 9 判断一颗二叉树是否满足大顶堆的条件
// 层序遍历队列或者用堆也行
// 此方法存在缺陷，不能够判读是否是颗完全树
int isSatisfyHeap(BTree * tree) {
    if(tree==NULL)
        return notsatisfy;
	BTree * stack[100];
    BTree * queue[100];
    int front=0,rear=0;
	int top = -1;
	stack[++top] = tree;
    queue[rear] = tree;
    rear++;
	BTree * p;
    // 先判断是否满足完全树
    // if(isComplete(tree)==0)
    //     return notsatisfy;
	while (front != rear)
	{
		//p = stack[top--];
        p = queue[front++];
        //printf("%d ",p->data);
		// 左右孩子均不能大于根结点
		if (p->lchild != NULL)
		{
			if (p->data < p->lchild->data)
			{
                printf("notsatisfy :lchild:%d > root:%d\n",p->lchild->data,p->data);
				return notsatisfy;
			}
			//stack[++top] = p->lchild;
		      queue[rear++] = p->lchild;
        }
		if (p->rchild != NULL)
		{
			if (p->data < p->rchild->data)
			{
                printf("not satisfy rchild:%d > root:%d\n",p->rchild->data,p->data);
				return notsatisfy;
			}
			//stack[++top] = p->lchild;
            queue[rear++] = p->lchild;
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
        visited[v] = NOT_VISITED;// 注意这里，如果在这里return的话，就需要手动将此顶点置为NOT_VISITED
                                 // 因为可能有多条不同的路径都会经过这个顶点
                                 // 及时的return可以有效减少时间   
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


// 17年839真题  合并两个有序的数组，不使用缓冲区，A的长度够长
// 两种思路
// 1.暴力解法
// 2.从后面忘前面添加新的大端
// 明显这种做法更高效
void mergeWithoutBuffer2(int *a,int n,int *b,int m){
    int i,j;
    int end = m+n-1;
    // i记录a j记录b
    for(i=n-1,j=m-1;j>=0&&i>=0;){
        if(a[i]>=b[j]){
            a[end--] = a[i--];
        } else  {
            a[end--] = b[j--];
        }
    }
    if(j!=-1){
        for(i=0;i<=j;i++)
            a[i] = b[i];
    }
}

int test2017(char * filenames[])
{

    //SortMatrix(filenames[2]);
    // int data[] = {1,2,4,-1,-1,5,8,-1,-1,-1,3,6,-1,-1,7,-1,-1};
    // BTree * tree = (BTree*)malloc(sizeof(BTree));
    // tree = createTree(tree,data);
    // LeverOrder(tree);
    // int key;
    // scanf("%d",&key);
    // printAnc(tree,key);
    //printf("%s\n",invert(123,5,2));    
    // int a = 175;
    // int b=8,c=16;
    // myprintf("%d\n",a);
    // //printf("%d\n",invert(a,4,3));
    // scanf("%d",&a);
    // DtoH(a);

    // printf("\n--> %X\n",a);
    // printf("\n");
    // B2I(a);
    // printf("\n");
    // myprintf("str = %s int :%d char:%c float:%f %d->八进制:%o %d->十六进制:%x finish\n","huangsheng",1,'c',2.0f,b,b,c,c);
    // //printf("%c\n",'a'+1+'0');
    BTree * T = (BTree*)malloc(sizeof(BTree));
    int data[] = {10,7,-1,6,-1,-1,8,-1,-1};
    T = createTree(T, data);
    LeverOrder(T);
    // PreOrderBiTree(T);
    // printf("\n");
    printf("isSatisfyHeap = %s\n",isSatisfyHeap(T)==satisfy?"satisfy":"notsatisfy");
    // printf("%d\n",123<<33  );
    return 1;
}
