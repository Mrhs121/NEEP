// git.cpp : 定义控制台应用程序的入口点。
//


#ifdef WINVER
#include "stdafx.h"
#endif

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

typedef struct BTree_char {
	char data;
	struct BTree_char * lchild;
	struct BTree_char * rchild;
}BTree_char;


typedef struct TStack {
	BTree * data[50];
	int top;
}TStack;

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


// 计算最大宽度
// 以及计算层数
int BTWidth(BTree * t) {
	int LeverCount[100];
	int max = -1;
	Qu _queue;
	_queue.front = -1;
	_queue.rear = -1;
	int last = 0;
	int Lever = 0;
	int count = 0;
	_queue.data[++_queue.rear] = t;
	BTree * p;
	while (_queue.front < _queue.rear) {
		p = _queue.data[++_queue.front];
		count += 1;
		if (p->lchild != NULL)
			_queue.data[++_queue.rear] = p->lchild;
		if (p->rchild != NULL)
			_queue.data[++_queue.rear] = p->rchild;
		// key
		if (_queue.front == last) {
			Lever++;
			cout << "count:" << count << endl;
			LeverCount[Lever] = count;
			// echoLeverWidth[Lever] = count;
			last = _queue.rear;
			count = 0;
		}
	}
	max = LeverCount[1];
	//cout<<"_max:"<<max<<endl;
	for (int i = 1;i <= Lever;i++) {
		if (max<LeverCount[i])
			max = LeverCount[i];
	}
	cout << "the tree's Lever is:" << Lever << endl;
	return max;
}



bool isEmpty(TStack s) {
	if (s.top == -1) {
		//cout<<"kong\n";
		return true;
	}
	else {
		//cout<<"not empty"<<endl;
		return false;
	}
}

void push(TStack * s, BTree * node) {
	s->data[++(s->top)] = node;
}

BTree * pop(TStack * s)
{

	return s->data[s->top--];
}

BTree * getTop(TStack s)
{
	return s.data[s.top];
}


BTree_char* createTree_char(BTree_char* T) {

	cout << "输入数据(-1表示空节点):";
	char data;
	//scanf("%d",&data);
	cout << _data_char2[_count] << endl;;
	data = _data_char2[_count];
	_count++;
	if (data == '#')
		return NULL;
	else
	{
		T = (BTree_char*)malloc(sizeof(BTree_char));
		T->data = data;
		cout << "input " << data << " 的左子树:" << endl;
		T->lchild = createTree_char(T->lchild);
		cout << "input " << data << " 的右子树:" << endl;
		T->rchild = createTree_char(T->rchild);
	}
	return T;
}






BTree* createTree(BTree* T,int _data[]) {

	cout << "输入数据(-1表示空节点):";
	int data;
	//scanf("%d",&data);
	cout << _data[_count] << endl;;
	data = _data[_count];
	_count++;
	if (data == -1)
		return NULL;
	else
	{
		T = (BTree*)malloc(sizeof(BTree));
		T->data = data;
		cout << "input " << data << " 的左子树:" << endl;
		T->lchild = createTree(T->lchild,_data);
		cout << "input " << data << " 的右子树:" << endl;
		T->rchild = createTree(T->rchild,_data);
	}
	return T;
}

// 839真题 答案 一颗二叉树采用标准存储
// 判断这棵树是否为堆的条件
int isSatisfyHeap(BTree * tree) {
	BTree * stack[maxsize];
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
	return 1;
}

void PreOrderBiTreeWithOutLeaf(BTree *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		if (T->lchild != NULL || T->rchild != NULL) {
			printf("%d ", T->data);
		}
		PreOrderBiTreeWithOutLeaf(T->lchild);
		PreOrderBiTreeWithOutLeaf(T->rchild);
	}
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

void PreOrderBiTreeWithLever(BTree *T,int lever)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf(" %d-----> %d ",lever ,T->data);
		PreOrderBiTreeWithLever(T->lchild,lever+1);
		PreOrderBiTreeWithLever(T->rchild,lever+1);
	}
}

void postOrderBiTree(BTree *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
	//	printf("%d ", T->data);
		PreOrderBiTree(T->lchild);
		PreOrderBiTree(T->rchild);
		printf("%d ", T->data);
    }
}

void PreOrderBiTree_char(BTree_char *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", T->data);
		PreOrderBiTree_char(T->lchild);
		PreOrderBiTree_char(T->rchild);
	}
}

void InOrderBiTree(BTree *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		//	printf("%d ", T->data);
		InOrderBiTree(T->lchild);
		cout << T->data << " ";
		InOrderBiTree(T->rchild);
	}
}

