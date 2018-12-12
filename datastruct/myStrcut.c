#include <stdio.h>
#include "../datastruct/myStrcut.h"
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

// create linklist with headnode
LNode * createWithoutHead(int data[],int n)
{

    LNode * head = (linklist)malloc(sizeof(LNode)); 
    head->data = data[0];
    LNode * m = head;
    int i = 0;
    for(i=1;i<n;i++){
        LNode *  node = (linklist)malloc(sizeof(LNode));
     //   printf("%p,%p\n",&node,node);
        node->data = data[i];
        node->next = NULL;
        m->next = node;
        m = node;
    }
    return head;
}
int _count;


BTree* createTree(BTree* T,int _data[]) {

    //printf("输入数据(-1表示空节点):");
	int data;
	//scanf("%d",&data);
	data = _data[_count];
	_count++;
	if (data == -1)
		return NULL;
	else
	{
		T = (BTree*)malloc(sizeof(BTree));
		T->data = data;
		//cout << "input " << data << " 的左子树:" << endl;
		T->lchild = createTree(T->lchild,_data);
		//cout << "input " << data << " 的右子树:" << endl;
		T->rchild = createTree(T->rchild,_data);
	}
	return T;
}

void PreOrderBiTree(BTree *T)
{
	if (T == NULL)
	{
        //printf("null ");
		return;
	}
	else
	{
	
        printf("%d ", T->data);
        //printf("\n");
        PreOrderBiTree(T->lchild);
		PreOrderBiTree(T->rchild);
	}
}
void PreOrderExBiTree(ExtendBTree *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
	
        printf("%d ", T->data);
        if(T->parent!=NULL){
            printf(" parent:%d",T->parent->data);
        }
        printf("\n");
        PreOrderExBiTree(T->lchild);
		PreOrderExBiTree(T->rchild);
	}
}


// 二叉树的层序遍历 使用队列若该节点的左右孩子不为空，则入队
void LeverOrder(BTree * root)
{
    int front = -1;
    int rear = -1;
    BTree * Q[1000];
    int last = 0;
    Q[++rear] = root;
    last = rear;
    int l=1;
    BTree * q = (BTree*)malloc(sizeof(BTree));
    while (front != rear)
    {
        q = Q[++front];
        printf("%d:%d\t",l,q->data);
        // 左右孩子入队
        if (q->lchild != NULL)
            Q[++rear] = q->lchild;
        if (q->rchild != NULL)
            Q[++rear] = q->rchild;
        if(front == last){
            last = rear;
            l++;
            printf("\n");
        }
    }

}

