

// 线索二叉树

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// 通过tag表示是否有孩子或者为前去后继

enum flag{Child,Thread};

struct ThrNode
{
	char data;
	ThrNode * lchild,*rchild;
	int ltag,rtag;
};

ThrNode * create(ThrNode * root)
{
	ThrNode * T = NULL;
        cout << "输入数据(#表示空节点):"<<endl;
        char data;
        cin>>data;
        if (data == '#')
                return NULL;
	else
        {
                T = (ThrNode*)malloc(sizeof(ThrNode));
                T->ltag=0; T->rtag=Child; T->data = data;
                cout <<"input "<< data <<" 的左子树:" << endl;
                T->lchild = create(T->lchild);
                cout << "input " << data <<" 的右子树:" << endl;
                T->rchild = create(T->rchild);
        }

        eturn T;	
}

//中序线索化链表，左孩子 根节点 右孩子
void createThread(ThrNode * node,ThrNode * pre)
{
	if(node == NULL){
		return ;
	}
	printf("线索化\n");
	createThread(node->lchild,pre);
	if(node->lchild==NULL) {
		printf("1 zhi qian");
		node->ltag = 1;
		printf("she zhi qian qu");
		node->lchild = pre; //设置前驱	
	}

	if(node->rchild == NULL) node->rtag = 1; // 如果孩子为空，则设置为后继
	if(pre!= NULL && pre->rtag==1 ) pre->rchild=node; // 设置后记
	pre=node;
	createThread(node->rchild,pre);
}


int main()
{
	ThrNode * root = NULL;
	root = create(root);
	ThrNode * pre = (ThrNode*)malloc(sizeof(ThrNode));
	pre = NULL;
	cout<<root->lchild->data<<endl;
	createThread(root,pre);
	return 0;
}