void InOrderBiTree_char(BTree_char *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		//	printf("%d ", T->data);
		InOrderBiTree_char(T->lchild);
		cout << T->data << " ";
		InOrderBiTree_char(T->rchild);
	}
}
// 将中序序列转换成数学表达式
void BTree_char2Exp(BTree_char * T, int deep) {

	//    cout<<"-->\n";
	if (T == NULL)
		return;
	else if (T->lchild == NULL && T->rchild == NULL)
		printf("%c", T->data);
	else {
		if (deep>1) {
			printf("(");
		}
		BTree_char2Exp(T->lchild, deep + 1);
		printf("%c", T->data);
		BTree_char2Exp(T->rchild, deep + 1);
		if (deep>1)
			printf(")");
	}
}
void BTree_char2E(BTree_char * T) {
	BTree_char2Exp(T, 1);
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
		cout <<l<<"----> "<< q->data<<" ";
		// 左右孩子入队
		if (q->lchild != NULL)
			Q[++rear] = q->lchild;
		if (q->rchild != NULL)
			Q[++rear] = q->rchild;
        if(front == last){
            last = rear;
            l++;
            cout<<endl;
        }
	}

}
// 非递归前序遍历 OK
void PreOrder(BTree * T)
{
	cout << "非递归前序遍历" << endl;
	int top = -1;
	BTree * s[1000];
	while (T != NULL || top != -1)
	{
		while (T != NULL)
		{
			cout << T->data << endl;
			s[++top] = T;
			T = T->lchild;
		}
		if (top != -1)
		{
            // gettop and pop 
			T = s[top--];
			T = T->rchild;
		}
	}
}

//寻找最近的公共祖先
// 从根节点开始遍历，如果node1和node2中的任一个和root匹配
// ，那么root就是最低公共祖先。 
// 如果都不匹配，则分别递归左、右子树，
// 如果有一个 节点出现在左子树，
// 并且另一个节点出现在右子树，则
// root就是最低公共祖先. 
// 如果两个节点都出现在左子树，
// 则说明最低公共祖先在左子树中，
// 否则在右子树
BTree * ancestor(BTree* root, int node1, int node2)
{
    // 有点复杂
        if (root == NULL)
            return NULL;
     
        if (node1 == root->data 
            || node2 == root->data)
            return root;
     
        BTree * cur = NULL;
     
        BTree * left_lca = ancestor(root->lchild, node1, node2);
        BTree * right_lca = ancestor(root->rchild, node1, node2);
        if (left_lca && right_lca)
            return root;
        if (left_lca == NULL)
            return right_lca;
        else
            return left_lca;
    
}

// 王道解法
BTree * ancestor_wd(BTree * root,BTree * p,BTree * q)
{
    return  NULL;
}
//非递归后序遍历
void postOrder(BTree * tree)
{

	int i = 0;
	TStack s;

	s.top = -1;
	BTree * p = tree;
	BTree * r = NULL;
	while (p != NULL || !isEmpty(s))
	{
		//cout<<"if "<<s.top<<"----------"<<s.data[s.top]->data<<endl;
		if (p != NULL) {
			push(&s, p);
			p = p->lchild;
			//            if(p==NULL){
			//              cout<<"left finish"<<endl;
			//        }
		}
		else
		{
			//      cout<<"tetst111111"<<endl;
			p = getTop(s);
			if (p->rchild&&p->rchild != r)
			{
				p = p->rchild; //上一个结点向右边走
				push(&s, p);
				p = p->lchild;
			}
			else
			{
				p = pop(&s);
				printf("%5d", p->data);
				r = p;
				p = NULL;
			}
		}
	}
	printf("\n");
}



void swap(BTree * b) {
	if (b) {
		swap(b->lchild);
		swap(b->rchild);
		// 从最底端开始交换，子结点所有子结点交换了之后
		// 交换这个两个上头的子结点
		BTree * temp = b->lchild;
		b->lchild = b->rchild;
		b->rchild = temp;
	}
}
//将前序变成后序序列
void preToPost(char pre[], int l1, int h1, char post[], int l2, int h2) {

	if (l1 <= h1) {

		// 处理结点，的第一个结点即为  的最后一个结点
		post[h2] = pre[l1];
		// 处理左边的左子树
		int half = (h1 - l1) / 2;
		preToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
		preToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
	}
}
// 获取与key的数值相同的路径
void getPathByKey(BTree * T,int key){
    if(T==NULL){
        return;
    }    
   // printf("hello world");
} 

