/*************************************************************************
	> File Name: 18_839.c
	> Author:黄大神 
	> Mail: 
	> Created Time: Sat 22 Sep 2018 08:17:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct LNode{
    int data;
    struct LNode * next;
}LNode,*linklist;


typedef struct BTree {
	int data;
	struct BTree* lchild;
	struct BTree* rchild;
}BTree;

typedef struct BTree_char {
	char data;
	struct BTree_char * lchild;
	struct BTree_char * rchild;
}BTree_char;


typedef struct TStack {
	BTree * data[50];
	int top;
}TStack;


void printStack(TStack s){
    while(s.top--){
        printf("%d ",s.data[i].data);
    }
}


typedef struct Qu {
	BTree * data[50];
	// int LeverCount[50];
	int front, rear;
}Qu;



//先序自动创建二叉树
int _data1[] = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1};
int _data[] = {1,2,3,4,-1,-1,5,-1,-1,6,-1,-1,7,-1,-1};
int _data2[] = { 1,2,3,-1,-1,-1,5,-1,-1 };
int _data_sortTree[] = {6,2,1,-1,-1,4,3,-1,-1,-1,8,-1,-1};
char _data_char[] = { '*','+','a','#','#','b','#','#','*','c','#','#','-','#','d','#','#' };
char _data_char2[] = { '+','+','a','#','#','b','#','#','+','c','#','#','+','d','#','#','e','#','#' };

static int _count = 0;
int _Lever = 0;




// create linklist with headnode
LNode * create(int data[],int n)
{


    LNode * head = (linklist)malloc(sizeof(LNode)); 
    head->data = -1;
    LNode * m = head;
    int i = 0;
    for(i=0;i<n;i++){
        LNode *  node = (linklist)malloc(sizeof(LNode));
        node->data = data[i];
        node->next = NULL;
        m->next = node;
        m = node;
    }
    return head;
}

// 2018 839 判断表b是否包含在a中 时间O(n)
int  isAIncludeB(LNode *a,LNode*b)
{
    LNode * _a = a->next;
    LNode * _b = b->next;
    // 如果匹配链 首元素的值比目标链的首元素都小
    // 那么肯定不包含
    if(_b->data < _a->data){
        return FALSE;
    }
    while(_a!=NULL){
        if(_a->data == _b->data){
            // 同时移动
            _a = _a->next;
            _b = _b->next;
        } else {
            // 不匹配的情况下 子表复原到表头
            _b = b->next;
            _a = _a->next;
        }
        // 如果走完了，那么说明吧全部匹配好了
        if(_b==NULL){
            return TRUE;
        }
    }
    if(_a==NULL && _b!=NULL){
        return FALSE;
    } else {
        return TRUE;
    }
    //return FALSE;
}

// 奇偶划分
void divide(int arr[],int left,int right){

    int base = arr[left];
    int l = left;
    int r = right;
    int temp;
    while(l<r){
        while(arr[r]%2==0 && l<r){
            r--;
        }
        while(arr[l]%2!=0 && l<r){
            l++;
        }
        // 当左边遇到偶数的时候，右边遇到奇数的时候，交换
        printf("swap %d <-- >%d\n",r,l);
        if(arr[l]%2==0&&arr[r]%2!=0){
            temp = arr[r];
            arr[r] = arr[l];
            arr[l] = temp;
        }   
    }   
}


void  testDivid(){
    int arr[7] = {2,2,1,2,2,2,1};
    divide(arr,0,6);
    int i=0;
    for(i=0;i<7;i++){
        printf("%4d",arr[i]);
    }
    printf("\n");
}

void testIsInclude(){
    int a[] = {1,2,3,4,5,6,7,8};
    int b[] = {1,2,3};
    LNode * A = create(a,8);
    LNode * B = create(b,3);
    if(isAIncludeB(A,B)){
        printf("A include B\n");
    } else {
        printf("not included B\n");
    }
}

int isSatisfyHeap(BTree * tree) {
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
				return -1;
			}

			stack[++top] = p->lchild;
		}

		if (p->rchild != NULL)
		{

			if (p->data < p->rchild->data)
			{
				return -1;
			}

			stack[++top] = p->lchild;
		}
	}
    // 队列 also ok
	return 1;
}



int main()
{

    testIsInclude(); 
    return 0;
}

