// Binary_Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
#define YES 1 // 是堆
#define NO -1
#define maxsize 100 // 规定二叉树的节点总数不超过100
/*
*  二叉树 前中后序遍历，非递归遍历（利用堆）（注：图的非递归遍历用的是队列）
*  时间：2017-09-17
*  作者：黄晟
*/

typedef struct BTree {
	int data;
	struct BTree* lchild;
	struct BTree* rchild;
}BTree;

// 生成一棵二叉树
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

// 判断此树是否是堆 17年839真题
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

// 前序遍历
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

// 中序遍历
void MidOrderBiTree(BTree *T)
{

}

// 后序遍历
void LastOrderBiTree(BTree *T)
{

}


// 线索二叉树
void create(){
	 //v
}/*
int main()
{
	BTree *T=NULL;
	T = createTree(T);
	cout << "test" << endl;
	PreOrderBiTree(T);
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
}*/

