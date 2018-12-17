#include <stdio.h>
#include <stdlib.h>
#include "../datastruct/myStrcut.h"
#include "./myhead.h"
#include <string.h>
#include <math.h>
#define YES 1
#define NO 0
#define MAX 100
#define eps 0.000000000001
typedef struct  Score{
    int num;
    char name[20];
    int score;
}Stu[200];


typedef struct{
    int data[MAXSIZE];
    int length;
}SqList;


static  void print(int b[],int n){
    int i;
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    printf("\n");
}

// 判断一个矩阵是否符合数独的要求 15年第五大题
int isSudo(int sudo[MAX][MAX],int n){
    int row[MAX];
    int cl[MAX];
    int i,j;
    for(i=0;i<=n*n;i++){
        row[i]= -1;
        cl[i] = -1;
    }

    // 先验证大的矩阵是否满足要求
    for(i=0;i<n*n;i++){
        for(j=0;j<n*n;j++){
        	// 同时检查第i行第i列
            if(row[sudo[i][j]]==-1){
                row[sudo[i][j]] = 1;
            } else {
                printf("行重复元素：(%d,%d)->%d\n",i,j,sudo[i][j]);
                return NO;
            }
            if(cl[sudo[j][i]]==-1){
                cl[sudo[j][i]] = 1;
            } else {
                printf("列重复元素：(%d,%d)->%d\n",j,i,sudo[j][i]);
                return NO;
            }
        }
        // 恢复检测表
        for(j=0;j<=n*n;j++){
            row[j]= -1;
            cl[j] = -1;
        } 

    }

    for(j=0;j<=n*n;j++){
        row[j]= -1;
        cl[j] = -1;
    } 

    // 再验证n*n的小矩阵是否符合要求
    for(i=0;i<n*n;i++){
    	for(j=0;j<n*n;j++){
    		int statr_clo=(i%3)*3;
    		int start_row=(i/3)*3;
    		int x = start_row+j/3;
    		int y = statr_clo+j%3;
    		if(j%3==0&&j!=0){
    			printf("\n");
    		}
    		printf("(%d,%d) ",x,y);

    		if(row[sudo[x][y]]!=-1){
    			printf("x:%d y:%d value:%d\n",x,y,sudo[x][y]);
    			return NO;
    		}
    		row[sudo[x][y]] = 1;
    	}
    	printf("\n--------------\n");
    	// 恢复检测表
    	for(j=0;j<=n*n;j++){
        	row[j]= -1;
        	cl[j] = -1;
   		} 
    }
    return YES;
}
int readSudo(int sudo[MAX][MAX]){
    FILE * in = fopen("./in.data","r");
    int i,j,n;
    fscanf(in,"%d\n",&n);
    for(i=0;i<n*n;i++){
        for(j=0;j<n*n;j++){
            fscanf(in,"%d",&sudo[i][j]);
        }
    }
    return  n;
}


// 2015 第十大题，生成二叉树的扩充标准形式的存储结构,即为多出一个指针指向双亲节点
ExtendBTree * TEN_extendTree2(BTree * tree,ExtendBTree * pre){
    if(tree == NULL){
        return NULL;
    }
    ExtendBTree * Extree = (ExtendBTree*)malloc(sizeof(ExtendBTree));
    Extree->data = tree->data;
    Extree->rchild = NULL; // 初始化
    Extree->lchild = NULL;
    Extree->parent = pre;
    if(tree->lchild!=NULL){
        Extree->lchild = TEN_extendTree2(tree->lchild,Extree);
    }
    if(tree->rchild!=NULL){
        Extree->rchild = TEN_extendTree2(tree->rchild,Extree);
    }
    return Extree;
}


void TEN(){
    int data[100];
    FILE * in =  fopen("./in.data","r");
    int n;
    int i=0;
    fscanf(in,"%d\n",&n);
    for(i=0;i<n;i++){
        fscanf(in,"%d",&data[i]);
    }
    for(i=0;i<n;i++){
        printf("%d ",data[i]);
    }
    printf("\n");
    BTree * tree = NULL;
    tree = createTree(tree,data);
    printf("标准存储结构\n");
    PreOrderBiTree(tree);
    printf("\n");
    LeverOrder(tree);
    //TEN_extendTree(tree,NULL);
    ExtendBTree * ExTree = (ExtendBTree*)malloc(sizeof(ExtendBTree));
    ExTree = TEN_extendTree2(tree,NULL);
    printf("扩充标准形式\n");
    PreOrderExBiTree(ExTree);
    
    printf("\n");
}

void move(SqList * A,int current){
    int len = A->length;
    int i;
    for(i=len-1;i>current;i--){
        A->data[i] = A->data[i-1]; 
    }
}
// 合并两个有序的数组，不是用缓冲区，a的长度够长
void Merge(int *a,int m,int *b,int n){
    int i=m-1,j=n-1,k=m+n-1;
    while(i!=-1 && j!=-1){
        if(a[i]>b[j]){
            //printf("add %d\n",a[i]);
            a[k--] = a[i--];
        } else {
            a[k--] = b[j--];
        }
    }
    printf("j = %d\n",j );
    if(j!=0){
        for(i=j;i>=0;i--){
            a[k--] = b[i];
        }
    }
    print(a,m+n);
}
//十二题
// 指定顶点之间的最短路径
// Dij算法即可解答
int test2015()
{
    //int a[]
    int a[100] = {4,5,99};
    int b[6] = {1,2,6,7,7,8};
    Merge(a,3,b,6);   
    //mergeWithoutBuffer2(a,3,b,6);
    // print(a,9);
    //TEN();
   //	int sudo[MAX][MAX];
   //	int n = readSudo(sudo);
   //	printf("issudo:%d\n",isSudo(sudo,n));
    return 1;
}
