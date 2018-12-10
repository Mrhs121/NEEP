#pragma once


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
LNode * create(int data[],int n);
// create linklist with headnode
LNode * createWithoutHead(int data[],int n);

BTree* createTree(BTree* T,int _data[]);
void PreOrderBiTree(BTree * T);
void PreOrderExBiTree(ExtendBTree *T);

// 二叉树的层序遍历 使用队列若该节点的左右孩子不为空，则入队
void LeverOrder(BTree * root);