void testPath(){
    int data[] = {10,5,4,-1,-1,7,-1,-1,12,-1,-1};
    BTree * T = NULL;
    T = createTree(T,data);
    LeverOrder(T);
    cout<<"------------------"<<endl;
    cout<<" ----> "<<T->data<<endl;
    PreOrderBiTree(T);
    getPathByKey(T,22);
}


void testBtree() {
	BTree * BST_search(int ,BTree*);
    BTree *T = NULL;
	cout << "--------------- create tree-------------------\n";
	T = createTree(T,_data_sortTree);
	cout << "\n---------------   finish  ---------------------\n";
	LeverOrder(T);
    cout << "\ntest" << endl;
	PreOrderBiTreeWithLever(T,1);
    /*
    PreOrderBiTree(T);
	cout << endl << "非叶子结点：";
	PreOrderBiTreeWithOutLeaf(T);
    cout<<endl;
    InOrderBiTree(T);
    cout << endl;
    BTree * t = BST_search(10,T);
    if(t!=NULL){
        cout<<"bst search res is:"<<t->data<<endl;
    }else{
        cout<<"not find "<<1<<"in the tree "<<endl;
    }
    
    
    
    cout<<"-------------------------------\n";
    char * pre = "1245367";
	char post[100];
	preToPost(pre, 0, 6, post, 0, 6);
	cout << "pre order:" << pre << endl;
	cout << "post order :" << post << endl;
    */
}

void testBtree_char() {
	BTree_char * T = NULL;
	T = createTree_char(T);
	PreOrderBiTree_char(T);
	cout << endl;
	InOrderBiTree_char(T);
	cout << endl;
	BTree_char2E(T);
	cout << endl;
}

// 查找树的创建/插入

int BST_Insert(BTree **T,int key){
    if(*T == NULL){
        *T = (BTree*)malloc(sizeof(BTree));
        (*T)->data = key;
        (*T)->lchild=(*T)->rchild = NULL;
        return 1;
    }
    else if(key==(*T)->data){
        return 0;
    } else if(key<(*T)->data){
        // 直接对原链进行修改
        return BST_Insert(&(*T)->lchild,key);
    } else {
        return BST_Insert(&(*T)->rchild,key);
    }
}

//   查找树的递归查找
BTree * BST_search(int data,BTree * T){
    if(T==NULL){
        return  NULL;
    }
    if(data == T->data){
        return T;
    }
    if(data < T->data){
        return BST_search(data,T->lchild);
    }else{
        return BST_search(data,T->rchild);
    }
}
// 在给定 排序树中 输出比 可以 大的结点 从大到小
void OutPut(BTree * bst_tree,int key){
    if(bst_tree == NULL){
        return;
    }
    if(bst_tree->rchild != NULL){
        OutPut(bst_tree->rchild,key);
    }
    if(bst_tree->data > key){
        printf("biger :%d\n",bst_tree->data);
    } else {
        printf("small :%d\n",bst_tree->data);
    }
    if(bst_tree->lchild!=NULL){
        OutPut(bst_tree->lchild,key);
    }
}

BTree * search_small(BTree * t,int k){
    return  NULL;
}


void testBST(){
    BTree* T=NULL ;
   // int q[] = {10,4,5,2,3,6,11};
    int q[] = {5,3,10,1,4,8,13};
    int i=0;
    for(i=0;i<7;i++){
        BST_Insert(&T,q[i]);
    }
    InOrderBiTree(T);
    cout<<"---------------------\n";
    PreOrderBiTree(T);
    cout<<"---------------------\n";
    LeverOrder(T);
    cout<<"----------------------\n";
    OutPut(T,4);
}
// 测试最近公共祖先
void testAncestor(){
    BTree * T = NULL;
    T = createTree(T,_data);
    PreOrderBiTree(T);
    cout<<"-------------------\n";
    BTree * res =  ancestor(T,5,6);
    if(res!=NULL){
        cout<<"the ancestor is :"<<res->data<<endl;
    }
}

int main()
{
    testPath();
//    testBtree();
//
//testBST();
    //    testAncestor();
   // testBST();
//	testBtree();
	//testBtree_char();
	//int echoLeverWidth[100];
	/*
	int max = BTWidth(T);
	cout<<"max width is:"<<max<<endl;
	*/

	/*
	cout<<"\n------------------------------\n";
	//cout<<endl;
	postOrder(T);
	cout<<"\n------------------------------"<<endl;
	swap(T);
	PreOrderBiTree(T);
	postOrder(T);
	//PreOrder(T);

	*/



	/*
	LeverOrder(T);
	int res = isSatisfyHeap(T);
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
	*/
#ifdef WINVER
	printf("win");
	system("pause");
#endif // WINVER

	cout << endl;
	return 0;
}

