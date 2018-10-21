#include "stdafx.h"
#include <stdlib.h>
#include<iostream>
using namespace std;

enum Tag { link, thread };  //这里定义一个枚举类型，link（0）表示指向孩子，thread(1)表示指向前驱后继的线索

							//定义节点结构
typedef struct BiThreadNode
{
	char data;
	struct BiThreadNode *lchild, *rchild;
	Tag ltag, rtag;

}BiThreadNode, *BiThreadTree;

//定义一个全局变量，始终指向刚刚访问过的节点
BiThreadTree pre;

//前序遍历创建二叉树
void createBtTree(BiThreadTree &T)
{
	char c;
	cout << "input (# mean null) : ";
	cin >> c;
	if (c == '#')
	{
		T = NULL;
	}
	else
	{
		T = new BiThreadNode;
		T->data = c;
		T->ltag = T->rtag = link;
		cout << c << " l child" << endl;
		createBtTree(T->lchild);
		cout << c << " r child" << endl;
		createBtTree(T->rchild);
	}
}

//中序遍历二叉线索树并且对节点进行处理.
void midOrderThread(BiThreadTree &T)
{
	if (T)
	{
		midOrderThread(T->lchild);
		//对节点进行处理,即把判断为线索的指针域修改为thread。注意修改前驱后继时分别对pre和T两个指针指向的节点进行处理。
		if (!T->lchild)
		{
			T->ltag = thread;
			T->lchild = pre;     //当发现左孩子为空时另ltag=thread,同时让lchild指针（本来为空）指向前驱节点pre
		}
		if (!pre->rchild)
		{
			T->rtag = thread;   //当发现pre节点的右孩子为空时，另其rtag=thread,同时让他的rchild指向其后继节点T
			pre->rchild = T;
		}
		pre = T;
		midOrderThread(T->rchild);
	}
}

//由于以上只是处理了动态的过程的代码，初始化时会因为pre指针没有赋值从而出错，需要在建立个函数解决此问题
//建立头结点，并中序线索二叉树
void inOrderThread(BiThreadTree &p, BiThreadTree &t)
{
	p = new BiThreadNode;
	p->ltag = link;
	p->rtag = thread;
	p->rchild = p;
	if (!t)
	{
		p->lchild = p;
		p->ltag = link;
	}
	else
	{
		p->lchild = t;
		pre = p;
		midOrderThread(t);
		pre->rchild = p;
		pre->rtag = thread;
		p->rchild = pre;

	}

}
//非递归方式遍历二叉树并输出
void inOrderVisit(BiThreadTree p)
{
	BiThreadTree T;
	T = p->lchild ;
	while (T != p)
	{
		while (T->ltag == link)
		{
			T = T->lchild;
		}
		cout << T->data;
		while (T->rtag == thread && T->rchild != p)
		{
			T = T->rchild;
			cout << T->data;
		}
		T = T->rchild;
	}

}
int main()
{
	BiThreadTree Tree, p;
	createBtTree(Tree);
	inOrderThread(p, Tree);
	inOrderVisit(p);
	system("pause");
}
