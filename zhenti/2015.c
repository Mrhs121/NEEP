#include <stdio.h>
#include <stdlib.h>
#include "../datastruct/myStrcut.h"

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


void print(int b[],int n){
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
//  完美解决方案
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
// 17年839真题  合并两个有序的数组，不使用缓冲区，A的长度够长
// 两种思路
// 1.在A中插入新的元素之后，后面的元素往后面移动即可，应为A 的长度够长
// 2.从后面忘前面添加新的大端
void mergeWithoutBuffer(SqList *A,SqList *B)
{
    void print(int arr[],int n);
    int i=0,j=0;
    while(i<A->length&&j<B->length)
    {
        if(A->data[i]<=B->data[j])
            i++;
        else{ 
            A->length++;
            move(A,i);
            A->data[i] = B->data[j];
            print(A->data,A->length);
            i++;
            j++;
        }
    }
    printf("i=%d,j=%d\n",i,j);
    while(j<B->length ){
        printf("add B\n");
        A->data[i++] = B->data[j++];   
        A->length++;
    }
//  return ture;
}
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

//十二题
// 指定顶点之间的最短路径
// Dij算法即可解答
int main()
{
    int a[100] = {4,5,99};
    int b[6] = {1,2,6,7,7,8};
    mergeWithoutBuffer2(a,3,b,6);
    print(a,9);
 //   TEN();
   //	int sudo[MAX][MAX];
   //	int n = readSudo(sudo);
   //	printf("issudo:%d\n",isSudo(sudo,n));
    return 1;
}
