// Binary_Tree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
#define YES 1 // �Ƕ�
#define NO -1
#define maxsize 100 // �涨�������Ľڵ�����������100
/*
*  ������ ǰ�к���������ǵݹ���������öѣ���ע��ͼ�ķǵݹ�����õ��Ƕ��У�
*  ʱ�䣺2017-09-17
*  ���ߣ�����
*/

typedef struct BTree {
	int data;
	struct BTree* lchild;
	struct BTree* rchild;
}BTree;

// ����һ�ö�����
BTree* createTree(BTree* T) {

	cout << "��������(-1��ʾ�սڵ�):";
	int data;
	scanf("%d",&data);
	if (data == -1)
		return NULL;
	else
	{
		T = (BTree*)malloc(sizeof(BTree));
		T->data = data;
		cout <<"input "<< data <<" ��������:" << endl;
		T->lchild = createTree(T->lchild);
		cout << "input " << data <<" ��������:" << endl;
		T->rchild = createTree(T->rchild);
	}

	return T;
}

// �жϴ����Ƿ��Ƕ� 17��839����
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

// ǰ�����
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

// �������
void MidOrderBiTree(BTree *T)
{

}

// �������
void LastOrderBiTree(BTree *T)
{

}


// ����������
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
		cout << "�����Ƕ�" << endl;
	}
	else
	{
		cout << "�������Ƕ�" << endl;
	}
	system("pause");
    return 0;
}*/

