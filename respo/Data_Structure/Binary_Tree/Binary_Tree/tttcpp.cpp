#include "stdafx.h"
#include <stdlib.h>
#include<iostream>
using namespace std;

enum Tag { link, thread };  //���ﶨ��һ��ö�����ͣ�link��0����ʾָ���ӣ�thread(1)��ʾָ��ǰ����̵�����

							//����ڵ�ṹ
typedef struct BiThreadNode
{
	char data;
	struct BiThreadNode *lchild, *rchild;
	Tag ltag, rtag;

}BiThreadNode, *BiThreadTree;

//����һ��ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľڵ�
BiThreadTree pre;

//ǰ���������������
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

//��������������������ҶԽڵ���д���.
void midOrderThread(BiThreadTree &T)
{
	if (T)
	{
		midOrderThread(T->lchild);
		//�Խڵ���д���,�����ж�Ϊ������ָ�����޸�Ϊthread��ע���޸�ǰ�����ʱ�ֱ��pre��T����ָ��ָ��Ľڵ���д���
		if (!T->lchild)
		{
			T->ltag = thread;
			T->lchild = pre;     //����������Ϊ��ʱ��ltag=thread,ͬʱ��lchildָ�루����Ϊ�գ�ָ��ǰ���ڵ�pre
		}
		if (!pre->rchild)
		{
			T->rtag = thread;   //������pre�ڵ���Һ���Ϊ��ʱ������rtag=thread,ͬʱ������rchildָ�����̽ڵ�T
			pre->rchild = T;
		}
		pre = T;
		midOrderThread(T->rchild);
	}
}

//��������ֻ�Ǵ����˶�̬�Ĺ��̵Ĵ��룬��ʼ��ʱ����Ϊpreָ��û�и�ֵ�Ӷ�������Ҫ�ڽ������������������
//����ͷ��㣬����������������
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
//�ǵݹ鷽ʽ���������������
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
