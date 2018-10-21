#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define YES 1 // 是堆
#define NO -1
#define maxsize 100 // 规定二叉树的节点总数不超过100
/*
 * *  二叉树 前中后序遍历，非递归遍历（利用堆）（注：图的非递归遍历用的是队列）
 * *  时间：2017-09-17
 * *  作者：黄晟
 * */

typedef struct BTree {
	int data;
	struct BTree* lchild;
	struct BTree* rchild;
}BTree;

BTree* createTree(BTree* T) {

	cout << "输入数据(-1表示空节点):";
	int data;
	scanf("%d",&data);
	if (data == -1)
		return NULL;
	else
	{
		T = (BTree*)malloc(sizeof(BTree));
		T->data = data;
		cout <<"input "<< data <<" 的左子树:" << endl;
		T->lchild = createTree(T->lchild);
		cout << "input " << data <<" 的右子树:" << endl;
		T->rchild = createTree(T->rchild);
	}

	return T;
}

// 839真题 判断一棵树是否为堆
int isHeap(BTree * tree) {
	BTree * stack[maxsize];
	int top = -1;
	stack[++top] = tree;
	BTree * p;
	while (top!=-1)
	{
		p = stack[top--]; 
		
		if (p->lchild !=NULL)
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
	return 1;
}

void PreOrderBiTree(BTree *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%d ", T->data);
		PreOrderBiTree(T->lchild);
		PreOrderBiTree(T->rchild);
	}
}

// 二叉树的层序遍历 使用队列若该节点的左右孩子不为空，则入队
void LeverOrder(BTree * root)
{
	int front= -1;
	int rear = -1;
	BTree * Q[1000];
	Q[++rear] = root;
	BTree * q = (BTree*)malloc(sizeof(BTree));
	while(front!=rear)
	{
		q = Q[++front];
		cout<<q->data<<endl;
		// 左右孩子入队
		if(q->lchild!=NULL)
			Q[++rear] = q->lchild;
		if(q->rchild!=NULL)
			Q[++rear] = q->rchild;
	} 

}
// 非递归前序遍历 OK
void PreOrder(BTree * T)
{
	cout<<"非递归前序遍历"<<endl;
	int top = -1;
	BTree * s[1000];	
	while(T!=NULL || top!=-1)
	{
	    while(T!=NULL)
	    {
		cout<<T->data<<endl;
		s[++top] = T;
		T = T->lchild;
	    }
	    if(top!=-1)
	    {
		T = s[top--];
		T = T->rchild;
	    }	
	}
}

int main()
{
	BTree *T=NULL;
	T = createTree(T);
	cout << "test" << endl;
	//PreOrderBiTree(T);
	//PreOrder(T);
	LeverOrder(T);
	int res = isHeap(T);
	cout << "res : " << res<<endl;
	if(res == YES)
	{
		cout << "此树是堆" << endl;
	}
	else
	{
		cout << "此树不是堆" << endl;
	}
	system("pause");
    return 0;
}
