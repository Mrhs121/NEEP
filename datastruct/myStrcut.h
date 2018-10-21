
#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define MAXNUM 100
typedef struct{
    int data[MAXSIZE];
    int front,rear;
}SqQueue;


typedef struct BTree {
	int data;
	struct BTree* lchild;
	struct BTree* rchild;
    //struct BTree * parent;
}BTree;
typedef struct ExtendBTree {
	int data;
	struct ExtendBTree* lchild;
	struct ExtendBTree* rchild;
    struct ExtendBTree * parent;
}ExtendBTree;

typedef struct BTree_char {
	char data;
	struct BTree_char * lchild;
	struct BTree_char * rchild;
}BTree_char;


typedef struct LNode{
    int data;
    struct LNode * next;
}LNode,*linklist;


//---------邻接矩阵

typedef struct{
    int Vex[MAXNUM];
    int Edge[MAXNUM][MAXNUM];
    int vexnum,edgenum;
}MGraph;

// ---------------------------

FILE * fin;
// ----邻接表------ 
typedef struct ArcNode{
    int adjvex; //vertices index
    int info; //  权值
    struct ArcNode * next;
}ArcNode;

typedef struct VNode{
    int data;
    ArcNode * first;
}VNode,AdjList[MAXNUM];

typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
// ----------------------------------------

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
        printf("null ");
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

